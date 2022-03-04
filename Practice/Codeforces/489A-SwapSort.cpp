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

	vector<pair<int, int>> res;
	int count = 0;

	for(int i = 0; i < n; i++){
		int j = i;

		for(int t = i; t < n; t++){
			if(arr[j] > arr[t]){
				j = t;
			}
		}

		if(i != j){
			res.push_back(make_pair(i, j));
			count++;
		}

		swap(arr[i], arr[j]);
	}

	cout << count << endl;
	for(int i = 0; i < res.size(); i++){
		cout << res[i].first << " " << res[i].second << endl;
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
