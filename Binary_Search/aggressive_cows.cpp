/*
Farmer John has built a new long barn, with N (2 ≤ N ≤ 100,000) stalls. The stalls are located along a straight line at positions x1 ... xN (0 ≤ xi ≤ 1,000,000,000).
His C (2 ≤ C ≤ N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows.
    Line 1: Two space-separated integers: N and C
    Lines 2..N+1: Line i+1 contains an integer stall location, xi

Output
For each test case output one integer: the largest minimum distance.
Example
Input:
1
5 3
1
2
8
4
9

Output:
3

Explanation

FJ can put his 3 cows in the stalls at positions 1, 4 and 8, resulting in a minimum distance of 3.
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool isPossible(vector<int> &arr, int n, int c, int minAllowDist){
    int cows = 1, lastStall = arr[0];

    for(int i = 1;i < n;i++){
        if(arr[i] - lastStall >= minAllowDist){
            cows++;
            lastStall = arr[i];
        }

        if(cows == c){
            return true;
        }
    }

    return false;
}

int getDistance(vector<int> &arr, int n, int c){
    sort(arr.begin(), arr.end());

    int left = 0, right = arr[n - 1] - arr[0];
    int ans = -1;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if(isPossible(arr, n, c, mid)){
            ans = max(ans, mid);
            left = mid - 1;
        } else{
            right = mid - 1;
        }
    }

    return ans;
}

int main(){
    int n, c;
    cout<<"Enter the no of stalls and cows: ";
    cin>>n>>c;
    vector<int> arr(n);
    
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }

    cout<<getDistance(arr, n, c);
    return 0;
}