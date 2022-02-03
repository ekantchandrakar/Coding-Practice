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

void quickSort(vector<int>& arr, int start, int end){
	// Base Case
	if(start >= end){
		return;
	}
	// Recursive Case
	int p = partition(arr, start, end);
	quickSort(arr, start, p - 1);
	quickSort(arr, p + 1, end);
}

void solve(){
	vector<int> arr = {10, 5, 2, 0, 7, 8, 6, 4, 9, 3, 1};
	int n = arr.size();

	quickSort(arr, 0, n - 1);

	for(int x: arr){
		cout << x << " ";
	}
}

int main() {
	fast_io;
	
	int t = 1; // cin >> t;
	while(t--){
		solve();
	}

	return 0;
}

/*

Time Complexity O(nlogn) in average cases. In worst cases O(n^2)

auxiliary space: only for recusive calls

stable: The default implementation is not stable. 

Inplace: Yes

*/