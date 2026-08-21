/*
Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]

Constraints:
    The number of nodes in the list is in the range [0, 500].
    -100 <= Node.val <= 100
    0 <= k <= 2 * 109
*/

#include<iostream>
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
    ListNode* rotateRight(ListNode* head, int k) {
       if(head == NULL || head->next == NULL || k == 0){
            return head;
       } 

       ListNode *ptr = head;
       int count = 0;

       while(ptr != NULL){
        count++;
        ptr = ptr->next;
       }

       k = k % count;

       if(k == 0){
        return head;
       }

       int currCount = 1;
       ptr = head;

       while(currCount != count - k){
        currCount++;
        ptr = ptr->next;
       }
    
       ListNode *newStart = (ptr->next != NULL) ? ptr->next : NULL;
       ListNode *tail = (ptr->next != NULL) ? ptr->next : NULL;
       ptr->next = NULL;

       while(tail->next != NULL){
        tail = tail->next;
       }

       tail->next = head;
       head = newStart;

       return head;

    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    Solution obj;

    head = obj.rotateRight(head, k);

    // Print result
    ListNode* curr = head;

    while (curr != nullptr) {
        cout << curr->val;

        if (curr->next != nullptr)
            cout << " -> ";

        curr = curr->next;
    }

    cout << endl;

    return 0;
}