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
	int x = 0;
	while(n--){
		string op;
		cin >> op;
		if(op == "X++" || op == "++X"){
			x++;
		} else if(op == "--X" || op == "X--"){
			x--;
		}
	}

	cout << x << endl;
}

int main() {
	fast_io;
	
	int t = 1; // cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
