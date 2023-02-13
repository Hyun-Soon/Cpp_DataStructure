/******************************* 
*     백준 13913  : 숨바꼭질 4    *
*******************************/                      

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, k, here, ret;
int visited[200004];
int prev_pos[200004];
queue<int> q;
vector<int> v;

int main()
{
    cin >> n >> k;
    visited[n] = 1;
    q.push(n);
    while (q.size())
    {
        here = q.front();
        if (here == k)
        {
            ret = visited[here];
            break;
        }
        q.pop();

        for (auto i : {here + 1, here - 1, 2 * here})
        {
            if (i < 0 || i > 200000 || visited[i] != 0)
                continue ;
            prev_pos[i] = here;
            visited[i] = visited[here] + 1;
            q.push(i);
        }
    }

//***************************************/
//      이렇게 작성하면 메모리 초과 발생.
//      변수 할당 최대한 줄이자.
//     while (prev_pos[here] != n)
//     {
//         v.push_back(prev_pos[here]);
//         here = prev_pos[here];
//     }
//***************************************/

    for (int i = k; i != n; i = prev_pos[i])
    {
        v.push_back(i);
    }
    v.push_back(n);
    reverse(v.begin(), v.end());
    cout << ret - 1 << '\n';
    for (auto i : v)
        cout << i << ' ';
    cout << '\n';
    return 0;
}