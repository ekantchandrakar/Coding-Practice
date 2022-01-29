/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;
// Return {x, y};
vector<int> extendedGCD(int a, int b){
	if(b == 0){
		// return the values of x, y
		return {1, 0}; // always true (ax + 0y = gcd(a, 0));	
	}
	vector<int> result = extendedGCD(b, a % b);

	// after the recursive call is over
	// bottom up way of solution building
	// doing the work after the function call has been made
	int smallX = result[0];
	int smallY = result[1];

	int x = smallY;
	int y = smallX - (a / b) * smallY;

	return {x, y};
}

void solve(){
	int a, b;
	cin >> a >> b;
	// we need to find the values of x and y such that 
	// ax + by = gcd(a, b);
	vector<int> result = extendedGCD(a, b);
	// x = result[0], y = result[1];
	cout << result[0] << " and " << result[1] << endl;
}

int main() {
	fast_io;
	
	int t = 1; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
