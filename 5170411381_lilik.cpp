#include <iostream>
#include <string.h>

using namespace std;

struct Node{
    int stu_no;
    char stu_name[50];
    char posis[50];
    Node *next;
};
Node *top;

class stack{

public:
    void push(int n,char name[],char pos[]);
    void pop();
    void display();
};

void stack :: push(int n, char name[], char pos [])
{
    struct Node *newNode=new Node;
    //fill data part
    newNode->stu_no=n;
    strcpy(newNode->stu_name,name);
    strcpy(newNode->posis,pos);
    //link part
    newNode->next=top;
    //make newnode as top/head
    top=newNode;
}
//pop
void stack ::pop()
{
    if(top==NULL){
        cout<<"data kosong!"<<endl;
        return;
    }
    top=top->next;
}
//display
void stack:: display()
{
if(top==NULL){
        cout<<"data kosong"<<endl;
        return;
    }
    struct Node *temp=top;
    while(temp!=NULL){
        cout<<temp->stu_no<<"->";
        cout<<temp->stu_name<<"->";
        cout<<temp->posis<<" ";
        cout<<endl;
        temp=temp->next;
    }
    cout<<endl;
}
int main(){

    stack s;
    char ch;
    int n;
    do{
    cout<<"1.Push\n"<<"2.Pop\n"<<"3.Display\n"<<"4.Exit\n";
    cout<<"pilihan (1-4): ";
    cin>>n;

    switch(n){
        case 1:{
            Node n;
            cout<<"Data Pemain Bola \n";
            cout<<"===================\n";
            cout<<"No Punggung : ";
            cin>>n.stu_no;
            cout<<"Nama: ";
            std::cin.ignore(1);
            cin.getline(n.stu_name,50);
            cout<<"Posisi : ";
            std::cin.ignore(1);
            cin.getline(n.posis,50);

            //push data into the stack
            s.push(n.stu_no,n.stu_name,n.posis);
            break;
        }
        case 2 :{
            //pop data from stack
            s.pop();
            break;
        }
        case 3 :{
            //display data
            s.display();
            break;
        }
        case 4:{
            cout<<"Exit";
            break;
        }
        default :{
            cout<<"Uwes bubar \n";
        }
    }
    cout<<"Y lanjut dan N sudah selesai yeeess"<<endl;
    cout<<"Apa anda Mau Lanjut Y dan N ? : ";
    cin>>ch;

    }while(ch=='Y'||ch=='y');
    return 0;
}
