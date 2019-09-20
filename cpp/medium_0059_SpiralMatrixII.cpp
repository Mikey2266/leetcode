#include<iostream>
#include<vector>
#include<windows.h>
#include<math.h>

using namespace std;

// class Solution {
// public:
//     vector<vector<int>> generateMatrix(int n) {
//         vector<vector<int>> res(n, vector<int>(n, 0));
//         int id = 1;
//         int x = 0;
//         int y = 0;
//         int layer = ceil(n / float(2));
//         for (int i = 0; i < layer; ++i) {
//             while (x < res[0].size() && res[y][x] == 0) {
//                 res[y][x] = id;
//                 id++;
//                 x++;
//             }
//             x--;
//             y++;
//             while (y < res.size() && res[y][x] == 0) {
//                 res[y][x] = id;
//                 id++;
//                 y++;
//             }
//             y--;
//             x--;
//             while (x >= 0 && res[y][x] == 0) {
//                 res[y][x] = id;
//                 id++;
//                 x--;
//             }
//             x++;
//             y--;
//             while (y >= 0 && res[y][x] == 0) {
//                 res[y][x] = id;
//                 id++;
//                 y--;
//             }
//             y++;
//             x++;
//         }
//         return res;
//     }
// };

// 最快实现
class Solution {
public:
    vector<vector<int>> v;
    vector<vector<bool>> flag;
    int east[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int south[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    int west[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int north[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<int>> generateMatrix(int n) {
        v = vector<vector<int>>(n, vector<int>(n));
        flag = vector<vector<bool>>(n, vector<bool>(n, true));
        int num = 1;
        DFS(0, 0, num, 0);
        return v;
    }
    void DFS(int r, int c, int &num, int drct) {
        flag[r][c] = false;
        v[r][c] = num++;
        for (int i = 0; i < 4; ++i) {
            int x;
            int y;
            if (drct == 0) {
                x = r + east[i][0];
                y = c + east[i][1];
            }
            else if (drct == 1) {
                x = r + south[i][0];
                y = c + south[i][1];
            }
            else if (drct == 2) {
                x = r + west[i][0];
                y = c + west[i][1];
            }
            else {
                x = r + north[i][0];
                y = c + north[i][1];
            }
            if (x >= 0 && x < v.size() && y >= 0 && y < v.size() && flag[x][y])
                DFS(x, y, num, (drct + i) % 4);
        }
    }
};

int main() {
    int input = 3;
    // long start = GetTickCount();
    vector<vector<int>> vec = Solution().generateMatrix(input);
    // long end = GetTickCount();
    cout << endl;
    // cout << end - start << endl;
    return 0;
}