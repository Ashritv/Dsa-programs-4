#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* link;
};

struct node* start = NULL;

void display() {
    struct node* temp;

    if (start == NULL)
        printf("\nList is empty\n");
    else {
        temp = start;
        while (temp != NULL) {
            printf("%d-> ", temp->info);
            temp = temp->link;
        }
    }
}

void insertAtfront() {
    int data;
    struct node* temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);
    temp->info = data;
    temp->link = start;
    start = temp;
}

void insertAtend() {
    int data;
    struct node* temp, * head;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);
    temp->link = NULL;
    temp->info = data;
    head = start;
    while (head->link != NULL) {
        head = head->link;
    }
    head->link = temp;
}

void insertAtposition() {
    struct node* temp, * newnode;
    int pos, data, i = 1;
    newnode = malloc(sizeof(struct node));

    printf("\nEnter position and data :");
    scanf("%d %d", &pos, &data);
    temp = start;
    newnode->info = data;
    newnode->link = NULL;
    while (i < pos - 1) {
        temp = temp->link;
        i++;
    }
    newnode->link = temp->link;
    temp->link = newnode;
}

void deletefirst() {
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else {
        temp = start;
        start = start->link;
        free(temp);
    }
}

void deleteposition() {
    struct node* temp, * position;
    int i = 1, pos;
    if (start == NULL)
        printf("\nList is empty\n");
    else {
        printf("\nEnter index : ");
        scanf("%d", &pos);
        position = malloc(sizeof(struct node));
        temp = start;
        while (i < pos - 1) {
            temp = temp->link;
            i++;
        }
        position = temp->link;
        temp->link = position->link;
        free(position);
    }
}

void reverse() {
    struct node* t1, * t2, * temp;
    t1 = t2 = NULL;
    if (start == NULL)
        printf("List is empty\n");
    else {
        while (start != NULL) {
            t2 = start->link;
            start->link = t1;
            t1 = start;
            start = t2;
        }
        start = t1;
        temp = start;
        printf("Rev ll is : ");
        while (temp != NULL) {
            printf("%d-> ", temp->info);
            temp = temp->link;
        }
    }
}

void savelistTofile(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    struct node* curr = start;
    while (curr != NULL) {
        fprintf(file, "%d\n", curr->info);
        curr = curr->link;
    }

    fclose(file);
    printf("List saved to file: %s\n", filename);
}

void loadlistfromfile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    struct node* head = NULL;
    int data;
    while (fscanf(file, "%d", &data) != EOF) {
        struct node* newnode = malloc(sizeof(struct node));
        newnode->info = data;
        newnode->link = NULL;

        if (head == NULL) {
            head = newnode;
            start = head;
        } else {
            head->link = newnode;
            head = head->link;
        }
    }

    fclose(file);
    printf("List loaded from file: %s\n", filename);
}

int main() {
    int choice;
    while (1) {
        printf("1. Display 2. Insert at front 3. Insert at end 4. Insert at position 5. Delete first 6. Delete position 7. Reverse 8. Exit 9. Save list to file 10. Load list from file\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            display();
            break;
        case 2:
            insertAtfront();
            break;
        case 3:
            insertAtend();
            break;
        case 4:
            insertAtposition();
            break;
        case 5:
            deletefirst();
            break;
        case 6:
            deleteposition();
            break;
        case 7:
            reverse();
            break;
        case 8:
            exit(0);
        case 9:
            savelistTofile("ll2.txt");
            break;
        case 10:
            loadlistfromfile("ll2.txt");
            break;
        default:
            printf("Incorrect choice\n");
        }
    }

    return 0;
}
