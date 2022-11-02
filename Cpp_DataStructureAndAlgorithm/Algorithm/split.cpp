#include <iostream>
#include <vector>

using namespace std;

vector<string> split(string input, string delimiter)
{
    vector<string> ret;
    long long pos = 0;
    string token = "";

    while ((pos = input.find(delimiter)) != string::npos)
    {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    ret.push_back(input);

    return ret;
}

vector<string> split_debug(string input, string delimiter)
{
    vector<string> ret;
    long long pos = 0;
    string token = "";

    while ((pos = input.find(delimiter)) != string::npos)
    {
        long long pos = input.find(delimiter);
        cout << "POS : " << pos << '\n';
        if (pos == string::npos)
            break;
        
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    ret.push_back(input);
    return ret;
}

int main()
{
    string s = "안녕하세요 c++을 공부중인 임현순입니다!";
    string d = " ";
    vector<string> a = split(s, d);

    for (string st : a)
        cout << st << '\n';
    cout << '\n';
    
    
    string s2 = "aaaa bbb ccccc ee dddddddd!";
    vector<string> c = split_debug(s2, d);

    for (string st2 : c)
        cout << st2 << '\n';
    cout << '\n';
}