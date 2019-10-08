#include<bits/stdc++.h> 
using namespace std;  

#if !ONLINE_JUDGE
    #include "/home/tushar_garg/Desktop/cpp/debug.h"
#else
    #define dbg(x...)
#endif

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

#define rep(i, a, n) for (auto i=(a)-((a)>(n)); i!=(n)-((a)>(n)); i+=1-2*((a)>(n)))
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

struct segtree{
    int n; vll t;
    segtree(int n): n(n),t(2*n) {build();}
    void build() {
    	rep(i,0,n) {int x; cin>>x; t[n+i]={x,0};}
    	rep(i,n,1)
    	{
	    	if(t[i<<1].se==0) t[i].fi=t[i<<1].fi|t[i<<1|1].fi;
	    	else t[i].fi=t[i<<1].fi^t[i<<1|1].fi;
	    	t[i].se=t[i<<1].se^1;
	    }
    }
    void update(int i, int val){
    	for(i+=n,t[i].fi=val; i!=1; i>>=1){
    		if(t[i].se==0) t[i>>1].fi=t[i].fi|t[i^1].fi;
	    	else t[i>>1].fi=t[i].fi^t[i^1].fi;
    	}
    }
};


int main(){
	flash; QuickSilver;
	
    int n,m; cin>>n>>m;
    segtree st(1<<n);
    while(m--){
    	int p,b; cin>>p>>b;
    	st.update(p-1,b);
    	cout<<st.t[1].fi<<"\n";
    }
	return 0;
}