#include <queue>

using namespace std;
class MedianFinder {
    struct cmp {
        bool operator()(double a, double b) {
            return a > b;
        }
    };

   private:
    priority_queue<double> maxHeap;
    priority_queue<double, vector<double>, cmp> minHeap;

   public:
    MedianFinder() {
        maxHeap = priority_queue<double>();
        minHeap = priority_queue<double, vector<double>, cmp>();
    }

    void addNum(int num) {
        if (maxHeap.empty()) {
            maxHeap.push(num);
            return;
        }

        if (num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        if (maxHeap.size() >= minHeap.size() + 2) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }

        return maxHeap.top();
    }
};
