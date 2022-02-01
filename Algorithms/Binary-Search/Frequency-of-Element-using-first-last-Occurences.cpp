/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int firstOccurence(vector<int> &arr, int key){
	int start = 0;
	int end = arr.size() - 1;
	int ans = -1;
	while(start <= end){
		int mid = start + (end - start) / 2;
		if(arr[mid] == key){
			ans = mid; // Everytime update the ans
			end = mid - 1; // Try to search in the left of mid
		} else if(key < arr[mid]){
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}

	return ans;
}

int lastOccurence(vector<int>& arr, int key){
	int start = 0;
	int end = arr.size() - 1;
	int ans = -1;

	while(start <= end){
		int mid = start + (end - start) / 2;
		if(arr[mid] == key){
			ans = mid;
			start = mid + 1;
		} else if(key < arr[mid]){
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}

	return ans;
}

void solve(){
	vector<int> arr = {0, 1, 1, 3, 3, 3, 3, 3, 3, 4, 5, 5, 5, 6};
	int n = arr.size();
	int firstOcc = firstOccurence(arr, 3);
	int lastOcc = lastOccurence(arr, 3);
	int frequency = lastOcc - firstOcc + 1;
	cout << frequency << endl;
}

int main() {
	fast_io;
	
	int t = 1; // cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
