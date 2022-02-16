/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

struct node {
	node* nxt[26];
	node() {
		for(int i = 0; i < 26; i++) {
			nxt[i] = NULL;
		}
	}
};

node* root = NULL;

// O(|s|)
void insert_trie(string s){
	node* curr = root;
	for(int i = 0; i < s.size(); i++){
		int index = s[i] - 'a';
		// new node 
		if(curr->nxt[index] == NULL){
			curr->nxt[index] = new node();		
		}
		// goto that node down the branch
		curr = curr->nxt[index];	
	}
}

// O(|s|)
bool search_trie(string s){
	node* curr = root;
	for(int i = 0; i < s.size(); i++){
		int index = s[i] - 'a';
		if(curr->nxt[index] == NULL){
			return false;
		}
		curr = curr->nxt[index];
	}

	return true;
}

int main() {
	fast_io;
	root = new node();

	string text = "ababba";
	string pattern = "abba";
	int n = text.length();
	
	for(int i = 0; i < n; i++){
		insert_trie(text.substr(i));	// O(n^2)
	}

	if(search_trie(pattern)){
		cout << "Found";	
	} else {
		cout << "Not Found";
	}

	// all the location where this pattern is found
	return 0;
}
