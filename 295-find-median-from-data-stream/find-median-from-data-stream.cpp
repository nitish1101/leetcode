class MedianFinder {
public:
    MedianFinder() {}

    void addNum(int num) {
        lo.push(num);                    // lower half (max-heap)
        hi.push(lo.top());               // keep all of lo <= all of hi
        lo.pop();
        if (lo.size() < hi.size()) {     // lo may hold one extra element
            lo.push(hi.top());
            hi.pop();
        }
    }

    double findMedian() {
        if (lo.size() > hi.size()) return lo.top();
        return ((double)lo.top() + hi.top()) / 2.0;
    }

private:
    priority_queue<int> lo;                              // max-heap: lower half
    priority_queue<int, vector<int>, greater<int>> hi;   // min-heap: upper half
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
