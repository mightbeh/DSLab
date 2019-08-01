#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>

void create1();
void create2();
void display();
void add();
struct node{
	int data;
	int exp;
	struct node* next;
};
node* head1=NULL,*head2=NULL,*newnode,*temp1,*temp2,*temp,*head=NULL,*ans;
int main()
{
	char ch;
	int c;
	int i,j;
	clrscr();
	do{
		cout<<"Polynomial Addition \n";
		cout<<"==================\n";
		cout<<"1.Create1 \n2.Create2\n 3.Add\n4.Display\n";
		cout<<"Enter the choice: ";
		cin>>c;
		switch(c){
			case 1:
				cout<<"\neq1 :" ;
				create1();
				break;
			case 2:
				cout<<"\neqn 2 :";
				create2();
				break;
			case 3:
				add();
				break;
			case 4:
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
	cout<<"\nEnter the coefficient : ";
	cin>>newnode->data;
	cout<<"\nEnter the exponent : ";
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
void add()
{
	int i;
	temp1=head1;
	temp2=head2;
	for(i=2;i>=0;i--)
	{
		ans = (node*)malloc(sizeof(node));
		if((i==temp1->exp)||(i==temp2->exp))
		{
			if(temp1->exp==temp2->exp)
			{
				ans->data=temp1->data+temp2->data;
				temp1=temp1->next;
				temp2=temp2->next;
				ans->exp=i;
			}
			else
			{
				if(temp1->exp==i)
				{
					ans->data=temp1->data;
					temp1=temp1->next;
					ans->exp=i;
				}
				else
				{
					ans->data=temp2->data;
					temp2=temp2->next;
					ans->exp=i;
				}
			}

			ans->next=head;
			head=ans;
		}
	}
}

void display()
 {
	cout<<"Polynomial eq1 : \n";
	temp=head1;
	while(temp!=NULL)
	{
		cout<<"\t"<<temp->data<<"x^"<<temp->exp<<"\t";
		temp=temp->next;
	}
	cout<<"NULL\n";
	cout<<"Polynomial eq2 : \n";
	temp=head2;
	while(temp!=NULL){
		cout<<"\t"<<temp->data<<"x^"<<temp->exp<<"\t";
		temp=temp->next;
	}
	cout<<"NULL\n";
	cout<<"Polynomial sum : \n";
	temp=head;
	while(temp!=NULL){
		cout<<"\t"<<temp->data<<"x^"<<temp->exp<<"\t";
		temp=temp->next;
	}
	cout<<"NULL\n";
}
