#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > v;

bool isPalindrome(string s,int i,int j){
	while(i < j){
		if(s[i] != s[j]) return false;
		else i++;j--;
	}
	return true;
}

int Prt(string s,int i,int j){
	if(i >= j) return 0;
	if(v[i][j] != -1) return v[i][j];
	if(isPalindrome(s,i,j) == true) return 0;
	int mn = INT_MAX;
	
	for(int k=i;k<j;k++){
		int left,right;
		
		if(v[i][k] != -1)  left =  v[i][k];
		else left = Prt(s,i,k); v[i][k] = left;
		if(v[k+1][j] != -1) right = v[k+1][j];
		else right = Prt(s,k+1,j) ; v[k+1][j] = right;

		int temp = left + right + 1;
		mn = min(mn,temp);
	}
	
	return v[i][j] = mn;
}

int main(){
	string s="hit";
	int j=s.size() - 1;
	v.resize(j+1,vector<int>(j+1,-1));
	cout<<Prt(s,0,j)<<endl;

}
