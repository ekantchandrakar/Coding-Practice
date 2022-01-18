/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define N 1000000
using namespace std;

void primeSieve(vector<int> &sieve){
	// 1 means prime, 0 means not prime
	// mark 1 and 0 as not prime
	sieve[0] = sieve[1] = 0;

	// Start from 2 and mark all multiples of ith number (prime) as not prime
	for(ll i = 2; i <= N; i++){
		if(sieve[i] == 1){ // only then mark multiple of this number i as not prime
			for(ll j = i * i; j <= N; j = j + i){ // i* i is part of optimization. we can also start from 2 * i
				sieve[j] = 0; // marking j as not prime		
			}	
		}
	}
}

void solve(){
	vector<int> sieve(N, 1);
	primeSieve(sieve);

	std::vector<int> csum(N, 0);
	for(int i = 0; i <= N; i++){
		if(sieve[i] == 1){
			csum[i] = csum[i - 1] + 1;
		}
	}

	for(int i = 0; i <= 100; i++){
		cout << csum[i] << " ";
	}
	/*
	int q;
	cin >> q;

	for(int i = 1; i <= q; i++){
		int a, b;
		cin >> a >> b;
		cout << csum[b] - csum[a - 1] << endl;
	}
	*/ 
}

int main() {
	fast_io;
	
	int t = 1; // cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
