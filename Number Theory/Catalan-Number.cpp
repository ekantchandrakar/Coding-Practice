/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

// Recursive --- exponential 
int countBST(int n){
	if(n == 0 || n == 1){
		return 1;
	}	

	int ans = 0;
	for(int i = 1; i <= n; i++){
		int left = countBST(i - 1);
		int right = countBST(n - i);
		ans += left*right;
	}

	return ans;
}

// Memoization (top - down) -- iterate over n states and in each state we doing O(n) work 
// so O(n^2)
int countBSTTopDown(int n, int dp[]){
	if(n == 0 || n == 1){
		return 1;
	}	

	if(dp[n] != 0){
		return dp[n];
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		int left = countBSTTopDown(i - 1, dp);
		int right = countBSTTopDown(n - i, dp);
		ans += left*right;
	}

	return dp[n] = ans;
}

int countBSTBottomUp(int N){
	std::vector<int> dp(N + 1, 0);
	dp[0] = dp[1] = 1;

	for(int n = 2; n <= N; n++){
		for(int i = 1; i <= n; i++){ // for the root node
			dp[n] += (dp[i - 1] * dp[n - i]);		
		}	
	} 

	return dp[N];
}

void solve(){
	int n = 5;
	cout << countBST(n) << endl;

	int dp[n + 1] = {0};
	cout << countBSTTopDown(n, dp) << endl;

	cout << countBSTBottomUp(n) << endl;
}

int main() {
	fast_io;
	
	int t = 1; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
