/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

const int N = 1e5;

void calculate_totient(){ // O(nloglog(n) + O(nloglog(n)))
	vector<bool> primes(N, true);
	vector<int> totient(N);
	for(ll i = 2; i < N; i++){
		for(ll j = i*i; j < N; j = j + i){
			primes[j] = false;	
		}
	}

	iota(totient.begin(), totient.end(), 0); // totient[i] = i
	
	for(int i = 2; i < N; i++){
		if(primes[i] == true){
			// iterate over all multiples of i (prime number)	
			for(int j = i; j < N; j += i){
				// j is divisible by i
				// i is prime number

				totient[j] /= i;
				totient[j] *= (i - 1);
			}
		}	
	}

	for (int i = 1; i <= 10; ++i){
		cout << i << " " << totient[i] << endl;
	}
}

void solve(){
	calculate_totient();
}

int main() {
	fast_io;
	
	int t = 1; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
