/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	string s;
	cin >> s;
	int maxiii = arr[0];
	for(int i = 0; i < n - 1; i++){
		maxiii = max(maxiii, arr[i]);

		if(s[i] == '0' && maxiii > i + 1){
			cout << "NO";
			return;	
		} 
	}
	cout << "YES";
}

int main() {
	fast_io;
	
	int t = 1; // cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
