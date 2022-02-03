/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

// Helper Function
void merge(vector<int>& arr, int start, int end){
	int i = start;
	int mid = start + (end - start) / 2;
	int j = mid + 1;
	vector<int> temp;

	while(i <= mid && j <= end){
		if(arr[i] < arr[j]){
			temp.push_back(arr[i]);
			i++;	
		} else {
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
	return;
}

// Sorting Method
void mergeSort(vector<int>& arr, int start, int end){
	// base case
	if(start >= end){
		return;
	}

	// Recursive case
	int mid = start + (end - start) / 2;
	mergeSort(arr, start, mid); // on left part of array
	mergeSort(arr, mid + 1, end); // on the right part of array
	return merge(arr, start, end);
}

void solve(){
	vector<int> arr = {10, 5, 2, 0, 7, 6, 4};
	int start = 0;
	int end = arr.size() - 1;
	mergeSort(arr, start, end);
	for(auto &x: arr){
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
Time Complexity: O(nlog(n)) in all 3 cases (worst, average, best) as merge sort always 
divides the array into two halves and take linear time to merge two halves.

Auxiliary Space: O(n)
Algorithmic Paradigm: Divide and Comquer
Sorting In Place: No... in a typical implimentation
Stable: Yes
*/