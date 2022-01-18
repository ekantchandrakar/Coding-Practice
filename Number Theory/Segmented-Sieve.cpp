/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define N 100000
using namespace std;

vector<int> primeSieve(vector<int> &sieve){
	// 1 means prime, 0 means not prime
	// mark 1 and 0 as not prime
	vector<int> primes;
	sieve[0] = sieve[1] = 0;

	// Start from 2 and mark all multiples of ith number (prime) as not prime
	for(ll i = 2; i <= N; i++){
		if(sieve[i] == 1){ // only then mark multiple of this number i as not prime
			primes.push_back(i);
			for(ll j = i * i; j <= N; j = j + i){ // i* i is part of optimization. we can also start from 2 * i
				sieve[j] = 0; // marking j as not prime		
			}	
		}
	}
}

int main() {
	fast_io;
	vector<int> sieve(N, 1);
	// Precompute
	vector<int> primes = primeSieve(sieve);

	int t;
	cin >> t;
	while(t--){
		int m, n;
		cin >> m >> n;

		vector<int> segment(n - m + 1, 1); 

		for(auto p: primes){
			// stop when p^2 > n in the segment
			if(p * p > n){
				break;
			}

			// otherwise we need to find the nearest starting point
			int start = (m / p) * p;
			
			//special case
			if(p >= m and p <= n){
				start = 2 * p;		
			}

			// start marking the numbers as not prime from start
			// if the start is out of the range jump to next position
			for(int j = start; j <= n; j = j + p){
				if(j < m){ // (98 < 99)
					continue;
				}	
				// marked as not prime
				segment[j - m] = 0;
			}
		}

		// primes stored as 1 in the segment;
		for(int i = m; i <= n; i++){
			if(segment[i - m] == 1 and i != 1){
				cout << i << endl;
			}	
		}
		cout << endl;
	}

	return 0;
}
