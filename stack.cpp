#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int x) {
        data = x;
    }
};

class Stack{
    node* top;
    public:
    Stack(){
        top = NULL;
    }
    int show_top() {return top->data;}
    void push(int x){
        node* temp = new node(x);
        if(top){
            temp->next = top;
            top = temp;
        }
        else{
            temp->next = NULL;
            top = temp;
        }
    }

    int pop(){
        int x = top->data;
        if(top->next){
            node* temp = top;
            top = top->next;
            free(temp);  
        }else{
            free(top);
        }
        return x;
    }
};


int main(){
    Stack s;
    string eqn;
    while(getline(cin,eqn,' ')){
        if(!eqn.compare("+")){
            int y = s.pop();
            int x = s.pop();
            int z = x+y;
            s.push(x+y);
        }else if(!eqn.compare("-")){
            int y = s.pop();
            int x = s.pop();
            s.push(x-y);            
        }else if(!eqn.compare("/")){
            int y = s.pop();
            int x = s.pop();
            s.push(x/y);
        }else if(!eqn.compare("*")){
            int y = s.pop();
            int x = s.pop();
            s.push(x*y);
        }else if(!eqn.compare("%")){
            int y = s.pop();
            int x = s.pop();
            s.push(x%y);
        }else{
            int x = stoi(eqn);
            s.push(x);
        }
    }
    cout<<s.pop();
}