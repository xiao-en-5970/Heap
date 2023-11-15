#include <cstdio>
#include <iostream>
using namespace std;

typedef struct heap
{
	int capacity;
	int size;
	int element[999];
} Heap, * pHeap;

pHeap init_heap(int max_element);
bool isempty(pHeap hp);
bool isfull(pHeap hp);
void insert_heap(int data, pHeap hp);
int delete_min(pHeap hp);
void print_heap(pHeap hp);


int main()
{
	pHeap hp = init_heap(20);
	insert_heap(13, hp);
	insert_heap(4, hp);
	insert_heap(33, hp);
	insert_heap(2, hp);
	insert_heap(29, hp);
	insert_heap(11, hp);

	print_heap(hp);

	delete_min(hp);
	print_heap(hp);

	return 0;
}

pHeap init_heap(int max_element)
{
	pHeap h = new Heap;
	h->capacity = max_element;
	h->size = 0;
	h->element[0] = -9999;
	cout << "�ѳ�ʼ����" << "\n";
	return h;
}

bool isempty(pHeap hp)
{
	return hp->size == 0;
}

bool isfull(pHeap hp)
{
	return hp->size == hp->capacity;
}

void insert_heap(int data, pHeap hp)
{
	if (isfull(hp))
	{
		printf("��������size̫���ˣ��岻��ȥ\n");
		return;
	}
	if (data < -9999)
	{
		printf("��̫С�ˣ��Ҳ�ϲ��С��\n");
		return;
	}
	int i;
	for (i = ++hp->size; data < hp->element[i / 2]; i /= 2)
	{
		hp->element[i] = hp->element[i / 2];
	}
	hp->element[i] = data;
	printf("�Ѳ��룺%d\n", data);
}
int delete_min(pHeap hp)
{
	if (isempty(hp))
	{
		cout << "��Ϊ�գ��޷�ɾ��\n";
	}
	int min = hp->element[1];
	int last = hp->element[hp->size];
	hp->size--;
	int i;
	for (i = 1; i * 2 <= hp->size; i *= 2)
	{
		if (hp->element[i * 2] < hp->element[i * 2 + 1])
		{
			hp->element[i] = hp->element[i * 2];
		}
		else
		{
			hp->element[i] = hp->element[i * 2 + 1];
			i++;
		}
	}
	hp->element[i] = last;
	printf("ɾ����Сֵ��%d\n", min);
	return min;
}
void print_heap(pHeap hp)
{
	cout << "��ӡ����ѣ�";
	for (int i = 1; i <= hp->size; i++)
	{
		cout << hp->element[i] << " ";
	}
	cout << "\n";
}