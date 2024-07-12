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
const int INF=1e9+7;
const ll MOD=1e9+7; 
/*
    ,_
    (OvO)
    /)_")
    /_/
*/
void solve(){
    int n;  cin>>n;
    ll a[n+1];   FOR(i,1,n)    cin>>a[i];
    ll dp[n+1][MASK(10)+1];  ms(dp,0);
    int state[n+1]; ms(state,0);
    FOR(i,1,n){
        ll temp=a[i];
        bool check=1;
        while(temp>0){
            if(!(state[i]&MASK(temp%10))) state[i]=SET_ON(state[i],(temp%10));
            else    {check=0;break;}
            temp/=10;
        }
        if(check)  dp[i][state[i]]=max(dp[i][state[i]],a[i]);
        else    state[i]=-1;
    }
    ll maxa=0;
    FOR(i,0,n-1){
        FOR(mask,0,(MASK(10)-1)){
            if(state[i+1]==-1)  continue;
            if(!(mask&state[i+1])){
                dp[i+1][(mask|state[i+1])]=max(dp[i+1][(mask|state[i+1])],dp[i][mask]+a[i+1]);
                for(int k=i+1;(k<=i+450)&&(k<=n);k++)   dp[k][(mask|state[i+1])]=dp[i+1][(mask|state[i+1])];
                if(maxa<dp[i+1][(mask|state[i+1])])   maxa=dp[i+1][(mask|state[i+1])];
            }
        }
    }cout<<maxa<<endl;
    /*FOR(i,1,n){
        FOR(j,1,MASK(10)){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }
    for(int c:state)    cout<<c<<" ";*/

}
signed main()
{   
	fast_file("bit");
    int t;  cin>>t;
    while(t--)  solve();
    return 0;
}
