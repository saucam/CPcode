#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ll long long
#define pi pair<int, int>
#define f first
#define s second
 
ll l, r;
 
ll solve(ll x){
    return x / 9 * 45 + x % 9 * (x % 9 + 1) / 2;
}
 
void answer(){
    cin >> l >> r;
    
    cout << (solve(r) - solve(l - 1)) << endl;
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	for(int i = 0; i < t; i++) answer();
 
	return 0;
}