/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int tiling(int n){
	if(n <= 3){
		return 1;
	}

	int ans = tiling(n - 1) + tiling(n - 4);
	return ans;
}

void solve(){
	int n;
	cin >> n;
	cout << tiling(n) << endl;
}

int main() {
	fast_io;
	
	int t = 1; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
