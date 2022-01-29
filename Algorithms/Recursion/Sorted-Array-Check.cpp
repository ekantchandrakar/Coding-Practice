/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

bool isSorted(int arr[], int n){
	// base case
	if(n == 0 || n == 1){
		return true;
	}	
	// recursive case
	if(arr[0] < arr[1] && isSorted(arr + 1, n - 1)){
		return true;	
	}
	return false;
}

bool isSortedUsingIndex(int arr[], int i, int n){
	if(i == n - 1){
		return true;
	}
	if(arr[i] < arr[i + 1] && isSortedUsingIndex(arr, i + 1, n)){
		return true;
	}
	return false;
}

void solve(){
	int arr[] = {1, 2, 3, 4, 15, 7};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << isSorted(arr, n) << endl;
	cout << isSortedUsingIndex(arr, 0, n) << endl;
}

int main() {
	fast_io;
	
	int t = 1; // cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
