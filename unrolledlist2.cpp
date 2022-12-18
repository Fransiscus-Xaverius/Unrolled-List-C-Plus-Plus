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
    addList(head, "221115959", "x2", 19);
    addList(head, "221115960", "y2", 19);
    addList(head, "221115961", "z2", 19);
    addList(head, "221115962", "x3", 19);
    addList(head, "221115963", "y3", 19);
    addList(head, "221115964", "z3", 19);
    addList(head, "221116956", "Lw7TS" ,19);
    addList(head, "221116957", "JB4Gr" ,19);
    addList(head, "221116958", "hIshp" ,19);
    addList(head, "221116959", "peYvX" ,19);
    addList(head, "221116960", "qiBb1" ,19);
    addList(head, "221116961", "GVEWG" ,19);
    addList(head, "221116962", "tR6p8" ,19);
    addList(head, "221116963", "IpJ8U" ,19);
    addList(head, "221116964", "tbU3m" ,19);
    addList(head, "221116965", "OLQlW" ,19);
    addList(head, "221116966", "c5qs9" ,19);
    addList(head, "221116967", "3YAkG" ,19);
    addList(head, "221116968", "e630z" ,19);
    addList(head, "221116969", "2sc1I" ,19);
    addList(head, "221116970", "adsij" ,19);
    addList(head, "221116971", "5INVb" ,19);
    addList(head, "221116972", "Puf0S" ,19);
    addList(head, "221116973", "G6GVe" ,19);
    addList(head, "221116974", "Ns4Hb" ,19);
    addList(head, "221116975", "WEW4J" ,19);
    addList(head, "221116976", "Oltjw" ,19);
    addList(head, "221116977", "0Htp3" ,19);
    addList(head, "221116978", "Sbs81" ,19);
    addList(head, "221116979", "uXg3F" ,19);
    addList(head, "221116980", "zOMjU" ,19);
    addList(head, "221116981", "CBKkF" ,19);
    addList(head, "221116982", "P7qZT" ,19);
    addList(head, "221116983", "hHBIA" ,19);
    addList(head, "221116984", "pxayJ" ,19);
    addList(head, "221116985", "5eB2j" ,19);
    addList(head, "221116986", "JlrLb" ,19);
    addList(head, "221116987", "Ocyr0" ,19);
    addList(head, "221116988", "FhNFj" ,19);
    addList(head, "221116989", "cOIcv" ,19);
    addList(head, "221116990", "PrLzE" ,19);
    addList(head, "221116991", "rTdP5" ,19);
    addList(head, "221116992", "pcjMI" ,19);
    addList(head, "221116993", "LbFx8" ,19);
    addList(head, "221116994", "QhpUx" ,19);
    addList(head, "221116995", "hUFeT" ,19);
    addList(head, "221116996", "8r6zQ" ,19);
    addList(head, "221116997", "QZcEl" ,19);
    addList(head, "221116998", "jMR91" ,19);
    addList(head, "221116999", "dWLux" ,19);
    addList(head, "221117000", "zTboz" ,19);
    addList(head, "221117001", "If2zI" ,19);
    addList(head, "221117002", "k7yMw" ,19);
    addList(head, "221117003", "RYwKB" ,19);
    addList(head, "221117004", "xxwoG" ,19);
    addList(head, "221117005", "D5mWL" ,19);
    addList(head, "221117006", "RY6Dr" ,19);
    addList(head, "221117007", "LviAH" ,19);
    addList(head, "221117008", "jeE90" ,19);
    addList(head, "221117009", "qgLI4" ,19);
    addList(head, "221117010", "yxI5M" ,19);
    addList(head, "221117011", "en2IK" ,19);
    addList(head, "221117012", "uMAm3" ,19);
    addList(head, "221117013", "FXVSc" ,19);
    addList(head, "221117014", "pYlSb" ,19);
    addList(head, "221117015", "SQ9nD" ,19);
    addList(head, "221117016", "fMJQ2" ,19);
    addList(head, "221117017", "ZjhzI" ,19);
    addList(head, "221117018", "VnScb" ,19);
    addList(head, "221117019", "bCKTq" ,19);
    addList(head, "221117020", "yWJJf" ,19);
    addList(head, "221117021", "ISRSK" ,19);
    addList(head, "221117022", "ZLEaN" ,19);
    addList(head, "221117023", "fcWlD" ,19);
    addList(head, "221117024", "NcMI1" ,19);
    addList(head, "221117025", "isIFP" ,19);
    addList(head, "221117026", "kMKau" ,19);
    addList(head, "221117027", "hnaS9" ,19);
    addList(head, "221117028", "WEZ6V" ,19);
    addList(head, "221117029", "BdtbD" ,19);
    addList(head, "221117030", "hIaRH" ,19);
    addList(head, "221117031", "h4PKB" ,19);
    addList(head, "221117032", "8gaME" ,19);
    addList(head, "221117033", "NeZMR" ,19);
    addList(head, "221117034", "VvCRW" ,19);
    addList(head, "221117035", "Kv4Zr" ,19);
    addList(head, "221117036", "F6L8p" ,19);
    addList(head, "221117037", "caWk0" ,19);
    addList(head, "221117038", "9oyWD" ,19);
    addList(head, "221117039", "7p5rq" ,19);
    addList(head, "221117040", "f5WK9" ,19);
    addList(head, "221117041", "79PnK" ,19);
    addList(head, "221117042", "lOR4K" ,19);
    addList(head, "221117043", "dyMgx" ,19);
    addList(head, "221117044", "F9RUI" ,19);
    addList(head, "221117045", "V8BdG" ,19);
    addList(head, "221117046", "UHoMn" ,19);
    addList(head, "221117047", "dDzkO" ,19);
    addList(head, "221117048", "9Wwak" ,19);
    addList(head, "221117049", "w8R9B" ,19);
    addList(head, "221117050", "QQJRQ" ,19);
    addList(head, "221117051", "rh8oR" ,19);
    addList(head, "221117052", "0JKnB" ,19);
    addList(head, "221117053", "zenD4" ,19);
    addList(head, "221117054", "u2zgM" ,19);
    addList(head, "221117055", "gJCnZ" ,19);

    searchNRP(head,"221116995");

}
