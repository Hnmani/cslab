#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Stack
{
    node *top;

public:
    Stack()
    {
        top = NULL;
    }
    int show_top() { return top->data; }
    void push(int x)
    {
        /*
            the push function creates a new node and
            initializes it with value x which is an
            integer and is passed to it as an argument.
            then it checks wheter there is a top element
            in the stack or not i.e. whether the stack is not empty
            if it is empty it sets top as new node's next
            finally it sets new node as top
        */
        node *temp = new node(x);
        if (top)
        {
            temp->next = top;
        }
        top = temp;
    }

    int pop()
    {
        int x = top->data;
        // returns the data of the top node
        // also deletes the top node
        if (top->next)
        {
            node *temp = top;
            top = top->next;
            free(temp);
        }
        else
        {
            free(top);
        }
        return x;
    }
};

vector<string> split_string(string s, char c)
{
    vector<string> str;
    string word = "";
    for (int i = 0; i <= s.size(); i++)
    {
        if (i == s.size())
        {
            str.push_back(word);
            return str;
        }
        if (s[i] == c)
        {
            str.push_back(word);
            word = "";
        }
        else
        {
            word = word + s[i];
        }
    }
}

int main()
{
    Stack s;
    string equation;
    getline(cin, equation);
    vector<string> tokenised_eqn = split_string(equation, ' ');
    for (string eqn : tokenised_eqn)
    {
        // here getline function takes the inputs
        // from console till it gets a space
        // storing the string with name eqn the program compares it
        // with the operator + - * / % and
        // then it perform action accodingly
        // if it is not an operator then it
        // converts string eqn to an integer
        // and stores it in the stack

        if (!eqn.compare("+"))
        {
            int y = s.pop();
            int x = s.pop();
            int z = x + y;
            s.push(x + y);
        }
        else if (!eqn.compare(""))
        {
            cout << "jo";
        }
        else if (!eqn.compare("-"))
        {
            int y = s.pop();
            int x = s.pop();
            s.push(x - y);
        }
        else if (!eqn.compare("/"))
        {
            int y = s.pop();
            int x = s.pop();
            s.push(x / y);
        }
        else if (!eqn.compare("*"))
        {
            int y = s.pop();
            int x = s.pop();
            s.push(x * y);
        }
        else if (!eqn.compare("%"))
        {
            int y = s.pop();
            int x = s.pop();
            s.push(x % y);
        }
        else
        {
            int x = stoi(eqn);
            s.push(x);
        }
    }
    // finally only one element remains in
    // the stack which is out desired output
    cout << s.pop();
}