//Binary Search Tree
#include<iostream>
#include<conio.h>
using namespace std;
struct node
{
    int data;
    node *left,*right;
    node *ptr;
};
//Class for Queue operation

class QueueLink
{
  public:
  node *first,*last;
  QueueLink()
  {
      first=last=NULL;
  }
  void enqueue(node *temp1)
  {
      temp1->ptr=NULL;
      if(last==NULL)
      {
          first=last=temp1;
      }
      else
      {
          last->ptr=temp1;
          last=temp1;
      }
  }
  node *dequeue()
  {
      node *temp1;
      if(last==NULL)
      {
          cout<<"\nEmpty\n";

      }
      else
      {
          temp1=first;
          first=first->ptr;
          return temp1;
          delete temp1;
      }
      if(first==NULL)
      {
          cout<<"\nReached end of QUEUE\n";
      }
  }

  bool isempty()
  {
      return(first==NULL);
  }
};

class StackArray
{
    int a[20];
    int top;
public:
    StackArray()
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
    int pop()
    {

        if(top==-1)
        {
            cout<<"Stack Empty\n";

        }
        else
        {

            return(a[top--]);
        }
    }
     bool isempty()
  {
      return(top==-1);
  }
};

//Stack operation for BINARY SEARCH TREE

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
                int c=1;
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
                        cout<<"Value inserted in the left node "<<c<<" \n";
                        break;
                    }
                    else if(temp1->data<temp->data)
                    {
                        c++;
                        temp=temp->left;
                    }
                    else if((temp1->data>temp->data)&&(temp->right==NULL))
                    {
                        temp->right=temp1;
                        cout<<"Value inserted in the right node "<<c<<"\n";
                        break;
                    }
                    else
                    {
                        c++;
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
        //Preorder Recursive function
        void recursive_preorder(node *temp)
        {
            if(temp!=0)
            {
                cout<<temp->data<<" ";
                recursive_preorder(temp->left);
                recursive_preorder(temp->right);
            }

        }
        //Inorder Recursive Function
        void recursive_inorder(node *temp)
        {
            if(temp!=0)
            {
                recursive_inorder(temp->left);
                cout<<temp->data<<" ";
                recursive_inorder(temp->right);
            }

        }
        //Postorder Recursive Function
        void recursive_postorder(node *temp)
        {
            if(temp!=0)
            {
                recursive_postorder(temp->left);
                recursive_postorder(temp->right);
                cout<<temp->data<<" ";
            }

        }
        void iteraive_preorder(node *temp)
        {
            node *temp1=new node();
            StackArray s1;
            s1.push(temp->data);

            while(temp!=NULL)
            {
                    int t;
                    t=s1.pop();
                    cout<<" "<<t;
                    if(temp->left!=NULL)
                    {
                        temp1=temp->left;
                        while(temp1->right!=NULL)
                        {
                            temp1=temp1->right;
                        }
                        temp1->right=temp->right;
                        temp->right=NULL;
                        temp=temp->left;
                        s1.push(temp->data);
                    }
                    else
                    {
                        temp=temp->right;
                        s1.push(temp->data);
                    }
            }
        }
        void bfs_traversal(node *temp)
        {
            QueueLink q1;
            if(temp!=0)
            {
                q1.enqueue(temp);
                while(!q1.isempty())
                {
                    temp=q1.dequeue();
                    cout<<" "<<temp->data;
                    if(temp->left!=NULL)
                    {
                        q1.enqueue(temp->left);
                    }
                    if(temp->right!=NULL)
                    {
                        q1.enqueue(temp->right);
                    }
                }
            }
        }

};
int main()
{
    bst b;
    int ch;
    cout<<"Enter your choice:\n";
    do
    {
        cout<<"\n1.To Insert Values in the Node\n2.To Search Value in the BST\n3.To show Preorder of the BST using Recursive Function\n4.To show Inorder of the BST using Recursive Function\n5.To show Postorder of The BST using Recursive Function\n";
        cout<<"6.To show Traversal of the BST\n7.To show Iterative Preorder of the BST\n8. Exit\n";
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
            cout<<"Preorder of BST :\n";
            b.recursive_preorder(b.root);
            break;
        case 4:
            cout<<"Inorder of BST :\n";
            b.recursive_inorder(b.root);
            break;
        case 5:
            cout<<"Postorder of BST :\n";
            b.recursive_postorder(b.root);
            break;
        case 6:
            cout<<"The Traversal For BST :\n";
            b.bfs_traversal(b.root);
            break;
        case 7:
            cout<<"Preorder Iteration in BST :\n";
            b.iteraive_preorder(b.root);
            break;
        }
    }while(ch!=8);

    return 0;

}
