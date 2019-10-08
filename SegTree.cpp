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
#define fill(a, b) memset(a, b, sizeof(a)
#define get(a) rep(i,0,sz(a))cin>>a[i];
#define sz(a) (ll)(a.size())
#define all(a) a.begin(), a.end()
#define mod 1000000009

template<typename... Args> ll mult(Args... args){return ((args%mod)*...)%mod;}
template<typename... Args> auto sum(Args... args){return (args+...);}
template<typename... Args> void giveme(Args&... args){((cin >> args), ...);}
template<typename... Args> void out(Args... args){((cout << args << " "), ...);}

struct segtree(){
    int n; vl t;
    SegTree(int n): n(n),t(2*n){}
    build() {rep(i,n-1,1)t[i]=t[i<<1]+t[i<<1|1];}
    modify(int l, int r, int v) {
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1) t[l++]+=v; 
            if(r&1) t[--r]+=v;
        }
    }
    query(int l, int r){
        ll val=0; 
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1) val+=t[l++];
            if(r&1) val+=t[--r];
        }
        return val;
    }
};

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    setprecision(12);
    cout.precision(12);
    
    int n,m; cin>>n>>m;
    segtree
    build();
    while(m--) {int p,b; cin>>p>>b; cout<<update(p, b, 0)<<"\n";}
    return 0; 
} 