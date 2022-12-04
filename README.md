# Red-Black-Tree
![11465432164_8cc32d5373_b](https://user-images.githubusercontent.com/76991612/205485435-05a90e88-9116-4c97-ae21-36025fd14acb.jpg)
*just a beautiful picture*
# Task description
 - Implementation of a red-black tree.
 - As a key - a value of 3 parts (Direction code).
 - Repeating elements are added to a linked list, which is contained in the key.
 - A package of methods for working with the red-black tree class.
 
 
 &nbsp;



## Methods
Public:
- **Add_Leaf** (int first, int second, int third)  -- Adds a leaf to the tree. Already existing values are added to the linked list, which is in the key. 
- **Delete_Leaf** (int first, int second, int third)  --  Removes a leaf from the tree by the given key.
- **Clear_Tree** ()  -- Clears the tree, frees memory.
- **Find_Leaf** (int first, int second, int third) -- Searches the tree for a leaf with the given key. If such a list exists, then returns true, otherwise - false.
- **Print_Tree** (int h) -- Prints the tree to the console. h - the number of spaces from the edge of the window.
- **Compare** (RBT tree2) -- Compares two red-black trees. Trees are equal if they contain the same elements. If the trees are equal, it returns true, otherwise it returns false.

 &nbsp;

Private:
- **Transplant** (TreeLeaf* Leaf1, TreeLeaf* Leaf2) -- Swaps two leaves of a tree when removed.
- **Rotate_left** (TreeLeaf* Leaf) -- Carried out a left rotation of the tree, relative to a given leaf.
- **Rotate_right** (TreeLeaf* Leaf) -- Carried out a right rotation of the tree, relative to a given leaf.
- **Balance** (TreeLeaf* Leaf) -- Performs tree balancing after leaf insertion.
- **BalanceAD** (TreeLeaf* Leaf) -- Rebalances the tree after deleting a leaf.
- **Delete_Leaf** (TreeLeaf* Leaf) -- An overloaded function that recursively deletes a tree cleans up memory.
- **Find_MinRight** (TreeLeaf* Leaf) -- Finds the minimum right leaf of a tree.
- **Add_Equals** (ListNode* head, ListNode* equal) -- Adds an equivalent key to the linked list stored in the leaf key.
- **Count_Equals** (ListNode* head) -- Counts the number of equivalent keys stored in the leaf. (needed to output the tree to the console)
- **Print_Leaf** (TreeLeaf* Leaf, int h) -- Recursive function that works in tandem with Print_Tree. Prints the tree to the console.
- **Node_Construct** (int first, int second, int third) -- Constructs a linked list node from 3 given values (direction code parts) for other functions to work.
- **Node_compareByKey** (ListNode* largest, ListNode* smallest) -- Compares two linked list nodes by key value. The first value is assumed to be greater than the second. If so, then true is returned, otherwise false.
- **Node_isEqualByKey** (ListNode* left, ListNode* right) -- Compares two linked list nodes by key value. If they are equal, then true is returned, otherwise false.
- **Symmetric_Bypass** (TreeLeaf* Leaf1, TreeLeaf* Leaf2) -- A recursive symmetrical tree traversal function that works in tandem with the Compare method. Compares element by element.
- **Clear_Tree** (TreeLeaf* Leaf) -- An overloaded function that recursively clears the leaves of a tree.

##
*The code was executed in Visual Studio 2022, "Console application" template.*
