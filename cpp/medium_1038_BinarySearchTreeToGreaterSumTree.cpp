#include<iostream>
#include<vector>
#include<windows.h>
#include<algorithm>
#include<queue>
#include<string>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int res = 0;
        if (!root) return NULL;
        deInorder(root, res);
        return root;
    }

    // 逆中序遍历 
    void deInorder(TreeNode* root, int& res) {
        if (!root) return;
        deInorder(root->right, res);
        root->val += res;
        res = root->val;
        deInorder(root->left, res);
    }
};

// 0297题
class Codec {
public:
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "[]")
            return NULL;
        vector<TreeNode*> tree;
        int i = 1;
        while(i < data.length()) {
            int flag = 0;
            if(data[i] == '-') {
                i++;
                flag = 1;
            }
            if(data[i] >= '0' && data[i] <= '9') {
                int num = 0;
                while(data[i] >= '0' && data[i] <= '9') {
                    num = num * 10 + data[i] - '0';
                    i++;
                }
                if(flag)
                    num = -num;
                TreeNode *node = new TreeNode(num);
                tree.push_back(node);
            }
            else if(data[i] == 'n') {
                i += 4;
                tree.push_back(NULL);
            }
            else
                i++;
        }
        queue<TreeNode*> q;
        TreeNode *root = tree[0], *cur;
        q.push(tree[0]);
        i = 1;
        while(!q.empty() && i < tree.size()) {
            TreeNode *cur = q.front();
            q.pop();
            cur->left = tree[i];
            if(cur->left)
                q.push(cur->left);
            if(i + 1 < tree.size()) {
                cur->right = tree[i + 1];
                if(cur->right)
                    q.push(cur->right);
            }
            i += 2;
        }
        return root;
    }
};

int main() {
    string s = "[4, 1, 6, 0, 2, 5, 7, null, null, null, 3, null, null, null, 8]";
    TreeNode* root = Codec().deserialize(s);
    // long start = GetTickCount();
    TreeNode* res = Solution().bstToGst(root);
    // cout << GetTickCount() - start << endl;
    return 0;
}