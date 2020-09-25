#include<bits/stdc++.h>
using namespace std;

unordered_map<string,int> mp;

bool isPalindrome(string s,int i,int j){
	while(i < j){
	       if(s[i] != s[j]) return false;
               else i++;j--;	       
	}
        return true;	
}

int Prt(string s,int i,int j){
	if(i >= j) return 0;
	
	string key=to_string(i);
	key.push_back('_');
	key.append(to_string(j));
	
	if(mp.find(key) != mp.end()) return mp[key];

	if(isPalindrome(s,i,j) == true) return 0;
	
	int mn=INT_MAX;
	
	for(int k=i;k<j;k++){
		int left,right;

		string keyl=to_string(i);
                keyl.push_back('_');
                keyl.append(to_string(k));

		string keyr=to_string(k+1);
                keyr.push_back('_');
                keyr.append(to_string(j));

		if(mp.find(keyl) != mp.end()) left = mp[keyl];
		else left = Prt(s,i,k) ; mp[keyl] = left;
		if(mp.find(keyr) != mp.end()) right = mp[keyr];
		else right = Prt(s,k+1,j) ; mp[keyr] = right;

		int temp = left + right + 1;
		mn = min(mn,temp);
	}
	return mp[key]=mn;
}
int main(){
	string s="abcddabc";
	int n = s.size() - 1;
	cout<<Prt(s,0,n)<<endl;
}
