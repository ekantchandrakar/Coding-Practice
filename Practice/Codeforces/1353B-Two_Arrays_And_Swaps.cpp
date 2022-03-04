/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());

	for(int i = 0; i < k; i++){
		if(b[i] > a[i]){
			swap(a[i], b[i]);
		}
	}
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += a[i];
	}
	cout << sum << endl;
}

int main() {
	fast_io;
	
	int t = 1; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
