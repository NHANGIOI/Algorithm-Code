#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);\
    cin.tie(0);\
    cout.tie(0);
#define pii pair<int,int>
#define endl "\n"
//chuyển từ danh sách cạnh sang ma  trận kề
int main()
{
    fastio;
    int n,m;
    cin>>n>>m;
    int matran[n][n];
    memset(matran,0,sizeof(matran));
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        matran[x][y]=matran[y][x]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matran[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}