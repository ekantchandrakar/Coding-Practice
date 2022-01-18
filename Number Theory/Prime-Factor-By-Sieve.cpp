/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define N 1000000
using namespace std;

void primeSieve(vector<int> &sieveArr){
	for(int i = 1; i <= N; i++){
		sieveArr[i] = i;
	}

	// Start from 2 to N
	for(ll i = 2; i <= N; i++){
		// Whether a number is prime  
		if(sieveArr[i] = i){
			for(ll j = i * i; j <= N; j = j + i){
				// mark them if they already not marked by the i;
				if(sieveArr[j] == j){
					sieveArr[j] = i;
				}
			}
		}
	}
}

vector<int> getFactors(int number, vector<int> &sieveArr){
	vector<int> factors;
	while(number != 1){
		factors.push_back(sieveArr[number]);
		number = number / sieveArr[number];
	}
	return factors;
}

void solve(){
	// Prime Sieve (Nloglog(N))
	vector<int> sieveArr(N + 1, 0);
	primeSieve(sieveArr);

	int number;
	cin >> number;

	// Method for multiple queries O(log(n))
	vector<int> factors = getFactors(number, sieveArr);
	for(int f: factors){
		cout << f << " ";
	}
	cout << "\n";
}

int main() {
	fast_io;
	
	int t = 1; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
