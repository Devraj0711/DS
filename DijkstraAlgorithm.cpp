//Dijkstra Algorithm
#include<iostream>
#include<conio.h>
using namespace std;
#define MAX 100
#define INFI 10000
void dijk(int a[MAX][MAX],int n,int start)
{
    int cost[MAX][MAX],dist[MAX],visited[MAX],pred[MAX];
    int count,mindistance,nextnode;
    for(int i=0 ;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
             if(a[i][j]==0)
             {
                 cost[i][j]=INFI;
             }
             else
             {
                 cost[i][j]=a[i][j];

             }

        }
    }
    int j;
    for(int i=0;i<n;i++)
    {
        dist[i]=cost[start][i];
        pred[i]=start;
        visited[i]=0;
    }
    dist[start]=0;
    visited[start]=1;
    count=1;
    while(count<n-1)
    {
        mindistance=INFI;
        for(int i=0;i<n;i++)
        {
            if(dist[i]<mindistance&& !visited[i])
            {
                mindistance=dist[i];
                nextnode=i;
            }
        }
    visited[nextnode]=1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if((mindistance+cost[nextnode][i])<dist[i])
            {
                dist[i]=mindistance+cost[nextnode][i];
                pred[i]=nextnode;
            }
        }
    }
    count++;
    }
    for(int i=0;i<n;i++)
    {
        if(i!=start)
        {
            cout<<"\nThe Distance of node "<<i<<" is :"<<dist[i]<<endl;
            cout<<"the path is :"<<i;
            j=i;
            do
            {
                j=pred[j];
                cout<<"<-"<<j;
            }while(j!=start);
        }
    }
    cout<<endl;
}
int main()
{
    int A[MAX][MAX], n;
    int i,j;;
    cout<<"\nEnter the number of vertices :";
    cin>>n;
    cout<<endl;
    cout<<"\nEnter the Graph :\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>A[i][j];
        }
    }
     int start;
     cout<<"Enter the starting node :";
     cin>>start;
     cout<<endl;
      dijk(A,n,start);
      return 0;
}
