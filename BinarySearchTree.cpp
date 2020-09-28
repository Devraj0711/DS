//Binary Search Tree
#include<iostream>
#include<conio.h>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
class bst
{
    public:
        node *root;
        bst()
        {
            root=NULL;
        }
        void insert()
        {
            int i;
            node *temp=new node();
            node *temp1=new node();
            cout<<"Enter Element in the node\n";
            cin>>i;
            if(root==NULL)
            {
                root=new node();
                root->left=root->right=NULL;
                root->data=i;
                cout<<"Root value inserted\n";
            }
            else
            {
                temp=root;
                temp1->left=temp1->right=NULL;
                temp1->data=i;
                while(temp!=NULL)
                {
                    if(temp1->data==temp->data)
                    {
                        cout<<"Value entered already exits. Enter another value\n";
                        break;
                    }
                    else if((temp1->data<temp->data)&&(temp->left==NULL))
                    {
                        temp->left=temp1;
                        cout<<"Value inserted in the left node\n";
                        break;
                    }
                    else if(temp1->data<temp->data)
                    {
                        temp=temp->left;
                    }
                    else if((temp1->data>temp->data)&&(temp->right==NULL))
                    {
                        temp->right=temp1;
                        cout<<"Value inserted in the right node\n";
                        break;
                    }
                    else
                    {
                        temp=temp->right;
                    }
                }

            }

        }
        void search()
        {
            int element;
            node *temp=new node();
            temp=root;
            cout<<"Enter the element to search \n";
            cin>>element;
            int count=0;
            string s;
            while(temp!=NULL)
            {
                if(element==temp->data)
                {
                    cout<<"Element present at "<<s<<" node "<<count<<": "<<element<<endl;
                    break;
                }
                 else if(element<temp->data)
                {
                        temp=temp->left;
                        count++;
                        s="left";
                }
                else
                {
                    temp=temp->right;
                    count++;
                    s="right";
                }

            }
        }
        void print()
        {

        }

};
int main()
{
    bst b;
    int ch;
    cout<<"Enter your choice:\n";
    do
    {
        cout<<"\n1.To Insert Values in the Node\n2.To Search Value in the BST\n3.To Print the BST\n4.To Exit\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
            b.insert();
            break;
        case 2:
            b.search();
            break;
        case 3:
            b.print();
            break;
        }
    }while(ch!=4);

    return 0;

}
