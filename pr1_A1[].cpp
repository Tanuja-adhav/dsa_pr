#include<iostream>
#include<string.h>
using namespace std;
struct node
{
	int value ;
	node*next;
}
*HashTable[10];
class hashing
{
	public:
	hashing()
	{
		for (int i=0;i<10;i++)
		{
			HashTable[i]=NULL;	
		}	
	}
	int HashFunction(int value)
	{
		return (value%10);
	}
	node*create_node(int x)
	{
		node*temp=new node;
		temp->next=NULL;
		temp->value=x;
		return temp;	
	}	
	void display()
	{
		for (int i=0;i<10;i++)
		{
			node*temp=new node;
			temp=HashTable[i];
			cout<<"a["<<i<<"]:";
			while (temp!=NULL)
			{
				cout<<"->"<<temp->value;
				temp=temp->next;
			}
			cout<<"\n";
		}
	}
	int searchElement(int value)
	{
		bool flag=false;
		int hash_val=HashFunction(value);
		node*entry=HashTable[hash_val];
		cout<<"\n Enter found at:";
		while (entry!=NULL)
		{
			if(entry->value==value)
			{
				cout<<hash_val<<":"<<entry->value<<endl;
				flag=true;
			}
			entry=entry->next;
		}
		if(!flag)
		return -1;
	}
	void deleteElement(int value)
	{
		int hash_val=HashFunction(value);
		node*entry=HashTable[hash_val];
		if(entry==NULL)
		{
			cout<<"No element found";
			return;
		}
		if(entry->value==value){
			HashTable[hash_val]=entry->next;
			return;
		}
		while((entry->next)->value !=value)
		{
			entry=entry->next;
		}
		entry->next=(entry->next)->next;
	}
	void insertElement(int value)
	{
		int hash_val=HashFunction(value);          //node*prev=null , node*entry=HahTable[hash_val]
		node*temp=new node;
		node*head=new node;
		head=create_node(value);
		temp=HashTable[hash_val];
		if(temp==NULL){
			HashTable[hash_val]=head;
		}	
		else
		{
			while (temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=head;
		}
	}
};
int main()
{
	int ch;
	int data,search,del;
	hashing h;
	do
	{
		cout<<"\n Telephone:\n1.Insert\n2Display\n3.Search\n4.Delete\n5.Exit";
		cin>>ch;
		switch (ch)
		{
			case 1:
			cout<<"Enter Phone no to be inserted:";
			cin>>data;
			h.insertElement(data);
			break;
			
			case 2:
			h.display();
			break;
			
			case 3:
			cout<<"\nEnter the no to be searched:";
			cin>>search;
			if(h.searchElement(search)==-1)
			{
				cout<<"No element found at key";
				continue;
				}	
			break;
			case 4:
				cout<<"Enter the phone number to be deleted:";
				cin>>del;
				h.deleteElement(del);
				cout<<"Phone no deleted"<<endl;
				break;
		}
	}
	while(ch!=5);
	return 0;
}



/*struct data
{  
   char name[30];
   long teleno;
};
class hash
{  
   int n,sum,x,c,i,j;  //n=no of clients, x=index of hash table  
   char na[30]; 
   long no;
   data d[10];
   public:
   hash()
   {  for(i=0;i<10;i++)
      {  
		d[i].teleno=0;   
	  }
   }  
   void insert();
   void search();
   void display();
};
void hash ::insert()
{
  cout<<"\n enter no. of clients";
  cin>>n;    //d[x].name
  for(j=0;j<n;j++)
  {   cout<<"\n enter name of client";
      cin>>na;
      cout<<"\n enter telephone no. of client";
      cin>>no;
      sum=0;
      for(i=0;i<strlen(na);i++)
      {   sum=sum+na[i]; 
      }
      x=(sum/strlen(na))%10;           //%(key/num of data)
      cout<<x;
      c=x;
           while(1)
           {
          
               if(d[x].teleno==0)
               {   strcpy(d[x].name,na);
                   d[x].teleno=no;
                   break;
               }
                x=(x+1)%10;
              if(c==x)
              {  cout<<"\n hash table is full";
                  break;
              }   
           }

   }
}
void hash::search()
{  
   cout<<"\n enter name to be searched";
   cin>>na;
  
    sum=0;
      for(i=0;i<strlen(na);i++)
      {   sum=sum+(int)na[i]; 
      }
      x=(sum/strlen(na))%10;
      c=x;
   while(1)
           {
          
               if(!strcmp(d[x].name,na))
               {   cout<<"\n data found : TELEPHONE NO:"<<d[x].teleno;
                   break;
               }
                x=(x+1)%10;
              if(c==x)
              {  cout<<"\n data not found";
                  break;
              }   
           }
}          
void hash::display()
{
        for(int i=0;i<10;i++){
        cout<<endl<<d[i].name<<" "<<d[i].teleno;
        }


}
int main()
{
  hash h ;
  h.insert();
  h.search();
}
*/
