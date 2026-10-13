class Solution {
public:
    // Step 1: DP structure declare karna. 
    // TreeNode* ko int (maximum money) se map karne ke liye unordered_map use karenge
    unordered_map<TreeNode*, int> dp;

    int rob(TreeNode* root) {
        // Base case: agar node null hai toh 0 return karo
        if (root == NULL) {
            return 0;
        }
        
        // Step 3: Check karna ki kya is node ka answer pehle se calculate ho chuka hai
        // map.find() ka use karte hain check karne ke liye ki entry map mein hai ya nahi
        if(dp.find(root) != dp.end()){
            return dp[root];
        }

        // Case 1: INCLUSION
        // Agar current node ko include karte hain, toh uski value add karo
        int includeAns = root->val;
        
        // Grandchildren (left side) ki values add karo
        if (root->left != NULL) {
            includeAns += rob(root->left->left) + rob(root->left->right);
        }
        // Grandchildren (right side) ki values add karo
        if (root->right != NULL) {
            includeAns += rob(root->right->left) + rob(root->right->right);
        }

        // Case 2: EXCLUSION
        // Agar current node exclude kiya, toh left child aur right child ka answer add karo
        int excludeAns = rob(root->left) + rob(root->right);

        // Step 2: Answer ko return karne se pehle store karna
        dp[root] = max(includeAns, excludeAns);
        
        return dp[root];
    }
};