/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

// Brute force approach O(n)=> worst case if the n is prime no.
void factorise(int n){
	for(int i = 2; i <= n; i++){
		if(n % i == 0){
			int count = 0;
			while(n % i == 0){
				count++;
				n = n / i;
			}

			cout << i << "^" << count << ",";
		}
	}	
}

// Optimized Approach O(sqrt(N))
// Observation: Once N is reduced to a prime number, the only factor
// that will be the number itself.

// If a number doesn't have any factor till sqrt(n)
// then it is a prime number.

// O(sqrt(N))
void factoriseOpt(int n){
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			int count = 0;
			while(n % i == 0){
				count++;
				n = n / i;
			}

			cout << i << "^" << count << ",";
		}
	}	

	if(n != 1){ // n will reduced to the prime no.
		cout << n << "^" << 1 << endl;	
	} 
}


void solve(){
	int n;
	cin >> n;
	factoriseOpt(n);
}

int main() {
	fast_io;
	
	int t = 1; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
