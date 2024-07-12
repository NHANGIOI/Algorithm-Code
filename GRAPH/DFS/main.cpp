//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define db long double
#define fi first
#define se second
#define pb emplace_back

#define vi vector<int>
#define vii vector<pair<int,int>>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define pdd pair<db, db>
#define iii pair<int, pair<int, int> >

#define ms(s, n) memset(s, n, sizeof(s))
#define all(a) a.begin(), a.end()
#define uni(a) (sort(all(a)), a.resize(unique(all(a))-a.begin()))
#define sz(a) int((a).size())

#define bit(x) bitset<10>((x))
#define MASK(i) (1LL << (i))
#define BIT(x, i) (1 &((x) >> (i)))
#define clz(x) __builtin_clz((x))
#define ctz(x) __builtin_ctz((x))
#define popc(x) __builtin_popcount((x))
#define clzll(x) __builtin_clzll((x))
#define ctzll(x) __builtin_ctzll((x))
#define popcll(x) __builtin_popcountll((x))

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define F0R(i, b) for (int i = 0, _b = (b); i < _b; ++i)
#define FORd(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define F0Rd(i, b) for (int i = (b)-1; i >= 0; i--)
#define rep(i, a) for (auto i : a)

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

void print(int x) {cerr << x;}
void print(long long x) {cerr << x;}
void print(long double x) {cerr << x;}
void print(double x) {cerr << x;}
void print(unsigned long long x) {cerr << x;}
void print(char x) {cerr << x;}
void print(bool x) {cerr << (x ? "True" : "False");}
void print(string x) {cerr << x;}

template <typename T,typename H>
void print(pair<T,H> a) {cerr << "("; print(a.fi); cerr << ','; print(a.se); cerr << ')';}
template <typename T>
void print(T vec) {int cnt=0; cerr << "{"; rep(x,vec) cerr << (cnt++?",":""), print(x); cerr << '}';}

void show() {}
template <typename Head, typename ...Tail>
void show(Head H, Tail ...T){
    print(H);
    if (sizeof...(T)) cerr << ", ";
    show(T...);
}
#define debug(X...) cerr << "LINE "  << __LINE__ << " - " <<  "[" << #X << "] = [", show(X), cerr << "]\n"

template<typename T1,typename T2> bool ckmax(T1 &x,const T2 &y){if(x<y){x=y; return 1;} return 0;}
template<typename T1,typename T2> bool ckmin(T1 &x,const T2 &y){if(y<x){x=y; return 1;} return 0;}

inline int gcd(int x,int y){while(y){int tmp=y;y=x%y;x=tmp;} return (x);}
inline int lcm(int x,int y){return (int)(x*y)/gcd(x,y);}

void read(){}
template <typename Head, typename ...Tail>
void read(Head &H, Tail &...T)
{
    int sign = 0;
    char c;
    for (c = getchar(); !isdigit(c); c = getchar())
        if (c == '-') sign = 1;
    H = c - '0';
    for (c = getchar(); isdigit(c); c = getchar())
        H = H * 10 + c - '0';
    if (sign) H = -H;
    read(T...);
}

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r){return l + rd()% (r-l+1);}

const int MOD = 1000000007;
const int mod = 998244353;
const int oo = 1061109567;
const long long INF = 4557430888798830399;
const double PI = acos(-1);
const int maxN = 2e5 + 1, maxM = 1e2 + 5;

/*
     /\_/\
    (= ._.)
    / >?  \>$
*/

int n;
int cnt[10];
ll a[21];

ll solve(int mask){
    ll sum = 0;
    ms(cnt, 0);
    F0R(i, n){
        if(BIT(mask, i)){
            ll tmp = a[i+1];
            while(tmp){
                int c = tmp % 10;
                if(++cnt[c] > 1) return 0;
                tmp /= 10;
            }
            sum += a[i+1];
        }
    }
    return sum;
}

void sol(){
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    vi v;
    ll ans = -INF;
    F0R(num, MASK(n)){
        if(ckmax(ans, solve(num))){
            v.clear();
            F0R(i, n) if(BIT(num, i)){
                v.pb(i+1);
            }
        }
    }
    cout << ans << endl;
//    for(int x : v) cout << a[x] << ' ';
}

signed main(){
    #define TASK "nhap"
    if(fopen(TASK".inp", "r")){
        freopen(TASK".inp", "r", stdin);
//        freopen(TASK".out", "w", stdout);
    }
    fast; int t = 1;
    cin >> t;
    while(t--) sol();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
}