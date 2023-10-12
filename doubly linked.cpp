# include<iostream>
using namespace std;
class node{
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
void insertathead(node* &head,int val)
{
	node* n=new node(val);
	n->next=head;
	if(head!=NULL)
	{
	head->prev=n;
}
	head=n;
}
void insertattail(node* &head,int val)
{
	if(head==NULL)
	{
		insertathead(head,val);
		return;
	}
	node* n=new node(val);
	node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=n;
	n->prev=temp;
}

void display(node* head)
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" "<<endl;
		temp=temp->next;
	}
	cout<<endl;
}
void deleteathead(node* &head)
{
	node* todelete=head;
	head=head->next;
	head->prev=NULL;
	
	delete todelete;
}
void deletion(node* &head,int pos)
{
	if(pos==1)
{
	deleteathead(head);
	return;
}
	node* temp=head;
	int count=1;
	while(temp!=NULL && count!=pos)
	{
		temp=temp->next;
		count++;
	}
	temp->prev->next=temp->next;
	if(temp->next!=NULL)
	{
	temp->next->prev=temp->prev;
}
	delete temp;
}
int length(node* &head)
{
	int l=0;
	node* temp=head;
	while(temp!=NULL)
	{
		l++;
		temp=temp->next;
	}
}
int insersection(node* &head1,node* &head2)
{
	int l1=length(head1);
	int l2=length(head2);
	
	int d=0;
	node* ptr1;
	node* ptr2;
	if(l1>l2)
	{
		d=l1-l2;
		ptr1=head1;
		ptr2=head2;
	}
	else
	{
		d=l2-l1;
		ptr1=head2;
		ptr2=head1;
	}
	while(d)
	{
		ptr1=ptr1->next;
		if(ptr1!=NULL)
		{
			return -1;
		}
	}
	d--;
}

int main()
{
	node* head=NULL;
	insertattail(head,1);
	insertattail(head,2);
	insertattail(head,3);
	insertattail(head,4);
	//insertattail(head,5);
	//insertattail(head,6);
	display(head);
	insertathead(head,5);
	display(head);
	deletion(head,1);
	display(head);
	
	return 0;
}
