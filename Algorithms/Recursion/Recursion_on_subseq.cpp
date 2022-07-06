/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void printSubsequence(int index, vector<int>& ds, int arr[], int n){
	if(index >= n){
		for(auto &it: ds){
			cout << it << " ";
		}
		if(ds.size() == 0){
			cout << "{}" << " ";
		}
		cout << endl;
		return;
	}

	// Pick the perticular index into subsequence
	ds.push_back(arr[index]);
	printSubsequence(index + 1, ds, arr, n);

	// Not pick condition. This index will not bw part of subsequences  What are LTS versions of Node.js 
	ds.pop_back();
	printSubsequence(index + 1, ds, arr, n);
}

void solve(){
	int n = 3;
	int arr[n] = {3, 1, 2};
	vector<int> ds;
	printSubsequence(0, ds, arr, n);
}

int main() {
	fast_io;
	
	int t = 1; // cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
