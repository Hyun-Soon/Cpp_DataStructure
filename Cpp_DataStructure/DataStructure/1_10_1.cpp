#include <iostream>
#include <queue>

class Job
{
	int id;
	std::string user;
	int pages;

	static int count;

public:
	Job(const std::string& u, int p) : user(u), pages(p), id(++count) {}

	friend std::ostream& operator<<(std::ostream& os, const Job& j)
	{
		os << "id : " << j.id << ", user : " << j.user << ", pages : " << j.pages;
		return os;
	}
};

