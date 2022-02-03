/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int partition(vector<int>& arr, int start, int end){
	int pivot = arr[end];
	int i = start - 1;

	for(int j = start; j <= end; j++){
		if(arr[j] < pivot){
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[end]);
	return i + 1;
}

int quickSelect(vector<int>& arr, int start, int end, int k){
	
	// assuming that k will be inside the array k <= n
	int p = partition(arr, start, end);
	if(p == k){
		return arr[p]; // kth smallest element
	} else if(k < p){
		return quickSelect(arr, start, p - 1, k); // go for the left half
	} else {
		return quickSelect(arr, p + 1, end, k);
	} 
}

void solve(){
	vector<int> arr = {10, 5, 2, 0, 7, 6, 4};
	int n = arr.size();
	int k;
	cin >> k;
	cout << quickSelect(arr, 0, n - 1, k) << endl;
}

int main() {
	fast_io;
	
	int t = 1; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}

