/*
Reverse first K of a Queue
Difficulty: EasyAccuracy: 81.28%Submissions: 197K+Points: 2

Given an integer k and a queue of integers, we need to reverse the order of the first k elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

    enqueue(x) : Add an item x to rear of queue
    dequeue() : Remove an item from front of queue
    size() : Returns number of elements in queue.
    front() : Finds front item.

Note: 

    The above operations represent the general processings.
    In-built functions of the respective languages can be used to solve the problem.
    If the size of queue is smaller than the given k , then return the original queue.

Examples:

Input: q = [1, 2, 3, 4, 5], k = 3
Output: [3, 2, 1, 4, 5]
Explanation: After reversing the first 3 elements from the given queue the resultant queue will be [3, 2, 1, 4, 5]

Input: q = [4, 3, 2, 1], k = 4
Output: [1, 2, 3, 4] 
Explanation: After reversing the first 4 elements from the given queue the resultant queue will be [1, 2, 3, 4] 

Constraints:
1 ≤ q.size(), q[i], k ≤ 105

*/

#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        int n = q.size();
        
        if(k > q.size()) return q;
        
        stack<int> st;
        
        for(int i = 0;i < k;i++){
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
        for(int i = 0;i < n - k;i++){
            q.push(q.front());
            q.pop();
        }
        
        return q;
    }
};

int main(){
    Solution s;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;
    q = s.reverseFirstK(q,k);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    
    return 0;
}
