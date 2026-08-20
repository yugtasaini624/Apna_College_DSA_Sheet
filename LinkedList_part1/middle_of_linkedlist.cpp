/*
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

Constraints:
    The number of nodes in the list is in the range [1, 100].
    1 <= Node.val <= 100
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
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        if(head->next->next == nullptr) return head->next;

        ListNode *ptr = head;
        int totalNodes = 0;

        while(ptr != nullptr){
            totalNodes++;
            ptr = ptr->next;
        }

        ptr = head;
        totalNodes /= 2;

        int curr = 0;

        while(curr != totalNodes){
            curr++;
            ptr = ptr->next;
        }

        return ptr;
    }
};

int main(){
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);

    Solution obj;

    ListNode* middle = obj.middleNode(head);

    cout<<"Middle node: "<<middle->val<<endl;

    return 0;
    
}