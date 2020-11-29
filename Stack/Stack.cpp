#include <iostream>
using namespace std;

class stack{
    int top;
    int arr[1001];

    public:

        stack(){
            top=-1;
            for(int i=0;i<1001;i++){
                arr[i]=0;
            }
        }

        bool isempty(){
            if(top==-1){
                return true;
            }
            else{
                return false;
            }
        }

        bool isfull(){
            if(top==1000){
                return true;
            }
            else{
                return false;
            }
        }

        void push(int n){
            if(isfull()){
                cout<<"Stack Overflow"<<endl;
            }
            else{
                top++;
                arr[top]=n;
            }
        }

        void pop(){
            if(isempty()){
                cout<<"Stack is empty"<<endl;
            }
            else{
                arr[top]=0;
                top--;
                cout<<"Element popped out from stack"<<endl;
            }
        }

        int peek(){
            if(isempty()){
                cout<<"Stack is empty"<<endl;
            }
            else{
                return arr[top];
            }
        }

        void change(int n,int pos){
            pos--;
            if(isempty()){
                cout<<"Stack is empty"<<endl;
            }
            else{
                if(pos>top){
                    cout<<"Position is not et filled"<<endl;
                }
                else{
                    arr[pos]=n;
                    cout<<"The element at position "<<pos+1<<" is "<<n<<endl;
                }
            }
        }

        void length(){
            if(isempty()){
                cout<<"Stack is empty"<<endl;
            }
            else{
                cout<<"Size of the Stack is "<<top+1<<endl;
            }
        }

        void display(){
            if(isempty()){
                cout<<"Stack is empty"<<endl;
            }
            else{
              for(int i=0;i<=top;i++){
                  cout<<arr[i]<<" ";
              }
              cout<<endl;
            }
        }
};

int main(){
    stack s;
    int n,num,pos;
    do{
            cout<<"Enter your option to perform on Stack"<<endl;
            cout<<"1 - To check if stack is empty"<<endl;
            cout<<"2 - To check if stack is full"<<endl;
            cout<<"3 - To push an element to the Stack"<<endl;
            cout<<"4 - To pop an element from the Stack"<<endl;
            cout<<"5 - To change an element of the Stack"<<endl;
            cout<<"6 - To get the peek element from the Stack"<<endl;
            cout<<"7 - To display the elements of the Stack"<<endl;
            cout<<"8 - To get the size of the Stack"<<endl;
            cout<<"9 - To clear the screen"<<endl;
            cout<<"10 - To Exit"<<endl;
            cin>>n;
            switch(n){
                case 1:
                if(s.isempty()){
                    cout<<"Stack is empty"<<endl;
                }
                else{
                    cout<<"Stack is not empty"<<endl;
                }
                break;

                case 2:
                if(s.isfull()){
                    cout<<"Stack is full"<<endl;
                }
                else{
                    cout<<"Stack is not full"<<endl;
                }
                break;

                case 3:
                cout<<"Enter the element to push"<<endl;
                cin>>num;
                s.push(num);
                break;

                case 4:
                s.pop();
                break;

                case 5:
                cout<<"Enter the number ans position"<<endl;
                cin>>num>>pos;
                s.change(num,pos);
                break;

                case 6:
                num=s.peek();
                cout<<num<<endl;
                break;

                case 7:
                s.display();
                break;

                case 8:
                s.length();
                break;

                case 9:
                    system("cls");
                    cout<<"Screen cleared"<<endl;
                break;

                case 10:
                break;

                default:
                cout<<"Enter a valid option"<<endl;
                break;
            }
    }while(n!=10);
}

