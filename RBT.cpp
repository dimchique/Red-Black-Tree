#include <iostream>

using namespace std;

class RBT final
{
	enum LeafColor {BLACK, RED};

	struct ListNode  
	{
		int first;
		int second;
		int third;
		ListNode* next;
	};

	struct TreeLeaf
	{
		ListNode* key;  // nn.nn.nn Код направления
		TreeLeaf* left;
		TreeLeaf* right;
		TreeLeaf* parent;
		LeafColor color;   

	};

private:

	TreeLeaf* root;
	TreeLeaf* TNull = new TreeLeaf;

	void Transplant(TreeLeaf* Leaf1, TreeLeaf* Leaf2)
	{
		if (Leaf1->parent == TNull) 
		{ 
			root = Leaf2; 
		}
		else if (Leaf1 == Leaf1->parent->left) 
		{ 
			Leaf1->parent->left = Leaf2; 
		}
		else 
		{ 
			Leaf1->parent->right = Leaf2; 
		}

		Leaf2->parent = Leaf1->parent;
	}

	void Rotate_left(TreeLeaf* Leaf)
	{
		TreeLeaf* current = Leaf;

		TreeLeaf* temp = current->right;
		current->right = temp->left;

		if (temp->left != TNull)
		{
			temp->left->parent = current;
		}
		temp->parent = current->parent;
		if (current->parent == TNull)
		{
			root = temp;
		}
		else if (current == current->parent->left)
		{
			current->parent->left = temp;
		}
		else
		{
			current->parent->right = temp;
		}

		temp->left = current;
		current->parent = temp;
	}

	void Rotate_right(TreeLeaf* Leaf)
	{
		TreeLeaf* current = Leaf;

		TreeLeaf* temp = current->left;
		current->left = temp->right;

		if (temp->right != TNull)
		{
			temp->left->parent = current;
		}
		temp->parent = current->parent;
		if (current->parent == TNull)
		{
			root = temp;
		}
		else if (current == current->parent->right)
		{
			current->parent->right = temp;
		}
		else
		{
			current->parent->left = temp;
		}
		temp->right = current;

		current->parent = temp;
	}

	void Balance(TreeLeaf* Leaf)
	{
		TreeLeaf* temp;
		TreeLeaf* current = Leaf;

		while (current->parent->color == RED)
		{
			if (current->parent == current->parent->parent->left)
			{
				temp = current->parent->parent->right;
				if (temp->color == RED)
				{
					current->parent->color = BLACK;
					temp->color = BLACK;
					current->parent->parent->color = RED;
					current = current->parent->parent;
				}
				else 
				{
					if (current == current->parent->right)
					{
						current = current->parent;
						Rotate_left(current);
					}

					current->parent->color = BLACK;
					current->parent->parent->color = RED;
					Rotate_right(current->parent->parent);
				}
			}
			else
			{
				temp = current->parent->parent->left;
				if (temp->color == RED)
				{
					current->parent->color = BLACK;
					temp->color = BLACK;
					current->parent->parent->color = RED;
					current = current->parent->parent;
				}
				else
				{
					if (current == current->parent->left)
					{
						current = current->parent;
						Rotate_right(current);
					}

					current->parent->color = BLACK;
					current->parent->parent->color = RED;
					Rotate_left(current->parent->parent);
				}
				
			}
		}

		root->color = BLACK;
	}

	void BalanceAD(TreeLeaf* Leaf)
	{
		while (Leaf != root && Leaf->color == BLACK)
		{
			if (Leaf == Leaf->parent->left)
			{
				TreeLeaf* temp;
				temp = Leaf->parent->right;
				if (temp->color == RED)
				{
					temp->color = BLACK;
					Leaf->parent->color = RED;
					Rotate_left(Leaf->parent);
					temp = Leaf->parent->right;
				}
				if (temp->left->color == BLACK && temp->right->color == BLACK)
				{
					temp->color = RED;
					Leaf = Leaf->parent;
				}
				else if (temp->right->color == BLACK)
				{
					temp->left->color = BLACK;
					temp->color = RED;
					Rotate_right(temp);
					temp = Leaf->parent->right;
				}
				temp->color = Leaf->parent->color;
				Leaf->parent->color = BLACK;
				temp->right->color = BLACK;
				Rotate_left(Leaf->parent);
				Leaf = root;
			}
			else
			{
				TreeLeaf* temp;
				temp = Leaf->parent->left;
				if (temp->color == RED)
				{
					temp->color = BLACK;
					Leaf->parent->color = RED;
					Rotate_right(Leaf->parent);
					temp = Leaf->parent->left;
				}
				if (temp->right->color == BLACK && temp->left->color == BLACK)
				{
					temp->color = RED;
					Leaf = Leaf->parent;
				}
				else if (temp->left->color == BLACK)
				{
					temp->right->color = BLACK;
					temp->color = RED;
					Rotate_left(temp);
					temp = Leaf->parent->left;
				}
				temp->color = Leaf->parent->color;
				Leaf->parent->color = BLACK;
				temp->left->color = BLACK;
				Rotate_right(Leaf->parent);
				Leaf = root;
			}
		}

		Leaf->color = BLACK;
	}

