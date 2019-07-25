#include<iostream.h>
#include<conio.h>
void init();
void insert();
void del();
int isEmpty();
int isFull();
void emptySlot();
void search();
void rmDup();
void display();

int arr[10], cnt = 0;

int main()
{
	char brk;
	int ch;
	init();
	do{clrscr();
	cout<<"1) Insert\n2) Delete\n3) Search\n4) Remove Duplicate\n5) Display\n6) Exit\n Enter Your Choice: ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			insert();
			break;
		case 2:
			del();
			break;
		case 3:
			search();
			break;
		case 4:
			rmDup();
			break;
		case 5:
			display();
			break;
		default:
			cout<<"\nEnter correct choice!!!\n";
	}cout<<"\nDo you want to continue: ";cin>>brk;
	}while(brk!='n');
	getch();
	return 0;
}

void init()
{
	for(int i=0;i<10;i++)
		arr[i] = -99;
}
void insert()
{
	int loc, ele;
	if(isFull()){
		cout<<"\nThe Array is Full, Delete a few.";
	}
	else
	{
		emptySlot();
		cout<<"\nEnter the location: "; cin>>loc;
		if (loc>=0 && loc<=9)
		{
			if(arr[loc]==-99)
			{
				cout<<"\nEnter the Value: "; cin>>ele;
				arr[loc] = ele;
				cnt++;
				cout<<"\nInserted.";
				display();
			}
			else cout<<"\nThe location is occupied.";
		}
		else cout<<"\nIndex out of bound.";
	}

}
void del()
{ 	int loc;
	if(isEmpty())
	{
	 cout<<"\nArray is Empty.";
	}
	else
	{
		cout<<"\nEnter the Location: "; cin>>loc;
		if(loc>=0 &&loc<=9)
		if(arr[loc]!=-99)
		{
		 arr[loc] = -99;
		 cnt--;
		 cout<<"\nLocation Element Deleted.";
		 display();
		}
		else
		{
		 cout<<"\nElement not available.";
		}
	}
}
int isEmpty()
{
	if(cnt==0)
	 return 1;
	else
	 return 0;
}
int isFull()
{
	if(cnt==10)
	 return 1;
	else
	 return 0;
}
void emptySlot()
{
	cout<<"\nThe Empty Locations are: ";
	for(int i=0;i<10;i++)
		if(arr[i]!= -99) cout<<i<<"\t";
}
void search()
{       int loc,tmp;
	cout<<"\nEnter the Element: "; cin>>loc;
	for(int i=0;i<10;i++)
	{
	 if(arr[i] == loc)
		tmp = i;
	}
	cout<<"\nThe location is: "<<tmp;
}
void rmDup()
{
	 int a[10]={-99,-99,-99,-99,-99,-99,-99,-99,-99,-99};
	 int l=0;
	 for(int i=0;i<10;i++)
	 {
	 int k=0;
	 for(int j=0;j<10;j++)
	 {
		if(arr[i]==a[j]&&arr[i]!=-99){
		arr[i]=-99;k=1;
		}
	  }
	  if(k==0&&arr[i]!=-99)
	  {
		a[l]=arr[i];l++;
	 }}
}

void display()
{
	cout<<"\nThe Elements are: ";
	for(int i=0;i<10;i++)
		cout<<"  "<<arr[i];
}
