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
//chuyển  từ ma trận kề sang danh sách cạnh trong đồ thị vô hướng
int main()
{
	fastio; int n;
    freopen("graph.inp","r",stdin);
    freopen("graph.out","w",stdout);
    cin>>n;
    vector<vector<int>>matran(n);
    vector<pii>edge;
    for_equal(i,1,n){
        for_equal(j,1,n){
            int x;  cin>>x;
            matran[i].push_back(x);
        }
    }
    for_equal(i,1,n){
        for_equal(j,1,n){
            if(matran[i][j]==1 && i<j)
                edge.push_back({i,j});
        }
    }
    for_nor(i,0,edge.size()){
        cout<<edge[i].fi<<" "<<edge[i].se<<endl;
    }
	return 0;
}