/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

// Euclid's Algorithm to compute GCD
int gcd(int a, int b){
	if(b == 0){
		return a;
	}
	return gcd(b, a % b);
}

// Extended Euclid Algorithm for ax + by = gcd(a, b) => Return {x, y};
// modification done to return gcd also 
vector<int> extendedGCD(int a, int b){
	if(b == 0){
		// return the values of x, y
		return {1, 0, a}; // always true (ax + 0y = gcd(a, 0));	
	}
	vector<int> result = extendedGCD(b, a % b);

	// after the recursive call is over
	// bottom up way of solution building
	// doing the work after the function call has been made
	int smallX = result[0];
	int smallY = result[1];
	int gcd = result[2];

	int x = smallY;
	int y = smallX - (a / b) * smallY;

	return {x, y, gcd};
}

// Code for MMI

int multiplicativeModInverse(int a, int m){
	vector<int> result = extendedGCD(a, m);
	int x = result[0];
	int gcd = result[2];

	if(gcd != 1){
		cout << "Multiplicative Modulo Inverse Not Exist";
		return -1;
	}

	int ans = (x % m + m) % m; // x can be negative also so and to be lie in the correct range (x % m + m) % m

	return ans; 
}

void solve(){
	int a, m;
	cin >> a >> m; // relatively prime

	cout << multiplicativeModInverse(a, m) << endl;

	/*
	int a, b;
	cin >> a >> b;
	// we need to find the values of x and y such that 
	// ax + by = gcd(a, b);
	vector<int> result = extendedGCD(a, b);
	// x = result[0], y = result[1];
	cout << result[0] << " and " << result[1] << " gcd " << result[2] << endl;
	cout << "From Euclid Algorithm " << gcd(a, b) << endl;
	*/
}

int main() {
	fast_io;
	
	int t = 1; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
