#include<iostream.h>
#include<process.h>
#include<conio.h>
#include<alloc.h>
struct node
{
  int data;
  struct node* next;
};
node *last=NULL, *head=NULL, *newnode, *temp;
void create();
void display();

void main()
{
  char ex;
  int key, choice;
  clrscr();
  do
  {
    clrscr();
    cout<<"\n\n---------------------SLL MENU-------------------------";
    cout<<"\n1) Create\n2) Display\n3) Exit";
    cout<<"\nEnter your choice: ";cin>>choice;
    cout<<"------------------------------------------------------";
    switch(choice)
    {
       case 1: create();
	 break;
       case 2: display();
	 break;
       case 3: exit(1);
       default:
	 cout<<"\nInvalid Choice!!";
    } cout<<"\nDo you Want to continue: "; cin>>ex;
  }while(ex!='n');
}
void create()
{
  newnode = (node *)malloc(sizeof(node));
  cout<<"\nEnter data value: "; cin>>newnode->data;
  if(head==NULL)
  {
    head = newnode;
    last = newnode;
    newnode->next=head;
    cout<<"\nNew List Created, Node created.";
  }
  else
  {
    newnode->next=head;
    last->next=newnode;
    last = newnode;
    cout<<"\nNew node created.";
  }
  display();
}
void display()
{
  cout<<"\nThe List:\n";
  temp = head;
  do
  {
    cout<<temp->data<<"->";
    temp=temp->next;
  }while(temp!=head);
  cout<<"head";
}