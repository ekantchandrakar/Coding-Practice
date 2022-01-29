/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int factorial(int n){
	// Base case
	if(n == 0){
		return 1;
	}

	// recursive case
	int ans = n * factorial(n - 1);
	return ans;
}

void solve(){
	int n;
	cin >> n;
	cout << factorial(n) << endl;
}

int main() {
	fast_io;
	
	int t = 1; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
