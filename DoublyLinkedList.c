// Ordered Doubly-LinkedList
#include <stdio.h>
#include <stdlib.h>

struct listNode {
	char data;
	struct listNode *nextPtr;
	struct listNode *prevPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

/*************
 * Develop this function at the bottom of this program
 * Insert a new node into the list.
 * The list should be always in ascending ordered. Therefore, the new node should be inserted into its correct position.
 */
void insert(ListNodePtr *sPtr, ListNodePtr *ePtr, char value);

/*************
 * Develop this function at the bottom of this program
 * Delete a node from the list.
 * If found and deleted, it returns the value of the deleted node.
 * Otherwise, returns '\0'
 */
char delete(ListNodePtr *sPtr, ListNodePtr *ePtr, char value);

/*************
 * Develop this function at the bottom of this program
 * Print the list in the reverse order (from the end of the list to the beginning of the list).
 */
void printListReverse(ListNodePtr currentPtr);

// Print out the list (Already developed)
void printList(ListNodePtr currentPtr);

// Check if the list is empty (Already developed)
int isEmpty(ListNodePtr sPtr);

// Selection menu (Already developed)
void menu(void);

int main(void) {

	// Two pointers for the beginning and ending of the linked list generated.
	ListNodePtr startPtr = NULL;
	ListNodePtr endPtr = NULL;
	char item;

	menu();
	printf("%s", "? ");
	unsigned int choice; // user's choice
	scanf("%u", &choice);

	while (choice != 5) {

		switch (choice) {
		case 1:
			/*************
			 * Complete this part:
			 * Prompt the user to input a character.
			 * Read the user's input.
			 * Then, insert the input character into the list.
			 * Then, print the linked list.
			 */
            printf("%s", "Enter a character: ");
            scanf("\n%c", &item);
            insert(&startPtr, &endPtr, item);
            printList(startPtr);
			break;
		case 2:
			/*************
			 * Complete this part:
			 * If the list is empty, print out a proper message and skip.
			 * Otherwise, prompt the user to input a character.
			 * Read the user's input.
			 * Then, delete the node that has the input character from the list, and print out a proper message.
			 * Then, print the linked list.
			 */
            if (!isEmpty(startPtr)){
                printf("%s", "Enter character to be deleted: ");
                scanf("\n%c", &item);
                
                if(delete(&startPtr, &endPtr, item)){
                    printf("%c deleted.\n", item);
                    printList(startPtr);
                }
                else {
                    printf("%c not found.\n\n", item);

                }
            }
            else {
                puts("List is empty.\n");
            }    
			break;
		case 3:
			/*************
			 * Complete this part:
			 * If the list is empty, print out a proper message and skip.
			 * Otherwise, print the linked list from the BEGINNING of the list.
			 */
			 if (!isEmpty(startPtr)){
                printList(startPtr);
			 }
			 else {
			     puts("List is empty.\n");
			 }
			break;
		case 4:
			/*************
			 * Complete this part:
			 * If the list is empty, print out a proper message and skip.
			 * Otherwise, print the linked list from the ENDING of the list.
			 */
            if (!isEmpty(startPtr)){
                printListReverse(startPtr);
                puts("NULL\n");
    		}
    		else {
    		    puts("22List is empty.\n");
    		}
			break;
		default:
			puts("Invalid choice.\n");
			break;
		} // end switch

		menu();
		printf("%s", "? ");
		scanf("%u", &choice);
	}

	puts("End of run.");
}

// display menu to the user (Already developed)
void menu(void) {
	puts("Enter your choice:\n"
			"   1 to insert an element into the list.\n"
			"   2 to delete an element from the list.\n"
			"   3 to print the list from the beginning.\n"
			"   4 to print the list from the end.\n"
			"   5 to end.");
}

// return 1 if the list is empty, 0 otherwise (Already developed)
int isEmpty(ListNodePtr sPtr) {
	return sPtr == NULL;
}

// print the list from the beginning (Already developed)
void printList(ListNodePtr currentPtr) {
	if (isEmpty(currentPtr)) {
		puts("List is empty.\n");
	} else {
		puts("The list is:");

		while (currentPtr != NULL) {
			printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
		}

		puts("NULL\n");
	}
}

void printListReverse(ListNodePtr currentPtr){
	// Base case   
    if (currentPtr == NULL) 
       return; 
  
    // print the list after current node 
    printListReverse(currentPtr->nextPtr); 
  
    // After everything else is printed, print currentPtr 
    printf("%c --> ", currentPtr->data);
}

/* Develop all the required functions from the function prototypes here: */
void insert(ListNodePtr *sPtr, ListNodePtr *ePtr, char value){
    ListNodePtr newPtr = malloc(sizeof(ListNode));
    
    if (newPtr != NULL){
        newPtr->data = value;
        newPtr->nextPtr = NULL;
        
        ListNodePtr previousPtr = NULL;
        ListNodePtr currentPtr = *sPtr;
        
        while(currentPtr != NULL && value > currentPtr->data)
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }    
        
        if (previousPtr == NULL){
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }
        else {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else{
        printf("%c not inserted. No memory available.\n", value);
    }
}

char delete(ListNodePtr *sPtr, ListNodePtr *ePtr, char value){
    if(value == (*sPtr)->data){
        ListNodePtr tempPtr = *sPtr;
        *sPtr = (*sPtr)->nextPtr;
        free(tempPtr);
        return value;
    }
    else {
        ListNodePtr previousPtr = *sPtr;
        ListNodePtr currentPtr = (*sPtr)->nextPtr;
        
        while (currentPtr != NULL && currentPtr->data != value){
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;

        }
        
        if(currentPtr != NULL){
            ListNodePtr tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }
    }
    return '\0';
}

