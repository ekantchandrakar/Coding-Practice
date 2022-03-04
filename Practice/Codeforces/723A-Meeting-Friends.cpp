/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void solve(){
	int n = 3;
	vector<int> cord(n);
	for(int i = 0; i < n; i++){
		cin >> cord[i];
	}
	sort(cord.begin(), cord.end());
	int minDist = (cord[1] - cord[0]) + (cord[2] - cord[1]);
	cout << minDist;
}

int main() {
	fast_io;
	
	int t = 1; // cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
