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

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	
	return 0;
}