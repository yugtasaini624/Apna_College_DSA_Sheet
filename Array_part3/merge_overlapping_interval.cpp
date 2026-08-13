/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

Example 3:
Input: intervals = [[4,7],[1,4]]
Output: [[1,7]]
Explanation: Intervals [1,4] and [4,7] are considered overlapping.

Constraints:
    1 <= intervals.length <= 104
    intervals[i].length == 2
    0 <= starti <= endi <= 104
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int> > mergeIntervals(vector<vector<int> > &arr){
    int n = arr.size();

    vector<vector<int> > res;

    for(int i = 0;i < n;i++){
        if(res.empty() || res.back()[1] < arr[i][0]){
            vector<int> vec(2);
            vec[0] = arr[i][0];
            vec[1] = arr[i][1];
            res.push_back(vec);
        } else{
            res.back()[1] = max(res.back()[1], arr[i][1]);
        }
    }

    return res;
}

int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;

    vector<vector<int> > arr(n, vector<int>(2));

    for(int i = 0;i < n;i++){
        for(int j =0;j < 2;j++){
            cin>>arr[i][j];
        }
    }

    vector<vector<int> > res = mergeIntervals(arr);

    for(int i = 0;i < res.size();i++){
        for(int j = 0;j < 2;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}