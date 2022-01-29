/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void solve(){
	float prob_same_bday;
	cin >> prob_same_bday;
	int people = 1;
	float num = 365;
	float demon = 365;
	float prob_diff_bday = 1;

	while(1){
		prob_diff_bday = prob_diff_bday * (num / demon);
		if(prob_diff_bday < prob_same_bday){
			break;
		}
		num = num - 1;
		people = people + 1;
	}

	cout << people << endl; 	
}

int main() {
	fast_io;
	
	int t = 1; // cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
