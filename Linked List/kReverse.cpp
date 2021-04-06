#include <iostream>
using namespace std;

class Node {

public:
	int data;
	Node*next;

	Node(int d){
		data = d;
		next = NULL;
	}


};

void create(Node*&head, int d){

	if(head==NULL)
	{
		head = new Node(d);
		return;
	}

	 	Node*tail = head;
	 	while(tail->next!=NULL)
	 	{
	 		tail = tail->next;
	 	}

		Node *n = new Node(d);
		tail->next = n;
		return;

}

Node* krev(Node *&head, int k){
        // base case
        if (!head)
            return NULL;

        Node*p = head;
        Node*q = NULL;

        Node*next = NULL;

        int cnt = 0;
        while (p != NULL and cnt < k)
        {
            next = p->next;

            p -> next = q;
            q = p;
            p = next;

            cnt++;
        }

        // next points to (k+1)th node

        if (next != NULL)
            head->next = krev(next, k);

        return q;
}

void print(Node*head){

	while(head!=NULL)
	{
		cout << head->data<<" ";
		head = head->next;
	}
	cout << endl;
}

int main(){
	Node*head = NULL;
	int K=3;

	// cin >> N;

	// for(int i=0;i<N;i++)
	// {
	// 	int ele;
	// 	cin >> ele;
	// 	create(head, ele);

	// }

	create(head, 1);
	create(head, 2);
	create(head, 3);
	create(head, 4);
	create(head, 5);
	create(head, 6);
	create(head, 7);
	create(head, 8);
	create(head, 9);
	create(head, 10);

	print(head);

	head = krev(head,3);
	print(head);
}