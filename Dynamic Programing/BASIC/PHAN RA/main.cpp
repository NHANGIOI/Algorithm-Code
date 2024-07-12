#include <iostream>
#include <fstream>
#include <stdlib.h>
#define MAX 255
using namespace std;
void doc();
void qhd();
void truyvet();
bool f[MAX][MAX];
string ss,aa,bb;
int n,m,p;
char s[MAX];
char a[MAX];
char b[MAX];
char ta[MAX];
char tb[MAX];
int i1=0;
int j1=0;
int main()
{

  doc();
  cout<<"xau ss: "<<ss<<endl;
  cout<<"xau aa: "<<aa<<endl;
  cout<<"xau bb: "<<bb<<endl;
  p=ss.length();
  n=aa.length();
  m=bb.length();
  cout<<"Do dai xau s: "<<p<<endl;
  cout<<"Do dai xau a: "<<n<<endl;
  cout<<"Do dai xau a: "<<m<<endl;
  //int k=0;
  for(int i=0; i<p; i++)
            s[i+1]=ss[i];
  for(int i=0; i<n; i++)
        a[i+1]=aa[i];
  for(int i=0; i<m; i++)
        b[i+1]=bb[i];

  cout<<"xau mang s"<<endl;
  for(int i=1 ;i<=p; i++) cout<<s[i]<<" ";
  cout<<endl;
  cout<<"xau mang a"<<endl;
  for(int i=1 ;i<=n; i++) cout<<a[i]<<" ";
  cout<<endl;
  cout<<"xau mang b"<<endl;
  for(int i=1 ;i<=m; i++) cout<<b[i]<<" ";
  qhd();
  cout<<endl;
  cout<<"ket qua mang f[n][m]:  "<<f[n][m]<<endl;
  if(f[n][m])
  {
   truyvet();

  }

  else
    cout<<"Khong ton tai cach phan ra hai xau: ";


 cout<<endl;
 cout<<"gia tri n= "<<n<<endl;
 cout<<"gia tri m= "<<m<<endl;

return 0;
}
void doc()
{
   ifstream fin("prhxc.inp");
   fin>>ss>>aa>>bb;
   fin.close();
}
void qhd()
{

   for(int i=0; i<=n; i++) f[i][0]=true;
   for(int j=0; j<=m; j++) f[0][j]=true;
    for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
              if ((b[j]!=s[i+j]) && (s[i+j]!= a[i]))//TH1;
                   f[i][j]=false;
              else
              if ((b[j]!=s[i+j]) && (s[i+j]== a[i]))//TH2;
                   f[i][j]=f[i-1][j];
              else
              if ((b[j]==s[i+j]) && (s[i+j]!=a[i]))//TH3
                   f[i][j]=f[i][j-1];
              else  //TH4 Cả 3 đều bằng nhau  (b[j]==s[i+j]) && (s[i+j]!=a[i])
                f[i][j]=(f[i-1,j]) || (f[i][j-1]);
}
void truyvet()
{
/*cout<<"xem mang ket qua f: "<<endl;

  for(int i=1; i<=n; i++)
  {
      for(int j=1; j<=m; j++)
        cout<<f[i][j]<<"  ";
      cout<<endl;
  }*/

  if (m*n==0)
    {
  cout<<endl;
  cout<<"xuat ket qua xau a:"<<endl;
  if(n>0)
    for(int i=n-1; i>0; i--)
      cout<<a[i];

  for(int i = i1;i>=1; i--)
    cout<<ta[i];

    cout<<endl;
  cout<<"xuat ket qua xau b:"<<endl;
  if(m>0)
    for(int i=1; i<=m; i++)
      cout<<b[i];
  for(int i = j1;i>=1; i--)
    cout<<tb[i];

    return;
    }
    if (f[n-1][m] == true)
    {

      i1++;
      ta[i1]=a[n];
      n=n-1;
    }

    else
    {

      j1++;
      tb[j1]=b[m];
      m=m-1;
    }


    truyvet();
}
