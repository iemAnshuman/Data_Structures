# Types of Data Structure
1. Linear
2. Non - linear

<br>

# Trees
- unordered (need explanation?)
- recursive call
- non linear data structure
- it is a collection of nodes
- nodes are arranged in hierarchical structure
- nodes are linked to each other by edges 
- it is preferred when we want to reduce the cost of operations and memory use.

<br>

## Properties and terminologies
* Node: Basic unit containing data and pointer to other nodes

* Root: Topmost node in a tree (for a tree there exists only one root)

* Child: The node which is the immediate successor of a node 

* Parent: The node which is a predecessor of a node.

* Ancestor: Any predessor node which is in the path from root to that node.

* Descendant: A node x is a descendant of y if and only if y is the ancestor of x.

* Sibling: Children of the same parent.

* Level: Total count of edges between current node and root of a tree

* Leaf(external node): Any node which doesn't have a child.

* Internal Node: A node with atleast one child.

* Neighbour of a node: Parent or child

* subtree: subset of the tree -> also a tree

* Edge: Link between two different nodes

* Height: The longest path which can be drawn between root node and leaf node.

* Breadth: Total number of leaf nodes present in the tree

* Degree: The count of child nodes that exist for the given node

* Intermediate node: nodes between two nodes

* Balanced and unbalanced: In a balanced tree, the heights of subtrees of any node differ by at most one level.
```css
Balanced:-
   A
  / \
 B   C
/ \ / \
D  E F  G
```

```css
Unbalanced:-
      A
     \
      B
       \
        C
         \
          D

```
<br>

## Applications of trees:-
* File System: efficient navigation and organisation of files
* Huffman coding: data compression technique that involves constructing a binary tree where the 
leaves of tree represent the characters and their frequency of occurance.
* B-trees and other tree structures are used in database indexing to efficiently search, store and retrieve data. 

## Types of trees (on the basis of children)
1. Binary Trees
2. Ternary trees
3. N-ary trees 
...

<br>

### Binary Trees
- each node has max two child
- one root
- common types: full binary trees, complete binary trees, balanced binary trees, and degenerate or pathological binary trees.

### Ternary Trees
- A Ternary Tree is a tree data structure in which each node has at most three child nodes, usually distinguished as “left”, “mid” and “right”.

### N-ary Trees
- also known as generic trees
- no degree restrictions 

<br>

# Types of trees (lecture)
1. General Trees: one root with no degree restrictions (?)
2. Forest Trees: disjoint union of trees. (undirected graph?)
3. Binary Trees
4. Binary search Trees