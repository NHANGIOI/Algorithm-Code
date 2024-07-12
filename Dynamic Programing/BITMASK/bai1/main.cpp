#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define sz(a)   a.size()
#define pb(a) push_back(a)
#define all(a)  a.begin(),a.end()
#define max_e(a)  max_element(all(a))
#define min_e(a)  min_element(all(a))
#define ms(a,b) memset(a,(b),sizeof(a))
#define max_heap_int(a)	priority_queue<int>a;
#define min_heap_int(a)	priority_queue<int,vector<int>,greater<int>>a;
#define max_heap_ll(a)	priority_queue<ll>a;
#define min_heap_ll(a)	priority_queue<ll,vector<ll>,greater<ll>>a;

#define MASK(i) (1LL << (i))
#define count_bit(a) __builtin_popcountll(a) // đếm số bit đang bật
#define BIT(x, i) ((x) & MASK(i)) // trạng thái của bit thứ i trong x
#define SET_ON(x, i) ((x) | MASK(i)) // bật bit thứ i trong x
#define SET_OFF(x, i) ((x) & ~MASK(i)) // tắt bit thứ i trong x

#define FOR(i,a,b)	for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)	for(int i=(a);i>=(b);i--)
#define FOR_ALL(i,a)    for(auto i:a)
#define endl '\n'
template <typename T1,typename T2>	bool maximize(T1 &a,const T2 b){	if(a<b){a=b;return 1;}	return 0;}
template <typename T1,typename T2>	bool minimize(T1 &a,const T2 b){	if(a>b){a=b;return 1;}	return 0;}
inline void fast_file(const string& nhap) {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
if(fopen((nhap+".INP").c_str(), "r")){freopen((nhap+".INP").c_str(), "r", stdin);freopen((nhap+".OUT").c_str(), "w", stdout);}}
using ll = long long;
using ull = unsigned long long;
using ld=long double;
const int BASE=257;
const ll oo=1e18+7;
const int INF=1e6+7;
const ll MOD=1e9+7; 
/*
    ,_
    (OvO)
    /)_")
    /_/
*/
signed main()
{
	fast_file("bit");
    int n;  cin>>n;
    int a[n][n];    FOR(i,0,n-1)  FOR(j,0,n-1)  cin>>a[i][j];
    int dp[n][MASK(n)];
    FOR(i,0,n-1)  FOR(j,0,MASK(n)-1)  dp[i][j]=INF;
    int mina=INF;
    FOR(i,0,n-1)    dp[i][MASK(i)] = 0;
    FOR(mask,0,MASK(n)-1){
        FOR(u,0,n-1)  FOR(v,0,n-1){
            if(!BIT(mask,v)){
                dp[v][SET_ON(mask,v)]=min(dp[v][SET_ON(mask,v)],dp[u][mask]+a[u][v]);
            }
        }
    }
    FOR(i,0,n-1)  mina=min(mina,dp[i][MASK(n)-1]);
    /*FOR(i,0,n-1){  
        FOR(j,0,MASK(n)-1)  cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/cout<<mina;
    return 0;
}
