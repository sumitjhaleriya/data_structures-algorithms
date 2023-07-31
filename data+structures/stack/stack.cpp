#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//implementing aditya verma stack playlist

//Nearest Smaller in Right
vector<int> NSR(vector<int> &prices)
{
    vector<int> v;
    stack<int> s;
    int n = prices.size() - 1;
    for (int i = n; i >= 0; i--)
    {
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else if (s.size() > 0 && s.top() < prices[i])
        {
            v.push_back(s.top());
        }
        else if (s.size() > 0 && s.top() >= prices[i])
        {

            while (s.size() > 0 && s.top() >= prices[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top());
            }
        }
        s.push(prices[i]);
    }
    reverse(v.begin(), v.end());
    // for (int j = 0; j < prices.size(); j++)
    // {
    //     v[j] = prices[j]-v[j];
    // }
    return v;
    //return v;

}


//Nearest Greater in Right
vector<int> NGR(vector<int> &prices){
    vector<int> v;
    stack<int> s;
    int n = prices.size() - 1;
    for (int i = n; i >= 0; i--)
    {
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else if (s.size() > 0 && s.top() > prices[i])
        {
            v.push_back(s.top());
        }
        else if (s.size() > 0 && s.top() <= prices[i])
        {

            while (s.size() > 0 && s.top() <= prices[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top());
            }
        }
        s.push(prices[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}

// Nearest Smaller in Left
vector<int> NSL(vector<int> &prices)
{
    vector<int> v;
    stack<int> s;
    int n = prices.size();
    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else if (s.size() > 0 && s.top() < prices[i])
        {
            v.push_back(s.top());
        }
        else if (s.size() > 0 && s.top() >= prices[i])
        {

            while (s.size() > 0 && s.top() >= prices[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top());
            }
        }
        s.push(prices[i]);
    }
    return v;
}
// Nearest Greater in Left
vector<int> NGL(vector<int> &prices)
{
    vector<int> v;
    stack<int> s;
    int n = prices.size();
    for (int i = 0; i <n; i++)
    {
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else if (s.size() > 0 && s.top() > prices[i])
        {
            v.push_back(s.top());
        }
        else if (s.size() > 0 && s.top() <= prices[i])
        {

            while (s.size() > 0 && s.top() <= prices[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top());
            }
        }
        s.push(prices[i]);
    }
    return v;
}
//NGRindex
vector<int> NGRindex(vector<int> &prices)
{
    vector<int> v;
    stack<pair<int,int>> s;
    int n = prices.size() - 1;
    for (int i = n; i >= 0; i--)
    {
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else if (s.size() > 0 && s.top().first > prices[i])
        {
            v.push_back(s.top().second);
        }
        else if (s.size() > 0 && s.top().first <= prices[i])
        {

            while (s.size() > 0 && s.top().first <= prices[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top().second);
            }
        }
        s.push({prices[i],i});
    }
    reverse(v.begin(), v.end());
    return v;
}
int main()
{
    vector<int> arr,test;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(4);
    test.push_back(10);
    test.push_back(1);
    test.push_back(1);
    test.push_back(6);
    //test.push_back(3);
    vector<int> ans1 = NGR(arr);
    vector<int> ans2 = NSR(test);
    vector<int> ans3 = NGL(arr);
    vector<int> ans4 = NSL(test);
    cout << "NGR :" ;
    for(int j = 0 ; j < ans1.size(); j++)
    {
     cout << ans1[j] <<" ";
    }
    cout << " \n NSR :";
    for (int j = 0; j < ans2.size(); j++)
    {
     cout << ans2[j] << " ";
    }
    cout << " \n NGL :";
    for (int j = 0; j < ans3.size(); j++)
    {
     cout << ans3[j] << " ";
    }
    cout << " \n NSL :";
    for (int j = 0; j < ans4.size(); j++)
    {
     cout << ans4[j] << " ";
    }
    return 0;
}