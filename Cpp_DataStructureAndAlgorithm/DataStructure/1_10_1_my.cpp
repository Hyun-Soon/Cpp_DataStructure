#include <queue>
#include <iostream>

struct Job
{
public:
	int ID;
	std::string username;
	int pages;

	friend std::ostream& operator<<(std::ostream& os, const Job& j);
};

class Printer
{

	std::queue<Job> printList;

public:
	Printer() = default;

	void requestPrint(Job& task)
	{
		printList.push(task);
		return;
	}

	friend std::ostream& operator<<(std::ostream& os, const Job& j)
	{
		os << "ID : " << j.ID << ", username : " << j.username << ", pages : " << j.pages << std::endl;
		return os;
	}

	void print()
	{
		while (!printList.empty())
		{
			auto p = printList.front();
			std::cout << p;
			printList.pop();
		}

		std::cout << "no more remaining print" << std::endl;
		return;
	}
};

int main()
{
	Printer printer;

	Job person1 = { 1, "hyunsoon", 3 };
	Job person2 = { 2, "sangjin", 4 };
	Job person3 = { 3, "gyugon", 1 };
	Job person4 = { 4, "chanjin", 2 };

	printer.requestPrint(person1);
	printer.requestPrint(person2);
	printer.print();
	printer.requestPrint(person3);
	printer.requestPrint(person4);
	printer.print();
	printer.print();
	printer.print();
	return 0;
}