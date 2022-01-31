/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void findSubsets(char *input, char *output, int i, int j){
	// base case
	if(input[i] == '\0'){
		output[j] = '\0';
		cout << output << endl;
		return;
	}

	// recursive case
	// Include the ith letter
	output[j] = input[i];
	findSubsets(input, output, i + 1, j + 1);
	
	// Exclude the ith letter
	// Overwriting
	findSubsets(input, output, i + 1, j);
}

void solve(){
	char input[100];
	char output[100];
	
	cin >> input;

	findSubsets(input, output, 0, 0);
}

int main() {
	fast_io;
	
	int t = 1; // cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
