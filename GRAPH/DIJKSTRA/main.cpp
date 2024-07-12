#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);\
    cin.tie(0);\
    cout.tie(0);
#define endl "\n"
const int inf = 1e9+1;
int v,e,s,f;
int main()
{   
    fastio;
    freopen("MINPATH.INP","r",stdin);
    freopen("MINPATH.OUT","w",stdout);
    
    cin>>v>>e>>s>>f;
    vector<vector<int>>matrix(v+1,vector<int>(v+1,inf));
    vector<int>dist(v+1);   dist[0]=inf;// không dùng đến nên để inf = 1e9+1
    vector<bool>visited(v+1,true);

    for(int i=1;i<=v;i++){
        matrix[i][i]=0;
    }
    for(int i=1;i<=e;i++){
        int a,b,c;  cin>>a>>b>>c;
        matrix[a][b]=c;
    }

    // khởi tạo
    for(int i=1;i<=v;i++){
        dist[i]=matrix[s][i];
    }
    int mina=inf;
    int u =0;
    do{
        mina=inf;
        for(int i=1;i<=v;i++){
            if(visited[i]&& mina>dist[i]){
                mina = dist[i];
                u = i;
            }
        }
        //Thuật toán sẽ kết thúc khi các đỉnh tự do đều có nhãn +Vô cùng hoặc đã chọn đến đỉnh F
        if(u == 0 || u == f)
            break;
        //Cố định nhãn đỉnh u
        visited[u]=false;
        //Dùng đỉnh u tối ưu nhãn những đỉnh tự do kề với u
        for(int i=1;i<=v;i++){
            if(visited[i]){
                dist[i]=min(dist[i],dist[u]+matrix[u][i]);
            }
        }
    }while(true);
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++) cout<<setw(15)<<matrix[i][j];
        cout<<endl;
    }
    cout<<dist[f];
    return 0;
}