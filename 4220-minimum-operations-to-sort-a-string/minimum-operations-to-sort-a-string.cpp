#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        
        // Base Case 0: If the string is already sorted, 0 operations needed.
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }
        
        // Base Case 1: If length is 2 (and it's not sorted), it's impossible.
        // You can only sort a *proper* substring (length 1), which does nothing.
        if (n == 2) {
            return -1;
        }
        
        // Find the global smallest and largest characters in the string
        char min_c = *min_element(s.begin(), s.end());
        char max_c = *max_element(s.begin(), s.end());
        
        // Case 1: 1 Operation
        // If the smallest char is already at the very beginning, we just sort the rest of the string (the suffix).
        // OR if the largest char is at the end, we just sort the prefix.
        if (s[0] == min_c || s[n - 1] == max_c) {
            return 1;
        }
        
        // Case 2: 2 Operations
        // If the smallest or largest char is somewhere in the middle, we can capture it 
        // in a proper substring, push it to its correct end, and then sort the remaining side.
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == min_c || s[i] == max_c) {
                return 2;
            }
        }
        
        // Case 3: 3 Operations
        // The absolute worst-case scenario: The largest character is stuck exactly at index 0, 
        // AND the smallest character is stuck exactly at the last index.
        return 3;
    }
};