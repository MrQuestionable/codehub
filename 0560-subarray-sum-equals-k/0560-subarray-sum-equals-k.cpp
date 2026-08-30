class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> prefixSumCount;
        int prefixSum = 0;
        int count = 0;
        prefixSumCount[0] = 1;
        for (int i = 0; i < n; i++) {
            prefixSum += arr[i];
            int remove = prefixSum - k;
            if (prefixSumCount.find(remove) != prefixSumCount.end()) {
                count += prefixSumCount[remove];
            }
            prefixSumCount[prefixSum]++;
        }
        return count;
    }
};