#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
bool vis[1000000 + 10];
int dis[1000000 + 10];
vi edge[1000000 + 10];
ll mod = 1e9 + 7;
ll qpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1){
			res = res * a % mod;
		}
		b /= 2;
		a = a * a % mod;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, 1, m + 1){
		int a, b;
		cin >> a >> b;
		edge[a].pb(b);
		edge[b].pb(a);
	}
	queue<int>q;
	ll ans = 0;
	q.push(1);
	vis[1] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(auto i : edge[x]){
			if(vis[i]) continue;
			vis[i] = true;
			dis[i] = dis[x] + 1;
			//cout << i << " " << x << " " << dis[i] << " " << dis[x] << endl;
			q.push(i);
		}
	}
	rep(i, 2, n + 1){
		//cout << dis[i] << " " << i  << endl;
 		ans = (ans + qpow(2, dis[i])) % mod;
	}
	cout << ans << endl;
	return 0;
}