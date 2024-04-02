//线性表的链式存储结构--链表
//每个物理结点增加一个指向后继结点的指针域(?)--单链表
//每个物理结点增加一个指向后继结点的指针域(?)以及一个指向前驱结点的指针域(?)--双链表
//注意：带头结点的单/双链表,以及带上头结点的优点。。。

#include<iostream>

struct Node
{
	int data;
	Node* next;
};

//头插法建表
void CreateListH(Node* &Head_Node, int arr[], int length)
{
	Node* temp;
	Head_Node->next = NULL; //开始时头结点置空
	for (int i = 0; i < length; ++i)
	{
		temp = new Node;
		temp->data = arr[i];
		temp->next = Head_Node; //头插法，将数据结点temp插入头结点之后，原数据结点之前
		Head_Node = temp;
	}
}

//尾插法建表 ??
void CreateListL(Node* &Head_Node, int arr[], int length)
{
	Node* temp;
	Node* Last_Node = new Node;
	Head_Node = new Node;
	Last_Node = Head_Node; //始终指向尾结点，初始指向头结点
	for (int i = 0; i < length; ++i)
	{
		temp = new Node;
		temp->data = arr[i];
		Last_Node->next = temp; //尾插法，将数据结点temp插入尾结点之后
		Last_Node = temp;
	}
	Last_Node->next = NULL; //!尾结点的next需置空
}

void OutputData(Node*& head)
{
	while (head->next != NULL)
	{
		std::cout << head->data << " ";
		head = head->next;
	}
	std::cout << std::endl;
}

int main()
{
	int arr[5]{ 3, 2, 12, 132, 0 };
	Node* head = new Node;
	Node* last = new Node;
	int arr2[7]{2234, 33, 9, 21, 121, 132231, 0 };
	CreateListH(head, arr, 5);
	OutputData(head);

	CreateListL(last, arr2, 7);
	OutputData(last);

	return 0;
}