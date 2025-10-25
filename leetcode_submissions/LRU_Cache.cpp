class LRUCache {
public:
    int capacity;

    struct node {
        int key;
        int val;
        node *next;
        node *prev;

        node(int k, int v) {
            key = k;
            val = v;
            next = nullptr;
            prev = nullptr;
        }
    };

    unordered_map<int, node*> mpp;
    node* frontdummy = new node(-1, -1);
    node* lastdummy = new node(-1, -1);

    void removeNode(node* temp) {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    void insertAtFront(node* temp) {
        node* first = frontdummy->next;
        frontdummy->next = temp;
        temp->prev = frontdummy;
        temp->next = first;
        first->prev = temp;
    }

    LRUCache(int capacity_) {
        capacity = capacity_;
        frontdummy->next = lastdummy;
        lastdummy->prev = frontdummy;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1;

        node* temp = mpp[key];
        removeNode(temp);
        insertAtFront(temp);
        return temp->val;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            node* temp = mpp[key];
            temp->val = value;
            removeNode(temp);
            insertAtFront(temp);
        } else {
            if (mpp.size() == capacity) {
                node* last = lastdummy->prev;
                removeNode(last);
                mpp.erase(last->key);
                delete last;
            }
            node* temp = new node(key, value);
            mpp[key] = temp;
            insertAtFront(temp);
        }
    }
};
