#include <bits/stdc++.h>
using namespace std;
#define maxElements 4

class Node
{
    public:
    int numElements;
    int array[maxElements];
    Node *next;
};

void printUnrolledList(Node *n)
{
    while (n != NULL)
    {
        for (int i=0; i<n->numElements; i++)
            cout<<n->array[i]<<" ";
        n = n->next;
    }
}

void searchUnrolledList(Node *n, int x){
    bool found = false; //cek found
    while(n!=NULL){
        for (int i=0; i<n->numElements; i++){
            if(n->array[i]==x){
                cout<<n->array[i]; //move array
                found = true; //ketemu
            }
            if(found){ //jika ketemu break
                cout<<"ketemu";
                break;
            }
        }
        if(!found){ //break lagi karena looping for merupakan looping nested
            n = n->next;
        }
        if(found){
            break;
        }
    }
}

int main()
{
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();
    fifth = new Node();
    sixth = new Node();
    seventh = new Node();
    eighth = new Node();
    nineth = new Node();
    tenth = new Node();

    head->numElements = 3;
    head->array[0] = 1;
    head->array[1] = 2;
    head->array[2] = 3;

    head->next = second;

    second->numElements = 3;
    second->array[0] = 4;
    second->array[1] = 5;
    second->array[2] = 6;

    second->next = third;

    third->numElements = 3;
    third->array[0] = 7;
    third->array[1] = 8;
    third->array[2] = 9;
    third->next = NULL;

    searchUnrolledList(head, 8);
    return 0;
}
