/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int findMinCoins(int demon[], int size, int rupees){
	sort(demon, demon + size);

	int count = 0;

	vector<int> changes;

	for(int i = size - 1; i >= 0; i--){
		while(rupees >= demon[i]){
			rupees -= demon[i];
			count++;
			changes.push_back(demon[i]);
		}
	}

	for(auto x: changes){
		cout << x << " ";
	}
	cout << endl;
	return count;
}

void solve(){
	int demon[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	int size = sizeof(demon) / sizeof(int);

	int rupees;
	cin >> rupees;

	cout << findMinCoins(demon, size, rupees) << endl;
}

int main() {
	fast_io;
	
	int t = 1; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}

// T.C. O(rupees)
// S.C. O(rupees)
