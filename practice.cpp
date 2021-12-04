#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node* prev;
    node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};
void insertathead(node* &head, int val)
{
    node* n=new node(val);
    n->next=head;
    if(head!=NULL)
    {
    
     head->prev=n;
    
    }
    head=n;
}
void insertattail(node* &head, int val)
{
    node* n = new node(val);
    node* temp=head;
    if(head==NULL)
    {
        insertathead(head, val);
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}
void display(node* &head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}
void del(node* &head, int val)
{
    node* temp=head;
    while(temp->next->data!=val)
    {
        temp=temp->next;
    }
    temp->next=temp->next->next;
    node* n=temp->next;
    temp->next->next->prev=temp->prev->prev;
    delete n;
}
int main()
{
    int n;
    cin>>n;
    node* head=NULL;
    for(int i=0;i<n;i++)
    {
        insertattail(head,i);
    }
    display(head);
    insertathead(head,5);
    display(head);
}