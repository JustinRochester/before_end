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
int a[100000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		int n;
		cin >> n;
		int ans = 0;
		rep(i, 1, n + 1) cin >> a[i];
		rep(i, 1, n + 1){
			if(a[i] == -1){
				int pos = i;
				while(pos <= n){
					if(a[pos] == -1) sum ++;
					else break;
					pos ++;
				}
				if(i != 1 && a[i - 1] == 0)
			}
			else ans ++ ;
		}
		cout << ans << endl;
	}
	return 0;
}