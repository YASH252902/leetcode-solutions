class Solution {
public:
    int minDays(int n) {
        // Space bound mathematical trick: Sum of streaks 1+2+..+k = k(k+1)/2. 
        // Max possible streak kabhi bhi sqrt(2*n) ko cross nahi karegi.
        int max_streak = sqrt(2 * n) + 2;
        int total_states = (n + 1) * (max_streak + 2);
        
        // 2D vector ki jagah flattened 1D array declare kiya taaki memory allocate instantly ho
        // Aur 1e9 initialize kiya taaki min() large invalid values ko naturally ignore kare
        vector<int> dp(total_states, 1e9);

        // Helper Lambda function: 2D coordinates (earn, streak) ko 1D index mein map karne ke liye
        auto get_idx = [&](int earn, int streak) {
            return earn * (max_streak + 2) + streak;
        };

        // Base case: Jab earn == n hota hai, tab target meet ho gaya, toh 0 extra days required
        for (int streak = 0; streak <= max_streak; streak++) {
            dp[get_idx(n, streak)] = 0;
        }

        // Bottom-up processing: Target (n-1) se reverse chalkar 0 tak aayenge
        for (int earn = n - 1; earn >= 0; earn--) {
            
            // STEP 1: Pehle streak = 0 ki state calculate karna zaroori hai.
            // Streak 0 par aap day skip (exclude) nahi kar sakte varna infinite loop banega, 
            // isliye sirf 'include' valid hai.
            if (earn + 1 <= n) {
                dp[get_idx(earn, 0)] = 1 + dp[get_idx(earn + 1, 1)];
            }

            // STEP 2: Baaki streaks ke liye dono condition (Include and Exclude) check karo
            for (int streak = 1; streak <= max_streak; streak++) {
                
                int includeAns = 1e9;
                
                // Include: Agar agle round mein points exceed nahi karte
                if (earn + streak + 1 <= n) {
                    includeAns = 1 + dp[get_idx(earn + streak + 1, streak + 1)];
                }

                // Exclude: Din zaya hoga aur streak zero ho jayegi, 
                // Ye humne STEP 1 mein upar already calculate kar liya hai
                int excludeAns = 1 + dp[get_idx(earn, 0)];

                // Dono conditions mein se minimum din store karo
                dp[get_idx(earn, streak)] = min(includeAns, excludeAns);
            }
        }

        // Final answer: 0 score aur 0 streak se start karke target tak pohochne ke min days
        return dp[get_idx(0, 0)];
    }
};