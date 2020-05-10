#include "GraphAsLists.h"
#include "QueueAsArray.h"
#include "StackAsArray.h"

GraphAsLists::~GraphAsLists()
{
	LinkedNode* temp = this->start;
	while (temp != nullptr)
		deleteNode(temp->info);
	this->start = nullptr;
}

LinkedNode* GraphAsLists::findNode(int info)
{
	LinkedNode* temp = start;
	while (temp!=nullptr && temp->info != info)
		temp = temp->next; //sl u listi cvorova
	return temp; //ili kraj(nullptr) ili nadjen odg cvor
}

Edge* GraphAsLists::findEdge(int a, int b)
{
	LinkedNode* nodeA = findNode(a);
	LinkedNode* nodeB = findNode(b);
	if (nodeA == nullptr || nodeB == nullptr)
		return nullptr; //nema jednog od cvorova pa nema ni potega
	Edge* temp = nodeA->adj; //lista potega cvora A
	while (temp != nullptr && temp->dest != nodeB)
		temp = temp->link;
	return temp;
}

bool GraphAsLists::insertNode(int info)
{
	LinkedNode* newNode = new LinkedNode(info, nullptr,this->start, 0); //novi cvor sa info, praznom listom potega i statusom 0
	//start je da bi ukazivalo na prvi cvor u listi cvorova
	if (newNode == nullptr)
		return false; //ako nije doslo do kreiranja cvora
	this->start = newNode; //novi cvor je sada prvi u listi cvorova
	++this->numberOfNodes;
	return true;
}

bool GraphAsLists::deleteNode(int info)
{
	if (this->start == nullptr) //ako nema grafa
		return false;
	LinkedNode* temp;
	if (this->start->info == info) //ako je bas prvi cvor
	{
		Edge* temp2 = this->start->adj;
		while (temp2 != nullptr)
		{
			Edge* temp3 = temp2->link;
			delete temp2;
			temp2 = temp3;
		}
		deleteEdgeToNode(start); //da obrise sve potege drugih cvorova koji su ukazivali na ovaj
		temp = this->start;
		this->start = this->start->next; //prelancavanje
		delete temp;
		--this->numberOfNodes;
		return true;
	}
	else
	{
		temp = this->start->next;
		LinkedNode* temp2 = this->start; //za prelancavanje
		while (temp != nullptr && temp->info != info)
		{
			temp2 = temp;
			temp = temp->next;
		}
		if (temp == nullptr) //nema tog cvora
			return false;
		//ako ne nadjen cvor
		temp2->next = temp->next; //prelancavanje
		Edge* temp3 = temp->adj;
		while (temp3 != nullptr)
		{
			Edge* temp4 = temp3->link;
			delete temp3;
			temp3 = temp4;
		}
		deleteEdgeToNode(temp);
		delete(temp);
		--this->numberOfNodes;
		return true;
	}
}

bool GraphAsLists::insertEdge(int a, int b)
{
	LinkedNode* nodeA = findNode(a);
	LinkedNode* nodeB = findNode(b);
	if (nodeA == nullptr || nodeB == nullptr)
		return false; //ako cvor A ili cvor B ne postoje
	Edge* newEdge = new Edge(nodeB, nodeA->adj); //od A do B i ukazuje na prvog u listi potega
	if (newEdge == nullptr)
		return false; //ako nije doslo do kreiranja potega
	nodeA->adj = newEdge; //novi cvor prvi u listi potega
	return true;
}

bool GraphAsLists::deleteEdge(int a, int b)
{
	LinkedNode* nodeA = findNode(a);
	LinkedNode* nodeB = findNode(b);
	Edge* temp = nodeA->adj;
	while (temp != nullptr && temp->dest != nodeB) //provera da li u listi potega A ima potega do B
		temp = temp->link;
	if (temp == nullptr)
		return false; //nema potega od A do B
	if (temp == nodeA->adj) //ako nije ni uslo u while
	{
		nodeA->adj = temp->link; //prelancavanje;
		delete temp;
		return true;
	}
	//ako nije u temp je poteg koji treba obrisati
	Edge* temp2 = nodeA->adj;
	while (temp2->link != temp) //treazenje prethodnika u listi potega
		temp2 = temp2->link; //zbog prelancavanja
	temp2->link = temp->link; //prelancavanje
	delete temp;
	return true;
}

