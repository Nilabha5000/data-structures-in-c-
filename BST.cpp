#include <iostream>

struct node{
     int info;
     node *left , *right;
     node(int info)
     {
        this->info = info;
        left = right = NULL;
     }
};

class BST{
    node *root;
    public:
       BST();
       bool isEmpty();
       void push(int);
       void preorder();
       void postorder();
       void inorder();

};

BST::BST()
{
    root = NULL;
}

bool BST::isEmpty()
{
    return (root == NULL);
}
void BST::push(int data)
{
    if(isEmpty())
        root = new node(data);
    else{
        node *t = root;
        while(t)
        {
            if(data < t->info && t->left != NULL)
            {
                t = t->left;
            }
            else if(data > t->info && t->right != NULL)
               t = t->right;
            else{
                 if(t->left == NULL)
                 {
                    t->left = new node(data);
                    t=t->left;
                 }
                 else{
                     t->right = new node(data);
                     t = t->right;
                 }
            }
        }
    }
}

void BST::preorder()
{
    if(root)
    {
        std::cout<<root->info;
        
    }
}
int main()
{
    /* code */
    return 0;
}