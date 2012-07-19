#include<iostream>
#include <conio.h>
#include<string>
#include<hash_map>

using namespace std;
using namespace stdext;

class Node
{

public:
	int data;
	Node* next;

	Node(int d)
	{
		data =d;
		next = NULL;
	}
};

class LinkedLists
{
	//using this everywhere..
	Node* head;

public:

#pragma region RemoveDuplicatesFromUnsortedLinkedList

	void RemoveDuplicatesFromUnsortedLinkedListWithoutAdditionalBuffer(Node* lHead)
	{
		Node* curr = lHead->next;
		Node* prev = lHead;
		Node* runner = lHead;
		
		while(curr)
		{
			bool found= false;
			while(runner!=curr)
			{
				if(runner->data == curr->data)
					found = true;
				runner = runner->next;
			}
			if (found)
				curr = curr->next;
			else
			{
				prev->next = curr;
				prev = curr;
				curr = curr->next;
			}
			found = false;
			runner = lHead;
		}
		prev->next = NULL;

	}

	void RemoveDuplicatesFromUnsortedLinkedList(Node *lHead)
	{
		hash_map<int, bool> listData;
		Node* cur = lHead->next;		
		Node* prev = lHead;

		listData[lHead->data] = true;
		while(cur)
		{
			if(listData[cur->data])
				cur = cur->next;
			else
			{
				listData[cur->data] = true;
				prev->next = cur;
				prev = cur;
				cur = cur->next;
			}
		}
		prev->next = NULL;

	}

	void RemoveDuplicatesFromUnsortedLinkedListControlFunction()
	{
		CreateLinkedListControlFunction();

		int choice;
		cout<<"\nEnter 1 for using additional buffer, 2 for not....\n";
		cin>>choice;

		if (choice==1)
			RemoveDuplicatesFromUnsortedLinkedList(head);
		else
			RemoveDuplicatesFromUnsortedLinkedListWithoutAdditionalBuffer(head);

		cout<<"\nNew linked list is...\n";
		PrintLinkedList();
		

	}
#pragma endregion

#pragma region RemoveNthFromLastElementInLinkedList


	Node* FindNthFromLastElementInLinkedListControlFunction(int n, Node* start)
	{
		Node* nFromLast = start;
		Node* curr = start;
		int count =1;
		while(count<=n)
		{
			if(curr == NULL)
			{
				cout<<"Not enough elements";
				return NULL;
			}
			curr= curr->next;		
			count++;
		}
		while(curr!=NULL)
		{
			nFromLast = nFromLast->next;
			curr= curr->next;
		}
		return nFromLast;

	}

	void FindNthFromLastElementInLinkedListControlFunction()
	{
		CreateLinkedListControlFunction();
		int n;
		cout<<"\nEnter which element NO. from last would you like to find\n";
		cin>>n;
		Node * nFromLast = FindNthFromLastElementInLinkedListControlFunction(n,head);
		cout<<"\nThe "<<n<<"th element from last is.."<<nFromLast->data;
	}

#pragma endregion

#pragma region RemoveAnElementWhenOnlyGivenAccessToThatElement


	void RemoveAnElementWhenOnlyGivenAccessToThatElement(Node* nElement)
	{	
		Node* curr = nElement;
		Node* nextElement = nElement->next;

		while(nextElement->next!=NULL)
		{
			curr->data = nextElement->data;
			nextElement = nextElement->next;
			curr = curr->next;	
		}
		curr->data  = nextElement->data;	
		curr->next = NULL;
		delete nextElement;

	}

	void RemoveAnElementWhenOnlyGivenAccessToThatElementControlFunction()
	{	
		CreateLinkedListControlFunction();
		int n;
		cout<<"\nWhich element number would you like to remove?\n";
		cin>>n;

		int count = 1;
		Node* nElement = head;
		while(count<n)
		{
			nElement = nElement->next;
			count++;
		}

		RemoveAnElementWhenOnlyGivenAccessToThatElement(nElement);

		PrintLinkedList();

	}
#pragma endregion

#pragma region AddTwoLinkedLists

