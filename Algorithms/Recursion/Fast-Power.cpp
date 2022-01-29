/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

// T. C. O(n), S.C. O(n)
int power(int a, int n){
	// base case
	if(n == 0){
		return 1;
	}

	return a * power(a, n - 1);
}

// T.C. O(log(n)); S.C. O(log(n))
int fastPower(int a, int n){
	if(n == 0){
		return 1;	
	}

	int subProblem = fastPower(a, n / 2);
	int subProblemSq = subProblem * subProblem;

	if(n & 1){
		return a * subProblemSq;	
	}
	return subProblemSq;
}

void solve(){
	int a, n;
	cin >> a >> n;
	cout << power(a, n) << endl;
	cout << fastPower(a, n) << endl;
}

int main() {
	fast_io;
	
	int t = 1; // cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
