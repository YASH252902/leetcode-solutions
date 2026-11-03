class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count the frequency of each element
        unordered_map<int, int> frequencyMap;
        for (int num : nums) {
            frequencyMap[num]++;
        }
        
        // Step 2: Use a min-heap to keep track of the top k elements.
        // We store pairs of (frequency, element). 
        // greater<pair<int, int>> makes it a min-heap based on the first element (frequency).
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        for (auto& [num, freq] : frequencyMap) {
            minHeap.push({freq, num});
            
            // If the heap size exceeds k, remove the element with the smallest frequency
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        // Step 3: Extract the k most frequent elements from the heap
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return result;
    }
};