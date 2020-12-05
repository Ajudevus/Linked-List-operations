#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
    int val;
    node *next;
} *root=NULL;

node *create_node(int k)
{
    node *Node=new node;
    Node->val=k;
    Node->next=NULL;
    return Node;
}
void insert(int k)
{
    auto nod=create_node(k);
    
    if(!root)
    {root=nod;
    
    }
    else
    {
    auto temp=root;
    root=nod;
    nod->next=temp;
    }
}
void rotate(int k)
{   
    while(k)
    {
        auto temp=root;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        auto ptr=temp->next;
        temp->next=NULL;
        auto save=root;
        root=ptr;
        ptr->next=save;
        k--;
    }
  
}
void display()
{
    auto temp=root;
    while(temp)
    {cout<<temp->val<<" ";
    temp=temp->next;
        
    }
}
int main()
{   int x;
    int r;
    int n;
    cout<<"Enter the total number of elements to be added in the list "<<endl;
    cin>>n;
    cout<<"Enter the elements (insertion at begining)"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        insert(x);
    }
    cout<<"total rotaion to be made?.."<<endl;
    cin>>r;
    cout<<"Original list"<<endl;
    display();
    cout<<endl;
    rotate(r);
    cout<<"Linked List after rotating "<<r<<" times"<<endl;
    display();
    
    return 0;
}
