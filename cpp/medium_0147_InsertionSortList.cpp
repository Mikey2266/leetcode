#include<iostream>
#include<windows.h>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// class Solution {
// public:
//     ListNode* insertionSortList(ListNode* head) {
//         if (!head) return NULL;
//         vector<ListNode*> vec;
//         while (head) {
//             vec.push_back(head);
//             head = head->next;
//         }
//         for (int i = 1; i < vec.size(); ++i) {
//             // 二分查找
//             int left = 0;
//             int right = i - 1;
//             while (left <= right) {
//                 int mid = left + (right - left) / 2;
//                 if (vec[mid]->val > vec[i]->val) right = mid - 1;
//                 else left = mid + 1;
//             }
//             int index = left;
//             // 插入
//             ListNode* temp = vec[i];
//             for (int j = i; j > index; --j) {
//                 vec[j] = vec[j - 1];
//             }
//             vec[index] = temp;
//         }
//         for (int i = 0; i < vec.size() - 1; ++i) {
//             vec[i]->next = vec[i + 1];
//         }
//         vec[vec.size() - 1]->next = NULL;
//         return vec[0];
//     }
// };

// 最快实现
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        ListNode *pre;
        dummy->next = head;
        while(head != NULL && head->next != NULL) {
            if(head->val <= head->next->val) {
                head = head->next;
                continue;
            }
            pre = dummy;
            while(pre->next->val < head->next->val)
                pre = pre->next;
            ListNode* curr = head->next;
            head->next = curr->next;
            curr->next = pre->next;
            pre->next = curr;
        }
        return dummy->next;
    }
};

int main() {
    vector<int> vec = {-1, 5, 3, 4, 0};
    ListNode* head = new ListNode(vec[0]);
    ListNode* link = head;
    for (int i = 1; i < vec.size(); ++i) {
        link->next = new ListNode(vec[i]);
        link = link->next;
    }
    // long start = GetTickCount();
    ListNode* res = Solution().insertionSortList(head);
    // long end = GetTickCount();
    // cout << end - start << endl;
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}