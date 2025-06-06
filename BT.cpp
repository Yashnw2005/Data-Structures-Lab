#include<iostream>
using namespace std;
class node
{
    public:
            int data;
            node*left;
            node*right;
            
            
        node(int x)
        {
            data=x;
            left=nullptr;
            right=nullptr;
        }
}*root,*newnode=nullptr;



void insert(node*temp,node*current)
{
    char ch;
    cout<<"enter the choice[left or right]:";
    cin>>ch;
    
     if(ch=='l'||ch=='L')
     {
          if(temp->left==nullptr)
          {
              temp->left=current;
          }
          else
          {
              insert(temp->left,current);
          }
     }
     else if(ch=='r'||ch=='R')
     {
          if(temp->right==nullptr)
          {
              temp->right=current;
          }
          else
          {
              insert(temp->right,current);
          }
     }
     else
     {
         cout<<"invalid choice:";
     }
    
}

void create()
{
    int value;
    cout<<"enter the data:";
    cin>>value;
    newnode=new node(value);
    if(root==nullptr)
    {
        root=newnode;
    }
    else
    {
        insert(root,newnode);
    }
}





int count=0;
void preorder(node*root)
{
    if(root==nullptr)
    {
        
        return;
    }
    
    cout<<root->data<<" ";
    count+=1;
    preorder(root->left);
    preorder(root->right);
}
void total_node()
{
    cout<<"total node present in tree is :"<<count<<endl;
}

void leaf_node(node*root)
{
    if(root==nullptr)
    {
        return;
    }
    if(root->left==nullptr && root->right==nullptr)
      {
          cout<<root->data<<" "<<endl;
      }
      leaf_node(root->left);
      leaf_node(root->right);
      

}

int height(node* root) {
    if (root == nullptr) {
        return 0;  
    }

    
    int leftHeight = height(root->left);  
    int rightHeight = height(root->right); 

   
    return max(leftHeight, rightHeight) + 1;
}




int main()
{
int chh;

do
{
    cout<<"TREES OPERATION:"<<endl;
    cout<<"1.insert:"<<endl;
    cout<<"2.preorder:"<<endl;
    cout<<"3.total nodes:"<<endl;
    cout<<"4.leaf nodes:"<<endl;
    cout<<"5.heigth of tree:"<<endl;
    cout<<"6.invalid choice:"<<endl;
    
    cout<<"enter choice:";
    cin>>chh;
      
      switch(chh)
      {
              case 1:create();
                     break;
                     
              case 2:preorder(root);
                     break;
              case 3: total_node();
                     break;
              case 4:leaf_node(root);
                     break;
              case 5:cout<<"height of tree is"<<height(root)<<endl;          
              case 6:cout<<"invalid..";
                     break;
                                  
      }
}while(chh!=6);
return 0;
}