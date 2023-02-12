#include <iostream>
#include <vector>

using namespace std;

int n = 5, r = 3, a[5] = {1, 2, 3, 4, 5};

//*******************************//
// r이 작을 때는 중첩 for문을 사용하자. //
//*******************************//

int main()
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                cout << a[i] << ' ' << a[j] << ' ' << a[k] << '\n';
    return 0;
}