	void AddTwoLinkedLists(Node* head1, Node* head2, Node* sumList)
	{
		int carry = 0;

		while(head1 && head2)
		{
			int sum = head1->data + head2->data + carry;
			carry = sum/10;
			sum = sum%10;
			Node* nnode = new Node(sum);
			nnode->next = sumList;
			sumList = nnode;
			head1 = head1->next;
			head2 = head2->next;
		}

		while(head1)
		{
			int sum = head1->data + carry;
			carry = sum/10;
			sum = sum%10;
			Node* nnode = new Node(sum);
			nnode->next = sumList;
			sumList = nnode;
			head1 = head1->next;			
		}

		while(head2)
		{
			int sum =  head2->data + carry;
			carry = sum/10;
			sum = sum%10;
			Node* nnode = new Node(sum);
			nnode->next = sumList;
			sumList = nnode;
			head2 = head2->next;
		}

		if(carry > 0)
		{
			Node* nnode = new Node(carry);
			nnode->next = sumList;
			sumList = nnode;
			head2 = head2->next;
		}

		head = sumList;
	}

	void AddTwoLinkedListsControlFunction()
	{
		Node* head1;
		Node* head2;
		CreateLinkedListControlFunction();
		head1 = head;

		CreateLinkedListControlFunction();
		head2 = head;

		head = NULL;
		AddTwoLinkedLists(head1,  head2,  head);

		cout<<"\nThe added result is :";
		PrintLinkedList();

	}


#pragma endregion

#pragma region FindLinkedListLoop

	Node* FindLinkedListLoop()
	{
		Node* ptr1 = head;
		Node* ptr2 = head;

		while(ptr2)
		{		
			ptr2 = ptr2->next->next;
			ptr1 = ptr1->next;
			if (ptr1 == ptr2)
				break;			
		}

		if (ptr2 == NULL)
		{
			cout<<"There are no loops";
			return NULL;
		}

		ptr1 = head;

		while(ptr1!=ptr2)
		{
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}

		return ptr1;
	}

	void FindLinkedListLoopControlFunction()
	{
		CreateLinkedListControlFunction();
		
		Node* curr = head;
		Node* end = head;
		int count = 1;

		cout<<"\nCreating a loop at 3rd element..\n";

		while(count<3)
		{
			curr = curr->next;
			++count;
		}

		end = curr;
		while(end->next !=NULL)
			end= end->next;

		end->next = curr;

		Node* loopBegining = FindLinkedListLoop();
		cout<<"\nThe loop begins at :"<<loopBegining->data;
	}	

#pragma endregion

#pragma region CreateLinkedList
	 
	Node* CreateLinkedList(int a[], int size)
	{
		Node *currHead = NULL;
		Node *curr = NULL;
		for(int i=0;i<size;i++)
		{
			Node* nnode= new Node(a[i]);
			if (currHead == NULL)
			{
				currHead = nnode;
				(*currHead).next = NULL;
				curr = currHead;
			}
			else
			{
			 (*curr).next = nnode;			
			 curr = nnode;
			}
		}
		return currHead;
	}

	void CreateLinkedListControlFunction()
	{
		int n;
		
		cout<<"\nCreate a linked list..Enter the size of the linked list..\n";
		cin>>n;

		int* a = new int[n];

		cout<<"\nEnter the elements of linked list..\n";
		for(int i=0;i<n;i++)
			cin>>a[i];

		head = CreateLinkedList(a,n);
		cout<<"\nPrinting linked list..\n";
		PrintLinkedList();


	}

	void PrintLinkedList()
	{
		Node* curr = head;
		
		while(curr)
		{
			cout<<(*curr).data<<' ';
			curr= (*curr).next;
		}
	}
	
#pragma endregion

};