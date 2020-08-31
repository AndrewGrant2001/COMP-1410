// LinkedList
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *nextPtr;
};

typedef struct node Node;
typedef Node *NodePtr;

/*************
* Develop this function at the bottom of this program
* Add a new element to the beginning of the list
*/
void addFirst(NodePtr *sPtr, NodePtr *ePtr, int value);

/*************
* Develop this function at the bottom of this program
* Add a new element to the end of the list
*/
void addLast(NodePtr *sPtr, NodePtr *ePtr, int value);

/*************
* Develop this function at the bottom of this program
* Print the list in the reverse order
*/
void printReverseList(NodePtr sPtr);

/*************
* Develop this function at the bottom of this program
* Reverse the list, in-place
*/
void reverseList(NodePtr *sPtr, NodePtr *ePtr);

/*************
* Develop this function at the bottom of this program
* Safely make a linked list empty.
*/
void emptyList(NodePtr *sPtr, NodePtr *ePtr);

/*************
* Develop this function at the bottom of this program
* Merge two lists into a new ordered list
*/
void merge(NodePtr list1, NodePtr list2, NodePtr *l3StartPtr, NodePtr *l3EndPtr);

// Check if the list is empty (Already developed)
int isEmpty(NodePtr sPtr);

// Print out the list (Already developed)
void printList(NodePtr sPtr);

// Selection menu (Already developed)
void menu(void);

int main(void) {

        // Two pointers for the beginning and ending of the linked list generated.
        NodePtr startPtr = NULL;
        NodePtr endPtr = NULL;

        // Three pairs of pointers for beginning and ending of the three linked lists used in the merge selection
        NodePtr l1StartPtr = NULL;
        NodePtr l1EndPtr = NULL;
        NodePtr l2StartPtr = NULL;
        NodePtr l2EndPtr = NULL;
        NodePtr l3StartPtr = NULL;
        NodePtr l3EndPtr = NULL;

        int item;

        menu();

        unsigned int choice;
        scanf("%u", &choice);
        while(getchar() != '\n') { }

        while (choice != 6) {

                switch (choice) {
                case 1:
                        /*************
                         * Complete this part:
                         * Prompt the user to input an integer number.
                         * Read the user's input.
                         * Then, add the input to the BEGINNING of the linked list with the two pointers startPtr and endPtr.
                         * Then, print the linked list.
                         */
                        printf("Enter an integer: ");
                        scanf("%d", &item);
                        addFirst(&startPtr, &endPtr, item);
                        printList(startPtr);
                        break;
                case 2:
                        /*************
                         * Complete this part:
                         * Prompt the user to input an integer number.
                         * Read the user's input.
                         * Then, add the input to the END of the linked list with the two pointers startPtr and endPtr.
                         * Then, print the linked list.
                         */
                        printf("Enter an integer: ");
                        scanf("%d", &item);
                        addLast(&startPtr, &endPtr, item);
                        printList(startPtr);
                        break;
                case 3:
                        /*************
                         * Complete this part:
                         * Print the list in the reverse order.
                         */
                        printf("NULL --> ");
                        printReverseList(startPtr);
                        puts("\n");
                        break;
                case 4:
                        /*************
                         * Complete this part:
                         * Reverse the list, in-place. You should not use any other dynamic structure, like another list, stack or queue.
                         * Then, print the linked list.
                         */
                        printReverseList(startPtr);
                        printf("NULL\n");
                        puts("");
                        break;
                case 5:
                        /*************
                         * Complete this part:
                         * Empty the three lists with the pair of pointers [l1StartPtr,l1EndPtr], [l2StartPtr,l2EndPtr] and [l3StartPtr,l3EndPtr]
                         */
                        emptyList(&l1StartPtr, &l1EndPtr);
                        emptyList(&l2StartPtr, &l2EndPtr);
                        emptyList(&l3StartPtr, &l3EndPtr);


                        // Create a linked list with some ordered elements      (Already developed)
                        for (unsigned int i = 1; i <= 20; i+=3)
                                addLast(&l1StartPtr, &l1EndPtr, i);

                        // Create another linked list with some ordered elements        (Already developed)
                        for (unsigned int i = 2; i <= 30; i+=7)
                                addLast(&l2StartPtr, &l2EndPtr, i);

                        /*************
                         * Complete this part:
                         * Merge the two above lists into a new ordered list. Use l3StartPtr, l3EndPtr for the new list
                         * Then, print the two original lists and the new merged list.
                         */
                        merge(l1StartPtr, l2StartPtr, &l3StartPtr, &l3EndPtr);

                        printf("Original list1: ");
                        printList(l1StartPtr);
                        printf("Original list2: ");
                        printList(l2StartPtr);
                        printf("Merged list: ");
                        printList(l3StartPtr);
                        break;
                default:
                        puts("Invalid choice.\n");
                        break;
                }
                menu();
                scanf("%u", &choice);
                while(getchar() != '\n') { }
        }
}

