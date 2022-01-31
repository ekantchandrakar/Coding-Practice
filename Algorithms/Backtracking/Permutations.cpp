/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void generatePermutation(string &s, int index){
	if(index == s.length()){
		cout << s << endl;
		return;
	}

	for(int i = index; i < s.length(); i++){
		swap(s[index], s[i]);
		generatePermutation(s, index + 1);
		swap(s[index], s[i]);
	}
}

void solve(){
	string s;
	cin >> s;
	generatePermutation(s, 0);
}

int main() {
	fast_io;
	
	int t = 1; // cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
