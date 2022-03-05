//�׶����� ������ ������κ��� ������ ���� �˻��ϱ�

#include <iostream>
#include <forward_list>
#include <vector>

int main()
{
	std::vector < std::string> vec = {
	"Lewis Hamilton", "Lewis Hamilton", "Nico Roseberg", 
	"Sebastian Vettel", "Lewis Hamilton", "Sebastian Vettel", 
	"Sebastian Vettel", "Sebastian Vettel", "Fernando Alonso" };
	
	auto it = vec.begin(); //��� �ð� (Vector)
	std::cout << "���� �ֱ� �����: " << *it << std::endl;

	it += 8; //��� �ð� (Vector)
	std::cout << "8�� �� �����: " << *it << std::endl;
	
	advance(it, -3); //��� �ð�(Vector)
	std::cout << "���� 3�� �� �����: " << *it << std::endl;

	//*******************************************************************************
	std::forward_list<std::string> fwd(vec.begin(), vec.end());

	auto it1 = fwd.begin();
	std::cout << "���� �ֱ� �����: " << *it1 << std::endl;

	advance(it1, 5); //���� �ð�(forward_list)
	std::cout << "5�� �� �����: " << *it << std::endl;

	//std::forward_list�� ���������θ� �̵��� �� �����Ƿ�
	//�Ʒ� �ڵ�� ������ �߻��Ѵ�.
	//advance(it1, -2);

}