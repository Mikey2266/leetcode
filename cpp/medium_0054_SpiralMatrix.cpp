#include<iostream>
#include<vector>
#include<windows.h>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> vec;
        if (matrix.size() == 0) {
            return vec;
        }
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        int x = 0;
        int y = 0;
        int up = -1;
        int down = matrix.size();
        int left = -1;
        int right = matrix[0].size();
        bool flag = false;
        int count = 0;
        
        while (true) {
            if (flag == true) {
                flag = false;
                up++;
                left++;
                down--;
                right--;
                if (up >= down || left >= right) {
                    return vec;
                }
                x = count;
                y = count;
                if (x > right || y > down) {
                    return vec;
                }
            }
            // 向右
            while (x < right && !visited[y][x]) {
                visited[y][x] = true;
                vec.push_back(matrix[y][x++]);
            }
            x--;
            y++;
            // 向下
            while (y < down && !visited[y][x]) {
                visited[y][x] = true;
                vec.push_back(matrix[y++][x]);
            }
            y--;
            x--;
            // 向左
            while (x > left && !visited[y][x]) {
                visited[y][x] = true;
                vec.push_back(matrix[y][x--]);
            }
            x++;
            y--;
            // 向上
            while (y > up && !visited[y][x]) {
                visited[y][x] = true;
                vec.push_back(matrix[y--][x]);
            }
            flag = true;
            count++;            
        }
        return vec;
    }
};

int main() {
    // vector<int> nums1 = {1, 2, 3, 4, 5};
    // vector<int> nums2 = {6, 7, 8, 9, 10};
    // vector<int> nums3 = {11, 12, 13, 14, 15};
    vector<vector<int>> matrix;
    // matrix.push_back(nums1);
    // matrix.push_back(nums2);
    // matrix.push_back(nums3);
    // long start = GetTickCount();
    Solution().spiralOrder(matrix);
    // long end = GetTickCount();
    cout << endl;
    // cout << end - start << endl;
    return 0;
}