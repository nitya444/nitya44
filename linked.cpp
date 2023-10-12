/*
# include<iostream>
using namespace std;
class node{
	public:
	int data;
	node* next;
	
	node(int val){
		data=val;
		next=NULL;
	}
};
void insertattail(node* &head,int val)
{
    node* n=new node(val);
    if(head==NULL)
    {
    	head=n;
    	return;
	}
	node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=n;	
}
void display(node* head)
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<endl;
}
void insertathead(node* &head,int val)
{
	node* n=new node(val);
	n->next=head;
	head=n;
}
bool search(node* head,int key)
{
	node* temp=head;
	while(temp!=NULL)
	{
		if(temp->data==key)
		{
			return true;
		}
		temp=temp->next;
	}
	return false;
}
void deletion(node* &head,int val)
{
	node* temp=head;
	while(temp->next->data!=val)
	{
		temp=temp->next;
	}
	node* todelete=temp->next;
	temp->next=temp->next->next;
	
	delete todelete;
}
void deleteathead(node* &head)
{
	node* todelete=head;
	head=head->next;
	
	delete todelete;
}
/*
node* reverse(node* &head)       //iterative reverse method
{
	node* prevptr=NULL;
	node* currptr=head;
	node* nextptr;
	
	while(currptr!=NULL)
	{
		nextptr=currptr->next;
		currptr->next=prevptr;
		
		prevptr=currptr;
		currptr=nextptr;
	}
	return prevptr;
}


node* reverserecursive(node* &head)     // RECURSIVE METHOD
{
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	node* newhead=reverserecursive(head->next);
		head->next->next=head;
		head->next=NULL;
		
		return newhead;
}
node* reversek(node* &head,int k)  // reverse k nodes
{
	node* prevptr=NULL;
	node* currptr=head;
	node* nextptr;
	
	int count=0;
	while(currptr!=NULL && count<k)
	{
		nextptr=currptr->next;
		currptr->next=prevptr;
		prevptr=currptr;
		currptr=nextptr;
		count++;
	}
	if(nextptr!=NULL)
{  
	head->next=reversek(nextptr,k);
}
return prevptr;
}
void makecycle(node* &head,int pos)
{
	node* temp=head;
	node* startnode;
	
	int count=1;
	while(temp->next!=NULL)
	{
		if(count==pos)
		{
			startnode=temp;
		}
		temp=temp->next;
		count++;
	}
	temp->next=startnode;
}
bool detectcycle(node* &head)
{
	node* slow=head;
	node* fast=head; 
	
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(fast==slow)
		return true;
	}
	return false;
}
void removecycle(node* &head)
{
	node* slow=head;
	node* fast=head;
	do
	{
		slow=slow->next;
		fast=fast->next->next;
	}while(slow!=fast);
	
	fast=head;
	while(slow->next!=fast->next)
	{
		slow=slow->next;
		fast=fast->next;
	}
	slow->next=NULL;
}
int main()
{
	node* head=NULL;
	insertattail(head,1);
	insertattail(head,2);
	insertattail(head,3);
	insertattail(head,4);
	insertattail(head,5);
	insertattail(head,6);
//	display(head);
	//insertathead(head,4);
	//display(head);
	//cout<<search(head,3)<<endl;
	//deletion(head,3);
	//deleteathead(head);
	//display(head);
	//node* newhead=reverserecursive(head);
	//display(newhead);
	//int k=2;
	//node* newhead=reversek(head,k);
	//display(newhead);
	//makecycle(head,3);
	cout<<detectcycle(head)<<endl;
	removecycle(head);
	cout<<detectcycle(head)<<endl;
	//display(head);
}
*/
//PALINDROME
/*
# include<iostream>
using namespace std;
class node{
	public:
	
	int data;
	node* next;
	
	node(int val)
	{
		data=val;
		next=NULL;
	}
};

void insertattail(node* &head,int val)
{
	node* n=new node(val);
	if(head==NULL){
		head=n;
		return;
	}
	node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=n;
}
void insertathead(node* &head,int val)
{
	node* n=new node(val);
	n->next=head;
	head=n;
}

bool ispalindrome(node* head,int val)
{
	node* slow=head;
	node* fast=head;
	
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	 if (fast != NULL && fast -> next == NULL) 
	{
		slow = slow -> next;
	}
        node* prv = NULL;
        node* tmp = NULL;
        while (slow != NULL) {
            tmp = slow -> next;
            slow -> next = prv;
            prv = slow;
            slow = tmp;
        }
        slow = prv, fast = head;
        while (slow && fast) {
            if (slow->data != fast->data) 
			{
			return false;
		}
            slow = slow->next;
            fast = fast->next;
}
        return true;
}


void display(node* head)
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}

int main()
{
	int val;
	node* head=NULL;
	insertattail(head,1);
	insertattail(head,1);
	insertattail(head,1);
	insertattail(head,2);
	display(head);
	//insertathead(head,4);
	//display(head);
	cout<<ispalindrome(head,1)<<endl;

}
*/

# include<iostream>
using namespace std;
class node{
  public:
  		int data;
  		node* next;
  		
  		node(int val)
  		{
  			data=val;
  			next=NULL;
		  }
};

void insertattail(node* &head,int val)
{
	node* n=new node(val);
	node* temp=head;
	if(head==NULL)
	{
		head=n;
		return;
	}
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=n;
}

void insertathead(node* &head,int val)
{
    node* n=new node(val);
    n->next=head;
    head=n;
}

/*
node* middlenode(node* head)
{
	node* slow=head;
	node* fast=head;
	
	while(fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
*/
// DELETE NODES WHICH HAVE A GREATER VALUE ON RIGHT SIDE
/*
node* reverse(node* &head)
{
	node* prevptr=NULL;
	node* currptr=head;
	node* nextptr;
	
	while(currptr!=NULL)
	{
	   nextptr=currptr->next;
	   currptr->next=prevptr;
	   
	   prevptr=currptr;
	   currptr=nextptr;
	}
	return prevptr;
}
node* compute(node* head)
{
	head=reverse(head);
	node* currptr=head;
	int ma=head->data;
	node* prevptr=head;
	head=head->next;
	while(head)
	{
		if(head->data>=ma)
		{
			ma=head->data;
			prevptr=head;
			head=head->next;
		}
		else
		{
			prevptr->next=head->next;
			head=prevptr->next;
		}
	}
	head=reverse(currptr);
	return head;
}
*/

node* insertion(node* head)
{
	node* dummy=new node(1000);
	
	while(head)
	{
		node* next=head->next;
		node* temp=dummy;
		
		while(temp->next && temp->next->data<head->data)
		{
			temp=temp->next;
		}
		head->next=temp->next;
		temp->next=head;
		head=next;
	}
	return dummy->next;
}
void display(node* head)
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}



int main()
{
   int val,count=0;
	node* head=NULL;
	insertattail(head,5);
	insertattail(head,2);
	insertattail(head,13);
	insertattail(head,3);
	insertattail(head,8);
	display(head);
    
	node* newhead=insertion(head);
	display(newhead);
}
