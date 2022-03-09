#include <queue>
#include <iostream>
#include <sstream>

struct Job
{
	int ID;
	std::string username;
	int pages;
};

class Printer
{
public:

	std::queue<Job> printList;
	

	void requestPrint(Job& task)
	{
		printList.push(task);
		return;
	}

	friend std::ostream& operator<<(std::ostream& os, Job& j)
	{
		os << "ID : " << j.ID << ", username : " << j.username << ", pages : " << j.pages << std::endl;
		return os;
	}

	void print()
	{
		auto p = printList.front();

		//std::cout << p;
	}
};

int main()
{
	Job a = {3, "soon", 10};
	Printer b;
	b.requestPrint(a);
	std::cout << b.printList.front();


	return 0;
}