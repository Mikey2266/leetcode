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

// class Codec {
// public:
//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         queue<TreeNode*> qu;
//         qu.push(root);
//         vector<string> res;
//         string s = "[";
//         while(!qu.empty()) {
//             if (qu.front() == NULL) {
//                 res.push_back("null");
//             }
//             else {
//                 qu.push(qu.front()->left);
//                 qu.push(qu.front()->right);
//                 res.push_back(to_string(qu.front()->val));
//             }
//             qu.pop();
//         }
//         for (int i = res.size()-1; i >= 0; i--) {
//             if (res[i] == "null") {
//                 res.erase(res.begin() + i);
//             }
//             else {
//                 break;
//             }
//         }
//         for (int i = 0; i < res.size(); i++) {
//             s = s + res[i] + ",";
//         }
//         if (s == "[") {
//             s = "[]";
//         }
//         else {
//             s = s.substr(0, s.size() - 1) + "]";
//         }
//         return s;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         data = data.substr(1, data.size()-2);
//         queue<string> vec;
//         if (data.size() == 0) {
//             vec.push("null");
//         }
//         else {
//             while (data.size() > 0) {
//                 vec.push(data.substr(0, data.find_first_of(",")));
//                 if (data.find_first_of(",") != -1) {
//                     data = data.substr(data.find_first_of(",") + 1, data.size());
//                 }
//                 else {
//                     data = "";
//                 }
//             }
//         }
//         TreeNode* root;
//         if (vec.size() == 0) {
//             root = NULL;
//             return root;
//         }
//         else {
//             if (vec.front() == "null") {
//                 root = NULL;
//                 return root;
//             }
//             else {
//                 root = new TreeNode(stoi(vec.front()));
//                 vec.pop();
//             }
//         }
//         iterate(root, vec);
//         return root;
//     }
    
//     void iterate(TreeNode* root, queue<string>& vec) {
//         queue<TreeNode*> buff;
//         buff.push(root);
//         while (buff.size() != 0) {
//             if (vec.size() >= 2) {
//                 if (vec.front() != "null") {
//                     buff.front()->left = new TreeNode(stoi(vec.front()));
//                     // buff.front()->left = &oneRoot;
//                     vec.pop();
//                     if (vec.front() != "null") {
//                         buff.front()->right = new TreeNode(stoi(vec.front()));
//                         // buff.front()->right = &oneRoot;
//                     }
//                     vec.pop();
//                 }
//                 else if (vec.front() == "null") {
//                     vec.pop();
//                     if (vec.front() != "null") {
//                         buff.front()->right = new TreeNode(stoi(vec.front()));
//                         // buff.front()->right = &oneRoot;
                        
//                     }
//                     vec.pop();
//                 }
//             }
//             else if (vec.size() == 1) {
//                 if (vec.front() != "null") {
//                     buff.front()->left = new TreeNode(stoi(vec.front()));
//                     vec.pop();
//                 }
//             }
//             if (buff.front()->left != NULL) {
//                 buff.push(buff.front()->left);
//             }
//             if (buff.front()->right != NULL) {
//                 buff.push(buff.front()->right);
//             }
//             buff.pop();
//         }
//     }
// };

class Codec {
public:
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
    string s = "[1,2,3,null,null,4,5]";
    // string s = "[1,2]";
    // string s = "[]";
    TreeNode* root = Codec().deserialize(s);
    string output;
    output = Codec().serialize(root);
    cout << output << endl;
    return 0;
}