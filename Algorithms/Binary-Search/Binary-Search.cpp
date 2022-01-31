/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int binarySearch(vector<int>& arr, int key){
	int start = 0;
	int end = arr.size() - 1;
	while(start <= end){
		int mid = start + (end - start) / 2;
		if(arr[mid] == key){
			return mid;
		} else if(key < arr[mid]){
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}

	return -1;
}

int binarySearchRecursive(vector<int>& arr, int key, int start, int end){
	if(start <= end){
		int mid = start + (end - start) / 2;
		if(arr[mid] == key){
			return mid;
		} else if(key < arr[mid]){
			return binarySearchRecursive(arr, key, start, mid - 1);
		} else {
			return binarySearchRecursive(arr, key, start + 1, end);
		}
	}
	return -1;
}

void solve(){
	vector<int> arr = {0, 1, 2, 3, 4, 5, 6};
	int key;
	cin >> key;
	cout << binarySearch(arr, key) << endl;
	cout << binarySearchRecursive(arr, key, 0, arr.size() - 1) << endl;
}

int main() {
	fast_io;
	
	int t = 1; // cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
