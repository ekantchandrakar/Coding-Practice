/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

vector<vector<int>> binomialCofficient(int n, int k){
	vector<vector<int>> table(n + 1, vector<int>(k + 1, 0));
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= min(i, k); j++){

			// base case
			if(j == 0 || j == i){
				table[i][j] = 1;
			} else {
				table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
			}
		}	
	}

	return table;	
}

void solve(){
	int n;
	cin >> n;
	vector<vector<int>> table = binomialCofficient(n, n);
	int queries = 6;
	while(queries--){
		int k;
		cin >> k;
		if(k <= n)
			cout << table[n][k] << endl;
	}
}

int main() {
	fast_io;
	
	int t = 1; // cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
