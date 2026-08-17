/*
Problem

There is fence which consists of  wooden blocks with each block having a number written on it represented by an array . The painter is also given two numbers  and  . He is given the task to paint the fence using at most  colors. But there are certain conditions which the painter must follow while painting:
    He has to paint the fence in sequential manner from left to right i.e, first paint the first block then second block and so on without leaving any block not being painted. 
    He will also use colors in sequential manner i.e, first paint with 1st color,then with 2nd color and so on. Note that he can paint any number of blocks sequentially with a single color and a color once used cannot be reused.
    The sum of numbers written on blocks painted with same color must lie between  and  ( both inclusive ).
*/

#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> &boards, int painters, int mid){
    int p = 1, time = 0;
    int n = boards.size();

    for(int i = 0;i < n;i++){
        if(time + boards[i] <= mid){
            time += boards[i];
        } else{
            p++;
            time = boards[i];
        }
    }

    if(painters >= p) return true;
    return false;
}

int minimizedMaxTime(vector<int> &boards, int painters){
    int minVal = INT_MIN, maxVal = 0;

    int n = boards.size();
    for(int i = 0;i < n;i++){
        if(boards[i] > minVal) minVal = boards[i];

        maxVal += boards[i];
    }

    int left = minVal, right = maxVal;
    int ans = 0;

    while(left <= right){
        int mid = left + (right - left) / 2;

        if(isPossible(boards, painters, mid)){
            ans = mid;
            right = mid - 1;
        } else{
            left = mid + 1;
        }
    }
    return ans;
}

int main(){
    int painters;
    cout<<"Enter the no. of painters: ";
    cin>>painters;

    int n;
    cout<<"Enter the no. of boards: ";
    cin>>n;

    vector<int> boards(n);
    for(int i = 0;i < n;i++){
        cin>>boards[i];
    }

    cout<<"Min time: "<<minimizedMaxTime(boards, painters);
}