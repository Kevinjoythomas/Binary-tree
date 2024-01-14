#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum of two numbers
int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// Node structure for the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a binary tree recursively
void createTree(struct Node* root) {
    int data;

    printf("Enter the left of %d (-1 if NULL): ", root->data);
    scanf("%d", &data);

    if (data == -1) {
        printf("Enter the right of %d (-1 if NULL): ", root->data);
        scanf("%d", &data);

        if (data == -1) {
            return;
        } else {
            struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
            new_node->data = data;
            new_node->left = NULL;
            new_node->right = NULL;

            root->right = new_node;
            createTree(new_node);
        }
    } else {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;

        root->left = new_node;
        createTree(new_node);

        printf("Enter the right of %d (-1 if NULL): ", root->data);
        scanf("%d", &data);

        if (data == -1) {
            return;
        } else {
            struct Node* new_nod = (struct Node*)malloc(sizeof(struct Node));
            new_nod->data = data;
            new_nod->left = NULL;
            new_nod->right = NULL;

            root->right = new_nod;
            createTree(new_nod);
        }
    }
}

// Function to perform in-order traversal of the binary tree
void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}

// Function to perform pre-order traversal of the binary tree
void preorder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Function to perform post-order traversal of the binary tree
void postorder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
}

// Function to calculate the height of the binary tree
void height(struct Node* root, int* p, int temph) {
    if (root == NULL) {
        return;
    } else if (root->left == NULL && root->right == NULL) {
        *p = max(*p, temph);
    } else {
        height(root->left, p, temph + 1);
        height(root->right, p, temph + 1);
        return;
    }
}

// Function to print nodes at a specific level of the binary tree
void printlevel(struct Node* root, int level, int cl) {
    if (root == NULL) {
        return;
    } else if (cl == level) {
        printf("%d ", root->data);
        return;
    } else {
        printlevel(root->left, level, cl + 1);
        printlevel(root->right, level, cl + 1);
    }
}

// Function to perform level order traversal of the binary tree
void levelorder(struct Node* root, int h) {
    int levels = h + 1;

    for (int i = 1; i <= levels; i++) {
        printlevel(root, i, 1);
        printf("\n");
    }
}

// Function to perform reverse level order traversal of the binary tree
void reverselevelorder(struct Node* root, int h) {
    int levels = h - 1;

    for (int i = levels; i > 0; i--) {
        printre(root, i, levels);
    }
}

// Function to print nodes at a specific level in reverse order
void printre(struct Node* root, int level, int cl) {
    if (root == NULL) {
        return;
    } else if (cl == level) {
        printf("%d", root->data);
    } else {
        printre(root->left, level, cl - 1);
        printre(root->right, level, cl - 1);
    }
}

// Function to find the successor in the binary tree
struct Node* successor(struct Node* root) {
    root = root->right;

    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

// Function to delete a node with a specific value in the binary tree
struct Node* delete(struct Node* root, int val) {
    if (root == NULL) {
        printf("Invalid value");
        return root;
    }

    if (val < root->data) {
        root->left = delete(root->left, val);
    } else if (val > root->data) {
        root->right = delete(root->right);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        } else {
            struct Node* temp = successor(root);
            root->data = temp->data;
            root->right = delete(root, temp->data);
        }
    }

    return root;
}

// Function to count the number of leaf nodes in the binary tree
int leafnode(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else if (root->left == NULL && root->right == NULL) {
        return 1;
    } else {
        return leafnode(root->left) + leafnode(root->right);
    }
}

// Placeholder for level order traversal using a queue (not implemented in the provided code)
void levelorderQueue();

int main() {
    int arr[10] = {200, 100, 400, 50, 150, 250, 180, 135, 120, 20};
    int root_data;

    printf("Please enter the root node: \n");
    scanf("%d", &root_data);

    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = root_data;
    root->left = NULL;
    root->right = NULL;

    createTree(root);
    levelorder(root);

    int k = leafnode(root);
    printf("%d\n", k);

    int h = 0;
    height(root, &h, 0);
    printf("%d", h);

    return 0;
}
