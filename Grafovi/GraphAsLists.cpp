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
	while (temp != nullptr && temp->info != info)
		temp = temp->next; //sl u listi cvorova
	return temp; //ili kraj(nullptr) ili nadjen odg cvor
}

Edge* GraphAsLists::findEdge(int a, int b)
{
	LinkedNode* nodeA = this->findNode(a);
	LinkedNode* nodeB = this->findNode(b);
	if (nodeA == nullptr || nodeB == nullptr)
		return nullptr; //nema jednog od cvorova pa nema ni potega
	Edge* temp = nodeA->adj; //lista potega cvora A
	while (temp != nullptr && temp->dest != nodeB)
		temp = temp->link;
	return temp;
}

bool GraphAsLists::insertNode(int info)
{
	LinkedNode* newNode = new LinkedNode(info, nullptr, this->start, 0); //novi cvor sa info, praznom listom potega i statusom 0
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
		deleteEdgeToNode(temp); //brisanje potega koji vode do ovog cvora drugih cvorva
		temp2->next = temp->next; //prelancavanje
		Edge* temp3 = temp->adj;
		while (temp3 != nullptr) //brisanje liste potega
		{
			Edge* temp4 = temp3->link;
			delete temp3;
			temp3 = temp4;
		}

		delete temp;
		--this->numberOfNodes;
		return true;
	}
}

bool GraphAsLists::insertEdge(int a, int b)
{
	LinkedNode* nodeA = this->findNode(a);
	LinkedNode* nodeB = this->findNode(b);
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
	LinkedNode* nodeA = this->findNode(a);
	LinkedNode* nodeB = this->findNode(b);
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
	while (temp2->link != temp) //trazenje prethodnika u listi potega
		temp2 = temp2->link; //zbog prelancavanja
	temp2->link = temp->link; //prelancavanje
	delete temp;
	return true;
}

int GraphAsLists::breadthTrav(int a)
{
	int count = 0;
	LinkedNode* temp = this->start;
	QueueAsArray* queue = new QueueAsArray(this->numberOfNodes);
	while (temp != nullptr)
	{
		temp->status = 1; //na cekanju
		temp = temp->next;
	}
	temp = this->findNode(a);
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
	while (temp != nullptr)
	{
		temp->status = 1; //na cekanju
		temp = temp->next;
	}
	temp = this->findNode(a);
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
				temp2->dest->status = 2; //na stacku
			}
			temp2 = temp2->link;
		}
	}
	delete stack;
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

void GraphAsLists::povratniPoteg(int info)
{
	LinkedNode* temp = this->findNode(info);
	if (temp != nullptr) //ako ima datog cvora
	{
		Edge* temp2 = temp->adj;
		while (temp2 != nullptr) //prolazak liste potega
		{
			LinkedNode* temp3 = temp2->dest;
			Edge* temp4 = temp3->adj;
			if (temp4 != nullptr) //ako ima potege trenutni cvor
			{
				Edge* temp5 = temp4;
				while (temp4 != nullptr && temp4->dest != temp)
				{
					temp5 = temp4;
					temp4 = temp4->link;
				}
				if (temp4 != nullptr)
				{
					if (temp5 == temp4 && temp4->link == nullptr) //ako ima samo jedan poteg
					{
						temp3->adj = nullptr;
						delete temp4;
					}
					else if (temp5 == temp4)
					{
						temp3->adj = temp5->link;
						delete temp4;
					}
					else
					{
						temp5->link = temp4->link;
						delete temp4;
					}
				}
			}
			temp2 = temp2->link;
		}
	}
}

int GraphAsLists::brojCvorova(int info, int duzina)
{
	int count = 0;
	LinkedNode* temp = this->findNode(info);
	QueueAsArray* queue = new QueueAsArray(this->numberOfNodes);
	if (temp != nullptr)
	{
		LinkedNode* temp2 = this->start;
		while (temp2 != nullptr)
		{
			temp2->status = 0; //ukoliko je bio neki obilazak pre ne bi bilo 0
			temp2->put = 0; //ukoliko je vec bila zvana funkcija
			temp2 = temp2->next;
		}
		Edge* temp3 = temp->adj;
		while (temp3 != nullptr)
		{
			temp2 = temp3->dest;
			if (temp2->status == 0)
			{
				queue->enqueue(temp2);
				while (!queue->isEmpty())
				{
					temp2 = queue->dequeue();
					if (temp2->status == 0)
					{
						temp2->status = 3; //obradjen
						++temp2->put; //doslo se do njega vec jednom
						++count; //broji se cvor
						Edge* temp4 = temp2->adj;
						if ((temp2->put + 1) < duzina) //ako bi put do sledeceg bio veci od duzine ni ne treba uzimati u obzir
						{
							while (temp4 != nullptr) //po listi potega trenutnog cvora u temp1
							{
								if (temp4->dest->status != 3) //ako nije vec obradjen
								{
									temp4->dest->put = temp2->put;
									queue->enqueue(temp4->dest); //u red 
								}
								temp4 = temp4->link;
							}
						}
					}
				}
			}
			temp3 = temp3->link;
		}
	}
	delete queue;
	return count;
}