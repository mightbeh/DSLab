#include<iostream.h>
#include<process.h>
#include<conio.h>
#include<alloc.h>
struct node
{
  int data;
  struct node* next;
};
node *head=NULL, *newnode, *temp;
void create();
void display();
int search(int);
void insert();
void ins_beg();
void ins_middle();
void ins_end();
void del();
void del_beg();
void del_middle();
void del_end();

void main()
{
  char ex;
  int key, choice;
  clrscr();
  do
  {
    clrscr();
    cout<<"\n\n---------------------SLL MENU-------------------------";
    cout<<"\n1) Create\n2) Display\n3) Insert\n4) Delete\n5) Search\n6) Exit";
    cout<<"\nEnter your choice: ";cin>>choice;
    cout<<"------------------------------------------------------";
    switch(choice)
    {
       case 1: create();
	 break;
       case 2: display();
	 break;
       case 3: insert();
	 break;
       case 4: del();
	 break;
       case 5:
	 cout<<"\nEnter Key Value: ";cin>>key;
	 if(search(key))
	   cout<<"\nKey found";
	 else
	   cout<<"\nKey not found";
	 break;
       case 6: exit(1);
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
    head->next=NULL;
    temp = head;
    cout<<"\nNew List Created, Node created.";
  }
  else
  {
    for(temp = head;temp->next!=NULL;temp=temp->next);
    temp->next=newnode;
    temp->next->next=NULL;
    cout<<"\nNew node created.";
  }
  display();
}
void display()
{
  cout<<"The List:\n";
  for(temp=head;temp!=NULL;temp=temp->next)
    cout<<temp->data<<" ->";
  cout<<"NULL";
}
void insert()
{
  int ic;
  clrscr();
  cout<<"\n\n-----------------------SLL MENU----------------------------";
  cout<<"\n\n--------------------INSERT SUBMENU-------------------------";
  cout<<"\n1) Insert Begin\n2) Insert Middle\n3) Insert End\n";
  cout<<"\nEnter your choice: ";cin>>ic;
  cout<<"---------------------------------------------------------------";
  switch(ic)
  {
    case 1:
	ins_beg();
	break;
    case 2:
	ins_middle();
	break;
    case 3:
	ins_end();
	break;
    default:
	cout<<"\nInvalid Choice!!!";
  }
}
void ins_beg()
{
  newnode=(node*)malloc(sizeof(node));
  cout<<"\nEnter value: "; cin>>newnode->data;
  newnode->next =head;
  head = newnode;
}
void ins_middle()
{
  int key;
  cout<<"\nEnter Key: "; cin>>key;
  if(search(key))
  {
     newnode=(node*)malloc(sizeof(node));
     cout<<"\nEnter Data: ";cin>>newnode->data;
     newnode->next = temp->next;
     temp->next = newnode;
  }
  else
  {
     cout<<"Key value not found";
  }
}
void ins_end()
{
  for(temp=head;temp->next!=NULL;temp=temp->next);
  newnode=(node*)malloc(sizeof(node));
  cout<<"Enter Data: "; cin>>newnode->data;
  newnode->next = NULL;
  temp->next=newnode;

}
void del()
{
  int dc;
  clrscr();
  cout<<"\n\n-----------------------SLL MENU----------------------------";
  cout<<"\n\n--------------------DELETE SUBMENU-------------------------";
  cout<<"\n1) Delete Begin\n2) Delete Middle\n3) Delete End\n";
  cout<<"\nEnter your choice: ";cin>>dc;
  cout<<"---------------------------------------------------------------";
  switch(dc)
  {
    case 1:
	del_beg();
	break;
    case 2:
	del_middle();
	break;
    case 3:
	del_end();
	break;
    default:
	cout<<"\nInvalid Choice!!!";
  }
}
void del_beg()
{
  node *todel;
  todel=head;
  head=head->next;
  free(todel);
  cout<<"\nFirst Node Deleted.";
  display();
}
void del_middle()
{
  int key;
  cout<<"\nEnter Key Valur: ";cin>>key;
  if(search(key))
  {
     for(temp=head;temp->next->data!=key;temp=temp->next);
     node *todel;
     todel = temp->next;
     temp->next=temp->next->next;
     free(todel);
     cout<<"\nDeleted";
     display();
  }
  else
  {
     cout<<"\nInvlaid Key Value";
  }
}
void del_end()
{
  node *todel;
  for(temp=head;temp->next->next!=NULL;temp=temp->next);
  todel=temp->next;
  temp->next=NULL;
  free(todel);
  cout<<"\nLast Node Deleted.";
  display();
}
int search(int key)
{
  for(temp=head;temp!=NULL;temp=temp->next)
  {
    if(temp->data==key)
      return 1;
  }
  return 0;
}
