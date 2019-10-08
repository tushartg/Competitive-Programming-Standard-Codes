#include<bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;  

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#if !ONLINE_JUDGE
#define TRACE
#endif
 
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
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
 
#define rep(i, a, n) for(__typeof(n) i=(a)-((a)>(n));i!=(n)-((a)>(n));i+=1-2*((a)>(n)))
#define trav(i, a) for(auto &i:a)

#define fi first 
#define se second 
#define mp make_pair 
#define pb push_back
#define eb emplace_back
#define fill(a, b) memset(a, b, sizeof(a)
#define get(a) rep(i, sz(a))cin>>a[i];
#define sz(a) (ll)(a.size())
#define all(a) a.begin(), a.end()
#define mod 1000000009

struct SQRT{
    int n,m; vl a,p,c;
    SQRT(int n):n(n) {m=n; rep(i,0,n) a[i]=i+1; p(m,-1); c(m,0)}
    update(){
        int l,r,x; ii(l,r,x);
        pl b={l/m, r/m};
        if(b.fi==b.se){p[b.fi]=-1; rep(i,l,r+1) c[i]+=abs(a[i]-x), a[i]=x;}
        else{
            rep(i,l,(b.fi+1)*m) c[i]+=abs(a[i]-x), a[i]=x;
            rep(i,b.fi+1,b.se) 
                if(p[i]==-1) rep(j,i,i+len) c[i]+=abs(a[i]-x), a[i]=x;
                else c[i]+=abs(a[i]-x), a[i]=x;
            for (int i=c_r*len; i<=r; ++i)
                sum += a[i];
        }
    }
    query(){
        int l,r; ii(l,r);
        
    }
};

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); cin.exceptions(cin.failbit); 
    cout.tie(nullptr); setprecision(12); cout.precision(12);
    
    int n,m; ii(n,m);
    SQRT arr(n); 
    rep(i,0,m){int t; cin>>t; if(t==1) arr.update(); else arr.query();}
    return 0; 
} 