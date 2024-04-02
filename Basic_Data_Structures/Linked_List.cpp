//���Ա����ʽ�洢�ṹ--����
//ÿ������������һ��ָ���̽���ָ����(?)--������
//ÿ������������һ��ָ���̽���ָ����(?)�Լ�һ��ָ��ǰ������ָ����(?)--˫����
//ע�⣺��ͷ���ĵ�/˫����,�Լ�����ͷ�����ŵ㡣����

#include<iostream>

struct Node
{
	int data;
	Node* next;
};

//ͷ�巨����
void CreateListH(Node* &Head_Node, int arr[], int length)
{
	Node* temp;
	Head_Node->next = NULL; //��ʼʱͷ����ÿ�
	for (int i = 0; i < length; ++i)
	{
		temp = new Node;
		temp->data = arr[i];
		temp->next = Head_Node; //ͷ�巨�������ݽ��temp����ͷ���֮��ԭ���ݽ��֮ǰ
		Head_Node = temp;
	}
}

//β�巨���� ??
void CreateListL(Node* &Head_Node, int arr[], int length)
{
	Node* temp;
	Node* Last_Node = new Node;
	Head_Node = new Node;
	Last_Node = Head_Node; //ʼ��ָ��β��㣬��ʼָ��ͷ���
	for (int i = 0; i < length; ++i)
	{
		temp = new Node;
		temp->data = arr[i];
		Last_Node->next = temp; //β�巨�������ݽ��temp����β���֮��
		Last_Node = temp;
	}
	Last_Node->next = NULL; //!β����next���ÿ�
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