#include<iostream>
#include<windows.h>
#include<vector>
#include<math.h>

using namespace std;

// https://www.jianshu.com/p/439fcf968854
// 最快实现
class Solution {
public:
    // 注意该层的转换方式
    int trans(int layer, int label) {
        int s = 1 << (layer - 1);
        int e = (1 << layer) - 1;
        return s + e - label;
    }
    
    vector<int> pathInZigZagTree(int label) {
        int layer = log(label) / log(2) + 1;
        vector<int> ans(layer, 1);
        while(layer > 1) {
            ans[layer - 1] = label;                                    
            if(layer %2 == 0) {
                label = trans(layer, label) /2;
            }
            else {
                label = trans(layer - 1, label / 2);
            }
           layer--;
        }
        return ans;
    }
};

int main() {
    int label = 10;
    // long start = GetTickCount();
    vector<int> res = Solution().pathInZigZagTree(label);
    cout << endl;
    // cout << GetTickCount() - start << endl;
    return 0;
}