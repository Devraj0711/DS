
//POSTHIX OPERATION USING STACK
#include<iostream>
#include<conio.h>
using namespace std;
class Stack
{
    int a1[20];
    int top;
public:
    Stack()
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
        { cout<<"hey\n";
        a1[++top]=item;
        }
    }
    int pop()
    {
        int ch;
        if(top==-1)
        {
            cout<<"Stack Empty\n";

        }
        else
        {
            //cout<<"Data at the End is removed\n";
            ch=a1[top--];
        }
    return ch;
    }

};
int main()
{

    int i=0,x,a,b;
    double c;
    char input[20];
    Stack s1;
    cout <<"Enter a valid postfix expression\n";
    cin>>input;
    while(input[i]!='\0')
    {
        if (input[i]>='0'&& input[i]<='9')
        {
            x=input[i]-48;
            s1.push(x);
        }
        else if(input[i]=='+'||input[i]=='-'||input[i]=='/'||input[i]=='*')
        {
            a=s1.pop();
            b=s1.pop();
            switch(input[i])
            {
            case '+':
                c=a+b;
                s1.push(c);
                break;
            case'-':
                c=b-a;

                s1.push(c);
                break;
            case'*':
                c=b*a;

                s1.push(c);
                break;
            case'/':
                c=b/a;

                s1.push(c);
                break;

                }**/
        }
        i++;
    }
    cout<<"Answer= "<<s1.pop()<<endl;
    return 0;
}
