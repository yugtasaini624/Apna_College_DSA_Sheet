/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:
Input: heights = [2,4]
Output: 4

Constraints:
    1 <= heights.length <= 105
    0 <= heights[i] <= 104
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int> &arr){
    int n = arr.size();

    vector<int> left(n, 0);
    vector<int> right(n , 0);

    stack<int> st;

    for(int i = n - 1;i >= 0;i--){
        while(st.size() > 0 && arr[st.top()] >= arr[i]){
            st.pop();
        }

        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    while(!st.empty()){
        st.pop();
    }

    for(int i = 0;i < n;i++){
        while(st.size() > 0 && arr[st.top()] >= arr[i]){
            st.pop();
        }

        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    int maxArea = 0;

    for(int i = 0;i < n;i++){
        int width = right[i] - left[i] - 1;
        int currArea = arr[i] * width;

        maxArea = max(maxArea, currArea);
    }

    return maxArea;
}

int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;

    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }

    cout<<"Max area = "<<largestRectangleArea(arr);
}