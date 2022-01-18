/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void multiply(vector<int> &a, int no, int &size){
	int carry = 0;
	for(int i = 0; i < size; i++){
		int product = a[i] * no + carry;
		a[i] = product % 10;
		carry = product / 10;
	}	

	// To handle the carry
	while(carry){
		a[size] = carry % 10;
		carry = carry / 10;
		size = size + 1;
	}
}

void bigFactorial(int n){
	vector<int> a(1000, 0); // to store the the result we get on each multiplication
	a[0] = 1; // for 1!
	int size = 1; // size of the output generated so far

	for(int i = 2; i <= n; i++){
		multiply(a, i, size);
	}

	// Print the result in reverse order i.e. size - 1 to 0
	for(int i = size - 1; i >= 0; i--){
		cout << a[i];
	}
	cout << endl;
}

void solve(){
	int n;
	cin >> n;

	bigFactorial(n);
}

int main() {
	fast_io;
	
	int t = 1; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
