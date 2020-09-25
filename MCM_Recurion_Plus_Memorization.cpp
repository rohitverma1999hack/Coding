#include<bits/stdc++.h>
using namespace std;

static vector<vector<int> > v;

int solve(int arr[],int i,int j){
	if(i >= j) return 0;
	if(v[i][j] != -1) return v[i][j];
	int mn = INT_MAX;
	for(int k=i;k<j;k++){
		int temp = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1] * arr[k] * arr[j];
		mn = min(mn,temp);
	}
	return v[i][j] = mn;
}

int main(){
	int n=4;
	int arr[] = {40,20,30,10};
	int i=1;
	int j=n-1;
	v.resize(n+1,vector<int>(n+1,-1));
	cout<<solve(arr,i,j)<<endl;
}

