//Symmetric Matrix in One Dimensional Array
#include<iostream>
#include<conio.h>
using namespace std;
class Symmetric
{
    int *a,*b;
    int n;
public:
    Symmetric(int size=10)
    {
        n=size;
        //for the size of the array
        if(n!=0)
        {
            a=new int[n];
            b=new int[n];
        }
        else
        {
            a=0;
        }
    }
    ~Symmetric()
    {
        delete []a;
    }
    //To Store the values in matrix
    void store(int x,int y,int ele,int pos,int rows)
    {
        if(x<1 ||y<1 || x>rows ||y>rows)
        {
            cout<<"Out of Bound";
            exit(0);
        }
        else
        {
            a[pos]=ele;
        }
    }
    //To show the transpose of the matrix
    void transpose(int Mrows)
    {
        int t=0;int index=0;
        for(int i=1;i<=Mrows;i++)
        {
            t=i;
            for(int j=1;j<=Mrows;j++)
            {
                index++;
                b[index]=a[t];
                t=t+Mrows;
            }
        }
        cout<<"\nThe Transpose of the Matrix :\n";
        show(Mrows,b);
    }
    //For the Symmetric Matrix function
    void Symmetric_matrix(int rows,int columns)
    {
        int t=0,element;
        for(int i=1;i<=rows;i++)
        {
            for(int j=1;j<=columns;j++)
            {
                t++;
                cout<<"\nEnter the Element in the Matrix at position "<<t<<" :";
                cin>>element;
                cout<<endl;
                store(i,j,element,t,rows);
            }
        }
        cout<<"\nThe Matrix is :\n";
        show(rows,a);
        transpose(rows);
        int index2=0,flag=0;
        //To Check whether the two matrix are Symmetric
        for(int i=1;i<=rows;i++)
        {
            for(int j=1;j<=columns;j++)
            {
                index2++;
                if(a[index2]==b[index2])
                {
                    flag++;
                }
            }
        }
        if(flag==n)
        {
            cout<<"\n--------------The Two Matrix are Symmetric-------------\n";
        }
        else
        {
            cout<<"\n-------------The Two Matrix are not Symmetric-----------\n";
        }
        int res,i,j;
        cout<<"\nEnter the location for the Retrival from the Matrix\n";
        cout<<"Row :\n";
        cin>>i;
        cout<<"Column :\n";
        cin>>j;
        res=retrival(i,j,rows);
        cout<<"\nRetrieved value is :"<<res<<endl;
    }
    //To retrive a value from the Matrix
    int retrival(int x,int y,int rows)
    {
        int k;
        if(x<1 ||y<1 || x>rows ||y>rows)
        {
            cout<<"Out of Bound";
            exit(0);
        }
        else
        {
            k=x*(x+1)/2+y;
            return a[k];
        }

    }

    //To display the matrix
    void show(int Mat_size,int arr[])
    {
        int index=0;
        for(int i=1;i<=Mat_size;i++)
        {
            for(int j=1;j<=Mat_size;j++)
            {
                index++;
                cout<<arr[index]<<"\t";
            }
            cout<<endl;
        }
    }

};
int main()
{
    int row,column;
    cout<<"\nEnter the row for the Matrix\n";
    cin>>row;
    cout<<"\nEnter the column for the Matrix\n";
    cin>>column;
    if(row==column)
    {
    Symmetric s(row*column);
    s.Symmetric_matrix(row,column);
    }
    else
    {
        cout<<"\nRows and Columns are not equal\n";
    }
    return 0;
}
