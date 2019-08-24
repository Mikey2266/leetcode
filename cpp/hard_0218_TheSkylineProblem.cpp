#include<iostream>
#include<vector>
#include<windows.h>
#include<set>
#include<algorithm>

using namespace std;

// // 超时
// class Solution {
// public:
//     vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
//         if (!buildings.size() || !buildings[0].size()) return {};
//         unordered_map<int, int> dict = {{buildings[0][2], buildings[0][1] - buildings[0][0]}};
//         vector<vector<int>> res = {{buildings[0][0], buildings[0][2]}};
//         int maxLen = INT_MIN;
//         for (auto each : buildings)
//             if (each[1] > maxLen) maxLen = each[1];
//         int index = 1;
//         for (int i = buildings[0][0] + 1; i <= maxLen; ++i) {
//             if (index >= buildings.size() || i < buildings[index][0]) {
//                 for (auto it = dict.begin(); it != dict.end();) {
//                     it->second -= 1;
//                     if (!it->second) {
//                         it = dict.erase(it);
//                         if (dict.empty()) res.push_back({i, 0});
//                         else {
//                             int maxTemp = INT_MIN;
//                             for (const auto& n : dict)
//                                 if (maxTemp < n.first) maxTemp = n.first;
//                             if (res.back()[1] != maxTemp) res.push_back({i, maxTemp});                            
//                         }
//                     }
//                     else ++it;
//                 }
//             }
//             else {
//                 if (dict.find(buildings[index][2]) == dict.end()) {
//                     for (auto it = dict.begin(); it != dict.end();) {
//                         it->second -= 1;
//                         if (!it->second) {
//                             it = dict.erase(it);
//                             if (dict.empty()) res.push_back({i, 0});
//                         }
//                         else ++it;
//                     }
//                     int maxTemp = INT_MIN;
//                     for (const auto& n : dict)
//                         if (maxTemp < n.first) maxTemp = n.first;                    
//                     dict[buildings[index][2]] = buildings[index][1] - buildings[index][0];
//                     if (buildings[index][2] > maxTemp && res.back()[1] != buildings[index][2]) res.push_back({i, buildings[index][2]}); 
//                 }
//                 else dict[buildings[index][2]] = max(dict[buildings[index][2]], buildings[index][1] - buildings[index][0]);
//                 index++;
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> h, res;
        multiset<int> m;
        int pre = 0, cur = 0;
        for (auto &a : buildings) {
            h.push_back({a[0], -a[2]});
            h.push_back({a[1], a[2]});
        }
        sort(h.begin(), h.end());
        m.insert(0);
        for (auto &a : h) {
            if (a[1] < 0) 
                m.insert(-a[1]);
            else 
                m.erase(m.find(a[1]));
            cur = *m.rbegin();
            if (cur != pre) {
                res.push_back({a[0], cur});
                pre = cur;
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    // long start = GetTickCount();
    vector<vector<int>> res = Solution().getSkyline(buildings);
    // long end = GetTickCount();
    // cout << end - start << endl;
    return 0;
}