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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            int len = s.size();
            for (int i = 0; i < len; ++i) {
                TreeNode* node = s.front();
                if (i == 0) res.push_back(node->val);
                if (node->right) s.push(node->right);
                if (node->left) s.push(node->left);
                s.pop();
            }
        }
        return res;
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
    string s = "[1,2,3,null,5,null,4]";
    TreeNode* root = Codec().deserialize(s);
    // long start = GetTickCount();
    vector<int> res = Solution().rightSideView(root);
    // cout << GetTickCount() - start << endl;
    return 0;
}