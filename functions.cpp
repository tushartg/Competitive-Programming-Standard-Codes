#include<bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

using namespace std;  
using namespace __gnu_pbds;


#if !ONLINE_JUDGE
    #include "/home/tushar_garg/Desktop/cpp/debug.h"
#else
    #define dbg(x...)
#endif

template <typename T>
using pbds = tree<T,null_type, less<T>,rb_tree_tag,tree_order_statistics_node_update>;

typedef     long long                            ll; 
typedef     pair<ll, ll>                         pl; 
typedef     vector<ll>                           vl;
typedef     vector<char>                         vc;
typedef     vector<bool>                         vb; 
typedef     vector<vl>                           vvl; 
typedef     vector<pl>                           vll; 
typedef     map<ll, ll>                          dict; 
typedef     map<ll, ll, greater <ll> >           sdict; 
typedef     map<char, ll>                        mcl;
typedef     priority_queue<ll>                   pqi;
typedef     priority_queue<pl>                   pqii;
typedef     priority_queue<ll, vl, greater<ll>>  pqmini;

#define rep(i, a, n) for (__typeof(n) i=(a)-((a)>(n)); i!=(n)-((a)>(n)); i+=1-2*((a)>(n)))
#define trav(i, a) for(auto &i:a)
#define fi first 
#define se second 
#define mp make_pair 
#define pb push_back
#define eb emplace_back
#define flash ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define QuickSilver cin.exceptions(cin.failbit),setprecision(12),cout.precision(12);
#define fill(a, b) memset(a, b, sizeof(a)
#define get(a) rep(i,0,sz(a))cin>>a[i];
#define sz(a) (ll)(a.size())
#define all(a) a.begin(), a.end()
#define mod 1000000009

template<typename... Args> ll mult(Args... args){return ((args%mod)*...)%mod;}
template<typename... Args> auto sum(Args... args){return (args+...);}
template<typename... Args> void giveme(Args&... args){((cin >> args), ...);}
template<typename... Args> void out(Args... args){((cout << args << " "), ...);}

 
ll bpow(ll a, ll b){
	ll r=1; for(;b>0;a=(a*a)%mod, b>>1) if(b&1) r=(r*a)%mod;
	return r;
}

void bfs(int n, int s, vl adj[]){
	vb vis(n,false); vis[s]=true;
	queue<int> q; q.push(s);
	vl d(n), p(n); p[s]=-1; d[s]=0;
	while(!q.empty())
	{
		int v=q.front(); q.pop();
		trav(i, adj[v]) if(vis[i]==false) 
			vis[i]=true, q.push(i), d[i]=d[v]+1, p[i]=v;
	}
}

vl PFn(string s){
    int n=sz(s); vl pi(n); pi[0]=0;
    FOR(i, 1, n){
        int j=pi[i-1];
        while(j>0 && s[i]!=s[j]) j=pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i]=j;
    }
    return pi;
}

pl fib(ll n){
	if(n==0) return {0,1}; pl p=fib(n>>1);
	pl f={p.fi*(2*p.se-p.fi),p.fi*p.fi+p.se*p.se};
	if(n&1) return {f.se, f.se+f.fi}; else return f;
}

const int MAX_PR = 5000000;
bitset<MAX_PR> isprime;
vl sieve(int lim){
	isprime.set(); isprime[0]=isprime[1]=0;
	for(int i=4;i<lim;i+=2) isprime[i]=0;
	for(int i=3;i*i<lim;i+=2) 
		if(isprime[i]) for(int j=i*i;j<lim;j+=i*2) isprime[j]=0;
	vi pr; repA(i,2,lim-1) if(isprime[i]) pr.push_back(i);
	return pr;
}

struct UF{
	vl e;
	UF(int n) : e(n, -1){}
	bool same_set(int a, int b) {return find(a)==find(b);}
	int size(int x) {return -e[find(x)];}
	int find(int x) {return e[x]<0?x:e[x]=find(e[x]);}
	void join(int a,int b){
		a=find(a), b=find(b);
		if(a==b)return;
		if(e[a]>e[b]) swap(a, b);
		e[a]+=e[b]; e[b]=a;
	}
};

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos,ll dif) { // a[pos] += dif
	for(;pos<sz(s); pos|=pos+1) s[pos]+=dif;}
	ll query(int pos){ // sum of values in [0, pos)
		ll res=0; for(;pos>0;pos&=pos-1) res+=s[pos-1];
		return res;
	}
	int lower_bound(ll sum){// min pos st sum of [0, pos] >= sum
	// Returns n if no sum is >= sum, or -1 if empty sum is.
		if(sum<=0) return -1;
		int pos=0;
		for(int pw=1<<25;pw;pw>>=1)
			if(pos+pw<=sz(s)&&s[pos+pw-1]<sum) pos+=pw,sum-=s[pos-1];
		return pos;
	}
};

template <class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};
typedef Point<ld> P;

struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
	ll madd = 0, val = 0,d;
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			d = (l->d+ r->d)%mod;
		}
		else if(lo+1==hi) d = v[lo];
	}
	ll query(int L, int R) {
		if (R <= lo || hi <= L) return 0;
		if (L <= lo && hi <= R) return val;
		push();
		return (l->query(L, R)+r->query(L, R))%mod;
	}
	void add(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			madd += x;
			val += x%mod*d%mod;
			madd%=mod;
			val%=mod;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = (l->val+ r->val)%mod;
		}
	}
	void push() {
		if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0,val = (l->val+r->val)%mod;
	}
};

