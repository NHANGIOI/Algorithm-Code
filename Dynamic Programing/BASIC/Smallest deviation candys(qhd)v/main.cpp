#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);\
    cin.tie(0);\
    cout.tie(0);
#define f(i,a,b)    for(int i =(a);i<(b);i++)
#define fe(i,a,b)   for(int i=(a);i<=(b);i++)
#define endl "\n"
int n,tb_keo=0;
int tong_keo=0;
vector<int>keo;
vector<int>part1;
vector<int>part2;
void doc(){
    cin>>n;
    keo.reserve(n);
    f(i,0,n){    
        cin>>keo[i];
        tong_keo += keo[i];
    }
}
void qhd(){
    tb_keo=static_cast<int>(tong_keo)/2;
    bool dp[n+1][tb_keo+1];
    fe(i,0,n)   dp[i][0]=true;
    fe(i,1,tb_keo)  dp[0][i]=false;

    fe(i,1,n){
        fe(k,1,tb_keo)
            dp[i][k]=dp[i-1][k];
        for(int j=tb_keo;j>=1;j--){
            if(dp[i][j]==true)
                continue;
            else
                dp[i][j]=dp[i][j-keo[i-1]];
        }
    }
    //tìm số lg gói kẹo phần 1 có số viên lớn nhất
    int keo_part1;
    for(int i=tb_keo;i>=0;i--){
        if(dp[n][i]==true)
            keo_part1=i;
            break;
    }
    int keo_part2= tong_keo - keo_part1;
    int dolech=abs(keo_part1-keo_part2);
    cout<<dolech<<endl;//in ra độ lệch
    //truy vết 
    int f = tb_keo;
    for(int i=n;i>=1;i--){
        if(dp[i][f]!= dp[i-1][f]){//nếu đúng thì cho vào phần 1
            part1.push_back(i);
            f -= keo[i-1];
        }
        else // sai thì vào phần 2
            part2.push_back(i);
    }
    reverse(part1.begin(),part1.end());//đảo ngược vector
    reverse(part2.begin(),part2.end());

}
void xuat(){
    for(vector<int>::iterator it=part1.begin();it!=part1.end();it++)//duyệt phần tử bằng con trỏ iterator
        cout<<*it<<" ";
    cout<<endl;
    for(vector<int>::iterator it=part2.begin();it!=part2.end();it++)
        cout<<*it<<" ";
}
int main()
{   
    fastio;
    freopen("chiakeo.inp","r",stdin);
    freopen("chiakeo.out","w",stdout);
    doc();
    qhd();
    xuat();
    return 0;
}