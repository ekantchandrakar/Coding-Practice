/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

// Helper Function
int merge(vector<int>& arr, int start, int end){
	int i = start;
	int mid = start + (end - start) / 2;
	int j = mid + 1;
	vector<int> temp;

	int count = 0;
	while(i <= mid && j <= end){
		if(arr[i] < arr[j]){
			temp.push_back(arr[i]);
			i++;	
		} else {
			count += (mid - i + 1); // inversion count 
			temp.push_back(arr[j]);
			j++;
		}		
	}

	while(i <= mid){
		temp.push_back(arr[i]);
		i++;
	}

	while(j <= end){
		temp.push_back(arr[j]);
		j++;
	}

	// copy back the element from temp to original array so that our mergeSort will see the actual changes
	int k = 0;
	for(int idx = start; idx <= end; idx++){
		arr[idx] = temp[k++];	
	}
	return count;
}

// Sorting Method
int inversion_count(vector<int>& arr, int start, int end){
	// base case
	if(start >= end){
		return 0;
	}

	// Recursive case
	int mid = start + (end - start) / 2;
	int c1 = inversion_count(arr, start, mid); // on left part of array
	int c2 = inversion_count(arr, mid + 1, end); // on the right part of array
	int CI = merge(arr, start, end);

	return c1 + c2 + CI;
}

void solve(){
	vector<int> arr = {0, 5, 2, 3, 1};
	int start = 0;
	int end = arr.size() - 1;
	cout << inversion_count(arr, start, end) << endl;
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
Time Complexity: O(nlog(n)) in all 3 cases (worst, average, best) as merge sort always 
divides the array into two halves and take linear time to merge two halves.

Auxiliary Space: O(n)
Algorithmic Paradigm: Divide and Comquer
Sorting In Place: No... in a typical implimentation
Stable: Yes
*/