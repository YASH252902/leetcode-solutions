class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int validCount = 0; // Keep track of how many valid elements we find
        
        for(int i = 0; i < arr1.size(); i++) {
            bool isValid = true; // Assume arr1[i] is valid until proven otherwise
            
            for(int j = 0; j < arr2.size(); j++) { // j must always start at 0
                if (abs(arr1[i] - arr2[j]) <= d) {
                    isValid = false; // Condition violated
                    break; // Stop checking arr2 for this specific arr1[i]
                }
            }
            
            // If the loop finished and isValid is still true, it means 
            // no element in arr2 violated the distance rule.
            if (isValid == true) { 
                validCount++;
            }
        }
        
        return validCount; // Return the final tally
    }
};