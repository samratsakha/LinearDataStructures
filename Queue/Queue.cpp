#include<iostream>
using namespace std;

class Queue{
    int front;
    int rear;
    int arr[1001];

public:

    Queue(){
        front=-1;
        rear=-1;
        for(int i=0;i<1001;i++){
            arr[i]=0;
        }
    }

    bool isempty(){
        if(front==-1 && rear==-1){
            return true;
        }
        else{
            return false;
        }
    }

    bool isfull(){
        if(rear==1000){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int n){
        if(isfull()){
            cout<<"Queue is full"<<endl;
        }
        else if(isempty()){
            front++;
            rear++;
            arr[rear]=n;
        }
        else{
            rear++;
            arr[rear]=n;
        }
    }

    void dequeue(){
        if(isempty()){
            cout<<"Queue is empty"<<endl;
        }
        else if(rear==front){
            arr[rear]=0;
            rear=-1;
            front=-1;
            cout<<"Dequeue success, Queue is empty now"<<endl;
        }
        else{
            arr[front]=0;
            front=0;
            for(int i=0;i<=rear;i++){
                arr[i]=arr[i+1];
            }
            arr[rear]=0;
            rear--;
        }
    }

    void length(){
        if(isempty()){
            cout<<"Queue is empty"<<endl;
        }
        else{
            cout<<"Size of the current Queue is: "<<rear+1<<endl;
        }
    }

    void display(){
        if(isempty()){
            cout<<"Queue is empty"<<endl;
        }
        else{
            cout<<"Elements in Queue are:"<<endl;
            for(int i=0;i<=rear;i++){
                cout<<arr[i]<<" "<<endl;
            }
            cout<<endl;
        }
    }



};

int main(){
    Queue q;
    int n,num;
    do{
         cout<<"Enter your option to perform on Stack"<<endl;
            cout<<"1 - To check if Queue is empty"<<endl;
            cout<<"2 - To check if Queue is full"<<endl;
            cout<<"3 - To enqueue an element to the Queue"<<endl;
            cout<<"4 - To dequeue an element from the Queue"<<endl;
            cout<<"5 - To display the elements of the Queue"<<endl;
            cout<<"6 - To get the size of the Queue"<<endl;
            cout<<"7 - To clear the screen"<<endl;
            cout<<"8 - To Exit"<<endl;
            cin>>n;
            switch(n){
                case 1:
                if(q.isempty()){
                    cout<<"Queue is empty"<<endl;
                }
                else{
                    cout<<"Queue is not empty"<<endl;
                }
                break;

                case 2:
                if(q.isfull()){
                    cout<<"Queue is full"<<endl;
                }
                else{
                    cout<<"Queue is not full"<<endl;
                }
                break;

                case 3:
                cout<<"Enter the element to enqueue to the queue"<<endl;
                cin>>num;
                q.enqueue(num);
                break;

                case 4:
                q.dequeue();
                break;

                case 5:
                q.display();
                break;

                case 6:
                q.length();
                break;

                case 7:
                system("cls");
                break;

                case 8:
                break;

                default:
                cout<<"Enter a valid option"<<endl;
                break;
            }

    }while(n!=8);
}