struct SuffixArray {
	vi a;
	string s;
	SuffixArray(const string& _s) : s(_s + '\0') {
		int N = sz(s);
		vector<pli> b(N);
		a.resize(N);
		rep(i,0,N) {
			b[i].first = s[i];
			b[i].second = i;
		}
 
		int q = 8;
		while ((1 << q) < N) q++;
		for (int moc = 0;; moc++) {
			count_sort(b, q); // sort(all(b)) can be used as well
			a[b[0].second] = 0;
			rep(i,1,N)
				a[b[i].second] = a[b[i - 1].second] +
					(b[i - 1].first != b[i].first);
 
			if ((1 << moc) >= N) break;
			rep(i,0,N) {
				b[i].first = (ll)a[i] << q;
				if (i + (1 << moc) < N)
					b[i].first += a[i + (1 << moc)];
				b[i].second = i;
			}
		}
		rep(i,0,sz(a)) a[i] = b[i].second;
	}
	int lower_bound(string t){
		int l = 1,r=sz(a);
		while(l<r){
			int m = (l+r)/2;
			if(s.substr(a[m],min(sz(s)-1-a[m],sz(t)+1)) >= t) r = m;
			else l = m+1;
		}
		return l;
	}
	int upper_bound(string t){
		int l = 1,r=sz(a);
		while(l<r){
			int m = (l+r)/2;
			if(s.substr(a[m],min(sz(a)-1-a[m],sz(t))) > t) r = m;
			else l = m+1;
		}
		return l;
	}
	vi lcp() {
		// longest common prefixes: res[i] = lcp(a[i], a[i-1])
		int n = sz(a), h = 0;
		vi inv(n), res(n);
		rep(i,0,n) inv[a[i]] = i;
		rep(i,0,n) if (inv[i] > 0) {
			int p0 = a[inv[i] - 1];
			while (s[i + h] == s[p0 + h]) h++;
			res[inv[i]] = h;
			if(h > 0) h--;
		}
		return res;
	}
};

//
struct Node {
    int link[2] = {-1, -1};
	int val=0;
};
 
class Trie {
public:
    Trie(int _lvlMax) {
        nodes.push_back(Node());
        lvlMax = _lvlMax;
    }
 
    void add(int value) {
        int node = 0;
		nodes[0].val++;
        for (int lvl = lvlMax; lvl >= 0; --lvl) {
            int b = !!(value & (1 << lvl));
            if (nodes[node].link[b] == -1) {
                int x = newNode();
                nodes[node].link[b] = x;
            }
            node = nodes[node].link[b];
			nodes[node].val++;
        }
    }
 
    int getMin(int value) {
        int node = 0;
        int ans = 0;
        for (int lvl = lvlMax; lvl >= 0; --lvl) {
            int b = !!(value & (1 << lvl));
            if (nodes[node].link[b] == -1||nodes[nodes[node].link[b]].val==0) {
				ans |= 1 << lvl;
                node = nodes[node].link[b ^ 1];
				nodes[node].val--;
            } else {
                node = nodes[node].link[b];
				nodes[node].val--;
            }
        }
        return ans;
    }
private:
    vector<Node> nodes;
    int lvlMax;
    int newNode() {
        nodes.push_back(Node());
        return sz(nodes) - 1;
    }
};//

struct Tree {
	typedef int T;
	const T LOW = 0;
	T f(T a, T b) { return a+b; }
 
	int n;
	vi s;
	Tree() {}
	Tree(int m, T def=0) { init(m, def); }
	void init(int m, T def) {
		n = 1; while (n < m) n *= 2;
		s.assign(n + m, def);
		s.resize(2 * n, LOW);
		for (int i = n; i --> 1; )
			s[i] = f(s[i * 2], s[i*2 + 1]);
	}
	void update(int pos, T val) {
		pos += n;
		s[pos] = val;
		for (pos /= 2; pos >= 1; pos /= 2)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int l, int r) { return que(1, l, r, 0, n); }
	T que(int pos, int l, int r, int lo, int hi) {
		if (r <= lo || hi <= l) return LOW;
		if (l <= lo && hi <= r) return s[pos];
		int m = (lo + hi) / 2;
		return f(que(2 * pos, l, r, lo, m),
				que(2 * pos + 1, l, r, m, hi));
	}
	T query2(int x) { return que2(1, 0, n,x); }
	T que2(int pos,  int lo, int hi,int x) {
		if(lo+1==hi) return lo;
		int m = (lo+hi)/2;
		if(x<=s[2*pos]) return que2(2*pos,lo,m,x);
		else return que2(2*pos+1,m,hi,x-s[2*pos]);
	}
 
};

bool topo_sort(vector<set<int> > &edges, vi &idx, int n) {
		vi indeg(n);
		rep(i,n)
			trav(e, edges[i])
				indeg[e]++;
		queue<int> q; // use priority queue for lexic. smallest ans.
		rep(i,n) if (indeg[i] == 0) q.push(-i);
		int nr = 0;
		while (q.size() > 0) {
			int i = -q.front(); // top() for priority queue
			idx[nr++] = i;
			q.pop();
			trav(e, edges[i])
				if (--indeg[e] == 0) q.push(-e);
		}
		return nr == n;
}


int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	
	return 0;
}