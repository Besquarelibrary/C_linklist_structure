#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int ID;
    char Name[20];
    int Day;
    int Month;
    int Year;
    struct Node* next;
};

void linkedListTraversal(struct Node* ptr)
{
    while (ptr != NULL)
	{
    	printf("Employee ID NO  : %d\n", ptr->ID);
        printf("           Name : %s\n", ptr->Name);
        printf("           Join Date : %02d/%02d/%04d\n", ptr->Day, ptr->Month, ptr->Year);

		ptr = ptr->next;
    }
}

struct Node* insertAtFirst(struct Node* head) {
    printf("Enter New Employee data\n");
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter New Employee ID :\n");
    scanf("%d", &new->ID);
    printf("Enter New Employee name :\n");
    scanf("%s", new->Name);

    // Get valid day input from user
    int valid_day = 0;
    while (!valid_day) {
        printf("Enter the day of joining In : DD Format\n");
        scanf("%d", &new->Day);
        if (new->Day < 1 || new->Day > 31) {
            printf("Invalid day entered. Please enter a value between 1 and 31 in DD formate.\n");
        } else {
            valid_day = 1;
        }
    }

    // Get valid month input from user
    int valid_month = 0;
    while (!valid_month) {
        printf("Enter the month of joining In : MM Format\n");
        scanf("%d", &new->Month);
        if (new->Month < 1 || new->Month > 12) {
            printf("Invalid month entered. Please enter a value between 1 and 12.\n");
        } else {
            valid_month = 1;
        }
    }

    // Get valid year input from user
    int valid_year = 0;
    while (!valid_year) {
        printf("Enter the year of joining in : YYYY Format\n");
        scanf("%d", &new->Year);
        if (new->Year < 1900 || new->Year > 2023) {
            printf("Invalid year entered. Please enter a value between 1900 and 2023.\n");
        } else {
            valid_year = 1;
        }
    }

    new->next = head;
    head = new;
    return head;
}


struct Node * insertAtEnd(struct Node *head){
   	printf("Enter New Employee data\n");
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    printf("Enter New Employee ID :\n");
    scanf("%d", &ptr->ID);
    printf("Enter New Employee name :\n");
    scanf("%s", ptr->Name);
    int valid_day = 0;
    while (!valid_day) {
        printf("Enter the day of joining In:  DD Format\n");
        scanf("%d", &ptr->Day);
        if (ptr->Day < 1 || ptr->Day > 31) {
            printf("Invalid day entered. Please enter a value between 1 and 31.\n");
        } else {
            valid_day = 1;
        }
    }

    // Get valid month input from user
    int valid_month = 0;
    while (!valid_month) {
        printf("Enter the month of joining In : MM Format\n");
        scanf("%d", &ptr->Month);
        if (ptr->Month < 1 || ptr->Month > 12) {
            printf("Invalid month entered. Please enter a value between 1 and 12.\n");
        } else {
            valid_month = 1;
        }
    }

    // Get valid year input from user
    int valid_year = 0;
    while (!valid_year) {
        printf("Enter the year of joining In : YYYY Format\n");
        scanf("%d", &ptr->Year);
        if (ptr->Year < 1900 || ptr->Year > 2023) {
            printf("Invalid year entered. Please enter a value between 1900 and 2023.\n");
        } else {
            valid_year = 1;
        }
    }
    
    struct Node * p = head ;
    

    while(p->next!=NULL)
    {
    	p = p->next; 
	}
	p->next = ptr;
	ptr->next = NULL;
	return head;

}

struct Node * insertInMiddle(struct Node *head ){
	int index ;
	printf("ENTER THE INDEX WHICH YOU WANT TO CHANGE :\n");
	scanf("%d",&index);
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    
    
    struct Node * p = head ;
    int i = 0;
    
   
    
    while(i!=index-1)
    {
    	p = p->next;
    	i++;
	}
    printf("Enter New Employee data\n");
    //struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter New Employee ID :\n");
    scanf("%d", &ptr->ID);
    printf("Enter New Employee name :\n");
    scanf("%s", ptr->Name);
   int valid_day = 0;
    while (!valid_day) {
        printf("Enter the day of joining In : DD Format\n");
        scanf("%d", &ptr->Day);
        if (ptr->Day < 1 || ptr->Day > 31) {
            printf("Invalid day entered. Please enter a value between 1 and 31.\n");
        } else {
            valid_day = 1;
        }
    }

    // Get valid month input from user
    int valid_month = 0;
    while (!valid_month) {
        printf("Enter the month of joining In : MM Format\n");
        scanf("%d", &ptr->Month);
        if (ptr->Month < 1 || ptr->Month > 12) {
            printf("Invalid month entered. Please enter a value between 1 and 12.\n");
        } else {
            valid_month = 1;
        }
    }

    // Get valid year input from user
    int valid_year = 0;
    while (!valid_year) {
        printf("Enter the year of joining In : YYYY Format\n");
        scanf("%d", &ptr->Year);
        if (ptr->Year < 1900 || ptr->Year > 2023) {
            printf("Invalid year entered. Please enter a value between 1900 and 2023.\n");
        } else {
            valid_year = 1;
        }
    }
    
