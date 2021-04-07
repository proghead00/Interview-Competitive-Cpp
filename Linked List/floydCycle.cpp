#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node*next;

	Node(int d)
	{
		data = d;
		next = NULL;
	}
};

void create(Node *&head, int d)
{
	if(head==NULL)
	{
		head = new Node(d);
		return;
	}

	Node *tail = head;
	while(tail->next!=NULL)
	{
		tail = tail->next;
	}

	Node*t = new Node(d);

	tail->next = t;

	return;
}

void makeCycle(Node*&head, int pos)
{
	Node*startNode;
	Node*temp = head;

	int c=1;

	while(temp->next!=NULL)
	{
		if(c==pos)
		{
			startNode = temp;
		}
		temp = temp->next;
		c++;

	}

	temp->next = startNode;
}

bool detectCycle(Node*head)
{
	Node*slow;
	Node*fast;
	fast = slow = head;

	while(fast!=NULL and fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;

		if(fast==slow)
			return true;
	}

	return false;

}


 void removeCycle(Node* head){
    Node* fast = head ;
    Node* slow = head ;

    do{
        fast=fast->next->next ;
        slow=slow->next ;

    }while(fast!=slow) ;

    // if cycle's at head
    if(fast==head){

        while(slow->next!=head)
        slow=slow->next ;
        slow->next=NULL ;
        return;

    }

    fast=head ;

    while(fast->next!=slow->next){
        fast=fast->next ;
        slow=slow->next ;
    }

    slow->next=NULL ;
}



void print(Node*head)
{
	while(head!=NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main(){

	Node*head = NULL;


	create(head, 1);
	create(head, 2);
	create(head, 3);
	create(head, 4);
	create(head, 5);
	create(head, 6);
	create(head, 7);
	create(head, 8);
	create(head, 9);
 	
 	print(head);

 	makeCycle(head,1);
    // print(head);
 	cout << detectCycle(head) << endl;

 	removeCycle(head);
 	cout << detectCycle(head) << endl;

 	print(head);
}