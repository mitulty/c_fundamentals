/**
 * @author: Mitul Tyagi
 * @description: Trees and Binary Search Tree
 */
/**
- Tree data structure is a hierarchical structure that is used to represent and
organize data in a way that is easy to navigate and search. It is a collection
of nodes that are connected by edges and has a hierarchical relationship
between the nodes. The topmost node of the tree is called the root, and the
nodes below it are called the child nodes. Each node can have multiple child
nodes, and these child nodes can also have their own child nodes, forming a
recursive structure.
- The data in a tree are not stored in a sequential manner i.e., they are not
stored linearly. Instead, they are arranged on multiple levels, with each level
containing a set of nodes. The nodes at the bottom level of the tree are
called leaf nodes, and the nodes that are not leaf nodes are called internal
nodes.
- The tree data structure is used to represent hierarchical relationships
between data. It is used in various applications such as file systems,
organization charts, database indexing, and network routing algorithms.
- Basic Terminologies In Tree Data Structure:
    -> Parent Node: The node which is an immediate predecessor of a node is
       called the parent node of that node.
    -> Child Node: The node which is the immediate successor of a node is called
       the child node of that node.
    -> Root Node: The topmost node of a tree or the node which does not have any
       parent node is called the root node. A non-empty tree must contain
       exactly one root node and exactly one path from the root to all other
       nodes of the tree.
    -> Leaf Node or External Node: The nodes which do not have any child nodes
       are called leaf nodes.
    -> Ancestor of a Node: Any predecessor nodes on the path of the root to that
       node are called Ancestors of that node.
    -> Descendant: A node x is a descendant of another node y if and only if y
       is an ancestor of x.
    -> Sibling: Children of the same parent node are called siblings.
    -> Internal node: A node with at least one child is called Internal Node.
    -> Neighbour of a Node: Parent or child nodes of that node are called
       neighbors of that node.
    -> Subtree: Any node of the tree along with its descendant.
    -> Depth/Level of a node: The count of edges on the path from the root node
       to that node. The root node has level 0.
    -> Degree of a Node: The number of children of a node is called the degree
       of that node.
    -> Height of a Node: The number of edges on the longest path from that node
       to a leaf node is called the height of that node.
    -> Height of a Tree: The height of the root node is called the height of the
       tree.
- A tree can be represented using a collection of nodes. Each of the nodes can
be represented with the help of class or structs.
- The tree data structure can be implemented using various data structures such
as arrays, linked lists, and pointers. The linked list implementation of the
tree is:
           struct Node {
           int data;
           struct Node* first_child;
           struct Node* second_child;
           struct Node* third_child;
           .
           .
           .
           struct Node* nth_child;
           };
- The tree data structure can be implemented using a recursive data structure.
Each node in the tree is represented by a struct that contains a data field and
a list of child nodes. The child nodes are stored in a linked list or an
array. The tree data structure can be implemented using a recursive struct as
follows:
        struct Node { int data;
                      struct Node* children[MAX_CHILDREN];
                      int num_children;
                    };
- Tree data structure can be classified into three types based upon the number
of children each node of the tree can have.
- Binary tree: In a binary tree, each node can have a maximum of two
children linked to it. Some common types of binary trees include full binary
trees, complete binary trees, balanced binary trees, and degenerate or
pathological binary trees. Examples of Binary Tree are Binary Search Tree and
Binary Heap.
- Ternary Tree: A Ternary Tree is a tree data structure in which each node
has at most three child nodes, usually distinguished as “left”, “mid” and
“right”.
- N-ary Tree or Generic Tree: Generic trees are a collection of nodes where
each node is a data structure that consists of records and a list of references
to its children(duplicate references are not allowed). Unlike the linked list,
each node stores the address of multiple nodes.
- Basic Operations Of Tree Data Structure:
    - Create: create a tree in the data structure.
    - Insert: Inserts data in a tree.
    - Search: Searches specific data in a tree to check whether it is present or
      not.
    - Traversal: Depth-First-Search Traversal and Breadth-First-Search Traversal
- Properties of Tree Data Structure:
    - Number of edges: An edge can be defined as the connection between two
      nodes. If a tree has N nodes then it will have (N-1) edges. There is only
      one path from each node to any other node of the tree.
    - Depth of a node: The depth of a node is defined as the length of the path
      from the root to that node. Each edge adds 1 unit of length to the path.
      So, it can also be defined as the number of edges in the path from the
      root of the tree to the node.
    - Height of a node: The height of a node can be defined as the length of the
      longest path from that node to a leaf node of the tree.
    - Height of the Tree: The height of a tree is the length of the longest path
      from the root of the tree to a leaf node of the tree.
    - Degree of a Node: The total count of subtrees attached to that node is
      called the degree of the node. The degree of a leaf node must be 0. The
      degree of a tree is the maximum degree of a node among all the nodes in
      the tree.
- Height of a tree is the maximum depth of any node in the tree. The height of a
tree is the length of the longest path from the root node to a leaf node in the
tree. The maximum level of any node in the tree is also the height of the
tree.
------------------------------------------------------------------------------------------------------------------------------------------------------------------
- A binary tree is a tree data structure in which each node has at most two
children, referred to as the left child and the right child. The left child is
the child node that is on the left side of the parent node, and the right child
is the child node that is on the right side of the parent node. A binary tree
can be empty, or it can consist of a root node connected to two subtrees,
referred to as the left subtree and the right subtree.
- The binary tree is used to represent hierarchical relationships between data
in a way that is easy to navigate and search. It is a collection of nodes that
are connected by edges, with each node having at most two children. The binary
tree is used in various applications such as expression trees, binary search
trees, and Huffman coding trees.
- The height of a binary tree is the length of the longest path from the root
node to a leaf node in the tree. The height of a binary tree is the maximum
depth of any node in the tree. The height of an empty tree is -1. Height of a
tree with only one node is 0.
- Full/Strict Binary Tree: A binary tree in which each node has either 0 or 2
children is called a full binary tree. It is also called a strictly binary tree.
A "strict" or "full" binary tree refers to a binary tree where every node has
either zero or two children, meaning no node can have only one child;
essentially, all internal nodes have exactly two children and all leaf nodes
have no children.
- Complete Binary Tree: A binary tree in which all levels are completely filled
except possibly the last level, which is filled from left to right, is called a
complete binary tree.
- Perfect Binary Tree: A binary tree in which all internal nodes have exactly
two children and all leaf nodes are at the same level is called a perfect binary
tree.
- Balanced Binary Tree: A binary tree in which the height of the left and right
subtrees of any node differ by at most one is called a balanced binary tree.
- Degenerate Tree: A binary tree in which each parent node has only one child is
called a degenerate tree. A degenerate tree is also known as a pathological tree
or a linear tree. Skeewed binary tree is a type of degenerate tree.
- Skewed Binary Tree: A binary tree in which each node has only one child is
called a skewed binary tree. A skewed binary tree can be either left-skewed or
right-skewed, depending on the direction of the child nodes.
- Maximum Number of Nodes at Level 'l' in a Binary Tree: 2^l
- Maximum Number of Nodes in a Binary Tree of Height 'h': 2^(h+1) - 1 or 2^(no.
of levels) - 1. The tree will be a perfect binary tree.
- Minimum Number of Nodes in a Binary Tree of Height 'h': h+1 (degenerate tree)
- Minimum height with n nodes: ceil(log2(n+1)) - 1
- Maximum height with n nodes: (n - 1)(degenerate tree)
- Height of a perferct binary tree: log2(n+1) - 1 where n is the number of nodes
in the tree.
- Height of a complete binary tree: floor(log2(n)) where n is the number of
nodes in the tree.
-------------------------------------------------------------------------------------------------------------------------------------------------------------
- A binary search tree (BST) is a binary tree data structure that satisfies the
following properties:
  -> The left subtree of a node contains only nodes with keys less than the
     node's key.
  -> The right subtree of a node contains only nodes with keys greater than the
     node's key.
  -> Both the left and right subtrees must also be binary search trees.
- The binary search tree is used to store data in a way that allows for
efficient searching, insertion, and deletion operations.
- The binary search tree can be a self-balancing data structure that maintains
the property of a binary search tree by performing rotations and other
operations to keep the tree balanced.
- The binary search tree is used in various applications such as database
indexing, searching algorithms, and network routing algorithms.
- The binary search tree is implemented using a tree data structure that
consists of nodes connected by edges. Each node contains a key, which is used to
determine the position of the node in the tree. The key is used to compare
nodes and determine the order in which they are stored in the tree.
- The binary search tree supports the following operations:
    - Insertion: Insert a new node with a given key into the tree.
    - Deletion: Remove a node with a given key from the tree.
    - Search: Search for a node with a given key in the tree.
    - Traversal: Traverse the tree in a specific order, such as inorder,
      preorder, or postorder.
- The binary search tree is a powerful data structure that provides efficient
searching, insertion, and deletion operations. It is used in various
applications.
- The lookup, insertion, and deletion operations in a binary search tree have an
average time complexity of O(log n), where n is the number of nodes in the tree
provided the BST is balanced. In the worst case, the time complexity of these
operations is O(n), where n is the number of nodes in the tree.
- The inorder traversal of a binary search tree gives the nodes in sorted order.
This property can be used to check if a binary tree is a binary search tree or
not.
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
    if (!newNode)
    {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert in a binary search tree
Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
        return root;
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

// Minimum element in a binary search tree
int minelement(Node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return -1;
    }

    if (root->left == NULL)
    {
        return root->data;
    }

    return minelement(root->left);
}

// Maximum element in a binary search tree
int maxelement(Node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return -1;
    }

    if (root->right == NULL)
    {
        return root->data;
    }

    return maxelement(root->right);
}

void freeTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Search in a binary search tree
int searchNode(Node *root, int data)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->data == data)
    {
        return 1;
    }

    if (data < root->data)
    {
        return searchNode(root->left, data);
    }
    else
    {
        return searchNode(root->right, data);
    }
}

// Height of a tree
int height(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Number of nodes in a tree
int numberOfNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return numberOfNodes(root->left) + numberOfNodes(root->right) + 1;
}

// Delete a node in a binary search tree
Node *deleteNode(Node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    // Node to be deleted
    else
    {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        // Case 2: One child
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            free(temp);
        }
        // Case 3: One child
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            free(temp);
        }
        // Case 4: Two children: Find the minimum element in the right subtree
        // and replace the node to be deleted with the minimum element. Then
        // delete the minimum element node. Also the maximum element in the left
        // subtree can be used to replace the node to be deleted.
        else
        {
            int temp = minelement(root->right);
            root->data = temp;
            root->right = deleteNode(root->right, temp);
        }
    }
    return root;
}

// Sum of all nodes.
int find_sum(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return root->data + find_sum(root->left) + find_sum(root->right);
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
    printf("\n");
    printf(searchNode(rootptr, 9) ? "Found\n" : "Not Found\n");
    return 0;
}
