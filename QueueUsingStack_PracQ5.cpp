//Implementation of Queue using stacks by adding overhead(cost) to enqueue operation
#include<iostream>
#include<conio.h>
using namespace std;
class stack
{
    int a[20];
    int top;
public:
    stack()
    {
        top=-1;
    }
      void push(int item)
    {
        if(top==19)
        {
            cout<<"Stack Full\n";
        }
        else
        {
        a[++top]=item;
        }
    }
    int AtTop()
    {
        char q;
        q=a[top];
        if(top==-1)
        {
            cout<<"Stack Empty\n";

        }
        return q;

    }
    int pop()
    {
        int a1;
        if(top==-1)
        {
            cout<<"Stack Empty\n";

        }
        else
        {
           a1=a[top--];
        }
        return a1;
    }
    bool isEmpty()
    {

        return(top==-1);

    }
    void display()
    {
        if(top==-1)
        {
            cout<<"Stack Empty\n";

        }
        else
        {
            cout<<"THE STACK IS\n";
            for(int i=0;i<=top;i++)
            {
                cout<<a[i]<<"\t";
            }
            cout<<endl;
        }
    }

};
class Queue
{
    public:
        stack s1,s2;
    void enqueue(int ele)
   {

    int x;
    int r1,r2;
    while(!s1.isEmpty())
    {
      x=s1.pop();
      s2.push(x);
    }
    s1.push(ele);
    while(!s2.isEmpty())
    {
        x=s2.pop();
        s1.push(x);
    }
}
int dequeue()
{
    int k;
    k=s1.pop();
    return k;

}
void Queuedisplay()
    {
       s1.display();
    }

};
int main()
{
    Queue s3;
    int ch;
    do
    {
        cout<<"\nEnter your choice\n1.To enter the Element in Queue\n2.To Delete the element in Queue\n3.To Display\n4.To Exit\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
            int z;
            cout<<"\nEnter the Element\n";
            cin>>z;
            s3.enqueue(z);
            break;
        case 2:
            cout<<"\nElement Deleted :";
            int del;
            del=s3.dequeue();
            cout<<del<<endl;
            break;
        case 3:
            s3.Queuedisplay();
            break;

        }
    }while(ch!=4);
    return 0;
}
