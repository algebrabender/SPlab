#include "MinHeap.h"
#include "StackAsArray.h"

MinHeap::MinHeap(int length)
{
	if (length > 0)
	{
		this->length = length + 1; //jer se ne stavlja na nultu poziciju
		this->heap = new int[length + 1];;
		this->numOfEl = 0;
	}
	else
		throw exception("Nevalidna velicina");
}

MinHeap::~MinHeap()
{
	if (this->heap != nullptr)
	{
		delete[] this->heap;
		heap = nullptr;
	}
}
void MinHeap::insert(int key)
{
	if (this->numOfEl >= this->length)
		throw exception("Heap je pun");
	else
	{
		++this->numOfEl; //da bi prvi element bio na poziciji 1
		int i = this->numOfEl;
		while (i > 1 && this->heap[i / 2] > key) //traziti se odgovarajuce mesto
		{
			this->heap[i] = this->heap[i / 2]; //pomeranje
			i /= 2;
		}
		//iz petlje se izaslo ili jer je i = 1 pa tu treba ubaciti element
		//ili jer je heap[i/2] vece od element pa na poziciju i treba staviti element
		this->heap[i] = key;
	}
}

int MinHeap::deleteRoot()
{
	if (this->numOfEl == 0)
		throw exception("Heap je prazan");
	else
	{
		int temp = this->heap[1];
		int last = this->heap[this->numOfEl];
		--this->numOfEl;
		int i = 1;
		while (i * 2 < this->numOfEl + 1) //dok je i u opstegu
		{
			int child = 2 * i; //levo dete trenutnog i
			if (child + 1 < (this->numOfEl + 1) && this->heap[child + 1] < this->heap[child])
				//ako je sl el u opsegu i ako se odrzava heap order
				child += 1; //prelazi se na sledeci el
			if (last <= this->heap[child]) //ako je poslednji el manji ili jednak trenutnom detetu
				break; //pomeranje je zavrseno 
			//ako nije kraj
			this->heap[i] = this->heap[child]; //pomeranje
			i = child;
		}
		this->heap[i] = last; //ako nije bilo break treba prebaciti
		return temp; //vracanje korena
	}
}

void MinHeap::breadthFirst()
{
	for (int i = 1; i <= this->numOfEl; i++)
		cout << this->heap[i] << " ";
}

void MinHeap::preorder(int index)
{
	if (index > 0 && index <= this->numOfEl)
	{
		cout << this->heap[index] << " ";
		preorder(index * 2); //preorder za levo dete
		preorder(index * 2 + 1); //preorder za desno dete
	}
}

void MinHeap::iterativePreorder() //ne radi kako treba za sada
{
	int i = 1;
	int temp = this->heap[i];
	StackAsArray* stack = new StackAsArray(this->numOfEl);
	if (this->numOfEl != 0) //ako ima elementa
	{
		stack->push(temp); //prvi na stack
		while (i < this->numOfEl)
		{
			temp = stack->pop();
			cout << temp << " ";
			if ((i * 2 + 1) < this->numOfEl) //desno dete
				stack->push(this->heap[i * 2 + 1]);
			if ((i * 2) < this->numOfEl)
				stack->push(this->heap[i * 2]);
			i *= 2;
		}
		while (!stack->isEmpty())
		{
			temp = stack->pop();
			cout << temp << " ";
		}
	}
	delete stack;
}

void MinHeap::toBST()
{
	int i = 1;
	BSTNode* root = nullptr;
	if (this->heap[i] != NULL)
	{
		root = new BSTNode(this->heap[i]);
		if (i * 2 < this->numOfEl)
			root->addLeft(new BSTNode(this->heap[i * 2]));
		if (i * 2 + 1 < this->numOfEl)
			root->addRight(new BSTNode(this->heap[i * 2 + 1]));
		i = 2; //levo dete roota
		int j = 3; //desno dete roota
		BSTNode* temp = root->left;
		BSTNode* temp2 = root->right;
		while (j < this->numOfEl && i < this->numOfEl) 
		{
			//levo podstablo roota
			if (i * 2 < this->numOfEl)
				temp->addLeft(new BSTNode(this->heap[i * 2]));
			if ((i * 2 + 1) < this->numOfEl)
				temp->addRight(new BSTNode(this->heap[i * 2 + 1]));
			temp = temp->left;
			i *= 2;
			//desno podstablo roota
			if (j * 2 <= this->numOfEl)
				temp2->addLeft(new BSTNode(this->heap[j * 2]));
			if ((j* 2 + 1) <= this->numOfEl)
				temp2->addRight(new BSTNode(this->heap[j * 2 + 1]));
			temp2 = temp2->left;
			j = j * 2 + 1;
		}
	}
	//za proveru da li je dobro ulancano bst
	preorderBST(root);
}

void MinHeap::preorderBST(BSTNode* node)
{
	if (node != nullptr) {
		node->visit();
		preorderBST(node->left);
		preorderBST(node->right);
	}
}