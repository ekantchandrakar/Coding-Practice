/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define int long long 
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int32_t main() {
	fast_io;
	
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	int maxChoco = 0;
	int curr = 1e18;
	for(int i = n - 1; i >= 0; i--){
		curr = min(curr - 1, arr[i]);
		curr = max(0LL, curr);
		maxChoco += curr;
	}

	cout << maxChoco;

	return 0;
}
