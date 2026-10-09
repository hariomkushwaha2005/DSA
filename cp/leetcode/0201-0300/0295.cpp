#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

public:
    MedianFinder() {}

    void addNum(int num) {
        minheap.push(num);
        maxheap.push(minheap.top());
        minheap.pop();

        if (maxheap.size() > minheap.size()) {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }

    double findMedian() {
        if (minheap.size() == maxheap.size())
            return (minheap.top() + maxheap.top()) / 2.0;
        return minheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */