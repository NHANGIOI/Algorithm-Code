#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
#define endl "\n"
int binarySearch(vector<pii> arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid].fi == target) {
            return arr[mid].se;
        } else if (arr[mid].fi < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
}
struct canh
{
    int x,y,w;
};
int main()
{
    freopen("TAITRONG.INP","r",stdin);
    freopen("TAITRONG.OUT","w",stdout);
    int n,m,s,e;    cin>>n>>m>>s>>e;
    vector<pii>adj[n+1];
    for(int i=0;i<m;i++){
        int x,y,w;  cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    priority_queue<pii>q;
    q.push({0,s});
    bool check[n+1];    memset(check,false,sizeof(check));
    vector<canh>mst;
    vector<int>parent(n+1);
    vector<int>dist(n+1,-1);
    while (!q.empty()){
        int u = q.top().se, trongso=q.top().fi; q.pop();
        if(check[u])    continue;
        check[u]=true;
        if(s!=u){
            mst.push_back({u,parent[u],trongso});
        }
        for(auto c :adj[u]){
            int v=c.fi, w=c.se;
            if(!check[v] && w > dist[v]){
                q.push({w,v});
                dist[v]=w;
                parent[v]=u;
            }
        }
    }
    priority_queue<int,vector<int>,greater<int>>path;
    int ex=e;
    while(ex!=s){
        for(auto c:adj[ex]){
            if(c.fi==parent[ex]){
                path.push(c.se);
            }
        }
        ex=parent[ex];
    }
    cout<<path.top();
    return 0;
}