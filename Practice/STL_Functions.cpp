#include<bits/stdc++.h>;
using namespace std;
#define all(a) a.begin(),a.end()
typedef vector<int> vi;
int main(){
	vi a;
	int val = 5;
	vi::iterator pos;
	a.erase(pos);
	find(all(a), 5); // returns iterator to the last element if not found
	reverse(all(a));
	count(all(a), 20);
	*max_element(all(a));
	*min_element(all(a));
	accumulate(all(a), 0); //sum
	upper_bound(all(a), val);
	binary_search(all(a), val);
	priority_queue<int> max_heap;
	a.erase(unique(all(a), a.end()));
	distance(a.begin(), max_element(all(a)));
	cout << lower_bound(all(a), val) - a.begin();
	priority_queue<int, vector<int>, greater<int>>;
	//math functions 
	int x = 20;
	sin(x);
	sqrt(x);
	log(x);
}