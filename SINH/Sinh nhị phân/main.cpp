#include<iostream>
using namespace std;
int main(){
    int n;  cin>>n;
    int a[n];   for(int i=0;i<n;i++)    cin>>a[i];
    for(int i=1;i<(1<<n);i++){
        cout<<i<<":{";
        for(int j=0;j<n;j++){
            if(i&(1<<j))    cout<<a[j]<<" ";
        }cout<<"}\n";
    }
    return 0;
}