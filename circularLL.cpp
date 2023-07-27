#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data ;
    node* next_node;
    node(int x){
        data = x;
        next_node=NULL;
    }
};

node* insert(node* item, node* head){
    node* temp = head;
    while(temp->next_node!=head)temp = temp->next_node;
    temp->next_node = item;
    item->next_node = head;
    return head;
}
void display(node* head){
    node* temp = head;
    do{
        cout<<temp->data<<"  ";
        temp = temp->next_node;
    }while(temp!=head);
}

int get_max(node* t, int k){
    int max_ = INT_MIN;
    for(int i =0; i<k;i++){
        if(t->data > max_) max_ = t->data;
        t = t->next_node;
    }
    return max_;
}
int main(){
    int n;
    cin>>n;
    int z;
    cin>>z;
    node* head = new node(z);
    n--;
    head->next_node=head;
    while(n--){
        int x;
        cin>>x;
        node* item = new node(x);
        item->next_node=NULL;
        head = insert(item,head);
    }
    int k;
    cin>>k;
    node* temp = head;
    vector<int> arr(k);
    for(int i = 0; i<k ; i++){
        arr[i] = get_max(temp->next_node,k);
        temp = temp->next_node;
    }
    while(temp!=head){
        temp->data = get_max(temp->next_node,k);
        temp = temp->next_node;
    }
    for(int i =0; i<k; i++){
        temp->data = arr[i];
        temp = temp->next_node;
    }
    display(head);
}