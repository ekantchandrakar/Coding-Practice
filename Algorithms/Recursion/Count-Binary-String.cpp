/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int countBinaryString(int n){
	if(n == 0 || n == 1){
		return n + 1;
	}
	int startingWithZero = countBinaryString(n - 1);
	int startingWithOne = countBinaryString(n - 2);

	return startingWithZero + startingWithOne;
}

void solve(){
	int n;
	cin >> n;
	cout << countBinaryString(n) << endl;
}

int main() {
	fast_io;
	
	int t = 1; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
