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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	rep(cas, 1, T + 1){
		int n, m;
		cin >> n >> m;
		rep(i, 2, n + 1) {
			cin >> a[i];
		}

		rep(i, 1, m + 1){
			int u, v;
			cin >> u >> v;
			link[u][v] = 1;
			link[v][u] = 1;
			id[u][v] = i;
			id[v][u] = i;
		}
	}
	return 0;
}