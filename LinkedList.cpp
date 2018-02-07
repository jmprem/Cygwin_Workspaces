#include <iostream>

using namespace std;

typedef struct Node
{
	uint32_t data;
	struct Node *next;
}NODE;

void print_ll(NODE *head)
{
	NODE *temp = head;
	
	while(head != NULL)
	{
		cout << head->data << endl;
		head = head->next;
	}
	
	head = temp;
}

bool find_ll(NODE *head, uint32_t data)
{
	NODE *temp = head;
	bool found = false;
	
	while(head != NULL)
	{
		if(head->data == data)
		{
			found = true;
			break;
		}
		head = head->next;
	}
	
	head = temp;
	return found;
}

void insert_ll(NODE *head, uint32_t data)
{
	NODE *temp = head;
	
	NODE *newNode = (NODE *)malloc(sizeof(NODE));
	newNode->data = data;
	newNode->next = head;
	head = newNode;
}

//Delete All instances
void delete_ll(NODE **head, uint32_t data)
{
	NODE *temp = *head;
	NODE *prevNode = NULL;
	
	//Check for head match. Special Condition
	while((temp != NULL) && (temp->data == data))
	{
		(*head)= temp->next;
		free(temp);
		temp = *head;
	}
	
	while(temp != NULL)
	{
		if(temp->data != data)
		{
			prev=temp; 
			temp=temp->next;
		}
		else
		{
			prev->next = temp->next;
			free(temp);
			temp= prev->next;
		}
	}
}

void merge_sorted_ll(Node **head1, Node **head2)
{
	Node *list1 = *head1;
	Node *list2 = *head2;
	Node **newHead = head1;
	
	if(list1->data < list2->data)
	{
		while(list1->data < list2->data)
			list1 = list1->next;
		list2->next = list1;
	}
	else
	{
		while(list1->data > list2->data)
		{
			newHead = head2;
			list2 = list2->next;
		}
		prev = list2->next;
		list2->next = list1;
		list1 = list1->next;
		list2 = prev;
	}
	
	while(list1 && list2)
	{
		while(list1->data > list2->data)
			list2 = list2->next;

		prev = list2->next;
		list2->next = list1;
		list1 = list1->next;
		list2 = prev;
	}
	
}

int main(int argc, char *argv[])
{
	
	return 0;
}