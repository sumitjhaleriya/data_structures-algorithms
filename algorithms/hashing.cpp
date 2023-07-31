#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_set<int> s;
    s.insert(5);
    s.insert(10);
    s.insert(10);
    s.insert(7);
    cout << s.size() << endl;
    if(s.find(5)==s.end())
        cout << "Not Found" << endl;
    else
        cout << "Found" << endl;
    for ( auto it = s.begin(); it !=s.end(); it++)
    {
        cout << (*it) <<" ";
    }
    //s.clear();
    //cout << s.size() << endl;
    cout << "Count of 10 is "<<s.count(10) << endl;
    cout << "Count of 5 is " << s.count(5) << endl;
    cout << "Count of 7 is " << s.count(7) << endl;
    
    return 0;
}