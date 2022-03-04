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

	if( n == 2){
		cout << -1 << endl;
		return;
	} else if(n % 2 == 1){
		for(int i = 1; i <= n; i++){
			cout << i << " ";
		}
		cout <<endl;
		return;
	} else if(n % 2 == 0){
		cout << 2 << " " << 3 << " " << 1 << " ";
		for(int i = 4; i <= n; i++){
			cout << i << " ";
		}
		cout << endl;
		return;
	}
}

int main() {
	fast_io;
	
	int t = 1; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
