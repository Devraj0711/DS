#include<iostream>
#include<conio.h>
//#include<stdio.h>
using namespace std;
class StackAdd12
{
    int a1[20];
    int top;
public:
    StackAdd12()
    {
        top=-1;
    }

   void push(int item)
    {
       if(top==20)
        {
        cout<<"Stack Full\n";
        }
        else
        {
        a1[++top]=item;
        }
    }
    void display()
    {
        if(top==-1)
        {
            std::cout<<"Stack Empty\n";

        }
        else
        {
            std::cout<<"THE STACK IS\n";
            for(int i=0;i<=top;i++)
            {
               cout<<a1[i]<<"\t";
            }
            cout<<"\n";
        }

    }
    int pop()
    {
      int ch1;
        if(top==-1)
        {
            cout<<"Stack Empty\n";

        }
        else
        {
            //cout<<"Data at the End is removed\n";
            ch1=a1[top];
            top--;
        }
        return ch1;

    }



};
int main()
{

    int i=0,x1,x2,i1=0;
    int choice;
    char input1[20],input2[20];
    StackAdd12 s1,s2,s3;
    do
    {
    cout<<"\nEnter your choice\n1.To enter First Integer\n2.To Enter Second integer\n3.display\n4.To ADD THE TWO INTEGERS\n0.To Exit\n";
    cin>>choice;
    switch(choice)
    {
        case 1:
    cout <<"Enter the First integer\n";
    cin>>input1;
    while(input1[i]!='\0')
    {
    if (input1[i]>='0'&& input1[i]<='9')
        {
            x1=input1[i]-48;
            s1.push(x1);
        }
        else
        {
            break;
        }
        i++;
    }
    break;
 case 2:
    cout<<"\nEnter the Second integers\n";
    cin>>input2;
    while(input2[i1]!='\0')
    {
    if (input2[i1]>='0'&& input2[i1]<='9')
        {
            x2=input2[i1]-48;
            s2.push(x2);
        }
    i1++;
    }
break;
case 3:
    cout<<"DISPLAY\n";
    s1.display();
    s2.display();

   break;
case 4:
    int carry=0,e,b,c,j=0;

    e=s1.pop();
    b=s2.pop();
    while(e>=1&&e<=9||b>=1&&b<=9)
    {
    e=s1.pop();
    b=s2.pop();

    c=e+b+carry;
    if(c/10!=0)
    {
        carry=c/10;
    }
    s3.push(c);
    j++;
    }
    s3.display();

    break;
             }
   }while(choice!=0);

    return 0;

}
