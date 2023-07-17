#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
} Node;


int getHeight(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Function to right rotate a subtree rooted with y
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // Return new root
    return x;
}

// Function to left rotate a subtree rooted with x
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Return new root
    return y;
}

// Function to get the balance factor of a node
int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Function to insert a node into the AVL tree
Node* insertNode(Node* node, int data) {
    // Perform the normal BST insertion
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
    else // Duplicates are not allowed in AVL tree
        return node;

    // Update the height of the current node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Check the balance factor and perform necessary rotations
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the updated node pointer
    return node;
}

// Function to find the node with minimum value in a given tree
Node* minValueNode(Node* node) {
    Node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

// Function to delete a node from the AVL tree
Node* deleteNode(Node* root, int data) {
    // Perform the normal BST delete
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        // Node to be deleted found

        // Node with only one child or no child
        if ((root->left == NULL) || (root->right == NULL)) {
            Node* temp = root->left ? root->left : root->right;

            // No child case
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else // One child case
                *root = *temp;

            free(temp);
        } else {
            // Node with two children
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
    }

    // If the tree had only one node, then return
    if (root == NULL)
        return root;

    // Update the height of the current node
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Check the balance factor and perform necessary rotations
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to display the AVL tree in inorder traversal
void displayTree(Node* root) {
    if (root != NULL) {
        displayTree(root->left);
        printf("%d ", root->data);
        displayTree(root->right);
    }
}

int main() {
    FILE* file;
    int number;
    Node* avlTree = NULL;

    // Generate random numbers and store them in a file
    file = fopen("numbers.txt", "w");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    printf("Generating random numbers and storing them in 'numbers.txt'...\n");

    srand(time(NULL));  // Seed the random number generator

    for (int i = 0; i < 10; i++) {
        number = rand() % 100;
        fprintf(file, "%d ", number);
    }

    fclose(file);

    // Read the numbers from the file and insert them into the AVL tree
    file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    printf("\nReading numbers from 'numbers.txt' and inserting them into the AVL tree...\n");

    while (fscanf(file, "%d", &number) != EOF) {
        avlTree = insertNode(avlTree, number);
    }

    fclose(file);

    // Display the AVL tree structure
    printf("\nAVL tree structure:\n");
    displayTree(avlTree);
    printf("\n");

    // Delete a node from the AVL tree
    int deleteNumber;
    printf("\nEnter a number to delete from the AVL tree: ");
    scanf("%d", &deleteNumber);

    avlTree = deleteNode(avlTree, deleteNumber);

    // Display the updated AVL tree structure
    printf("\nAVL tree structure after deletion:\n");
    displayTree(avlTree);
    printf("\n");

    return 0;
}
