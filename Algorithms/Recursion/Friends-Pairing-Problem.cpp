/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int friendsPairing(int n){
	if(n == 0 || n == 1){
		return 1;
	}

	int alone = 1 * friendsPairing(n - 1);
	int pair = (n - 1) * friendsPairing(n - 2);

	return alone + pair;
}

void solve(){
	int n;
	cin >> n;
	cout << friendsPairing(n) << endl;
}

int main() {
	fast_io;
	
	int t = 1; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
