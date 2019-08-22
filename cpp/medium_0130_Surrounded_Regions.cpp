#include<iostream>
#include<vector>
#include<algorithm>
#include<windows.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    void solve(vector<vector<char>>& board) {
        if (!board.size() || !board[0].size()) return;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < 1; ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'O') dfs(board, i, j, visited);
            }
        }
        for (int i = board.size() - 1; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'O') dfs(board, i, j, visited);
            }
        }
        for (int j = 0; j < 1; ++j) {
            for (int i = 0; i < board.size(); ++i) {
                if (board[i][j] == 'O') dfs(board, i, j, visited);
            }
        }
        for (int j = board[0].size() - 1; j < board[0].size(); ++j) {
            for (int i = 0; i < board.size(); ++i) {
                if (board[i][j] == 'O') dfs(board, i, j, visited);
            }
        }
        for (int i = 1; i < board.size() - 1; ++i) {
            for (int j = 1; j < board[0].size(); ++j) {
                if (!visited[i][j]) {
                    if (board[i][j]== 'O') board[i][j] = 'X';
                }
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited) {
        if (visited[i][j]) return;
        visited[i][j] = true;
        int m = board.size(), n = board[0].size();
        for (auto a : dirs) {
            int x = i + a[0], y = j + a[1];
            if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] == 'X') continue;
            dfs(board, x, y, visited);
        }
    }
};

int main() {
    vector<char> nums1 = {'X', 'X', 'X', 'X'};
    vector<char> nums2 = {'X', 'O', 'O', 'X'};
    vector<char> nums3 = {'X', 'X', 'O', 'X'};
    vector<char> nums4 = {'X', 'O', 'X', 'X'};
    vector<vector<char>> board;
    board.push_back(nums1);
    board.push_back(nums2);
    board.push_back(nums3);
    board.push_back(nums4);
    // long start = GetTickCount();
    Solution().solve(board);
    // long end = GetTickCount();
    // cout << end - start << endl;
    return 0;
}