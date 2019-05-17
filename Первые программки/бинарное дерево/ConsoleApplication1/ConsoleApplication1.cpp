#include <iostream>
#include <string>

class Tree
{
	struct Tnode
	{
		std::string word;
		int count;
		Tnode* left,
			 * right;
	};

	Tnode* tnode;

public:
	Tree() : tnode (0) {}

	void add(std::string word)
	{
		Tnode* newTnode = new Tnode;
		newTnode->word = word;
		newTnode->count = 1;
		newTnode->left = 0;
		newTnode->right = 0;

		if (tnode == 0)
		{
			tnode = newTnode;

		} else {

			if (tnode->word > newTnode->word)
			{
				tnode = tnode->left;
				add(word);

			} else if (tnode->word < newTnode->word) {

				tnode = tnode->right;
				add(word);

			} else {

				tnode->count++;
			}
		}
	}

	void print()
	{
		if (tnode)
		{
			std::cout << tnode->word << " - " << tnode->count << std::endl;
			Tnode* right = tnode->right;
			Tnode* left = tnode->left;
			tnode = right;
			(*this).print();
			tnode = left;
			(*this).print();
		}
	}
};

/*void addTnode(std::string word, Tnode** tnode)
{
	Tnode* newTnode = new Tnode;
	newTnode->word = word;
	newTnode->count = 1;
	newTnode->left = 0;
	newTnode->right = 0;
	if ((*tnode) != 0)
	{
		if ((*tnode)->word > newTnode->word)
		{
			addTnode(word, &(*tnode)->left);
		} 
		else if ((*tnode)->word < newTnode->word)
		{
			addTnode(word, &(*tnode)->right);
		}
		else
		{
			(*tnode)->count++;
		}
	}
	else {
		(*tnode) = newTnode;
	}
}

void printTnode(Tnode** tnode)
{
	if ((*tnode) == 0) return;

	std::cout << (*tnode)->word << " - " << (*tnode)->count << std::endl;
	printTnode(&(*tnode)->left);
	printTnode(&(*tnode)->right);
}*/

int main(int argc, char* argv[])
{
	Tree tree;

	tree.add("a");
	tree.add("a");
	tree.add("b");
	tree.add("o");
	tree.add("s");
	tree.add("z");
	tree.print();
	/*Tnode* tree = 0;

	addTnode("abc", &tree);
	addTnode("bbc", &tree);
	addTnode("abc", &tree);
	addTnode("zbc", &tree);
	addTnode("xbc", &tree);
	addTnode("bbc", &tree);	
	addTnode("pbc", &tree);
	addTnode("qbc", &tree);

	printTnode(&tree);*/
}