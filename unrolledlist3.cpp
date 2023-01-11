#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <time.h>
#include <stdlib.h>
#include <string>

const int NODE_SIZE = 4;  // Maximum number of elements per node

using namespace std;

class Mahasiswa{
private:
    string name;
    string nrp;
    int age;

public:

    Mahasiswa(string name, string nrp, int age)
    : name(name), nrp(nrp), age(age)
    {
    }
    //Getter
    string get_name() const { return name; }
    string get_nrp() const { return nrp; }
    int get_age() const { return age; }
    //Setter
    void set_name(string name) { this->name = name; }
    void set_nrp(string nrp) { this->nrp = nrp; }
    void set_age(int age) { this->age = age; }
};

struct Node
{
    std::vector<Mahasiswa> elements;  // Elements stored in the node
    Node* next;  // Pointer to the next node in the list
};

class UnrolledList
{
private:
    Node* head;
    Node* tail;
    int size;
    vector<Mahasiswa> elements;
public:
    UnrolledList()
        : head(nullptr), tail(nullptr), size(0)
    {
    }
    ~UnrolledList()
    {
        Node* node = head;
        while (node != nullptr)
        {
            Node* next_node = node->next;
            delete node;
            node = next_node;
        }
    }

    void insert(const Mahasiswa& element)
    {
        // Create a new node if the list is empty
        if (tail == nullptr)
        {
            tail = new Node;
            head = tail;
        }
        // Create a new node if the current node is full
        else if (tail->elements.size() == NODE_SIZE)
        {
            tail->next = new Node;
            tail = tail->next;
        }

        // Insert the element into the current node
        tail->elements.push_back(element);
        ++size;
    }

    void search_by_nrp(const std::string& nrp)
{
    Node* node = head;
    bool found = false;
    while (node != nullptr)
    {
        for (const auto& element : node->elements)
        {
            if (element.get_nrp() == nrp)
            {
                cout<<"Name : "<<element.get_name();
                cout<<"NRP : "<<element.get_nrp();
                found=true;
            }
        }
        node = node->next;
    }
    if(!found){
        cout<<"Data not found";
    }
}

// Search for a Mahasiswa object by name
    void search_by_name(const std::string& name)
    {
        Node* node = head;
        bool found = false;
        while (node != nullptr)
        {
            for (const auto& element : node->elements)
            {
                if (element.get_name() == name)
                {
                    cout<<"Name : "<<element.get_name();
                    cout<<"NRP : "<<element.get_nrp();
                    found = true;
                }
            }
            node = node->next;
        }
        if(!found){
            cout<<"Data not found";
        }
    }

    void erase_all()
    {
        // Delete all nodes in the list
        Node* node = head;
        while (node != nullptr)
        {
            Node* next_node = node->next;
            delete node;
            node = next_node;
        }

        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void delete_all(){
        Node* node = head;
        while (node != nullptr){
            Node* next_node = node->next;
            delete node;
            node = next_node;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void print_all(){
        Node* node = head;
        while(node!=nullptr){
            for(int i = 0;i<node->elements.size();i++){
                cout<<"Name : "<<node->elements.at(i).get_name()<<endl;
                cout<<"NRP : "<<node->elements.at(i).get_nrp()<<endl;
                cout<<"Age : "<<node->elements.at(i).get_age()<<endl;
            }
            node = node->next;
        }
    }

    void delete_by_name(const std::string& name) {
        Node* node = head;
        Node* prev_node = nullptr;
        while (node != nullptr) {
            std::vector<Mahasiswa>& elements = node->elements;
            for (int i = 0; i < elements.size(); ++i) {
                if (elements[i].get_name() == name) {
                    string delNRP = elements[i].get_nrp();
                    int delAge = elements[i].get_age();
                    elements.erase(elements.begin() + i);
                    --size;
                    if (node == head && elements.empty()) {
                        // If this is the first and only element in the first node, update head
                        head = node->next;
                        delete node;
                    }
                    else if (node == tail && elements.empty()) {
                        // If this is the first and only element in the last node, update tail
                        tail = prev_node;
                        tail->next = nullptr;
                        delete node;
                    }
                    else if (elements.empty()) {
                        // If this is the first and only element in a non-head, non-tail node, update the previous node
                        prev_node->next = node->next;
                        delete node;
                    }
                    cout<<"Data with NRP: " <<delNRP<<endl<<"Name : "<<name<<endl<<"Age : "<<delAge<<" has been deleted";
                    return;
                }
            }
            prev_node = node;
            node = node->next;
        }
        cout << "Data with Name: " <<name<< " not found"<<endl;
    }

    void delete_by_nrp(const std::string& nrp) {
        Node* node = head;
        Node* prev_node = nullptr;
        while (node != nullptr) {
            std::vector<Mahasiswa>& elements = node->elements;
            for (int i = 0; i < elements.size(); ++i) {
                if (elements[i].get_nrp() == nrp) {
                    string delName = elements[i].get_name();
                    int delAge = elements[i].get_age();
                    elements.erase(elements.begin() + i);
                    --size;
                    if (node == head && elements.empty()) {
                        // If this is the first and only element in the first node, update head
                        head = node->next;
                        delete node;
                    }
                    else if (node == tail && elements.empty()) {
                        // If this is the first and only element in the last node, update tail
                        tail = prev_node;
                        tail->next = nullptr;
                        delete node;
                    }
                    else if (elements.empty()) {
                        // If this is the first and only element in a non-head, non-tail node, update the previous node
                        prev_node->next = node->next;
                        delete node;
                    }
                    cout<<"Data with NRP: " <<nrp<<endl<<"Name : "<<delName<<endl<<"Age : "<<delAge<<" has been deleted";
                    return;
                }
            }
            prev_node = node;
            node = node->next;
        }
        cout << "Data with NRP: " <<nrp<< " not found"<<endl;
    }


};

    int main(){
//        Mahasiswa student1("John Doe", "1234567890", 20);
//        Mahasiswa student2("Jane Doe", "0987654321", 21);
        UnrolledList my_list;
//        my_list.insert(student1);
//        my_list.insert(student2);

//        my_list.search_by_name("John Doe");
        srand (time(NULL));
        int r;
        string temp;

        for(int i=0; i<100; i++){
            r = (rand() % 100) + 1;
            temp = to_string(i);
            string uname = "u"+temp;
            my_list.insert(Mahasiswa(uname,temp,r));
        }

    }
