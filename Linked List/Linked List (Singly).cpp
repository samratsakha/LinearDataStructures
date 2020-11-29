#include<iostream>
using namespace std;

class node{
    public:
        int key;
        int data;
        node* next;

        node(){
            key=0;
            data=0;
            next=NULL;
        }
};

class slk{
    public:
    node* head;

    slk(){
        head=NULL;
    }

    node* keyexist(node* nod){
        node* ptr;
        node* temp=NULL;
        ptr=head;
        while(ptr!=NULL){
            if(ptr->key==nod->key){
                temp=ptr;
            }
            ptr=ptr->next;
        }
        return temp;
    }

    void append(node* nod){
        if(keyexist(nod)!=NULL){
            cout<<"Key already exists"<<endl;
        }
        else{
            if(head==NULL){
                head=nod;
            }
            else{
                node* ptr=head;
                while(ptr->next!=NULL){
                    ptr=ptr->next;
                }
                ptr->next=nod;
            }
            cout<<"Append successfull"<<endl;
        }
    }

    void prepend(node* nod){
        if(head==NULL){
            head=nod;
        }
        else{
            if(keyexist(nod)!=NULL){
                cout<<"Key already exists"<<endl;
            }
            else{
                nod->next=head;
                head=nod;
                cout<<"Prepend successfull"<<endl;
            }
        }
    }

    void insertnode(node* nod,int k){
        if(keyexist(nod)!=NULL){
            cout<<"Key of the inserting node already exists"<<endl;
        }
        else{
            int flag=0;
            node* ptr=head;
            if(head->key==k){
                nod->next=head->next;
                head->next=nod;
                flag=1;
            }
            else{
                while(ptr->next!=NULL){
                    if(ptr->next->key==k){
                        nod->next=ptr->next->next;
                        ptr->next->next=nod;
                        flag=1;
                        break;
                    }
                    ptr=ptr->next;
                }
            }
            if(flag==0){
               cout<<"Key after which node has to insert is not present"<<endl;
            }
        }
    }

    void deletenode(node* nod){
        int flag=0;
        if(head->key==nod->key){
            head=head->next;
            cout<<"Done"<<endl;
        }
        else{
        node* ptr=head;
        node* prev;
        while(ptr!=NULL){
            if(ptr->key==nod->key){
                flag=1;
                break;
            }
            prev=ptr;
            ptr=ptr->next;
        }
        if(flag==0){
            cout<<"No key in the list"<<endl;
        }
        else{
            prev->next=ptr->next;
            cout<<"Done"<<endl<<endl;
        }
        }
    }

    void update(node* nod){
        node* ptr;
        ptr=keyexist(nod);
        if(ptr==NULL){
            cout<<"No key present in the list"<<endl;
        }
        else{
            ptr->data=nod->data;
        }
    }

    void sortlist(){
        node* ptr;
        node* prev;
        int x=1;
        while(x!=0){
            x=0;
            ptr=head;
            while(ptr->next!=NULL){
                prev=ptr->next;
                if((ptr->data)>(prev->data)){
                    swap(ptr->data,prev->data);
                    swap(ptr->key,prev->key);
                    x++;
                }
                ptr=ptr->next;
            }
        }
    }

    void reverselist(){
        node* cur,*next,*prev;
        cur=head;
        prev=NULL;
        while(cur!=NULL){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        head=prev;
    }


    void display(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
        }
        else{
            node* ptr=head;
            while(ptr!=NULL){
                cout<<ptr->key<<" "<<ptr->data<<endl;
                ptr=ptr->next;
            }
        }
    }


};

int main(){
    int opt,k,d,ins;
    slk s;
    do{
        node* n = new node;
        cout<<"Enter the option from below to perform on Linked List"<<endl;
        cout<<"1 - To check if key is present in the list"<<endl;
        cout<<"2 - To append a Node to the list"<<endl;
        cout<<"3 - To prepend a Node to the list"<<endl;
        cout<<"4 - To insert a Node after an key"<<endl;
        cout<<"5 - To delete a Node"<<endl;
        cout<<"6 - To update a node "<<endl;
        cout<<"7 - To sort the list"<<endl;
        cout<<"8 - To reverse the list"<<endl;
        cout<<"9 - To display the elements in the list"<<endl;
        cout<<"0 - To Exit"<<endl;
        cin>>opt;

        switch(opt){

        case 1:
            cout<<"Enter the key to check"<<endl;
            cin>>k;
            n->key=k;
            if(s.keyexist(n)==NULL){
                cout<<"Key is not present in the List"<<endl;
            }
            else{
                cout<<"Key is present in the List"<<endl;
            }
            break;

        case 2:
            cout<<"Enter the key and then enter the value to be appended"<<endl;
            cin>>k>>d;
            n->key=k;
            n->data=d;
            s.append(n);
            break;

        case 3:
            cout<<"Enter the key and then enter the value to be prepended"<<endl;
            cin>>k>>d;
            n->key=k;
            n->data=d;
            s.prepend(n);
            break;

        case 4:
            cout<<"Enter the key after which the node has to be inserted"<<endl;
            cout<<"Enter the key and the value of the node"<<endl;
            cin>>ins>>k>>d;
            n->key=k;
            n->data=d;
            s.insertnode(n,ins);
            break;

        case 5:
            cout<<"Enter the key of the node to delete"<<endl;
            cin>>k;
            n->key=k;
            s.deletenode(n);
            break;

        case 6:
            cout<<"Enter the key to update and the new value of that node"<<endl;
            cin>>k>>d;
            n->key=k;
            n->data=d;
            s.update(n);
            break;

        case 7:
            s.sortlist();
            cout<<"List Sorted"<<endl<<endl;
            s.display();
            cout<<endl;
            break;

        case 8:
            s.reverselist();
            cout<<endl;
            s.display();
            cout<<endl;
            break;

        case 9:
            s.display();
            break;

        case 10:
            system("cls");
            cout<<"Screen cleared"<<endl;
            break;

        case 0:
            break;

        default:
            cout<<"Enter a valid option"<<endl;
            break;

        }
    }while(opt!=0);
}