// display menu to the user (Already developed)
void menu(void) {
        puts("Enter your choice:\n"
                        "   1 to add a new element to the beginning of the list.\n"
                        "   2 to add a new element to the end of the list.\n"
                        "   3 to print the list in the reverse order.\n"
                        "   4 to reverse the list, in-place.\n"
                        "   5 to merge two ordered lists into a new ordered list.\n"
                        "   6 to end.");
        printf("%s", "? ");
}

// return 1 if the list is empty, 0 otherwise (Already developed)
int isEmpty(NodePtr sPtr) {
        return sPtr == NULL;
}

// print the list from the beginning (Already developed)
void printList(NodePtr sPtr) {
        if (isEmpty(sPtr))
                puts("List is empty.\n");
        else {
                puts("The list is:");

                while (sPtr != NULL) {
                        printf("%d --> ", sPtr->data);
                        sPtr = sPtr->nextPtr;
                }
                puts("NULL\n");
        }
}

/* Develop all the required functions from the function prototypes here: */

/*************
* Develop this function at the bottom of this program
* Add a new element to the beginning of the list
*/
void addFirst(NodePtr *sPtr, NodePtr *ePtr, int value) {
    NodePtr tmp = malloc(sizeof(NodePtr));
    tmp->data = value;
    if(*sPtr == NULL) {
        *sPtr = tmp;
        *ePtr = tmp;
    } else {
        tmp->nextPtr = *sPtr;
        *sPtr = tmp;
    }
}

/*************
* Develop this function at the bottom of this program
* Add a new element to the end of the list
*/
void addLast(NodePtr *sPtr, NodePtr *ePtr, int value) {
    NodePtr tmp = malloc(sizeof(NodePtr));
    tmp->data = value;
    if(*ePtr == NULL) {
        *sPtr = tmp;
        *ePtr = tmp;
    } else {
        (*ePtr)->nextPtr = tmp;
        *ePtr = tmp;
    }
}

/*************
* Develop this function at the bottom of this program
* Print the list in the reverse order
*/
void printReverseListHelper(NodePtr sPtr) {
    if(sPtr != NULL) {
        printReverseListHelper(sPtr->nextPtr);
        printf("%d --> ", sPtr->data);
    }
}

void printReverseList(NodePtr sPtr) {
    if (isEmpty(sPtr))
        puts("List is empty.\n");
    else {
        printReverseListHelper(sPtr);
    }
}

/*************
* Develop this function at the bottom of this program
* Reverse the list, in-place
*/
void reverseList(NodePtr *sPtr, NodePtr *ePtr) {
    if(*sPtr == NULL || *sPtr == *ePtr) {
        return;
    }
    NodePtr x = *sPtr;
    NodePtr newHead = x->nextPtr;
    NodePtr newTail = *ePtr;
    reverseList(&newHead, &newTail);
    newTail->nextPtr = x;
    x->nextPtr = NULL;
    *ePtr = newTail;
    *sPtr = newHead;
}

/*************
* Develop this function at the bottom of this program
* Safely make a linked list empty.
*/
void emptyList(NodePtr *sPtr, NodePtr *ePtr) {
    if(*sPtr == NULL) {
        return;
    }
    NodePtr x = (*sPtr)->nextPtr;
    emptyList(&x, ePtr);
    free(*sPtr);
    *sPtr = NULL;
    *ePtr = NULL;
}

/*************
* Develop this function at the bottom of this program
* Merge two lists into a new ordered list
*/
void merge(NodePtr list1, NodePtr list2, NodePtr *l3StartPtr, NodePtr *l3EndPtr) {
    NodePtr x = list1;
    while(x != NULL) {
        addLast(l3StartPtr, l3EndPtr, x->data);
        x = x->nextPtr;
    }
    x = list2;
    while(x != NULL) {
        addLast(l3StartPtr, l3EndPtr, x->data);
        x = x->nextPtr;
    }
}

