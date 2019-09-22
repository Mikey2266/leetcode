#include<iostream>
#include<vector>
#include<windows.h>
#include<math.h>
#include<algorithm>

using namespace std;

// class Solution {
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         sort(candidates.begin(), candidates.end());
//         vector<vector<int>> res;
//         vector<int> temp;
//         int index = 0;
//         int s = 0;
//         backTrack(candidates, target, 0, res, temp);
//         return res;
//     }

//     void backTrack(vector<int>& candidates, int target, int index, vector<vector<int>>& res, vector<int>& temp) {
//         for (int i = index; i < candidates.size(); ++i) {
//             if (target > 0) {
//                 temp.push_back(candidates[i]);
//                 backTrack(candidates, target - candidates[i], i, res, temp);
//                 temp.pop_back();
//             }
//             else if (target < 0) return;
//             else {
//                 res.push_back(temp);
//                 return;
//             }
//         }
//     }
// };

// 最快实现
class Solution {
private:
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;
public:
    void DFS(int start, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for(int i = start; i < candidates.size() && target - candidates[i] >= 0; ++i){
            path.push_back(candidates[i]);
            DFS(i, target - candidates[i]);
            path.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        DFS(0, target);
        return res;
    }   
};

int main() {
    vector<int> candidates = {2, 3, 5};
    int target = 8;
    // long start = GetTickCount();
    vector<vector<int>> vec = Solution().combinationSum(candidates, target);
    // long end = GetTickCount();
    cout << endl;
    // cout << end - start << endl;
    return 0;
}

