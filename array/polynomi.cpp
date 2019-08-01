#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
using namespace std;
void create1();
void create2();
void display();
void add();
struct node{
	int data;
	int exp;
	struct node* next;
};
node* head1=NULL,*head2=NULL,*newnode,*temp1,*temp2,*temp,*head=NULL;
int main()
{
	char ch;
	int c;
	do{
		cout<<"Doubly linked list \n";
		cout<<"==================\n";
		cout<<"1.Create1 \n2.Create2 3.Display\n";
		cout<<"Enter the choice : ";
		cin>>c;
		switch(c){
			case 1:
				cout<<"eq1 :" ;
				create1();
				break;
			case 2:
				cout<<"eqn 2 :";
				create2();
				break;
			case 3:
				add();
				display();
				break;
		}
		cout<<"\nDo you want to continue : (y/n)";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
	return 0;
}
void create1(){
	newnode = (node*)malloc(sizeof(node));
	cout<<"Enter the coefficient : ";
	cin>>newnode->data;
	cout<<"Enter the exponent : ";
	cin>>newnode->exp;
	newnode->next=head1;
	head1=newnode;
}
void create2(){
	newnode = (node*)malloc(sizeof(node));
	cout<<"Enter the coefficient : ";
	cin>>newnode->data;
	cout<<"Enter the exponent : ";
	cin>>newnode->exp;
	newnode->next=head2;
	head2=newnode;
}
void add(){
	int pass=0;
	temp1=head1;
	temp2=head2;
	newnode = (node*)malloc(sizeof(node));
	while(temp1->next!=NULL)
	{
		while(temp2->next!=NULL){

		
		if(temp1->exp==temp2->exp)
		{	
			newnode->data=temp1->data+temp2->data;
			newnode->exp=temp1->exp;
			newnode->next=head;
			head=newnode;
			pass=1;
		}
		temp2=temp2->next;
	}
	if(pass==0)
	{
		newnode->data=temp1->data;
		newnode->exp=temp1->exp;
		newnode->next=head;
		head=newnode;
	}
	temp2=head2;
	temp1=temp1->next;
	pass=0;
	}	
}
void display()
 {
	cout<<"Polynomial eq1 : \n";
	temp=head1;
	while(temp!=NULL){
		cout<<"\t"<<temp->data<<"x"<<temp->exp<<"\t";
		temp=temp->next;
	}
	cout<<"NULL\n";
	cout<<"Polynomial eq2 : \n";
	temp=head2;
	while(temp!=NULL){
		cout<<"\t"<<temp->data<<"x"<<temp->exp<<"\t";
		temp=temp->next;
	}
	cout<<"NULL\n";
	cout<<"Polynomial sum : \n";
	temp=head;
	while(temp!=NULL){
		cout<<"\t"<<temp->data<<"x"<<temp->exp<<"\t";
		temp=temp->next;
	}
	cout<<"NULL\n";
}
