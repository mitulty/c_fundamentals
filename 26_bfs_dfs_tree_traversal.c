/**
 * @author: Mitul Tyagi
 * @description: Breadth-First Search (BFS) and Depth-First Search (DFS)
 */
/**
- A Tree is a special kind of a graph that has a hierarchical structure. It is a
collection of nodes connected by edges, where each node has a parent node and
zero or more child nodes. The topmost node of the tree is called the root node,
and the nodes below it are called the child nodes. The nodes that do not have
any child nodes are called leaf nodes. The tree data structure is used to
represent hierarchical relationships between data.
- BFS (Breadth-First Search) and DFS (Depth-First Search) are two common
algorithms used to traverse a tree data structure. These algorithms are used to
visit each node in the tree and perform some operation on the nodes.
- In BFS traversal, the nodes are visited level by level, starting from the root
node and moving to the next level before visiting the nodes at the same level.
BFS traversal uses a queue data structure to keep track of the nodes to be
visited. The nodes are visited in the order they are inserted into the queue.
- In DFS traversal, the nodes are visited depth by depth, starting from the root
node and moving to the deepest level before backtracking to the previous level.
DFS traversal uses a stack data structure to keep track of the nodes to be
visited. The nodes are visited in the order they are pushed onto the stack.
- BFS traversal is also known as level-order traversal, as it visits the nodes
level by level. DFS traversal is also known as pre-order, in-order, and
post-order traversal, depending on the order in which the nodes are visited.
- Inorder traversal of a binary search tree gives the nodes in sorted order.
This can be used to check if a binary tree is a binary search tree or not.
- Time Complexity of BFS and DFS traversal is O(n), where n is the number of
nodes in the tree.
- Space Complexity of BFS and DFS traversal is O(n), where n is the number of
nodes in the tree.
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *rootptr = NULL;
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }

    return root;
}

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        Node *current = queue[front++];
        printf("%d -> ", current->data);

        if (current->left != NULL)
        {
            queue[rear++] = current->left;
        }

        if (current->right != NULL)
        {
            queue[rear++] = current->right;
        }
    }
}

void inorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left);
    printf("%d -> ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d -> ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postoderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postoderTraversal(root->left);
    postoderTraversal(root->right);
    printf("%d -> ", root->data);
}

int isbinarysearchtree(Node *root, int max, int min)
{
    if (root == NULL)
    {
        return 1;
    }

    if (root->data < min || root->data > max)
    {
        return 0;
    }

    return isbinarysearchtree(root->left, root->data - 1, min) &&
           isbinarysearchtree(root->right, max, root->data + 1);
}

// Function to find some data in the tree
Node *Find(Node *root, int data)
{
    if (root == NULL)
        return NULL;
    else if (root->data == data)
        return root;
    else if (root->data < data)
        return Find(root->right, data);
    else
        return Find(root->left, data);
}

// Function to find Node with minimum value in a BST
struct Node *FindMin(struct Node *root)
{
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Function to find Node with maximum value in a BST
struct Node *FindMax(struct Node *root)
{
    if (root == NULL)
        return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

// Function to find Inorder Successor in a BST
struct Node *Getsuccessor(struct Node *root, int data)
{
    // Search the Node - O(h)
    struct Node *current = Find(root, data);
    if (current == NULL)
        return NULL;
    if (current->right != NULL)
    {                                   // Case 1: Node has right subtree
        return FindMin(current->right); // O(h)
    }
    else
    { // Case 2: No right subtree  - O(h)
        struct Node *successor = NULL;
        struct Node *ancestor = root;
        while (ancestor != current)
        {
            if (current->data < ancestor->data)
            {
                successor = ancestor; // so far this is the deepest node for
                                      // which current node is in left
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
}

int main(int argc, char const *argv[])
{
    rootptr = insertNode(rootptr, 10);
    insertNode(rootptr, 5);
    insertNode(rootptr, 20);
    insertNode(rootptr, 8);
    insertNode(rootptr, 30);
    insertNode(rootptr, 3);
    insertNode(rootptr, 9);
    printf("Inorder Traversal: ");
    inorderTraversal(rootptr);
    printf("\nPreorder Traversal: ");
    preorderTraversal(rootptr);
    printf("\nPostorder Traversal: ");
    postoderTraversal(rootptr);
    printf("\nLevel Order Traversal: ");
    levelOrderTraversal(rootptr);
    isbinarysearchtree(rootptr, INT32_MAX, INT32_MIN)
        ? printf("\nIt is a Binary Search Tree\n")
        : printf("\nIt is not a Binary Search Tree\n");
    printf("\n");
    struct Node *successor = Getsuccessor(rootptr, 1);
    if (successor == NULL)
        printf("No successor Found for 1\n");
    else
        printf("Successor is %d\n", successor->data);
    successor = Getsuccessor(rootptr, 10);
    if (successor == NULL)
        printf("No successor Found\n");
    else
        printf("Successor for 10 is %d\n", successor->data);
    return 0;
}
