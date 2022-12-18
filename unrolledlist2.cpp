#include <bits/stdc++.h>
using namespace std;
#define maxElements 4

class Mahasiswa{
public:
    string nrp;
    int age;
    string name;
};

class Node{
     public:
    int numElements = 3;
    Mahasiswa array[maxElements];
    Node *next;
};

void printUnrolledList(Node *n)
{
    while (n != NULL)
    {
        for (int i=0; i<n->numElements; i++){
            if(n->array[i].age!=0){
                cout<<n->array[i].nrp<<" "<<endl;
                cout<<n->array[i].age<<" "<<endl;
                cout<<n->array[i].name<<" "<<endl;
            }
        }
        n = n->next;
    }
}

void searchNRP(Node *n, string x){
    bool found = false; //cek found
    while(n!=NULL){
        for (int i=0; i<n->numElements; i++){
            if(n->array[i].nrp==x){
                cout<<n->array[i].name; //move array
                cout<<endl<<n->array[i].nrp;
                cout<<endl<<n->array[i].age;
                found = true; //ketemu
            }
            if(found){ //jika ketemu break
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
    if(n==NULL){
        cout<<"Data not found";
    }
}

void addList(Node *n, string nrp, string name, int age){
    bool kosong = false;
    while (n != NULL)
    {
        for (int i=0; i<n->numElements; i++){
            if(n->array[i].age==0){
                kosong = true;
                n->array[i].age = age;
                n->array[i].nrp = nrp;
                n->array[i].name = name;
                break;
            }
        }
        if(!kosong){
            if(n->next==NULL){
                n->next = new Node();
            }
            n = n->next;
        }
        else{
            break;
        }
    }

}

int main()
{
    Node* head = NULL;

    head = new Node();
    head->numElements = 3;
    head->array[0].age = 20;
    head->array[0].name = "Fransiscus X";
    head->array[0].nrp = "221116955";

    addList(head, "221115956", "x", 19);
    addList(head, "221115957", "y", 19);
    addList(head, "221115958", "z", 19);

    printUnrolledList(head);

//    searchNRP(head,"221116953");

}
