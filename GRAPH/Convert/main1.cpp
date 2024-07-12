#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<int,int>
#define fi first
#define se second
#define for_nor(i,a,b)	for(int i=(a);i<(b);i++)
#define for_equal(i,a,b)	for(int i=(a);i<=(b);i++)
#define endl "\n"
using ll = long long;
// chuyển từ danh sách cạnh sang danh sách kề trong đồ thị vô hướng
int main()
{
	fastio;
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n+1);
    for_equal(i,1,m){
        int x,y;    cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for_equal(i,1,n){
        cout<<i<<" : ";
        for(int j : a[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
	return 0;
}