
#include<bits/stdc++.h>

using namespace std;

int lis(int a[],int n)
{
    int lis[n];
    lis[0]=1;
    for(int i=1;i<n;i++)
    {
        lis[i]=1;
      for(int j=0;j<i;j++)
      {
          if(a[j]<a[i]&&lis[i]<lis[j]+1)
          {
              lis[i]=lis[j]+1;
          }
      }
    }
    return *max_element(lis,lis+n);

}


int main()
{

    int a[]={0,4,12,2,10,6,9,13,3,11,7,15};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<lis(a,n);
    return 0;
}
