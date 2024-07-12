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
//chuyển  từ ma trận kề sang danh sách kề trong đồ thị vô hướng
int main()
{
	fastio; int n;
    freopen("graph.inp","r",stdin);
    freopen("graph.out","w",stdout);
    cin>>n;
    int matran[n+1][n+1];
    vector<int> edge[n+1];
    for_equal(i,1,n){
        for_equal(j,1,n){
            cin>>matran[i][j];
        }
    }
    for_equal(i,1,n){
        for_equal(j,1,n){
            if(matran[i][j]==1)
                edge[i].push_back(j);
        }
    }
    for_equal(i,1,n){
        cout<<i<<" : ";
        for(int c : edge[i])
            cout<<c<<" ";
        cout<<endl;
    }
	return 0;
}