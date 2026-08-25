/*
Sort a stack
Difficulty: MediumAccuracy: 69.19%Submissions: 188K+Points: 4Average Time: 20m

Given a stack of integers st[]. Sort the stack in ascending order (smallest element at the bottom and largest at the top).

Examples:

Input: st[] = [41, 3, 32, 2, 11]
Output: [41, 32, 11, 3, 2]
Explanation: After sorting, the smallest element (2) is at the bottom and the largest element (41) is at the top.

Input: st[] = [3, 2, 1]
Output: [3, 2, 1]
Explanation: The stack is already sorted in ascending order.

Constraints:
1 ≤ st.size() ≤ 103
0 ≤ stack element ≤ 103 
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
  public:
    void sortStack(stack<int> &st) {
        int n = st.size();
        
        vector<int> arr;
        while(!st.empty()){
            arr.push_back(st.top());
            st.pop();
        }
        
        sort(arr.begin(), arr.end());
        int i = 0;
        while(i < arr.size()){
            st.push(arr[i]);
            i++;
        }
    }
};

int main() {

    Solution obj;

    stack<int> st;

    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    obj.sortStack(st);

    cout<<"Sorted stack: ";

    while (!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}