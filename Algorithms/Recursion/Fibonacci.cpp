/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

// T.C. O(2^N); S.C. O(N)
int fibonacci(int n){
	if(n == 0 || n == 1){
		return n;
	}
	// int ans = fibonacci(n - 1) + fibonacci(n - 2);
	// return ans;
	int f1 = fibonacci(n - 1);
	int f2 = fibonacci(n - 2);

	return f1 + f2;
}

void solve(){
	int n;
	cin >> n;
	cout << fibonacci(n) << endl;	 
}

int main() {
	fast_io;
	
	int t = 1; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
