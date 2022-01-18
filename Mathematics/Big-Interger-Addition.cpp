/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

char digitToChar(int digit){
	return digit + '0';
}

int charToDigit(char ch){
	return ch - '0';
}

string addNumbers(string n1, string n2){
	// make sure n2 is larger i.e. more number of digits
	if(n1.length() > n2.length()){
		swap(n1, n2);
	}

	// Result
	// reverse the numbers, after reversing perform addition from
	// left to right order (it will be easy for us to handle carry)
	// if any carry available can be easily appended to the right of the result string

	string result = "";
	// Reverse
	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());

	// Add digits upto n1.length() because n1 is smaller number
	int carry = 0;
	for(int i = 0; i < n1.length(); i++){
		int d1 = charToDigit(n1[i]);
		int d2 = charToDigit(n2[i]);

		int sum = d1 + d2 + carry;
		int output_digit = sum % 10;
		carry = sum / 10;

		result.push_back(digitToChar(output_digit));
	}

	for(int i = n1.length();i < n2.length(); i++){
		int d2 = charToDigit(n2[i]);
		int sum = d2 + carry;

		int output_digit = sum % 10;
		carry = sum / 10;

		result.push_back(digitToChar(output_digit));
	}

	// Finally if carry is generated
	if(carry){
		result.push_back(digitToChar(carry));	
	}
	
	// Reverse the final result
	reverse(result.begin(), result.end());
	return result;
}

void solve(){
	string s1, s2;
	cin >> s1 >> s2;

	string result = addNumbers(s1, s2);

	cout << result << endl;
}

int main() {
	fast_io;
	
	int t = 1; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
