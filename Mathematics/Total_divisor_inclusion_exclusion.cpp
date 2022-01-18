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

	// if we take other than primes then we have t divide them 
	// using the gcd but for prime just multiply them and than divide
	std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	int m = primes.size();

	// to make all types of set (generate alll sets of these prime numbers)
	int ans = 0;
	for(int i = 1; i < (1 << m); i++){
		int lcm = 1;
		for(int j = 0; j < m; j++){
			// if jth bit of ith element is set then include it
			if((i >> j) & 1){
				// cout << primes[j] << " ";
				lcm *= primes[j];	
			}	
		}
		// __builtin_popcount(i) tells the total no of set bit in i
		if(__builtin_popcount(i) % 2 == 0){
			ans -= (n / lcm);
		} else {
			ans += (n / lcm);
		}
	}
	cout << ans << endl;
}	


int main() {
	fast_io;
	
	int t = 1; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
