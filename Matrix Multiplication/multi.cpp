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
#define max_heap(a)	priority_queue<int>a;
#define min_heap(a)	priority_queue<int,vector<int>,greater<int>>a;
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
	int n,m,p,q;	cin>>n>>m;
	int a[n+1][m+1];
	FOR(i,1,n)	FOR(j,1,m)	cin>>a[i][j];
	cin>>p>>q;
	int b[p+1][q+1];
	FOR(i,1,p)	FOR(j,1,q)	cin>>b[i][j];
	int matrix[n+1][q+1];
	FOR(i,1,n){
		FOR(j,1,q){
			int tong=0;
			FOR(k,1,m)	tong+=a[i][k]*b[k][j];
			matrix[i][j]=tong;
		}
	}
	FOR(i,1,n){	
		FOR(j,1,m)	cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}