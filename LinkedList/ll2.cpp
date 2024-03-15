#include <bits/stdc++.h>
using namespace std;
class Node{
	public:
	int data;
	Node* next;

	Node(int data){
		this->data=data;
		this->next=NULL;
	}
};
void inserthead(Node* &head, int d){
	Node* temp = new Node(d);
	temp->next=head;
	head=temp;
}
void print(Node* &head){
	Node* temp=head;
	while (temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
signed main(){
	Node* node1=new Node(10);
	Node* head=node1;
	print(head);
	inserthead(head,12);
	inserthead(head,13);
	print(head);
	inserthead(head,14);
	print(head);
}