    ptr->next= p->next;
    p->next= ptr;
    return head;

}

// Function to delete the first node of a linked list
struct Node * deleteFromStart(struct Node *head) {
    if (head == NULL) {
        printf("List is already empty\n");
        return head;
    }

    struct Node * temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete the last node of a linked list
struct Node * deleteFromEnd(struct Node *head) {
    if (head == NULL) {
        printf("List is already empty\n");
        return head;
    }
    
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->next!=NULL)
    {
    	p = p->next;
    	q = q->next;
	}
	p->next= NULL;
	free(q);
	return head;
    
}

// Function to delete a node from a specified index in a linked list
struct Node * deleteFromIndex(struct Node *head) {
	int index ;
	printf("ENTER THE INDEX WHICH YOU WANT TO CHANGE :\n");
	scanf("%d",&index);
	
    if (head == NULL) {
        printf("List is already empty\n");
        return head;
    }
    
    struct Node *p = head;
    struct Node *q = head->next;
    for(int i=0;i<index-1;i++)
    {
    	p = p->next;
    	q = q->next;
	}
	p->next= q->next;
	free(q);
	return head;
}

int main()
{
	int ch ;
	char choice;
	
    struct Node* head = NULL;
    struct Node* current = NULL;
    
    // Create 10 nodes using a for loop and get user input for each node
    for(int i = 1; i <= 10; i++) {
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for Employee :  \n");
        printf("ID : ");
        scanf("%d", &node->ID);
        //strcpy(node->Name, i);
        printf("Name: ");
        scanf("%s", node->Name);
        int valid_day = 0;
    while (!valid_day) {
        printf("Enter the day of joining In : DD Format\n");
        scanf("%d", &node->Day);
        if (node->Day < 1 || node->Day > 31) {
            printf("Invalid day entered. Please enter a value between 1 and 31 in DD formate.\n");
        } else {
            valid_day = 1;
        }
    }

    // Get valid month input from user
    int valid_month = 0;
    while (!valid_month) {
        printf("Enter the month of joining In : MM Format\n");
        scanf("%d", &node->Month);
        if (node->Month < 1 || node->Month > 12) {
            printf("Invalid month entered. Please enter a value between 1 and 12.\n");
        } else {
            valid_month = 1;
        }
    }

    // Get valid year input from user
    int valid_year = 0;
    while (!valid_year) {
        printf("Enter the year of joining In : YYYY Format\n");
        scanf("%d", &node->Year);
        if (node->Year < 1900 || node->Year > 2023) {
            printf("Invalid year entered. Please enter a value between 1900 and 2023.\n");
        } else {
            valid_year = 1;
        }
    }

        node->next = NULL;
        
        // Add the node to the linked list
        if(head == NULL) {
            head = node;
            current = node;
        } else {
            current->next = node;
            current = node;
        }
    }
    
    // Print the linked list
    printf("Linked List:\n");
    current = head;
    while(current != NULL) {
        printf("ID: %d\n", current->ID);
        printf("Name: %s\n", current->Name);
        printf("Join Date : %02d/%02d/%04d\n", current->Day, current->Month, current->Year);
        printf("\n");
        current = current->next;
    }

    //printf("\nLinked list before Change\n");
    //linkedListTraversal(first);
    
    do {
    printf("\n");
    printf ( "			1. ADD NODE FIRST IN LINK \n " ) ;  
    printf ( "			2. ADD NODE LAST IN LINK \n " ) ;  
    printf ( "			3. ADD NODE AT FIX INDEX IN LINK \n " ) ;  
    printf ( "			4. DELETE NODE AT FIRST IN LINK \n " ) ;  
    printf ( "			5. DELETE NODE AT LAST IN LINK \n " ) ;  
    printf ( "			6. DELETE NODE AT FIX INDEX IN LINK \n " ) ;
	printf ( "			7. PRINT THE EMPLOYEE DATA \n " ) ; 
    printf ( "			8. EXIT OFF \n " ) ;
            
	
    printf ( "ENTER THE CHOICE \n " ) ;  
    scanf ( " %d" , &ch ) ;
    
     switch (ch )  
    {  
        case 1 :  
            head = insertAtFirst(head);  
            break ;  
        case 2 :  
            head = insertAtEnd(head);  
            break ;  
        case 3 :  
            head = insertInMiddle(head);  
            break ;  
        case 4 :  
           	head = deleteFromStart(head);  
            break ;  
        case 5 :  
            head = deleteFromEnd(head);  
            break ;  
        case 6 :  
            head = deleteFromIndex(head);  
            break ;
		case 7 :  
            linkedListTraversal(head);  
            break ;  
        case 8 :  
            exit( 0 ) ;  
            break ;
    	default :  
            printf ( " Not available \n " ) ;
   	}
   	
   	
//   	printf("\nLinked list after change\n");
//    linkedListTraversal(head);
    
    printf("Do you want to continue (y/n)? ");
    scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
	
}
