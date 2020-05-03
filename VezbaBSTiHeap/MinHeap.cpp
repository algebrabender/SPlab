#include "MinHeap.h"
#include "StackAsArray.h"

MinHeap::MinHeap(int length)
{
	if (length > 0)
	{
		this->length = length + 1; //jer se ne stavlja na nultu poziciju
		this->heap = new BSTNode*[length + 1];
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
void MinHeap::insert(BSTNode* node)
{
	if (this->numOfEl >= this->length)
		throw exception("Heap je pun");
	else
	{
		++this->numOfEl; //da bi prvi element bio na poziciji 1
		int i = this->numOfEl;
		while (i > 1 && this->heap[i / 2]->getKey() > node->getKey()) //traziti se odgovarajuce mesto
		{
			this->heap[i] = this->heap[i / 2]; //pomeranje
			i /= 2;
		}
		//iz petlje se izaslo ili jer je i = 1 pa tu treba ubaciti element
		//ili jer je heap[i/2] vece od element pa na poziciju i treba staviti element
		this->heap[i] = node;
	}
}

BSTNode* MinHeap::deleteRoot()
{
	if (this->numOfEl == 0)
		throw exception("Heap je prazan");
	else
	{
		BSTNode* temp = this->heap[1];
		BSTNode* last = this->heap[this->numOfEl];
		--this->numOfEl;
		int i = 1;
		while (i * 2 < this->numOfEl + 1) //dok je i u opstegu
		{
			int child = 2 * i; //levo dete trenutnog i
			if (child + 1 < (this->numOfEl + 1) && this->heap[child + 1]->getKey() < this->heap[child]->getKey())
				//ako je sl el u opsegu i ako se odrzava heap order
				child += 1; //prelazi se na sledeci el
			if (last->getKey() <= this->heap[child]->getKey()) //ako je poslednji el manji ili jednak trenutnom detetu
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
		this->heap[i]->visit();
}

void MinHeap::preorder(int index)
{
	if (index > 0 && index <= this->numOfEl)
	{
		this->heap[index]->visit();
		preorder(index * 2); //preorder za levo dete
		preorder(index * 2 + 1); //preorder za desno dete
	}
}

void MinHeap::iterativePreorder()
{
	int i = 1;
	BSTNode* temp;
	StackAsArray* stack = new StackAsArray(this->numOfEl);
	if (this->heap[i] != 0) //ako ima elementa
	{
		stack->push(this->heap[i]); //prvi na stack
		while (i < this->numOfEl)
		{
			temp = stack->pop();
			temp->visit();
			if ((i * 2 + 1) < this->numOfEl+1) //prvo desno dete zbog vracanja sa stacka
				stack->push(this->heap[i * 2 + 1]);
			if ((i * 2) < this->numOfEl+1)
				stack->push(this->heap[i * 2]);
			i *= 2;
		}
		while (!stack->isEmpty())
		{
			temp = stack->pop();
			temp->visit();
		}
	}
	delete stack;
}

void MinHeap::toBST()
{

}