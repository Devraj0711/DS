//Distance vector Algorithm 
#include<iostream>
#include<conio.h>
using namespace std;
struct node
{
    unsigned dist[20];
    unsigned from[20];
}rt[10];

int main()
{
    int dmat[20][20];
    int n,i,j,k,count=0;
    cout<<"\nEnter the Number of Nodes\n";
    cin>>n;
    cout<<"Enter the Cost matrix :\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>dmat[i][j];
            dmat[i][i]=0;
            rt[i].dist[j]=dmat[i][j];
            rt[i].from[j]=j;
        }
    }
        do
        {
            count=0;
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    for(k=0;k<n;k++)
                    {
                        if(rt[i].dist[j]>dmat[i][k]+rt[k].dist[j])
                        {
                            rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
                            rt[i].from[j]=k;
                            count++;
                        }
                    }
                }

            }
        }while(count!=0);
        cout<<"\nUpdated Router table is\n";
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cout<<"\t"<<rt[i].dist[j];
            }
            cout<<endl;
        }
        return 0;
}
