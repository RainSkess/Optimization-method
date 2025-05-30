/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //某些情况不用翻转
        if (k == 1 || head->next == nullptr) return head;
        
        //计算有多少个节点
        int n = 0;//n个节点
        ListNode* begin = head;
        while (begin)
        {
            ++n;
            begin = begin->next;
        }

        //循环m次，每次进行长度为k的逆序
        ListNode* guard = new ListNode(0);
        ListNode* tmp = guard;//作为返回的节点
        ListNode* cur = head;
        ListNode* tail = guard;
        int m = n / k;//循环m次
        for (int i = 0; i < m; ++i)
        {
            tail = cur;
            for (int j = 0; j < k; ++j)
            {
                ListNode* next = cur->next;
                cur->next = tmp->next;
                tmp->next = cur;
                cur = next;
            }
            //需要找到尾节点作为起始位置
            tmp = tail;
        } 

        //不需要逆序的节点尾插
        tail->next = cur;
        //进行释放指针
        tmp = guard->next;
        delete guard;
        return tmp;
    }
};