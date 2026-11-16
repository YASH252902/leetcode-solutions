class Solution {
public:
    string digitSum(string s, int k) {
        // Loop continuously as long as the string length is greater than k
        while (s.length() > k) {
            
            string mergedAns = ""; // Start with an empty string for this round
            
            // Jump through the string in steps of 'k'
            for (int i = 0; i < s.length(); i += k) {
                
                int currentSum = 0;
                
                // Determine the end of the current chunk.
                // min() ensures we don't go out of bounds on the very last chunk.
                int endOfChunk = min((int)s.length(), i + k);
                
                // Sum the digits in the current chunk
                for (int j = i; j < endOfChunk; j++) {
                    currentSum += (s[j] - '0'); 
                }
                
                // Convert the integer sum to a string and append it
                mergedAns += to_string(currentSum);
            }
            
            // Update 's' with the newly formed string for the next round
            s = mergedAns; 
        }
        
        // Once the loop terminates, 's' is the required length
        return s;
    }
};