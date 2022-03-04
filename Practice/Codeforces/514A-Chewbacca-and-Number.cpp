/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

char invert(char c, int isFirst){
	char trans;
	int dig = c - '0';
	if(isFirst && dig == 9){
		trans = c;
	} else{
		if(9 - dig < dig){
			trans = (char)(9 - dig + '0');
		} else {
			trans = c;
		}
	}

	return trans;
}

void solve(){
	string s;
	cin >> s;
	for(int i = 0; i < s.length(); i++){
		if(i == 0){
			s[i] = invert(s[i], 1);
		} else {
			s[i] = invert(s[i], 0);
		}
	}

	cout << s;
}

int main() {
	fast_io;
	
	int t = 1; // cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
