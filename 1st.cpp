
#include<iostream>
#include<cstring>

using namespace std;

int c[20][20];
char b[20][20];
char str1[20],str2[20];

int m,n;
int count=0;
void display(int i,int j)
{
   if(i==0||j==0)
   {
       return;
   }
   if(b[i][j]=='c')
   {
       display(i-1,j-1);
       cout<<str1[i-1];
       count++;
   }
  else if(b[i][j]=='u')
   {
        display(i-1,j);

   }
    else
   {
        display(i,j-1);

   }
  // cout<<"lenght="<<count<<"\n";
}

void lcs()
{
m=strlen(str1);
n=strlen(str2);

for (int i=0;i<=m;i++)
{

    c[i][0]=0;
}
for (int i=0;i<=n;i++)
{

    c[0][i]=0;
}

for(int i=1;i<=m;i++)
{

    for(int j=1;j<=n;j++)
    {

        if(str1[i-1]==str2[j-1])
        {

            c[i][j]=c[i-1][j-1]+1;
            b[i][j]='c';
        }
       else if(c[i-1][j]>=c[j][i-1])
        {

            c[i][j]=c[i-1][j];
            b[i][j]='u';

        }
        else
        {
           c[i][j]=c[i][j-1];
            b[i][j]='l';

        }

    }
}
}

int main()
{
    cout<<"enter first st";
    cin>>str1;
    cout<<"enter second str2";
    cin>>str2;
    lcs();
    display(m,n);
    return 0;

}
