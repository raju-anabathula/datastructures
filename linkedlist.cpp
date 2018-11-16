#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node* link;
} Node;

Node* root;

void append()
{
    Node* temp = new Node;
    cout << "Enter data:";
    cin >> temp->data;
    
    temp->link = NULL;
    
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        Node* p = root;
        while(p->link != NULL)
        {
            p = p->link;
        }
        
        p->link = temp;
    }
    cout << "Node inserted data is: " << temp->data << endl;
}

void insertAtBegin()
{
    Node* temp = new Node;
    cout << "Enter data:";
    cin >> temp->data;
    
    temp->link = NULL;
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        temp->link = root;
        root = temp;
    }
    cout << "Node inserted data is: " << root->data << endl;
}

int length()
{
    int count = 0;
    Node *p = NULL;
    
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        p = root;
        while(p != NULL)
        {
            count ++;
            p = p->link;
        }
        return count;
    }
}
void print()
{
    if(root == NULL)
    {
        cout << "Linked list is empty\n";
    }
    else
    {
        Node *p = root;
        while(p != NULL)
        {
            cout << p->data << "-->";
            p = p->link;
        }
        cout << endl;
    }
}

void insertAtAfter()
{
    int loc = 0;
    
    cout << "Enter location:";
    cin >> loc;
    
    if(loc > length())
    {
        cout << "The given location is not present in LL.\n";
        cout << "Nodes in the list are:";
        print();
    }
    else
    {
        Node *temp = new Node;
        temp->link = NULL;
        cout << "Enter data:";
        cin >> temp->data;
        
        // Traverse to index
        Node *p = root;
        int i = 1;
        while(i < loc)
        {
            p = p->link;
            i++;
        }
        
        temp->link = p->link;
        p->link = temp;
    }
}

void deleteAt()
{
    int loc;
    cout << "Enter location to delete:";
    cin >> loc;
    
    int len = length();
    
    if(loc > len)
    {
        cout << "Invalid location given.";
    }
    else if(loc == 1)
    {
        Node *temp = root;
        root = temp->link;
        
        temp->link = NULL;
        free(temp);
    }
    else
    {
        Node *p = root;
        int i = 1;
        
        if(i < (loc -1))
        {
            p = p->link;
            i++;
        }
        
        Node *q = p->link;
        p->link = q->link;
        
        q->link = NULL;
        free(q);
    }
}

int main() 
{
    int option;
	
	while(1)
	{
	    cout<<"LL operations:\n"
	<< "1. Append\n"
	<< "2. Prepend\n"
	<< "3. insert At After\n"
	<< "4. Delete\n"
	<< "5. Print\n"
	<< "Enter option:";
	cin >> option;
	switch(option)
	{
	    case 1:
	        append();
	    break;
	    case 2:
	        insertAtBegin();
	    break;
	    case 3:
	        insertAtAfter();
	    break;
	    case 4:
	        deleteAt();
	    break;
	    case 5:
	        cout << "Length:" << length() << endl;
	        print();
	    break;
	    default:
	    cout << "Invalid option\n";
	    break;
	}
	}
	return 0;
}

