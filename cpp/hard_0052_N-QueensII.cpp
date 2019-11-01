#include<iostream>
#include<vector>
#include<windows.h>

using namespace std;

// 简单回溯
class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<vector<int>> rec;
        bt(n, res, rec, 0);
        return res;
    }
    
    void bt(int n, int& res, vector<vector<int>>& rec, int layer) {
        if (rec.size() == n) {
            res++;
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (rec.empty()) rec.push_back({i, layer});
            else {
                // 判断能否插入
                int j = 0;
                for (; j < rec.size(); ++j) {
                    if ((rec[j][0] == i) || (abs(layer - rec[j][1]) == abs(i - rec[j][0]))) break;
                }
                if (j == rec.size()) rec.push_back({i, layer});
            }
            if (rec.size() == layer + 1) {
                bt(n, res, rec, layer + 1);
                rec.pop_back();
            }
        }
    }
};

int main() {
    int n = 4;
    // long start = GetTickCount();
    cout << Solution().totalNQueens(n) << endl;
    // cout << GetTickCount() - start << endl;
    return 0;
}