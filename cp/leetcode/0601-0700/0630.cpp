#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        priority_queue<int> pq;
        sort(courses.begin(), courses.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
             });
        int end = 0;
        int course = 0;
        for (auto& it : courses) {
            pq.push(it[0]);
            end += it[0];
            course++;
            if (end > it[1]) {
                end -= pq.top();
                pq.pop();
                course--;
            }
        }
        return course;
    }
};