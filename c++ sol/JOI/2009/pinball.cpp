#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
#define endl '\n'
#define ll long long
#define pi pair<int, int>
#define f first
#define s second

const ll inf = 0x3f3f3f3f3f3f3f3f;
int n, m;
map<int, ll> dpl;
map<int, ll, greater<int>> dpr;

template<typename T>
void add(T &dp, int x, ll y){
	auto it = dp.insert({x, y}).f;
	y = min(y, it->s), it->s = y;
	if(next(it) != dp.end() && next(it)->s <= y) it = dp.erase(it);
	while(it != dp.begin() && (--it)->s >= y) it = dp.erase(it);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	ll ret = !!~-m * inf;
	dpl[1] = 0, dpl[m] = inf, dpr[1] = inf, dpr[m] = 0;
	for(int i = 0; i < n; i++){
		int l, r, x, y;
		cin >> l >> r >> x >> y;
		ll vl = dpl.lower_bound(l)->s, vr = dpr.lower_bound(r)->s;
		ret = min(ret, vl + vr + y);
		add(dpl, x, vl + y), add(dpr, x, vr + y);
	}
	
	cout << (ret < inf ? ret : -1) << endl;

	return 0;
}