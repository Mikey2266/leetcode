#include<iostream>
#include<windows.h>
#include<vector>


using namespace std;

// 最快实现, 二次编码
class Solution
{
private:
	int hash[26];
	int count;
public:
	void _sort(char s, string& _hash) {
		if (hash[s - 'a'] == 0) {
			count += 1;
			hash[s - 'a'] = count;
		}
		_hash += hash[s - 'a'] + '0';
	}

	vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
		vector<string> ans;
		int len_p = pattern.length(), len_w = words.size();
		string hash_sp = "", hash_sw = "";
		memset(hash, 0, sizeof(hash));
		count = 0;
		for (int i = 0; i < len_p; ++i) {
			_sort(pattern[i], hash_sp);
		}
		for (int i = 0; i < len_w; ++i) {
			if (words[i].size() != len_p) continue;
			memset(hash, 0, sizeof(hash));
			count = 0;
			hash_sw = "";
			for (int j = 0; j < words[i].size(); ++j) _sort(words[i][j], hash_sw);
			if (hash_sp == hash_sw) ans.push_back(words[i]);
		}
		return ans;
	}
};

int main() {
    string pattern = "abb";
    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    // long start = GetTickCount();
    vector<string> res = Solution().findAndReplacePattern(words, pattern);
    // cout << GetTickCount() - start << endl;
    return 0;
}