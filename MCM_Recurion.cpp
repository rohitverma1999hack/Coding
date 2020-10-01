/*
 * Finding the minimum cost of multiplying the the given matrix
 * */
#include<bits/stdc++.h>
using namespace std;

int MCM(int arr[],int i,int j){
	//Base Condition
	if(i >= j) return 0;

	int mn=INT_MAX;
	
	//Hypothesis
	for(int k=i;k<j;k++){
		int temp = MCM(arr,i,k) + MCM(arr,k+1,j) + arr[i-1] * arr[k] * arr[j];
		mn=min(mn,temp);
	}
	return mn;

}

int main(){
	int n=5;
	int arr[] = {40,20,30,10,30};
	int i=1;
	int j=n-1;
	cout<<MCM(arr,i,j)<<endl;
}
