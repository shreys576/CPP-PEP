#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

void InsertAtStart(Node* &head, int value){
    Node* newnode = new Node(value);
    if(head == nullptr){
        head = newnode;
        newnode -> next = head;
        return;
    }

    Node* temp = head;
    while(temp -> next != head){
        temp = temp -> next;
    }

    newnode -> next = head;
    head = newnode;
    temp -> next = head;
}

void InsertAtEnd(Node* &head, int value){
    Node* newnode = new Node(value);
    if(head == nullptr){
        head = newnode;
        head -> next = head;
        return;
    }

    Node* temp = head;
    while(temp -> next != head){
        temp = temp -> next;
    }
    temp -> next = newnode;
    newnode -> next = head;
}

void InsertAtPoint(Node* &head, int value, int point){
    if(head == nullptr){
        InsertAtStart(head, value);
        return;
    }
    if(point == 1){
        InsertAtStart(head, value);
        return;
    }
    Node* temp = head;
    for(int i = 1; i < point - 1; i ++){
        if(temp -> next == head){
            InsertAtEnd(head, value);
            return;
        }
        temp = temp -> next;
    }
    if(temp -> next == head){
        InsertAtEnd(head, value);
        return;
    }
    Node* newnode = new Node(value);
    newnode -> next = temp -> next;
    temp -> next = newnode;
}

void PrintList(Node* head){
    if(head == nullptr){
        return;
    }
    Node* temp = head;
    cout << temp -> data << " ";
    while(temp -> next != head){
        temp = temp -> next;
        cout << temp -> data << " ";
    }
    cout << endl;
}


int main(){
    Node* head = nullptr;
    InsertAtStart(head, 3);
    PrintList(head);

    InsertAtEnd(head, 5);
    InsertAtPoint(head, 8, 2);

    PrintList(head);

}