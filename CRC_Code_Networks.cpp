#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int msize,Gsize,m[50],g[50],rem[50];
    cout<<"Enter the Message size :";
    cin>>msize;
    cout<<"Enter the Message in Binary\n";
    for(int i=0;i<msize;i++)
    {
        cout<<"Enter Bit "<<i+1<<":";
        cin>>m[i];
    }
    cout<<"\nEnter the Generator size :";
    cin>>Gsize;
    cout<<"\nEnter the Generator in Binary\n";
    for(int i=0;i<Gsize;i++)
    {
        cout<<"Enter Bit "<<i+1<<":";
        cin>>g[i];
    }
    //To Display the Message and Generator Entered by the User
    cout<<"\nThe Message in Binary :";
    for(int i=0;i<msize;i++)
    {
        cout<<m[i];
    }
    cout<<"\nThe Generator in Binary :";
    for(int i=0;i<Gsize;i++)
    {
        cout<<g[i];
    }
    cout<<endl;
    //To Append Zero's at the end of Message
    int a1=0;
    for(int i=msize;i<(msize+Gsize)-1;i++)
    {
        m[i]=0;
        a1++;
    }
    cout<<"\nThe Message after zero is appended :";
    for(int i=0;i<(msize+Gsize)-1;i++)
    {
        cout<<m[i];
    }
    cout<<endl;
    int n;
    //To Find the Remainder of CRC
    for(int i=0;i<Gsize;i++)
    {
        rem[i]=m[i]^g[i];
        n=i;

    }
    int flag=0,a=0,e[50];
    int r;
    r=msize+Gsize;
    while(n<(msize+a1)-1)
    {
        while(flag==0)
              {
                  if((rem[a]==0)&&(n!=(msize+a1)-1))
                    {
                        rem[n+1]=m[n+1];
                        a++;
                        n++;

                    }
                    else
                    {
                        flag++;
                    }
              }
              flag=0;
              int k=0,p=0;
              for(int i=a;i<(Gsize+a);i++)
              {
                  if(n!=(msize+a1)-1)
                     {
                       rem[i]=rem[i]^g[k];
                  k++;
                     }
                        else
                        {
                  e[p]=rem[i];
                  p++;
                        }

              }
              k=0;

    }
    cout<<"Remainder :";
    for(int i=0;i<Gsize;i++)
    {
        cout<<e[i];
    }
    cout<<endl;
    int size2;
    size2=Gsize-1;
    for(int j=(msize+a1)-1;j>=(r-1)-a1;j--)
    {
        m[j]=m[j]+e[size2];
        size2--;
    }
    cout<<"===============================================\n";
    cout<<"Message after addition of remainder :";
    for(int i=0;i<(msize+Gsize)-1;i++)
    {
        cout<<m[i];
    }
    cout<<endl;
//Second Division to check for error
    int rem1[50];
    for(int i=0;i<Gsize;i++)
    {
        rem1[i]=m[i]^g[i];
        n=i;

    }
    int flag1=0,a3=0,e1[50];
    int r2;
    r2=msize+Gsize;
    while(n<(msize+a1)-1)
    {
        while(flag1==0)
              {
                  if((rem1[a3]==0)&&(n!=(msize+a1)-1))
                    {
                        rem1[n+1]=m[n+1];
                        a3++;
                        n++;

                    }
                    else
                    {
                        flag1++;
                    }
              }
              flag1=0;
              int k1=0,p1=0;
              for(int i=a3;i<(Gsize+a3);i++)
              {
                  if(n!=(msize+a1)-1)
                     {
                       rem1[i]=rem1[i]^g[k1];
                  k1++;
                     }
                        else
                        {
                  e1[p1]=rem1[i];
                  p1++;
                        }

              }
              k1=0;

    }
    cout<<"Remainder :";
    for(int i=0;i<Gsize;i++)
    {
        cout<<e1[i];
    }
    cout<<endl;
    return 0;

}

