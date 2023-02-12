#include <iostream>
#include <vector>

using namespace std;

int a[3] = {1, 2, 3};
vector<int> v;

void printV(vector<int> &v)
{
    for (unsigned int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << "\n";
}

void make_permutation(int n, int depth)
{
    if (n == depth)
    {
        printV(v);
        return ;
    }
    for (int i = depth; i < n; i++)
    {
        swap(v[i], v[depth]);
        make_permutation(n, depth + 1);
        swap(v[i], v[depth]);
    }
    return ;
}

int main()
{
    for (int i = 0; i < 3; i++)
        v.push_back(a[i]);
    make_permutation(3, 0);
    return 0;
}