/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void nToOne(int n){
	if(n == 0){
		return;
	}
	// execute in calling phase i.e. while going towards the base case
	cout << n << " "; 
	nToOne(n - 1);
}

void oneToN(int n){

	if(n == 0){
		return;
	}

	oneToN(n - 1);
	cout << n << " "; // execute in Returning phase i.e. while coming back from base case
}

void solve(){
	int n;
	cin >> n;
	oneToN(n);
	cout << endl;
	nToOne(n);
}

int main() {
	fast_io;
	
	int t = 1; // cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
