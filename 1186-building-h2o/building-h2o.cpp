class H2O {
public:
    mutex m;
    condition_variable cv;
    int h = 0;

    H2O() {}

    void hydrogen(function<void()> releaseHydrogen) {
         unique_lock<mutex> lock(m);

        cv.wait(lock, [&]() { return h < 2; });
        releaseHydrogen();
        h++;
        if (h == 2) cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {

        unique_lock<mutex> lock(m);
        cv.wait(lock, [&]() { return h == 2; });
         releaseOxygen();
        h = 0;
        cv.notify_all();
        
    }
};
