class FizzBuzz {
private:
    int n;
    int i = 1;
    mutex m;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        unique_lock<mutex> lock(m);
        while (i <= n) {
            while (i <= n && (i % 3 != 0 || i % 5 == 0)) {
                cv.wait(lock);
            }
            if (i > n) break;
            printFizz();
            i++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        unique_lock<mutex> lock(m);
        while (i <= n) {
            while (i <= n && (i % 5 != 0 || i % 3 == 0)) {
                cv.wait(lock);
            }
            if (i > n) break;
            printBuzz();
            i++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        unique_lock<mutex> lock(m);
        while (i <= n) {
            while (i <= n && (i % 3 != 0 || i % 5 != 0)) {
                cv.wait(lock);
            }
            if (i > n) break;
            printFizzBuzz();
            i++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        unique_lock<mutex> lock(m);
        while (i <= n) {
            while (i <= n && (i % 3 == 0 || i % 5 == 0)) {
                cv.wait(lock);
            }
            if (i > n) break;
            printNumber(i);
            i++;
            cv.notify_all();
        }
    }
};