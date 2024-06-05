#include <iostream>
using namespace std;

//Creating a class node as done in the earlier code
class Node{
  public:
    int data;
    Node* next;

    Node () {
     data = 0;
     next = NULL;
    }

    Node (int data) {
    this->data = data;
    next = NULL;
   }
};

//Insert at head
void insertatHead(Node* &head, int data) {
  //Step 1
  Node* newnode = new Node(data);
  //Step 2
  newnode -> next = head;
  //Step 3
  head = newnode;
}

//Deleting at head
void deleteatTail(Node* &head) {

  //Step 1
  Node* prev = head;
  Node* temp = head;
  //Step 2 : Find (prev and temp)
  while(temp -> next != NULL) {
    prev = temp;
    temp = temp -> next;
  }
  //Step 3
  prev -> next = NULL;
  //Step 4
  delete temp;
}

//Print function as use din previous code
void print ( Node* &head) {
  Node* temp = head;
  while(temp != NULL) {
    cout << temp->data << " ";
  temp = temp->next;
  }
  cout << endl;
}

int main() {

  //Making a node
  Node* head;
  //Created a node in heap memory
  head = new Node(10);

  //First making a LL for deleting
  //Inserting at Head
  insertatHead(head, 20);
  insertatHead(head, 30);
  insertatHead(head, 40);
  insertatHead(head, 50);
  insertatHead(head, 60);
  insertatHead(head, 70);

  cout << "Printing the LL: " << endl;
  print(head);

  deleteatTail(head);
  deleteatTail(head);
  deleteatTail(head);

  cout << "Printing after deleting: " << endl;
  print(head);


  return 0;
}