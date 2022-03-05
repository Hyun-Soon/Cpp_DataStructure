//기본적인 사용자 정의 컨테이너 만들기

#include <iostream>
//#include <algorithm>

struct singly_ll_node
{
	int data;
	singly_ll_node* next;
};

class singly_ll
{
public:
	using node = singly_ll_node;
	using node_ptr = node*;

private:
	node_ptr head;

	//push_front, pop_front 구현하기
public:
	void push_front(int val)
	{
		auto new_node = new node{ val, NULL };
		if (head != NULL)
			new_node->next = head;
		head = new_node;
	}
};
