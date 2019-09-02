#include<iostream>
#include<vector>
#include<windows.h>
#include<algorithm>
#include<queue>
#include<string>
#include<sstream>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
    TreeNode* res = new TreeNode(0);
    TreeNode* head = res;
public:
    TreeNode* increasingBST(TreeNode* root) {
        LDR(root);
        return res->right;
    }

    void LDR(TreeNode* root) {
        if (root) {
            LDR(root->left);
            head->right = new TreeNode(root->val);
            head = head->right;
            LDR(root->right);
        }
    }

    // 以下是0297序列化与反序列化代码
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) {
            string s = "[]";
            return s;
        }
        string s = "[";
        queue<TreeNode*> q;
        q.push(root);
        int i, len;
        while(!q.empty()) {
            len = q.size();
            for(i = 0; i < len; i++) {
                TreeNode *front = q.front();
                q.pop();
                if (front) {
                    s += std::to_string(front->val);
                    q.push(front->left);
                    q.push(front->right); 
                }
                else
                    s += "null";
                if(!q.empty())
                    s += ",";
            }
        }
        for(i = s.length() - 1; i >= 0; i--) {
            if(s[i] >= '0' && s[i] <= '9')
                break;
        }
        s = s.substr(0, i + 1);
        s += "]";
        return s;
    }
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
    string s = "[5, 3, 6, 2, 4, null, 8, 1, null, null, null, 7, 9]";
    TreeNode* root = Codec().deserialize(s);
    TreeNode* res = Codec().increasingBST(root);
    return 0;
}