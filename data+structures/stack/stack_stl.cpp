#include <iostream>
#include <stack>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

bool isValid_bracket(string s)
{
    int m = s.size();

    stack<char> st;

    bool ans = true;
    for (int i = 0; i < m; i++)
    {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
                st.pop();
            else
            {
                ans = false;
                break;
            }
        }
        else if (s[i] == ']')
        {
            if (!st.empty() && st.top() == '[')
                st.top();
            else
            {
                ans = false;
                break;
            }
        }
        else if (s[i] == '}')
        {
            if (!st.empty() && st.top() == '{')
                st.top();
            else
            {
                return false;
                break;
            }
        }
    }
    if (!st.empty())
    {
        return false;
    }
    return ans;
}
int prec(char c)
{

    if (c == '^')
        return 3;

    else if (c == '*' || c == '/')
        return 2;

    else if (c == '+' || c == '-')
        return 1;

    else
        return -1;
}
string infixtoPrefix(string s)
{

    reverse(s.begin(), s.end());
    string res;

    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            res += s[i];

        else if (s[i] == ')')
            st.push(s[i]);

        else if (s[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() && prec(st.top()) > prec(s[i]))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
string infixtoPostfix(string s)
{
    reverse(s.begin(), s.end());
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++)
    {

        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            res += s[i];

        else if (s[i] == '(')
            st.push(s[i]);

        else if (s[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() && prec(st.top()) > prec(s[i]))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int postfixEvaluation(string s)
{

    stack<int> st;

    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {

            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;

            case '-':
                st.push(op1 - op2);
                break;

            case '*':
                st.push(op1 * op2);
                break;

            case '/':
                st.push(op1 / op2);
                break;

            case '^':
                st.push(op1 ^ op2);
                break;
            }
        }
    }
    return st.top();
}
int prefixEvaluation(string s)
{

    stack<int> st;

    for (int i = s.length() - 1; i >= 0; i--)
    {

        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;

            case '-':
                st.push(op1 - op2);
                break;

            case '*':
                st.push(op1 * op2);
                break;

            case '/':
                st.push(op1 / op2);
                break;

            case '^':
                st.push(pow(op1, op2));
                break;
            }
        }
    }
    return st.top();
}
void insertAtBottom(stack<int> &st, int ele)
{

    if (st.empty())
    {
        st.push(ele); // element ko push krna
        return;
    }

    int topel = st.top();
    st.pop();
    insertAtBottom(st, ele);
    st.push(topel); // ab reverse ho gaya stack
}
void reverseStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int ele = st.top();
    st.pop();         // top element ko nikalna
    reverseStack(st); // reversively pop karana elements
    insertAtBottom(st, ele);
}

void reverseSentence(string s)
{

    stack<string> st;

    for (int i = 0; i < s.length(); i++)
    {

        string word = "";
        while (s[i] != ' ' && i < s.length())
        {
            word += s[i]; // aggregating word
            i++;
        }
        if(!word.empty())st.push(word); // pushing them into stack
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop(); // popping them out so that they can be auto reversed using stack
    }
    cout << endl;
}
string removeDuplicates(string s)
{
    string ans="";
    stack<char> st;
    stack<char> r;
    int i = 0;
    int l = s.length();
    st.push(s[0]);
    for (int i = 1; i < l; i++)
    {
        if(st.top()==s[i])
        {
            st.pop();
        }
        else{
            st.push(s[i]);
        } 
       // cout << "Outside c " << endl;
    }
    while (!st.empty())
    {
        r.push(st.top());
        // cout << "r stack : " << r.top()<< endl;
        st.pop();
    }
    while (!r.empty())
    {
        ans = ans + r.top();
        r.pop();
    }
    return ans;
    // while (i<s.length())
    // {
    //     //cout << " value of i :" << i << endl;
    //     st.push(s[i++]);
    //     cout << "s[i]:" << s[i] << " st.top():" << st.top() << endl;

    //    // cout << "st top :" << st.top() << " i is : " << i << endl;
    //     if(s[i]==st.top()){
    //         st.pop();
    //         i++;
    //         cout << "Inside condn" << endl;
    //         cout << "s[i]:" << s[i] << " st.top():" << st.top() << endl;

    //         //    cout << "st top :" << st.top() << " i is : " << i << endl;
    //     }
    //     cout << "Outside condn " << endl;
    // }
}
int maxDepth(string s)
{
    stack<char> st;
    int depth = 0, maxdepth = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char temp = ')';
        if (s[i] == '(')
        {
            st.push(s[i]);
            depth++;
        }
        else if (s[i] == temp)
        {
                st.pop();
                depth = 0;
        }
        cout << " depth : " << depth<<endl;
        maxdepth = max(depth, maxdepth);t
    }
    return maxdepth;
}
vector<int> asteroidCollision(vector<int> &asteroids)
{
    int n = asteroids.size() - 1;
    vector<int> ans;
    stack<int> s;
    s.push(asteroids[n]);
    for (int i = n - 1; i >= 0; i--)
    {
        int j = s.top();
        int k = i * j;
        if (k < 0)
        {
                cout << "gaya" << endl;
                // if (abs(i) > abs(j))
                // s.pop(), s.push(i);
                // if (abs(i) < abs(j))
                // i++;
                // if (abs(i) == abs(j))
                // s.pop();
        }
        else if (k > 0)
        {
                cout << "aya" << endl;
                s.push(i);
        }
    }
    while (s.size() > 0)
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
int main()
{

    // 1 Reverse a sentence
    //  string s ="aLpha beta gamae";
    //  reverseSentence(s);//o/p : gamae beta aLpha

    /*
    //2 Reversing a stack
        stack<int> st;
        st.push(1);
        st.push(2);
        st.push(3);

        reverseStack(st);
        while(!st.empty()){
          cout<<st.top()<<" ";
          st.pop();
        }
    */
    // string Str = "abbaca";
    // string sol = removeDuplicates(Str);
    // cout << "after removing duplicates " << Str << "-->" << sol <<" ";
    // string test = "(1+(2*3)+((8)/4))+1";
    // int op = maxDepth(test);
    // cout <<" output : " <<op << endl;
    // cout << prefixEvaluation("-+7*45+20") << endl;
    vector<int> asteroid,op;
    asteroid.push_back(5);
    asteroid.push_back(10);
    asteroid.push_back(-5);
    op = asteroidCollision(asteroid);
    for(int i = 0 ; i < op.size(); i++)
    {
        cout << op[i] << " ";
    }
    return 0;
}
/*
   if(st.length()>0 &&  st.char_at(st.length()-1)){
    
   }
*/





























