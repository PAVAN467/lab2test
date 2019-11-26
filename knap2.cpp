
#include<iostream>
using namespace std;

int knap(int n, int M, int w[], int p[])
{
    int i,j;
    int knap[n+1][M+1];
    for(j=0;j<=M;j++)

    {    knap[0][j]=0;
    }

     for(i=0;i<=n;i++)
     {
        knap[i][0]=0;
     }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=M;j++)
        {
           if(j-w[i-1]>=0)
            {
                knap[i][j]=max(knap[i-1][j],p[i-1]+knap[i-1][j-w[i-1]]);
            }
          else
            {
                knap[i][j]=knap[i-1][j];
            }
        }
    }

 return knap[n][M];


}

int main()
{
    int i,j;
    int n;
    int M;
    cout<<"Enter the no. of items ";
    cin>>n;
    int w[n];
    int p[n];

    cout<<"Enter the weights and prices"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>w[i]>>p[i];
    }

    cout<<"enter the capacity of knapsack  ";
    cin>>M;
    int result=knap(n,M,w,p);
    cout<<"The maximum value "<<result;

    return 0;
}
