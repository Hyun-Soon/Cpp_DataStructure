//중앙값 구하기
//
//두 개의 힙(최대 힙, 최소 힙)을 사용하여 데이터를 저장한다. 새로 들어오는 데이터가 기존 데이터의 중앙값보다 작으면 최대 힙에 저장하고,
// 크면 최소 힙에 저장한다. 이런 방식을 통해 두 힙의 최상단 원소를 이용하여 중앙값을 계산할 수 있다.

#include <iostream>
#include <queue>
#include <vector>

struct median
{
    std::priority_queue<int> maxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    void insert(int data)
    {
        if (maxHeap.size() == 0)
        {
            maxHeap.push(data);
            return;
        }

        if (maxHeap.size() == minHeap.size())
        {
            if (data <= get())
                maxHeap.push(data);
            else
                minHeap.push(data);

            return;
        }

        if (maxHeap.size() < minHeap.size())
        {
            if (data > get())
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(data);
            }
            else
                maxHeap.push(data);

            return;
        }

        if (data < get())
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(data);
        }
        else
            minHeap.push(data);
    }

    double get() //저장된 원소로부터 중앙값을 구하여 반환하는 함수
    {
        if (maxHeap.size() == minHeap.size())
            return (maxHeap.top()+minHeap.top())/2.0;

        if (maxHeap.size() < minHeap.size())
            return minHeap.top();

        return maxHeap.top();
    }
};

int main()
{
    median med;

    med.insert(1);
    std::cout << "1 삽입 후 중앙값: " << med.get() << std::endl;

    med.insert(5);
    std::cout << "5 삽입 후 중앙값: " << med.get() << std::endl;

    med.insert(2);
    std::cout << "2 삽입 후 중앙값: " << med.get() << std::endl;

    med.insert(10);
    std::cout << "10 삽입 후 중앙값: " << med.get() << std::endl;
}