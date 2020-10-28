//Upper Triangular Matrix in One Dimensional Array
#include<iostream>
#include<conio.h>
using namespace std;
class upperTrianlge
{
    int *a,n;
public:
    upperTrianlge(int size=50)
    {
        n=size;
        //for the size of the array
        if(n!=0)
        {
            a=new int[n];
        }
        else
        {
            a=0;
        }
    }
    upperTrianlge()
    {
        delete []a;
    }

    //To Store Element in the Upper Triangular Matrix
    void store(int element,int x,int y,int index)
    {
        if(x<1 ||y<1 || x>n ||y>n)
        {
            cout<<"Out of Bound";
            exit(0);
        }
        else if(x>y &&element!=0)
        {
            cout<<"\nMust be Zero\n";
        }
        else if(x<=y)
        {
        a[index]=element;
        }
    }

     //Upper Triangular Matrix
    void upper_triangle(int m1)
    {
        int element,i,j,pos=0;
        for(i=1;i<=m1;i++)
        {
            for(j=1;j<=m1;j++)
            {
                if(i<=j)
                {
                    pos++;
                    cout<<"Enter the Element in the Array at position "<<pos<<" :";
                    cin>>element;
                    cout<<endl;
                    store(element,i,j,pos);
                }
            }
        }
        cout<<"\nThe Upper Triangular Matrix is :\n";
        show(m1);
        cout<<"\nEnter the location for the retrieval\n";
        cout<<"Row :";
        cin>>i;
        cout<<"\nColumn :";
        cin>>j;
        int array_index=0;
        for(int x=1;x<=i;x++)
        {
            for(int y=1;y<=j;y++)
            {
                if(x<=y)
                {
                    array_index++;
                }
            }
        }
        int res;
        res=retrieval(i,j,array_index);
        cout<<"\nRetrieved value is :"<<res<<endl;
    }

    //To Show the Elements of the Upper Triangular Matrix
    void show(int Mat_size)
    {
        int index=0;
        for(int i=1;i<=Mat_size;i++)
        {
            for(int j=1;j<=Mat_size;j++)
            {
                if(i>j)
                    cout<<"0\t";
                else
                {
                    index++;
                    cout<<a[index]<<"\t";
                }
            }
            cout<<endl;
        }
    }

    //To Retrive the value in a Upper Triangular Matrix
    int retrieval(int x,int y, int Aindex)
    {
        if(x<1 ||y<1 || x>n ||y>n)
        {
            cout<<"Out of Bound";
            exit(0);
        }
        else if(x<=y)
        {
            return a[Aindex];
        }
        else
        {
            return 0;
        }

    }

};
int main()
{
    int row,column,size_array=0;
    cout<<"\nEnter the row for the Matrix\n";
    cin>>row;
    cout<<"\nEnter the Column for the Matrix\n";
    cin>>column;
    if(row==column)
    {
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=column;j++)
        {
            if(i<=j)
            {
                size_array++;
            }
        }
    }
    upperTrianlge u1(size_array);
    u1.upper_triangle(row);
    }
    else
    {
        cout<<"\nRow and Columns are not equal\n";
    }
   return 0;
}


