#include<iostream>
#include<windows.h>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>


using namespace std;

// // 回溯超时
// class Solution {
// private:
//     unordered_map<string, vector<int>> m;
//     vector<bool> visited;
//     int res = INT_MAX;
//     string target;
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         // 防止环
//         // 构建字典
//         for (int i = 0; i < wordList.size(); ++i) {
//             string each = wordList[i];
//             int l = each.size();
//             for (int j = 0; j < l; ++j) {
//                 string key = each.substr(0, j) + "-" + each.substr(j + 1, l - j - 1);
//                 if (m.find(key) == m.end()) {
//                     vector<int> v = {i};
//                     m[key] = v;
//                 } else {
//                     m[key].push_back(i);
//                 }
//             }
//         }
//         // 回溯
//         // visited = vector<bool>(true, wordList.size());
//         visited = vector<bool>(wordList.size(), true);
//         string w = beginWord;
//         target = endWord;
//         bt(w, wordList, 1);
//         return res == INT_MAX ? 0 : res;
//     }

//     void bt(string w, vector<string>& wordList, int count) {
//         if (w == target && count < res) {
//             res = count;
//             return;
//         }
//         for (int i = 0; i < w.size(); ++i) {
//             string temp = w.substr(0, i) + "-" + w.substr(i + 1, w.size() - i - 1);
//             if (m.find(temp) != m.end()) {
//                 for (const auto& index : m[temp]) {
//                     if (!visited[index]) continue;
//                     visited[index] = false;
//                     bt(wordList[index], wordList, count + 1);
//                     visited[index] = true;
//                 }
//             }
//         }
//     }
// };

class Solution {
private:
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 防止环
        unordered_map<string, vector<int>> m;
        string target;
        // 构建字典
        for (int i = 0; i < wordList.size(); ++i) {
            string each = wordList[i];
            int l = each.size();
            for (int j = 0; j < l; ++j) {
                string key = each.substr(0, j) + "-" + each.substr(j + 1, l - j - 1);
                if (m.find(key) == m.end()) {
                    vector<int> v = {i};
                    m[key] = v;
                } else {
                    m[key].push_back(i);
                }
            }
        }
        string w = beginWord;
        target = endWord;
        unordered_map<string, int> um;
        for(const auto& word : wordList)
            um[word] = -1;
        um[w] = 1;
        if(um.find(target) == um.end()) return 0;
        queue<string> q;
        q.push(w);
        while(!q.empty()) {
            string word = q.front();
            for(int i = 0; i < word.size(); ++i) {
                string temp = word.substr(0, i) + "-" + word.substr(i + 1, word.size() - i - 1);
                if(m.find(temp) != m.end()) {
                    for (const auto& index : m[temp]) {
                        if(um[wordList[index]] != -1) {
                            um[wordList[index]] = min(um[wordList[index]], um[word] + 1);
                        } else {
                            q.push(wordList[index]);
                            um[wordList[index]] = um[word] + 1;
                            if(wordList[index] == target) return um[target];
                        }
                    }
                }
            }
            q.pop();
        }
        return 0;
    }
};

// // 最快实现
// class Solution {
// public:
// 	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
// 		unordered_set<string> word_set(wordList.begin(), wordList.end());
// 		if (!word_set.count(endWord))
// 			return 0;
// 		queue<string> q{ {beginWord} };
// 		int res = 0;
// 		while (!q.empty()) {
// 			for (int k = q.size(); k > 0; --k) {
// 				string word = q.front();
// 				q.pop();
// 				if (word == endWord) {
// 					return res + 1;
// 				}
// 				for (int i = 0; i < word.size(); i++) {
// 					string new_word = word;
// 					for (char ch = 'a'; ch <= 'z'; ch++) {
// 						new_word[i] = ch;
// 						if (word_set.count(new_word) && new_word!= word) {
// 							q.push(new_word);
// 							word_set.erase(new_word);
// 						}
// 					}
// 				}
// 			}
// 			++res;
// 		}
// 		return 0;
// 	}
// };

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    // string beginWord = "qa";
    // string endWord = "sq";
    // vector<string> wordList = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
    // long start = GetTickCount();
    cout << Solution().ladderLength(beginWord, endWord, wordList);
    // cout << GetTickCount() - start << endl;
    return 0;
}