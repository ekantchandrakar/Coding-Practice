/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int searchInRotatedSortedArray(vector<int>& nums, int target){
	int start = 0;
	int end = nums.size() - 1;

	// Binary Search
	while(start <= end){
		int mid = start + (end - start) / 2;
		if(nums[mid] == target){
			return mid;
		} else if(nums[start] <= nums[mid]){ // left part of mid is sorted
			if(nums[start] <= target && target <= nums[mid]){
				end = mid - 1;
			} else {
				start = mid + 1;
			}
		} else if(nums[mid] <= nums[end]) {
			if(nums[mid] <= target && target <= nums[end]){
				start = mid + 1;
			} else {
				end = mid - 1;
			}
		}
	}

	return -1;
}

void solve(){
	vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
	int target;
	cin >> target;
	cout << searchInRotatedSortedArray(nums, target) << endl;
}

int main() {
	fast_io;
	
	int t = 1; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
