#include <iostream>
#include <array>

int main()
{
	std::array<int, 10> arr1; //ũ�Ⱑ 10�� int Ÿ�� �迭 ����

	arr1[0] = 1; // ù��° ���Ҹ� 1�� ����
	std::cout << "arr1 �迭�� ù ��° ����: " << arr1[0] << std::endl;

	std::array<int, 4> arr2 = { 1,2,3,4 };
	std::cout << "arr2�� ��� ���� : ";
	
	for (int i = 0; i < arr2.size(); ++i)
		std::cout << arr2[i] << " ";
	std::cout << std::endl; 

	/*********************************************/

	std::array<int, 4> arr3 = { 1,2,3,4 };

	try
	{
		std::cout << arr3.at(3) << std::endl; // not error
		std::cout << arr3.at(4) << std::endl; // std::out_of_range exception occurs
	}
	catch (const std::out_of_range& ex)
	{
		std::cerr << ex.what() << std::endl;
	}


	return 0;
}