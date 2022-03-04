/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void solve(){
	int n;
	string s;
	cin >> n >> s;

	int i = 0, j = n - 1, op = 0;
	vector<int> vis(n, 0);
	while(i <= j){
		if(s[i] != s[j]){
			if(!vis[j] && i != j - 1 && s[i] == s[j - 1]){
				vis[i] = vis[j - 1] = 1;
				swap(s[j], s[j - 1]);
				op++;	
			} else if(!vis[i] && i + 1 != j && s[i + 1] == s[j]){
				vis[j] = vis[i + 1] = 1;
				swap(s[i], s[i + 1]);
				op++;
			} else{
				cout << "NO\n";
				return;
			}
		}
		i++;
		j--;
	}

	cout << "YES\n" << op;
	cout << endl;
}

int main() {
	fast_io;
	
	int t = 1; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
