/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

class Solution
{
public:
    /*You are required to complete below method */
    int maxLevelSum(Node *root)
    {
        int ans = INT_MIN; // To store answer
        if (root == NULL)
            return 0;
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) // Level order traversal
        {
            int n = q.size(), temp = 0;
            while (n--)
            {
                Node *top = q.front();
                q.pop();
                temp += top->data;
                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
            }
            ans = max(ans, temp); // Sum of each level
        }
        return ans;
    }
};