	void Delete_Leaf(TreeLeaf* Leaf)
	{
		TreeLeaf* temp1;
		TreeLeaf* temp2 = Leaf;
		LeafColor tempOC = temp2->color;
		if (Leaf->left == TNull)
		{
			temp1 = Leaf->right;
			Transplant(Leaf, Leaf->right);
		}
		else if (Leaf->right == TNull)
		{
			temp1 = Leaf->left;
			Transplant(Leaf, Leaf->left);
		}
		else
		{
			temp2 = Find_Minimum(Leaf->right);
			tempOC = temp2->color;
			temp1 = temp2->right;
			if (temp2->parent == Leaf)
			{
				temp1->parent = temp2;
			}
			else
			{
				Transplant(temp2, temp2->right);
				temp2->right = Leaf->right;
				temp2->right->parent = temp2;
			}

			Transplant(Leaf, temp2);
			temp2->left = Leaf->left;
			temp2->left->parent = temp2;
			temp2->color = Leaf->color;
		}

		if (tempOC == BLACK)
		{
			BalanceAD(temp1);
		}
	}

	TreeLeaf* Find_Minimum(TreeLeaf* Leaf)
	{
		TreeLeaf* current = Leaf;
			
		if (current->left != TNull)
		{
			while (current->left != TNull)
			{
				current = current->left;
			}

			return current;
		}
		else
		{
			return current;
		}
			
	}

	void Add_Equal(ListNode* head, ListNode* equal)
	{
		ListNode* current = head;

		while (current->next != NULL)
		{
			current = current->next;
		}

		current->next = equal;

	}

	void Delete_Equal(ListNode* Head)
	{
		ListNode* current = Head;
		while (current->next->next != NULL)
		{
			current = current->next;
		}

		delete current->next;
		current->next = NULL;
	}

	int Count_Equals(ListNode* head)
	{
		ListNode* current = head;
		int i = 0;

		while (current->next != NULL)
		{
			i++;
			current = current->next;
		}
		
		return i;
	}

	void Print_Leaf(TreeLeaf* Leaf, int h)
	{
		if (Leaf != TNull)
		{
			Print_Leaf(Leaf->right, h + 13);
			for (int i = 1; i <= h; i++)
			{
				cout << " ";
			}
			cout << "(" << Count_Equals(Leaf->key) << ")";
			cout << Leaf->key->first << '.' << Leaf->key->second << '.' << Leaf->key->third;
			cout << "(" << Leaf->color << ")" << endl;
			Print_Leaf(Leaf->left, h + 13);
		}
	}

	ListNode* Node_Construct(int first, int second, int third)
	{
		ListNode* Node = new ListNode;
		Node->first = first;
		Node->second = second;
		Node->third = third;
		Node->next = NULL;
		return Node;
	}

