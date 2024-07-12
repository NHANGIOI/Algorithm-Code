#include <bits/stdc++.h>
using namespace std;

#define                fi   first
#define                se   second
#define              endl   '\n'
#define           MASK(i)   (1LL << (i))
#define            all(a)   a.begin(),a.end()
#define        FOR(i,a,b)   for(int i=(a),_b = (b);i <= _b;++i)
#define        REP(i,a,b)   for(int i=(a),_b = (b);i < _b;++i)
#define       FORD(i,a,b)	for(int i=(a),_b = (b);i >= _b;--i)

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l,ll r){ return l+rng()%(r-l+1);}

const ll oo = 1e18+7;
const int INF = 1e9+7;
const ll MOD = 1e9 + 7;
const int NMAX = 10 + 10;
/*
    ,_
    (OvO)
    /)_")
    /_/
*/
int n;
vector<int> adj[NMAX];
int e[2 * NMAX];
int l[2 * NMAX];
int h[NMAX];
bool check[NMAX];
int ide = 1;
void DFS(int u){
    check[u] = 1;
    if(h[u] == 0)   h[u] = ide;
    l[ide] = l[ide - 1] + 1;
    e[ide++] = u;
    for(int v : adj[u]) if(check[v] == 0){
        check[v] = 1;
        DFS(v);
        l[ide] = l[ide - 1] - 1;
        e[ide++] = u;
    }
}
void build(){

}
signed main()
{
 	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define TASK "a"
    if(fopen(TASK".inp", "r")){
        freopen(TASK".INP", "r", stdin);
        freopen(TASK".OUT", "w", stdout);
    }
    cin>>n;
    FOR(i,1,n-1){
        int x,y;    cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    DFS(1);
    REP(i,1,2*n)    cout<<e[i]<<" ";
    cout<<endl;
    REP(i,1,2*n)  cout<<l[i]<<" ";
    cout<<endl;
    FOR(i,1,n)  cout<<h[i]<<" ";
    cerr <<endl<< "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << endl;
    return 0;
}
