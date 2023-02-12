#include <iostream>
#include <vector>

using namespace std;

unsigned int n = 5, r = 3, a[5] = {1, 2, 3, 4, 5};

void print(vector<int> b)
{
    for (auto i : b)
        cout << i << " ";
    cout << '\n';
}

void combi(int start, vector<int> b)
{
    if (b.size() == r)
    {
        print(b);
        return ;
    }
    for (unsigned int i = (unsigned int)(start + 1); i < n; i++)
    {
        b.push_back(a[i]);
        combi(i, b);
        b.pop_back();
    }
    return ;
}

int main()
{
    vector<int> b;
    combi(-1, b);
    return 0;
}