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
const int N = 1e5+10;
struct Node { 
	int val, cnt, sz, ls, rs; 
	ll r;
	bool rev;
};
struct fhqTreap {
	static const int N = ::N;
	int rt, L; Node nd[N];
	void init() { rt = L = 0; srand(time(0)); }
	ll Rand() { return ((rand() * 1ll << 32) ^ (rand() * 1ll << 16) ^ rand()); }
	int newnode(int c) {
		nd[++L].r = Rand();
		nd[L].val = c;
		nd[L].cnt = nd[L].sz = 1;
		nd[L].ls = nd[L].rs = nd[L].rev = 0;
		return L;
	}
	void up(int x) {
		if(!x) return ;
		int ls = nd[x].ls, rs = nd[x].rs;
		nd[x].sz = nd[ls].sz + nd[rs].sz + nd[x].cnt;
	}
	void gao(int x) {
		if(!x) return ;
		nd[x].rev ^= 1, swap(nd[x].ls, nd[x].rs);
	}
	void down(int x) { if(nd[x].rev) gao(nd[x].ls), gao(nd[x].rs), nd[x].rev = 0; }
	// u -> (<= c) (> c)
	void splitc(int u, int c, int &x, int &y) {
		if(u) {
			down(u);
			if(nd[u].val <= c) x = u, splitc(nd[u].rs, c, nd[u].rs, y);
			else y = u, splitc(nd[u].ls, c, x, nd[u].ls);
			up(u);
		} else x = y = 0;
	}
	// u -> (1 ~ k) (k+1 ~ L)
	// !!!: nd[].cnt == 1
	void splitk(int u, int k, int &x, int &y) {
		if(u) {
			down(u);
			int sz = nd[nd[u].ls].sz;
			if(sz < k) x = u, splitk(nd[u].rs, k - sz - 1, nd[u].rs, y);
			else y = u, splitk(nd[u].ls, k, x, nd[u].ls);
			up(u);
		} else x = y = 0;
	}
	int merge(int x, int y) {
		if(x && y) {
			if(nd[x].r < nd[y].r) { down(x), nd[x].rs = merge(nd[x].rs, y), up(x); return x; } 
			else { down(y), nd[y].ls = merge(x, nd[y].ls), up(y); return y; }
		} else return x + y;
	}
	void insert(int c){
		int x,y;
		splitc(rt,c-1,x,y);
		int z=newnode(c);
		rt=merge(x,merge(z,y));
	}
	void del(int c){
		int x,y;
		splitc(rt,c-1,x,y);
		int z;
		splitk(y,1,z,y);
		if(z == 0|| nd[z].val != c){
			rt=merge(x,merge(z,y));
			return ;
		}
		rt=merge(x,y);
	}
	int rank(int c){
		int x,y;
		splitc(rt,c-1,x,y);
		int ans=nd[x].sz+1;
		rt = merge(x,y);
		return ans;
	}
	int  mink(int k){
		int x, y;
		splitk(rt,k-1,x,y);
		int z;
		splitk(y,1,z,y);
		int ans = nd[z].val;
		rt = merge(x, merge(z, y));
		return ans;
	}
	int pre(int c){
		int x, y;
		splitc(rt, c-1, x, y);
		int z;
		splitk(x, nd[x].sz-1, x, z);
		int ans=nd[z].val;
		rt = merge(x, merge(z, y));
		return ans;
	}
	int ne(int c){
		int x, y;
		splitc(rt, c, x, y);
		int z;
		splitk(y, 1, z, y);
		int ans=nd[z].val;
		rt = merge(x, merge(z, y));
		return ans;
	}
}T;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	rep(i,1,n+1){
		int op,x;
		cin >> op >> x;
		if(op == 1){
			T.insert(x);
		}
		else if(op == 2){
			T.del(x);
		}
		else if(op == 3){
			cout << T.rank(x) << endl;
		}
		else if(op == 4){
			cout << T.mink(x) << endl;
		}
		else if(op == 5){
			cout<< T.pre(x) << endl;
		}
		else {
			cout<< T.ne(x) << endl;
		}
	}
	return 0;
}