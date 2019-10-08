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
#define fill(a, b) memset(a, b, sizeof(a)
#define get(a) rep(i,0,sz(a))cin>>a[i];
#define sz(a) (ll)(a.size())
#define all(a) a.begin(), a.end()
#define mod 1000000009

struct node{
	node* left, right;
	int key, val;
};

struct AVL{
	node* root;
	void make_node(int x, int y){node* p=(node*) malloc(sizeof(node*)); p->key=x; p->val=y; insert(p);}
	bool insert(int a, int b) {return find(a)==find(b);}
	int size(int x) {return -e[find(x)];}
	int find(int x) {return e[x]<0?x:e[x]=find(e[x]);}
	void join(int a,int b){
		a=find(a), b=find(b);
		if(a==b)return;
		if(e[a]>e[b]) swap(a, b);
		e[a]+=e[b]; e[b]=a;
	}
};

int main(){
	flash; QuickSilver;
	
	
    return 0;
} 