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

int tt=0;
void dfs_vis(int s, vl adj[], vb vis, vl in, vl out){
	vis[s]=true; in[s]=tt++;
	trav(i, adj[s]) if(vis[i]==false) dfs_vis(i, adj, vis, in, out);
	out[s]=tt++;
}


void dfs(int n, int s, vl adj[]){
	vb vis(n,false);
	vl in(n), out(n);
	rep(i, 0, n) if(!vis[i]) dfs_vis(s, adj, vis, in, out);
}

int main(){
	int n, m; cin>>n>>m;
	vl adj[n];
	rep(i, 0, m)
	{
		int u, v; cin>>u>>v; 
		adj[u-1].pb(v-1); 
		adj[v-1].pb(u-1);
	}
	dfs(n, 0, adj);
	return 0;
}