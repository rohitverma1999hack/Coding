#include<bits/stdc++.h>
using namespace std;

unordered_map<string,int> mp;

int isPrt(string s,int i,int j,bool isTrue){
	if(i>j) return false;
	if(i==j){
		if(isTrue == true){
			return s[i] == 'T';
		}else{
			return s[i] == 'F';
		}
	}	
	int ans = 0;
	string key = to_string(i);
	key.push_back('_');
	key.append(to_string(j));
	key.push_back('_');
	key.append(to_string(isTrue));
	
	if(mp.find(key) != mp.end()) return mp[key];

	for(int k=i+1;k<j;k+=2){
		int lt = isPrt(s,i,k-1,true);
		int lf = isPrt(s,i,k-1,false);
		int rt = isPrt(s,k+1,j,true);
		int rf = isPrt(s,k+1,j,false);

		if(s[k] == '&'){
			if(isTrue == true){
				ans+= (lt * rt);
			}else{
				ans += (lt*rf) + (lf * rt) + (lf*rf); 
			}	
		}

		if(s[k] == '|'){
			if(isTrue == true){
				ans += (lt*rt) + (lt * rf) + (lf*rt);
			}else{
				ans += (lf*rf);
			}
		}

		if(s[k] == '^'){
			if(isTrue == true){
				ans+= (lt*rf) + (lf*rt);
			}else{
				ans += (lt*rt) + (lf*rf);
			}

		}
	}
	return mp[key]=ans;
}

int main(){
	string s= "T|T&F^T";
	int n = s.size() - 1;
	cout<<isPrt(s,0,n,true)<<endl;

}