	bool Node_compareByKey(ListNode* largest, ListNode* smallest)
	{
		if (largest->first == smallest->first)
		{
			if (largest->second == smallest->second)
			{
				if (largest->third == smallest->third)
				{
					return false;
				}
				else if (largest->third > smallest->third)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else if (largest->second > smallest->second)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (largest->first > smallest->first)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Node_isEqualByKey(ListNode* left, ListNode* right)
	{
		if (left->first == right->first)
		{
			if (left->second == right->second)
			{
				if (left->third == right->third)
				{
					return true;
				}
			}
		}

		return false;
	}

	bool Symmetric_Bypass(TreeLeaf* Leaf1, TreeLeaf* Leaf2)
	{
		if (Leaf1->key == NULL && Leaf2->key == NULL) 
		{ 
			return true; 
		}

		if (Leaf1->key != NULL && Leaf2->key != NULL) 
		{ 
			return Symmetric_Bypass(Leaf1->left, Leaf2->left) &&
				   (Node_isEqualByKey(Leaf1->key, Leaf2->key)) &&
				   Symmetric_Bypass(Leaf1->right, Leaf2->right);
		}
		else 
		{ 
			return false; 
		}

	}

	void Clear_Tree(TreeLeaf* Leaf)
	{
		if (Leaf->left != TNull)  
		{ 
			Clear_Tree(Leaf->left); 
		}
		if (Leaf->right != TNull) 
		{ 
			Clear_Tree(Leaf->right); 
		}

		delete Leaf;
	}

public:
	
	RBT()
	{
		root = NULL;

		TNull->color = BLACK;
		TNull->key = NULL;
		TNull->left = NULL;
		TNull->parent = NULL;
		TNull->right = NULL;
	}

	void Add_Leaf(int first, int second, int third)  // Add equals in list (With repeats)
	{
		ListNode* ckey = Node_Construct(first, second, third);
		TreeLeaf* leaf = new TreeLeaf;
		leaf->color = RED;
		leaf->key = ckey;
		leaf->parent = TNull;
		leaf->left = TNull;
		leaf->right = TNull;

		if (root == NULL)
		{
			leaf->color = BLACK;
			root = leaf;
		}
		else
		{
			TreeLeaf* current = root;

			while (!Node_isEqualByKey(current->key, ckey) && (((Node_compareByKey(current->key, ckey)) && (current->left != TNull)) || ((Node_compareByKey(ckey, current->key)) && (current->right != TNull))))
			{
				if (Node_compareByKey(current->key, ckey))
				{
					current = current->left;
				}
				else if (Node_compareByKey(ckey, current->key))
				{
					current = current->right;
				}
			}

			if (Node_isEqualByKey(current->key, ckey))
			{
				delete leaf;
				Add_Equal(current->key, ckey);
			}
			else if (Node_compareByKey(current->key, ckey))
			{
				leaf->parent = current;

				current->left = leaf;

				Balance(leaf);
			}
			else if (Node_compareByKey(ckey, current->key))
			{
				leaf->parent = current;

				current->right = leaf;

				Balance(leaf);
			}
		}
	}

	void Delete_Leaf(int first, int second, int third)  // Change to the minimum on the right
	{
		if (root != NULL)
		{
			ListNode* ckey = Node_Construct(first, second, third);
			TreeLeaf* current = root;

			while ((current != TNull) && !Node_isEqualByKey(current->key, ckey))
			{
				if (Node_compareByKey(current->key, ckey))
				{
					current = current->left;
				}
				else if (Node_compareByKey(ckey, current->key))
				{
					current = current->right;
				}
			}

			if (current != TNull)
			{ 
				if (Count_Equals(current->key) == 0)
				{
					delete current->key;
					current->key = NULL;
					Delete_Leaf(current);
				}
				else
				{
					Delete_Equal(current->key);
				}
			}
		}
	}

	void Clear_Tree()
	{
		if (root != NULL)
		{
			if (root->left == TNull)
			{
				Clear_Tree(root->right);
			}
			else
			{
				Clear_Tree(root->left);
			}
		}
		delete root;
		root = NULL;
	}

	bool Find_Leaf(int first, int second, int third)
	{
		if (root == NULL) { return false; }
		else
		{
			ListNode* ckey = Node_Construct(first, second, third);
			TreeLeaf* current = root;

			while ((current != TNull) && !Node_isEqualByKey(current->key, ckey))
			{
				if (Node_compareByKey(current->key, ckey))
				{
					current = current->left;
				}
				else if (Node_compareByKey(ckey, current->key))
				{
					current = current->right;
				}
			}

			if (current != TNull) 
			{ 
				return true; 
			}
			else 
			{ 
				return false; 
			}
		}
	}

	void Print_Tree(int h)
	{
		if (root == NULL)
		{
			cout << "Tree is empty. \n";
		}
		else
		{
			Print_Leaf(root->right, h + 13);
			for (int i = 1; i <= h; i++)
			{
				cout << " ";
			}
			cout << "(" << Count_Equals(root->key) << ")";
			cout << root->key->first << '.' << root->key->second << '.' << root->key->third;
			cout << "(" << root->color << ")" << endl;
			Print_Leaf(root->left, h + 13);
		}
		cout << endl << "--------------------------------------------------------------------" << endl;
	}

	bool Compare(RBT tree2)  // Two trees are equal if they contain the same by key elements
	{
		if (root == NULL && tree2.root == NULL) 
		{ 
			return true; 
		}

		if (root != NULL && tree2.root != NULL) 
		{ 
			return Symmetric_Bypass(root, tree2.root); 
		}
		else 
		{ 
			return false; 
		}
	}

};

int main(){
	RBT one;

	one.Add_Leaf(15, 15, 44);
	one.Add_Leaf(15, 14, 44);
	one.Add_Leaf(15, 26, 44);
	one.Add_Leaf(15, 25, 44);
	one.Add_Leaf(15, 26, 44);
	one.Add_Leaf(15, 25, 44);
	one.Add_Leaf(16, 26, 45);
	one.Add_Leaf(12, 15, 44);
	one.Add_Leaf(12, 14, 44);
	one.Add_Leaf(12, 26, 44);

	one.Delete_Leaf(12, 26, 44);
	one.Delete_Leaf(15, 15, 44);

	one.Print_Tree(2);


	return 0;	
}
