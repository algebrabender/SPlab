#include "BST.h"
#include "QueueAsArray.h"
#include "StackAsArray.h"

BST::~BST()
{
	if (root != nullptr)
		deleteTree(this->root);
}

void BST::deleteTree(BSTNode* node)
{
	if (node != nullptr)
	{
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
		node = nullptr;
	}
}

BSTNode* BST::search(BSTNode* node, int key)
{
	while (node != nullptr)
	{
		if (node->isEqual(key))
			return node; //kada se nadje odgovarajuci key vraca se iz f-je
		else if (node->isGreater(key)) //zbog uredjenosti stabla
			node = node->left; //levo podstablo ima manje vrednost za key
		else
			node = node->right; //desno podstablo ima vece vredost za key
	}
	return nullptr; //znaci da se izaslo iz petlje tj nije nadjen key
}

void BST::insert(int key)
{
	BSTNode* temp = this->root; //za trazenje mesta
	BSTNode* prev = nullptr; //za prelancavanje
	while (temp != nullptr)
	{
		prev = temp;
		if (temp->isLower(key)) //ako je veci treba da icice se u levo podstablo
			temp = temp->right; //ako je manji ide se u desno podstablo
		else
			temp = temp->left; 
	}
	if (this->root == nullptr) //ako je stablo prazno
		this->root = new BSTNode(key);
	//ako nije stablo prazno iz petlje se izaslo jer je nadjeno mesto
	else if (prev->isLower(key)) //provera da li se dodaje u desno ili levo dete
		prev->right = new BSTNode(key);
	else
		prev->left = new BSTNode(key);
	++this->numOfEl;
}

void BST::breadthFirst()
{
	BSTNode* temp = this->root;
	QueueAsArray* queue = new QueueAsArray(this->numOfEl); //red za redosled
	if (temp != nullptr) //ako ima cvorova
	{
		queue->enqueue(temp); //ubacuje se root u red
		while (!queue->isEmpty())
		{
			temp = queue->dequeue(); //vraca se node za obradu
			temp->visit(); //posecuje se node
			if (temp->left != nullptr) //ako ima levo dete
				queue->enqueue(temp->left); //ubacuje se levo dete u red
			if (temp->right != nullptr) //ako ima desno dete
				queue->enqueue(temp->right); //ubacuje se desno dete u red
		}
	}
	delete queue;
}

void BST::inorder(BSTNode* node)
{
	if (node != nullptr)
	{
		inorder(node->left);
		node->visit();
		inorder(node->right);
	}
}
//algoritam sa slajdova sa predavanja
void BST::iterativeInorder()
{
	BSTNode* temp = this->root;
	StackAsArray* stack = new StackAsArray(this->numOfEl); //stack za redosled
	stack->push(nullptr); //kada se dodje do kraja obilaska
	while (temp != nullptr)
	{
		while (temp != nullptr) //sva leva deca na stack
		{
			stack->push(temp);
			temp = temp->left;
		}
		temp = stack->pop(); //poslednje levo dete
		while (temp != nullptr)
		{
			temp->visit(); //posecuje se levo dete
			if (temp->right != nullptr) //ako ima desno dete
			{
				temp = temp->right;
				stack->push(temp); //desno dete na stack
				while (temp->left != nullptr) //ako desno dete ima levo dete
				{ 
					//opet sva leva deca na stack kao prva petlja (umesto go to sa prez)
					temp = temp->left;
					stack->push(temp);
				}
			}
			temp = stack->pop(); //bice nullptr sa pocetka ili levo dete
		}
	}
	delete stack;
}

int BST::brojCvorova(BSTNode* node)
{
	int count = 1;
	if (node != nullptr)
	{
		if (node->right != nullptr) // ako ima desno dete
		{
			count += brojCvorova(node->right);
			if (node->left != nullptr)
				--count;
		}
	}
	return count;
}