#include<iostream>
#include<conio.h>
using namespace std;
struct node
{
    int data,height;
    node *left,*right;

};
class Avl
{
    public:
    //Maximum Between The Two Number
    int max(int a, int b)
    {
        if(a<b)
        {
            return b;
        }
        else
        {
            return a;
        }
    }

       //Height Of the AVL tree
       int height(node *temp1)
        {
           if (temp1 == NULL)
           {
            return 0;
           }
           else
           {
           return temp1->height;
           }
        }

         node* newNode(int key)
          {
            node *temp= new node();
            temp->data = key;
            temp->left = NULL;
            temp->right = NULL;
            temp->height = 1; // new node is initially
            return(temp);
          }

          //Right Rotate
          node *rightrotate(node *y)
          {
           node *x = y->left;
           node *T2 = x->right;

           // Perform rotation
           x->right = y;
           y->left = T2;

           // Update heights
            y->height = 1+max(height(y->left),height(y->right));
            x->height = max(height(x->left),height(x->right)) + 1;
            return x;
          }

         //Left Rotate
         node *leftrotate(node *x)
         {
            node *y = x->right;
            node *T2 = y->left;

           // Perform rotation
           y->left = x;
           x->right = T2;
           x->height = max(height(x->left),height(x->right)) + 1;
           y->height = max(height(y->left),height(y->right)) + 1;
           return y;
        }

         node* insert(node* temp1, int key1)
       {
           int balance;
           if (temp1== NULL)
           {
           return(newNode(key1));
           }
           else
           {
           if (key1 < temp1->data)
           {
            temp1->left = insert(temp1->left, key1);
           }
           else if (key1 >temp1->data)
           {
            temp1->right = insert(temp1->right, key1);
           }
           else
           {
            return temp1;
           }
           //AVL Algorithm

         temp1->height = 1 + max(height(temp1->left),height(temp1->right));
         balance =(height(temp1->left)-height(temp1->right));

    // Left Left Rotation
    if (balance > 1 && key1 < temp1->left->data)
        return rightrotate(temp1);
    // Right Right Rotation
    if (balance < -1 && key1 > temp1->right->data)
        return leftrotate(temp1);
    // Left Right Rotation
    if (balance > 1 && key1 > temp1->left->data)
    {
        temp1->left = leftrotate(temp1->left);
        return rightrotate(temp1);
    }
    // Right Left Rotation
    if (balance < -1 && key1 < temp1->right->data)
    {
        temp1->right= rightrotate(temp1->right);
        return leftrotate(temp1);
    }
     return temp1;
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
        node *Delete_avl(node *temp)
        {
         int element,balance;
            cout<<"Enter the Element you want to Delete :\n";
            cin>>element;
            node *prev;
            while(temp!=NULL)
            {
                if(element==temp->data)
                {
                    break;
                }
                 else if(element<temp->data)
                {
                        prev=temp;
                        temp=temp->left;
                }
                else
                {
                    prev=temp;
                    temp=temp->right;
                }
            }
            //To Delete The Element By Using Deleting By Merging Method Of BST
            if(temp!=NULL&&element==temp->data)
           {
           /**if(temp==)
            {
                delmerg(root);
            }**/
            if(prev->left==temp)
            {
                delmerg(prev->left);
            }
            else
            {
                delmerg(prev->right);
            }
           }


           //Applying AVL Rotation to the Sibling Of the Deleted element
            if(prev->right==NULL)
            {
                prev=prev->left;
                balance=height(prev->left)-height(prev->right);
                cout<<balance;
                //Right Rotation
                if(balance==0||balance==-1)
                {
                    return rightrotate(prev);
                }
                //Left Right Rotation
                else if(balance==1)
                {
                     cout<<prev->data;
                    prev->left = leftrotate(prev->left);
                    return rightrotate(prev);

                }
                else
                {
                    return prev;
                }

            }
        }

        void delmerg(node *&temp1)
        {
            if(temp1!=NULL)
            {
            node *t=temp1;
            if(temp1->left==NULL)
            {
                temp1=temp1->right;
            }
            else if(temp1->right==NULL)
            {
                temp1=temp1->left;
            }
            else
            {
                t=temp1->left;
                while(t->right!=NULL)
                {
                    t=t->right;
                }
                t->right=temp1->right;
                t=temp1;
                temp1=temp1->left;
            }
            delete t;
          }
        }


    };


int main()
{
    node *root = NULL;
    Avl a1;
    int ch;
    do
    {
        cout<<"\n-------Menu------\n";
        cout<<"1.To Insert in the AVL tree\n2.To Show Preorder of AVL Tree\n3.To Delete element in AVL\n";
        cout<<"4.To Exit\nEnter Your Choice\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
            int element;
            cout<<"\nEnter Element in The AVL Tree\n";
            cin>>element;
            root=a1.insert(root,element);
            break;
        case 2:
            cout<<"Preorder Of Elements in the AVL Tree\n";
            a1.recursive_preorder(root);
            break;
        case 3:
            root=a1.Delete_avl(root);
            break;
        default:
            if(ch==4)
            {
                break;
            }
            cout<<"\nInvalid Choice";
            break;
        }
        }while(ch!=4);
        return 0;
}