int GraphAsLists::breadthTrav(int a)
{
	int count = 0;
	LinkedNode* temp = start;
	QueueAsArray* queue = new QueueAsArray(this->numberOfNodes);
	while (temp != nullptr)
	{
		temp->status = 1; //na cekanju
		temp = temp->next;
	}
	temp = findNode(a);
	if (temp == nullptr)
		return 0; //nema tog cvora
	queue->enqueue(temp);
	temp->status = 2; //u redu
	while (!queue->isEmpty())
	{
		temp = queue->dequeue();
		temp->visit();
		temp->status = 3; //obradjen
		++count;
		Edge* temp2 = temp->adj; //po listi potega
		while (temp2 != nullptr)
		{
			if (temp2->dest->status == 1) //ako je na cekanju
			{
				queue->enqueue(temp2->dest);
				temp2->dest->status = 2; //u redu
			}
			temp2 = temp2->link;
		}
	}
	delete queue;
	return count;
}

int GraphAsLists::depthTrav(int a)
{
	int count = 0;
	LinkedNode* temp = this->start;
	StackAsArray* stack = new StackAsArray(this->numberOfNodes);
	return count;
	while (temp != nullptr)
	{
		temp->status = 1; //na cekanju
		temp = temp->next;
	}
	temp = findNode(a);
	if (temp == nullptr)
		return 0; //nema tog cvora
	stack->push(temp);
	temp->status = 2; //na stacku
	while (!stack->isEmpty())
	{
		temp = stack->pop();
		temp->visit();
		temp->status = 3;
		++count;
		Edge* temp2 = temp->adj; //po listi potega
		while (temp2 != nullptr)
		{
			if (temp2->dest->status == 1) //ako je na cekanju
			{
				stack->push(temp2->dest);
				temp2->dest->status = 2; //u redu
			}
			temp2 = temp2->link;
		}
	}
	delete stack;
	return count;
}

int GraphAsLists::topologicalOrderTrav()
{
	int count = 0;
	LinkedNode* temp = this->start;
	while (temp != nullptr)
	{
		temp->status = 0; //da svi imaju nula
		temp = temp->next;
	}
	temp = this->start;
	while (temp != nullptr)
	{
		Edge* temp2 = temp->adj;
		while (temp2 != nullptr)
		{
			temp2->dest->status += 1; //odredivanje tezine
			temp2 = temp2->link;
		}
		temp = temp->next;
	}
	QueueAsArray* queue = new QueueAsArray(this->numberOfNodes);
	temp = start;
	while (temp !=nullptr)
	{
		if (temp->status == 0) //svi cvorovi u queue
			queue->enqueue(temp);
		temp = temp->next;
	}
	while (!queue->isEmpty())
	{
		temp = queue->dequeue();
		temp->visit();
		++count;
		Edge* temp2 = temp->adj;
		while (temp2 != nullptr)
		{
			temp2->dest->status -= 1; //status mu se smanjuje
			if (temp2->dest->status == 0) //ako se smanjilo skroz do 0
				queue->enqueue(temp2->dest); //moze u red
			temp2 = temp2->link; 
		}
	}
	delete queue;
	return count;
}

void GraphAsLists::print()
{
	LinkedNode* temp = start; //od prvog cvora
	while (temp != nullptr)
	{
		cout << temp->info << "->";
		Edge* temp2 = temp->adj; //poteg trenutnog cvora
		while (temp2 != nullptr)
		{
			cout << temp2->dest->info << "|"; //stamapanje info cvora povezanog potegom
			temp2 = temp2->link; //na sledeci u listi
		}
		cout << endl;
		temp = temp->next; //sl u listi cvorova
	}
}

void GraphAsLists::deleteEdgeToNode(LinkedNode* node)
{
	LinkedNode* temp = start;
	while (temp != nullptr) //dok nije kraj liste cvorova
	{
		if (temp != node) //ako trenutni cvor nije cvor koji se brise
			deleteEdge(temp->info, node->info); //obrisace poteg izmedju trenutnog cvora i cvora za brisanje, ako ga ima
		temp = temp->next;
	}
}