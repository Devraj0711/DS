#include<iostream>
#include<conio.h>
using namespace std;
class Queues
{
    int a[100];int n;
    int front,rear;
public:
    Queues(int s)
    {
       n=s;
       front=rear=-1;
    }
void enqueue(int item)
{
    if(front==0&&rear==n-1||front==rear+1)
    {
        cout<<"\nQueue full\n";
    }
    else if(rear==-1)
    {
        front=rear=0;
    }
    else if(rear==n-1)
    {
        rear=0;
    }
    else
    {
        rear++;
    }
    a[rear]=item;
}
int dequeue()
{
    int r;
    if(front==-1)
    {
        cout<<"\nunderflow\n";
        exit(0);
    }
    else
    {
        r=a[front];
        if(front==rear)
            front=rear=-1;
        else if(front==n-1)
        front=0;
        else
            front++;
    }
    return r;
}
void display()
    {
        if(rear==-1)
        {
            cout<<"Queue Empty\n";
        }
        else
        {
            if(front<=rear)
            {
            cout<<"THE QUEUE IS\n";
            for(int i=front;i<=rear;i++)
            {
                cout<<a[i]<<"\t";
            }
            cout<<endl;
            }
            else if(rear>=front)
            {
                cout<<"THE QUEUE IS\n";
            for(int i=front;i<=rear;i++)
            {
                cout<<a[i]<<"\t";
            }
            cout<<endl;
            }
            else
            {
              int i=front;
              while(i<n)
            {
                cout<<a[i]<<"\t";
            i++;
            }
            cout<<endl;
            for(int i=front;i<=rear;i++)
            {
                cout<<a[i]<<"\t";
            }
            cout<<endl;
            }
        }
    }
};

int main()
{
    int size;
    cout<<"\nEnter the size of the Array\n";
    cin>>size;
    Queues q1(size);
    int choice,b;
    do
    {
        cout<<"\nEnter your choice\n1.To Insert in QUEUE\n2.To Delete in Queue\n3.To Display\n4.To Exit\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the Element\n";
            cin>>b;
            q1.enqueue(b);
            break;
        case 2:
            q1.dequeue();
            break;
        case 3:
            q1.display();
            break;
        }
    }while(choice!=4);
    return 0;
}
