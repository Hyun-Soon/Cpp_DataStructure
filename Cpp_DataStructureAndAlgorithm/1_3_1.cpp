#include <iostream>
#include <sstream>
#include <algorithm>

template <typename T>
class dynaamic_array
{
	T* data;
	size_t n;

public:
	// Constructor
	dynamic_array(int n) 
	{
		this->n = n;
		data = new T[n];
	}

	// Copy constructor
	dynamic_array(const dynamic_array<T>& other) 
	{
		n = other.n;
		data = new T[n];

		for (int i = 0; i < n; ++i)
		{
			data[i] = other[i];
		}
	}

	// Operator[] override
	T& operator[](int index)
	{
		return data[index];
	}

	const T& operator[](int index) const
	{
		return data[index];
	}

	T& at(int index)
	{
		if (index < n)
			return data[index];

	}
};

int main()
{
	


	return 0;
}