// Introduction to Trees

/*
Node: Considered to contain the value and links to other nodes (children and parent)
Root: The node at the top position (original position)
Sibling: Children of the same parent 
Leaf: The nodes at the bottom with no child
Depth: Length of path from root to x; number of edges in path from root to x
Height: Number of edges in longest path from x to a leaf 

Tree is considered a recursive data structure.
It is understood that with a root, there are subtrees related to the root node.
   root
     |
    / \ 
subtree subtree

With N number of nodes, there are N-1 number of edges 

Binary Tree: A tree in which each node can have at most 2 children
    * We would most likely use pointer to nodes when creating trees 
    * The nodes would contain the value, pointer to left child and pointer to right child

Applications:
    * Storing naturally hierarchical data eg.) file system 
    * Organizing data - quick search, insertino, deletion eg.) Binary Search Tree
    * Trie - used to store dictinoary eg.) dynamic spell checking
    * Network Routing Algorithm 
*/

typedef struct node {
    int data;
    node* left;
    node* right;
}node; // For Binary Tree