/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:

Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]

 

Constraints:

    The number of nodes in the list is n.
    1 <= n <= 500
    -500 <= Node.val <= 500
    1 <= left <= right <= n

 
Follow up: Could you do it in one pass?
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverse(ListNode *head){
        if(head == nullptr || head->next == nullptr) return head;

        ListNode *ptr = head;
        ListNode *curr = head->next;
        ListNode *temp = nullptr;

        while(curr != nullptr){
            temp = curr->next;
            curr->next = ptr;
            ptr = curr;
            curr = temp;
        }

        return ptr;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || head->next == nullptr || left == right) return head;

        ListNode *ptr = head;

        ListNode *startNode = nullptr;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        ListNode *lastNode = nullptr;

        int count = 1;

        while(count != left){
            count++;
            prev = ptr;
            ptr = ptr->next;
        }

        startNode = ptr;

        ListNode *tail = startNode;

        while(count != right){
            count++;
            ptr = ptr->next;
        }

        lastNode = ptr;

        next = lastNode->next;

        lastNode->next = nullptr;

        startNode = reverse(startNode);

        if(prev){ 
            prev->next = startNode;
        } 
        else{
            head = startNode;
        }

        tail->next = next;

        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;

    int left = 2;
    int right = 4;

    head = obj.reverseBetween(head, left, right);

    ListNode* curr = head;

    while(curr != nullptr) {
        cout<<curr->val;

        if(curr->next != nullptr)
            cout<<" -> ";

        curr = curr->next;
    }

    return 0;
}