// Binary Tree
#include <stdio.h>
#include <stdlib.h>

struct treeNode {
	struct treeNode *leftPtr;
	int data;
	struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

struct queueNode {
	TreeNodePtr node;
	struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

// Insert a new element to the binary tree	(Already developed)
void insert(TreeNodePtr *treePtr, int value);

/*************
 * Develop this function at the bottom of this program
 * In-Order traversal and print out of the binary tree into the output file.
 */
void inOrder(TreeNodePtr treePtr);

/*************
 * Develop this function at the bottom of this program
 * Level-Order traversal and print out of the binary tree
 */
void levelOrder(TreeNodePtr treePtr, QueueNodePtr *headPtr, QueueNodePtr *tailPtr);

/*************
 * Develop this function at the bottom of this program
 * Reverse-Order traversal and print out of the binary tree. ((Decreasing order)
 */
void reverseOrder(TreeNodePtr treePtr);

/*************
 * Develop this function at the bottom of this program
 * Print out the binary tree with 90-degree counterclockwise rotated
 */
void printTree(TreeNodePtr treePtr, int totalSpaces);

/*************
 * Develop this function at the bottom of this program
 * Search the binary tree for a value and return the result node
 */
TreeNodePtr searchTree(TreeNodePtr treePtr, int value);

// Check if the queue is empty	(Already developed)
int isQueueEmpty(QueueNodePtr headPtr);

// Enqueue a new element into the queue	(Already developed)
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, TreeNodePtr node);

// Dequeue an element from the queue	(Already developed)
TreeNodePtr dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);

// Declare a global input file pointer
FILE *inPtr;

// Declare a global output file pointer
FILE *outPtr;

int main(void) {

	// A pointers for the root of the binary tree.
	TreeNodePtr rootPtr = NULL;

	// Two pointers for the head and tail of the queue
	QueueNodePtr headPtr = NULL;
	QueueNodePtr tailPtr = NULL;

	/*************
	 * Complete this part
	 * Open the file "input.txt" as the input file.
	 * If the operation is not successful, you must print out a proper message and terminate the program.
	 */
    inPtr = fopen("Input.txt", "r");
    if(inPtr == NULL)
    {
       printf("The Text file cannot be opened!\n");
       return 0;
    }

	/*************
	 * Complete this part
	 * Open the file "output.txt" as the output file.
	 * If the operation is not successful, you must print out a proper message and terminate the program.
	 */
    outPtr = fopen("Output", "w");
    if(outPtr == NULL)
    {
       printf("The Text file cannot be opened!\n");
       return 0;
    }

	/*************
	 * Complete this part
	 * Print the following header line into the output file: "The numbers being inserted into the binary tree are:".
	 * Using a loop:
	 * 		Read every line from the input file. (Note that inside the input file, you have one integer number in each line.)
	 * 		Print out the element you read into the output file.
	 *		Insert the element into the binary tree.
	 * At the end, close the input file.
	 */
	 int num;
    fprintf(outPtr, "%s", "The numbers being inserted into the binary tree are:\n");
    for(int i = 0; i <= 9; i++){
        fscanf(inPtr, "%d\n", &num);
        insert(&rootPtr, num);
        fprintf(outPtr, "%d ", num);
    }
    
    fclose(inPtr);

	/*************
	 * Complete this part
	 * Print the following header line into the output file: "In-Order traversal and print out of the binary tree is:".
	 * Print out the elements of the binary tree, in-order, into the output file .
	 */
    fprintf(outPtr, "%s", "\nIn-Order traversal and print out of the binary tree is:\n");
    inOrder(rootPtr);

	/*************
	 * Complete this part
	 * Print the following header line into the output file: "Level-Order traversal of the binary tree is:".
	 * Print out the elements of the binary tree, level-order, into the output file .
	 */
    fprintf(outPtr, "%s", "\nLevel-Order traversal of the binary tree is:\n");
    levelOrder(rootPtr, &headPtr, &tailPtr);




	/*************
	 * Complete this part
	 * Print the following header line into the output file: "The Binary Tree in reverse (decreasing) order is:".
	 * Print out the elements of the binary tree, reverse-order, into the output file. (Decreasing order)
	 */
    fprintf(outPtr, "%s", "\nThe Binary Tree in reverse (decreasing) order is:\n");
    reverseOrder(rootPtr);

	/*************
	 * Complete this part
	 * Print the following header line into the output file: "Printing the binary tree with 90-degree counterclockwise rotated:".
	 * Print out the binary tree, with 90-degree counterclockwise rotated, into the output file.
	 */
    fprintf(outPtr, "%s", "\nPrinting the binary tree with 90-degree counterclockwise rotated:\n");
    printTree(rootPtr, 0);

	/*************
	 * Complete this part
	 * Print the following header line into the output file: "Searching the binary tree:".
	 * Search the binary tree for three values, 10, 5, and 30, separately, and print out the results into the output file.
	 */
    fprintf(outPtr, "%s", "\nSearching the binary tree:\n");

    if(searchTree(rootPtr, 10)!=NULL){
            fprintf(outPtr,"10 found\n");
    }else{
        fprintf(outPtr,"10 not found\n");
    }

    if(searchTree(rootPtr, 5)!=NULL){
        fprintf(outPtr,"5 found\n");
    }else{
        fprintf(outPtr,"5 not found\n");
    }

    if(searchTree(rootPtr, 30)!=NULL){
        fprintf(outPtr,"30 found\n");
    }else{
        fprintf(outPtr,"30 not found\n");
    }

	/*************
	 * Complete this part
	 * At the end, close the output file.
	 */
    fclose(outPtr);
}

