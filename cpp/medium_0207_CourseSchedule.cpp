#include<iostream>
#include<vector>
#include<windows.h>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> m;
        vector<int> vec(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); ++i) {
            for (int j = 1; j < prerequisites[i].size(); ++j) {
                auto p = m.find(prerequisites[i][0]);
                if (p == m.end()) {
                    vector<int> vec(1, prerequisites[i][j]);
                    m.insert(make_pair(prerequisites[i][0], vec));
                }
                else {
                    p->second.push_back(prerequisites[i][j]);
                }
            }
            ++vec[prerequisites[i][0]];
        }
        
        vector<int> res;
        for (int i = 0; i < numCourses; ++i) {
             for (int j = 0; j < numCourses; ++j) {
                 if (vec[j] == 0) {
                     res.push_back(j);
                     vec[j] = -1;
                     for (int k = 0; m.find(j) != m.end() && k < m.find(j)->second.size(); ++k) {
                         --vec[m.find(j)->second[k]];
                     }
                 }
             }
        }
        return res.size() == numCourses;
    }
};

int main() {
    // vector<int> nums1 = {2, 0};
    // vector<int> nums2 = {1, 0};
    // vector<int> nums3 = {3, 1};
    // vector<int> nums4 = {3, 2};
    // vector<int> nums5 = {1, 3};

    // vector<int> nums1 = {0, 1};
    // vector<int> nums2 = {2, 3};
    // vector<int> nums3 = {1, 2};
    // vector<int> nums4 = {3, 0};

    // vector<int> nums1 = {1, 0};
    // vector<int> nums2 = {0, 2};
    // vector<int> nums3 = {2, 1};

    // vector<int> nums1 = {0, 1};
    // vector<int> nums2 = {1, 3};
    // vector<int> nums3 = {3, 1};
    // vector<int> nums4 = {3, 2};

    // vector<int> nums1 = {1, 0};
    // vector<int> nums2 = {2, 1};

    // vector<int> nums1 = {0, 1};
    // vector<int> nums2 = {0, 2};
    // vector<int> nums3 = {1, 2};

    vector<int> nums1 = {1, 0};   

    vector<vector<int>> prerequisites;
    prerequisites.push_back(nums1);
    // prerequisites.push_back(nums2);
    // prerequisites.push_back(nums3);
    // prerequisites.push_back(nums4);
    // prerequisites.push_back(nums5);
    int numCourses = 2;
    // long start = GetTickCount();
    cout << Solution().canFinish(numCourses, prerequisites);
    // long end = GetTickCount();
    cout << endl;
    // cout << end - start << endl;
    return 0;
}