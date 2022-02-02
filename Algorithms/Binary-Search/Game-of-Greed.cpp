/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

bool divideAmongK(vector<int>& coins, int n, int k, int min_coins){
	int partitions = 0;
	int current_friend = 0;

	for(int i = 0; i < n; i++){
		if(current_friend + coins[i] >= min_coins){
			partitions++;
			current_friend = 0;
		} else {
			current_friend += coins[i];
		}
	}

	return partitions >= k;
}

int k_Partition(vector<int> &coins, int n, int k){
	// Binary Search
	int start = 0; // we can also do like int start = *min_element(coins.begin(), coins.end());
	int end = accumulate(coins.begin(), coins.end(), 0);
	int ans = -1;
	while(start <= end){
		int mid = start + (end - start) / 2;
		bool isPossible = divideAmongK(coins, n, k, mid); // such that everyone gets atleast mid no of coins

		if(isPossible){
			ans = mid;
			start = mid + 1; // to maximise the ans 
		} else {
			end = mid - 1; 
		}
	}

	return ans;
}

void solve(){

	vector<int> coins = {10, 20, 50, 40};
	int n = coins.size();
	int k = 3; // we need to do 3 partition
	cout << k_Partition(coins, n, k) << endl; // maximum amount from the minimum partition
}

int main() {
	fast_io;
	
	int t = 1; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
