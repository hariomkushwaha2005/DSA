class Solution {
public:
    int digitFrequencyScore(int n) {
        int arr[10] = {0};
        while (n > 0) {
            arr[n % 10]++;
            n /= 10;
        }
        int sum = 0;
        for(int i = 1; i < 10; i++){
            sum += (arr[i]*i);
        }
        return sum;
    }
};