/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

bool canPlaceBirds(int B, int N, vector<int>& nests, int separation){
	
	int birds = 1;
	int location = nests[0];

	for(int i = 1; i <= N - 1; i++){
		int current_location = nests[i];
		if(current_location - location >= separation){
			birds++;
			location = current_location;
			if(birds == B){
				return true;
			}
		}	
	}	
	return false;
}

void solve(){
	int B = 3;
	vector<int> nests = {1, 2, 4, 8, 9};
	// Sorting
	sort(nests.begin(), nests.end());
	int N = nests.size();

	// Binary Search
	int start = 0;
	int end = nests[N - 1] - nests[0];
	int ans = -1;

	while(start <= end){
		int mid = start + (end - start) / 2;

		bool canPlace = canPlaceBirds(B, N, nests, mid);
		if(canPlace) { // search on right to maximize the distance i.e. ans
			ans = mid;
			start = mid + 1; 
		} else { // otherwise search on the left 
			end = mid - 1;
		}
	}

	cout << ans << endl;
}

int main() {
	fast_io;
	
	int t = 1; // cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
