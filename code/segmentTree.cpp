#include <bits/stdc++.h> 

void build(int ind,vector<int> &arr, vector<int> &seg,
int low,int high){
    if(low==high){
        seg[ind] = arr[low];
        return;
    }

    int mid = (low+high)/2;
    build(2*ind+1,arr,seg,low,mid);
    build(2*ind+2,arr,seg,mid+1,high);

    seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
}

int que(int ind,vector<int> &seg, int low,int high,
int l, int r){
    if(low>=l && high<=r){
        return seg[ind];
    }
    if(high<l || low>r){
        return INT_MAX;
    }

    int mid = (low+high)/2;

    int left = que(2*ind+1,seg,low,mid,l,r);
    int right= que(2*ind+2,seg,mid+1,high,l,r);
    return min(left,right);
}
vector<int> rangeMinimumQuery(int n, vector<int> arr, int q, vector<vector<int>> query) {
    // Write your code here.
    vector<int> seg(4*n,0);
    build(0,arr,seg,0,n-1);
    vector<int> ans;

    for(auto it: query){
        int l=it[0];
        int r=it[1];

        int x = que(0,seg,0,n-1,l,r);
        ans.push_back(x);
    }

    return ans;
}

