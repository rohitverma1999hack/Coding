#include<bits/stdc++.h>
using namespace std;

int NOW(string s,int i,int j,bool isTrue){
	if(i>j) return 0;
	if(i==j){
		if(isTrue == true) return s[i] == 'T';
		else return s[i] == 'F';
	}
	int ans = 0;	
	for(int k=i+1;k<j;k=k+2){

		int lt = NOW(s,i,k-1,true);
		int lf = NOW(s,i,k-1,false);
		int rt = NOW(s,k+1,j,true);
		int rf = NOW(s,k+1,j,false);

		if(s[k] == '&'){
			if(isTrue == true) ans+= (lt * rt);
			else ans += (lt*rf) + (lf *rf) + (lf*rt);
		}

		if(s[k] == '|'){
			if(isTrue == true) ans += (lt*rt) + (lf*rt) + (lt*rf);
			else ans += lf*rf;
		}

		if(s[k] == '^'){
			if(isTrue == true) ans += (lt*rf) + (lf*rt);
			else ans += (lt*rt) + (lf*rf);
		}
	}
	return ans;
}

int main(){
	string s="T|T&F^T";
	int n = s.size() - 1;
	cout<<NOW(s,0,n,true)<<endl;
}
