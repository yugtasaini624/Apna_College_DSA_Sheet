/*
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]

Constraints:
    The number of nodes in both lists is in the range [0, 50].
    -100 <= Node.val <= 100
    Both list1 and list2 are sorted in non-decreasing order.
*/

#include<iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr) return nullptr;

        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;

        while(list1 && list2){
            if(list1->val < list2->val){
                tail->next = new ListNode(list1->val);
                tail = tail->next;
                list1 = list1->next;
            } else{
                tail->next = new ListNode(list2->val);
                tail = tail->next;
                list2 = list2->next;
            }
        }

        while(list1){
            tail->next = new ListNode(list1->val);;
            tail = tail->next;
            list1 = list1->next;
        }

        while(list2){
            tail->next = new ListNode(list2->val);;
            tail = tail->next;
            list2 = list2->next;
        }   

        return dummy->next;
    }
};

int main(){
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);

    ListNode* h1 = new ListNode(10);
    h1->next = new ListNode(20);
    h1->next->next = new ListNode(30);
    h1->next->next->next = new ListNode(40);
    h1->next->next->next->next = new ListNode(50);

    Solution obj;

    head = obj.mergeTwoLists(head, h1);
    ListNode *ptr = head;
    while(ptr != nullptr){
        cout<<ptr->val<<" -> ";
        ptr =  ptr->next;
    }
    cout<<"end"<<endl;
    return 0;
}