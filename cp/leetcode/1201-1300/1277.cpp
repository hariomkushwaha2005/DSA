#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int histo(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        int ans = 0;
        
        // Loop to n to flush the stack at the end (arr[n] is effectively 0)
        for (int i = 0; i <= n; i++) {
            int current_height = (i == n) ? 0 : arr[i];
            
            while (!st.empty() && arr[st.top()] > current_height) {
                int x = st.top();
                st.pop();
                
                int height = arr[x];
                
                // The left boundary is the NEW top of the stack
                int left = st.empty() ? -1 : st.top();
                int right = i;
                int width = right - left - 1;
                
                // The tallest adjacent boundary
                int left_height = st.empty() ? 0 : arr[left];
                int right_height = current_height;
                int low = max(left_height, right_height);
                
                // --- THE CORRECTED INTEGRATION MATH ---
                
                // Squares must have side lengths (k) between A and B
                int A = low + 1;
                int B = min(height, width); 
                
                if (A <= B) {
                    int n_terms = B - A + 1;
                    int first_term = width - A + 1;  // Squares of size A
                    int last_term = width - B + 1;   // Squares of size B
                    
                    // Arithmetic progression sum
                    int y = n_terms * (first_term + last_term) / 2;
                    ans += y;
                }
            }
            st.push(i);
        }
        return ans;
    }

public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dp(m, 0);
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // Don't forget to fix the '1' bug here too!
                if(matrix[i][j] == 1) dp[j]++;
                else dp[j] = 0;
            }
            ans += histo(dp);
        }
        return ans;
    }
};