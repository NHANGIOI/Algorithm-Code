#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);\
    cin.tie(0);\
    cout.tie(0);
#define endl "\n"
int main()
{
    fastio;
    freopen("BFS.INP","r",stdin);
    freopen("BFS.OUT","w",stdout);
    int n,m;  cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=1;i<=m;i++){
        int x,y;    cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    //BFS
    queue<int>q;
    bool check[n+1];    memset(check,false,sizeof(check));
    q.push(1);
    check[1]=true;
    while(!q.empty()){
        int top=q.front();  q.pop();
        cout<<top<<" visited"<<endl;
        for(auto it:adj[top]){
            if(!check[it]){
                q.push(it);
                check[it]=true;
            }
        }
    }
    /**for(int i=1;i<=n;i++){
        cout<<i<<": ";
        for(auto it:adj[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }**/
    return 0;
}