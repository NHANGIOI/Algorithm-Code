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
#define FOR(i,a,b)	for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)	for(int i=(a);i>=(b);i--)
#define FOR_ALL(a)	for(auto c:a)	cout<<c<<" ";
#define endl '\n'
template <typename T1,typename T2>	bool maximize(T1 &a,const T2 b){	if(a<b){a=b;return 1;}	return 0;}
template <typename T1,typename T2>	bool minimize(T1 &a,const T2 b){	if(a>b){a=b;return 1;}	return 0;}
inline void fast_file(const string& nhap) {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
if(fopen((nhap+".INP").c_str(), "r")){freopen((nhap+".INP").c_str(), "r", stdin);freopen((nhap+".OUT").c_str(), "w", stdout);}}
using ll = long long;
using ull = unsigned long long;
const int BASE=257;
const ull INF=1e18+7;
const ll MOD=1e9+7;
signed main()
{
	fast_file("matrix");
	int n,m;	cin>>n>>m;
	int a[n+1][m+1];	FOR(i,1,n)	FOR(j,1,m)	cin>>a[i][j];
	int b[m+1][n+1];
	FOR(i,1,m)	FOR(j,1,n){
		b[i][j]=a[j][i];
    }
	int c[n+1][n+1];
	FOR(i,1,n)	FOR(j,1,n){
		c[i][j]=0;
		FOR(k,1,m){
			c[i][j]+=a[i][k]*b[k][j];
		}
	}
	FOR(i,1,n){	{FOR(j,1,n)	cout<<c[i][j]<<" ";}	cout<<endl;}
}