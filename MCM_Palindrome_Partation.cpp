#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s,int i,int j){
	while(i < j){
		if(s[i] != s[j]) return false;
		else i++;j--;
	}
	return true;
}

int Min_Partation(string s,int i,int j){
	if(i >= j) return 0;
	if(isPalindrome(s,i,j) == true) return 0;
	int mn = INT_MAX;
	for(int k=i;k<j;k++){
		int temp = 1 + Min_Partation(s,i,k) + Min_Partation(s,k+1,j);
		mn = min(mn,temp);
	}
	return mn;

}

int main(){
	string s = "hit";
	int j=s.size() - 1;
	cout<<Min_Partation(s,0,j)<<endl;
}
