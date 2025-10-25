import requests
import os
import time
import json

# ================= USER CONFIG =================
LEETCODE_SESSION = "hello there"  # Replace with your cookie
SAVE_DIR = "leetcode_submissions"  # Folder to save code files
LANGUAGE = "cpp"  # Change to cpp, python3, java, etc.
REQUEST_DELAY = 1.0  # Increased delay between requests (1 second)
RETRY_DELAY = 5.0  # Delay before retrying after error
MAX_RETRIES = 3  # Maximum retry attempts per request
PROGRESS_FILE = "download_progress.json"  # Track progress
# ===============================================

session = requests.Session()
session.headers.update({
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36",
    "Referer": "https://leetcode.com",
    "Cookie": f"LEETCODE_SESSION={LEETCODE_SESSION}",
    "Content-Type": "application/json",
    "Accept": "application/json"
})

def get_file_extension(lang):
    """Map language to file extension"""
    extensions = {
        "cpp": "cpp",
        "c++": "cpp",
        "python": "py",
        "python3": "py",
        "java": "java",
        "javascript": "js",
        "typescript": "ts",
        "c": "c",
        "csharp": "cs",
        "golang": "go",
        "go": "go",
        "ruby": "rb",
        "swift": "swift",
        "kotlin": "kt",
        "scala": "scala",
        "rust": "rs",
        "php": "php"
    }
    return extensions.get(lang.lower(), "txt")

def save_progress(offset, problem_map):
    """Save current progress to file"""
    progress = {
        "offset": offset,
        "problem_map": problem_map
    }
    with open(PROGRESS_FILE, "w", encoding="utf-8") as f:
        json.dump(progress, f, indent=2)

def load_progress():
    """Load progress from file"""
    if os.path.exists(PROGRESS_FILE):
        try:
            with open(PROGRESS_FILE, "r", encoding="utf-8") as f:
                return json.load(f)
        except:
            return None
    return None

def fetch_submissions(offset=0, limit=20):
    """Fetch submissions from LeetCode API with pagination and retry logic"""
    url = f"https://leetcode.com/api/submissions/?offset={offset}&limit={limit}"
    
    for attempt in range(MAX_RETRIES):
        try:
            resp = session.get(url, timeout=15)
            
            if resp.status_code == 403:
                print(f"\n⚠️  Rate limit hit at offset {offset}. Waiting {RETRY_DELAY * (attempt + 1)}s...")
                time.sleep(RETRY_DELAY * (attempt + 1))
                continue
            
            resp.raise_for_status()
            return resp.json()
        
        except requests.exceptions.Timeout:
            print(f"\n⏱️  Timeout at offset {offset}. Retrying (attempt {attempt + 1}/{MAX_RETRIES})...")
            time.sleep(RETRY_DELAY)
        
        except Exception as e:
            if attempt < MAX_RETRIES - 1:
                print(f"\n❌ Error at offset {offset}: {e}. Retrying in {RETRY_DELAY}s...")
                time.sleep(RETRY_DELAY)
            else:
                print(f"\n❌ Failed after {MAX_RETRIES} attempts: {e}")
                return None
    
    return None

def save_code(title, code, lang):
    """Save code to a file with problem name as filename"""
    safe_title = "".join(c if c.isalnum() or c in (' ', '-', '_') else '_' for c in title)
    safe_title = safe_title.strip().replace(' ', '_')
    
    ext = get_file_extension(lang)
    filename = os.path.join(SAVE_DIR, f"{safe_title}.{ext}")
    
    # Skip if file already exists (no duplicates)
    if os.path.exists(filename):
        return None
    
    try:
        with open(filename, "w", encoding="utf-8") as f:
            f.write(code)
        return filename
    except Exception as e:
        print(f"\n⚠️  Error saving {filename}: {e}")
        return None

def main():
    if not os.path.exists(SAVE_DIR):
        os.makedirs(SAVE_DIR)
    
    print("=" * 60)
    print("LeetCode Submission Downloader (Resume Support)")
    print("=" * 60)
    print(f"Language: {LANGUAGE}")
    print(f"Save Directory: {SAVE_DIR}")
    print(f"Request Delay: {REQUEST_DELAY}s")
    print("=" * 60)
    
    # Check for existing progress
    progress = load_progress()
    if progress:
        print(f"\n🔄 Found previous progress at offset {progress['offset']}")
        print(f"   Already collected {len(progress['problem_map'])} problems")
        response = input("   Resume from last position? (y/n): ").lower()
        if response == 'y':
            offset = progress['offset']
            problem_map = progress['problem_map']
            print("   ✅ Resuming download...\n")
        else:
            offset = 0
            problem_map = {}
            print("   🆕 Starting fresh download...\n")
    else:
        offset = 0
        problem_map = {}
    
    limit = 20
    total_fetched = offset
    consecutive_failures = 0
    max_consecutive_failures = 3

    print("📥 Fetching submissions...\n")
    
    while True:
        data = fetch_submissions(offset, limit)
        
        if data is None:
            consecutive_failures += 1
            if consecutive_failures >= max_consecutive_failures:
                print(f"\n⛔ Too many consecutive failures. Stopping.")
                print(f"📊 Progress saved. Run script again to resume from offset {offset}")
                save_progress(offset, problem_map)
                break
            continue
        
        consecutive_failures = 0  # Reset on success
        
        submissions = data.get("submissions_dump", [])
        if not submissions:
            print("\n✅ Reached end of submissions!")
            break

        for sub in submissions:
            total_fetched += 1
            
            if sub["status_display"] != "Accepted":
                continue
            
            lang = sub["lang"].lower()
            if lang != LANGUAGE.lower():
                continue
            
            slug = sub["title_slug"]
            title = sub["title"]
            
            if slug not in problem_map:
                problem_map[slug] = {
                    "title": title,
                    "code": sub["code"],
                    "lang": sub["lang"],
                    "timestamp": sub["timestamp"]
                }

        print(f"📊 Fetched {total_fetched} submissions | Found {len(problem_map)} accepted {LANGUAGE} solutions", end='\r')

        if not data.get("has_next"):
            print("\n✅ Reached end of submissions!")
            break

        offset += limit
        save_progress(offset, problem_map)  # Save after each successful batch
        time.sleep(REQUEST_DELAY)

    print(f"\n\n✅ Collected {len(problem_map)} unique accepted {LANGUAGE} submissions")
    
    if len(problem_map) == 0:
        print("\n⚠️  No submissions found.")
        return

    print(f"\n💾 Saving submissions to '{SAVE_DIR}' folder...")
    saved_count = 0
    skipped_count = 0
    
    for idx, (slug, sub) in enumerate(problem_map.items(), 1):
        filename = save_code(sub["title"], sub["code"], sub["lang"])
        if filename:
            saved_count += 1
            print(f"[{idx}/{len(problem_map)}] ✓ {os.path.basename(filename)}", end='\r')
        else:
            skipped_count += 1
        time.sleep(0.1)  # Small delay for saving

    print(f"\n\n{'=' * 60}")
    print(f"✅ Saved: {saved_count} new files")
    print(f"⏭️  Skipped: {skipped_count} existing files")
    print(f"📁 Location: {os.path.abspath(SAVE_DIR)}")
    print("=" * 60)
    
    # Clean up progress file on successful completion
    if os.path.exists(PROGRESS_FILE):
        os.remove(PROGRESS_FILE)
        print("🗑️  Progress file cleaned up")

if __name__ == "__main__":

    main()
