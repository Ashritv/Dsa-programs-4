#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}
void inorderTraversal(struct Node* root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct Node* root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    int rangeMin, rangeMax, maxValue;
    printf("enter  range min and max: ");
    scanf("%d %d", &rangeMin, &rangeMax);
    printf("Enter the maximum value to be stored: ");
    scanf("%d", &maxValue);
    FILE* file = fopen("random_numbers.txt", "w");
    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return 1;
    }
    srand(time(NULL));
    struct Node* root = NULL;
    int i;
    for (i = 0; i < maxValue; i++)
    {
        int randomNum = rand() % (rangeMax - rangeMin + 1) + rangeMin;
        fprintf(file, "%d\n", randomNum);
        root = insert(root, randomNum);
    }
    fclose(file);
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");
    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");
    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");
    return 0;
}
