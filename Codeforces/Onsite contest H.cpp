#include <iostream>
#include<vector>
#include<map>
#include<iomanip>
#include<string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>v(n+1),vv(n+1,0);
    for(int i=0;i<n;i++)
    cin>>v[i];
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int l,r;
        cin>>l>>r;
        if(l>r)
        swap(l,r);

        vv[l-1]+=-1;

        vv[r]+=1;

    }

  for(int i=0;i<n+1;i++)
 {if(i)
     vv[i]+=vv[i-1];
     }
   int cnt=0;
   for(int i=0;i<n;i++)
   {
       if(vv[i]==0)
       cnt++;
   }
   cout<<cnt<<endl;
   for(int i=0;i<n;i++)
   {
       if(vv[i]==0)
       cout<<v[i]<<' ';

   }
   cout<<endl;
    return 0;
}