// Insert a node into the binary tree	(Already developed)
void insert(TreeNodePtr *treePtr, int value) {
	// If the tree is empty
	if (*treePtr == NULL) {
		*treePtr = malloc(sizeof(TreeNode));

		// If memory allocation was successful
		if (*treePtr != NULL) {
			(*treePtr)->data = value;
			(*treePtr)->leftPtr = NULL;
			(*treePtr)->rightPtr = NULL;
		} else {
			printf("%d No more memory is available.\n", value);
		}
	} else { // The tree is not empty
		// The new data is less than the data in the current node
		if (value < (*treePtr)->data) {
			insert(&((*treePtr)->leftPtr), value);
		}

		// The new data is greater than the data in the current node
		else if (value > (*treePtr)->data) {
			insert(&((*treePtr)->rightPtr), value);
		} else { // Duplication will be ignored
			printf("%s\n", "Inserting a duplicated value is ignored");
		}
	}
}

// Insert a node at queue tail	(Already developed)
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, TreeNodePtr node) {
	QueueNodePtr newPtr = malloc(sizeof(QueueNode));

	if (newPtr != NULL) { // is space available
		newPtr->node = node;
		newPtr->nextPtr = NULL;

		// if empty, insert node at head
		if (isQueueEmpty(*headPtr)) {
			*headPtr = newPtr;
		} else {
			(*tailPtr)->nextPtr = newPtr;
		}

		*tailPtr = newPtr;
	} else {
		printf("Not inserted. No memory available.\n");
	}
}

// Remove node from queue head	(Already developed)
TreeNodePtr dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr) {
	TreeNodePtr value = (*headPtr)->node;
	QueueNodePtr tempPtr = *headPtr;
	*headPtr = (*headPtr)->nextPtr;

	// if queue is empty
	if (*headPtr == NULL) {
		*tailPtr = NULL;
	}

	free(tempPtr);
	return value;
}

// Return 1 if the queue is empty, 0 otherwise	(Already developed)
int isQueueEmpty(QueueNodePtr headPtr) {
	return headPtr == NULL;
}

/* Develop all the required functions from the function prototypes here: */
void inOrder(TreeNodePtr treePtr){
    if (treePtr != NULL){
        inOrder(treePtr->leftPtr);
        fprintf(outPtr ,"%d ", treePtr->data);
        inOrder(treePtr->rightPtr);
    }
}

void levelOrder(TreeNodePtr treePtr, QueueNodePtr *headPtr, QueueNodePtr *tailPtr){
    // enqueue current node
    enqueue(headPtr,tailPtr,treePtr);
    //queue will be empty after processing the nodes
    while(!isQueueEmpty(*headPtr)){
        // dequeue current node
        TreeNodePtr currPtr = dequeue(headPtr,tailPtr);
        // print the data of current node
        fprintf(outPtr,"%d ",currPtr->data);
        // enqueue the left child if not NULL
        if(currPtr->leftPtr != NULL)
            enqueue(headPtr,tailPtr,currPtr->leftPtr);
        // enqueue the right child if not NULL
        if(currPtr->rightPtr != NULL)
            enqueue(headPtr,tailPtr,currPtr->rightPtr);
    }
}


void reverseOrder(TreeNodePtr treePtr){
    // base case
    if(treePtr == NULL) 
        return; 
    
    // process right child
    reverseOrder(treePtr->rightPtr);
    // print the value of current node
    fprintf(outPtr,"%d ",treePtr->data);
    // process left child
    reverseOrder(treePtr->leftPtr);
}


void printTree(TreeNodePtr treePtr, int totalSpaces){
    if(treePtr != NULL){
        printTree(treePtr->rightPtr, totalSpaces + 5);
        for(int i = 0; i < totalSpaces; i++){
            fprintf(outPtr, "%s", " ");
        }
        fprintf(outPtr, "%d \n", treePtr->data);
        printTree(treePtr->leftPtr, totalSpaces + 5);
    }
}


TreeNodePtr searchTree(TreeNodePtr treePtr, int value){
    while(treePtr !=NULL ){
        /*
        Check current node has value,
        else if current node has greater value,
        the value can be only in left sub tree,
        else value can be in right sub tree
        */
        if(treePtr->data == value)
            return treePtr;
        else if(treePtr->data > value)
            treePtr = treePtr->leftPtr;
        else
            treePtr = treePtr->rightPtr;
    }
    return NULL;
}

