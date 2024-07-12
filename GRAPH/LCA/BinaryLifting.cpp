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

const ll oo = 1e18+7;
const int INF = 1e9+7;
const ll MOD = 1e9 + 7;
const int NMAX = 500;
const int MMAX = 5e3 + 10;
/*
    ,_
    (OvO)
    /)_")
    /_/
*/
int n;
vector<int> adj[NMAX];
int par[NMAX];
bool check[NMAX];
int st[NMAX][17];
void DFS(int u){
    for(int v : adj[u]) if(!check[v]){
        check[v] = 1;
        par[v] = u;
        DFS(v);
    }
}
int LG;
void build(){
    FOR(i,1,n)  st[i][0] = par[i];
    REP(j,2,LG) FOR(u,1,n){
        st[u][j] = st[st[u][j - 1]][j - 1];
    }
}
int ancestork(int u,int k){
    int ans = u;
    for(int i = 0;(1 << i) <= k; ++i)   if((k >> i) & 1){
        ans = st[ans][i];
    }
    return ans;
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
    LG = __lg(n);
    cerr <<endl<< "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << endl;
    return 0;
}
