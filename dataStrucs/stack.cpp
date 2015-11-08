#include <iostream>
using namespace std;
#include <stdexcept>

class Stack{
    public:
        Stack(int size): 
            top(0), 
            sizeS(size), 
            S(new int[size]) {
            //S = new int[size];
            //top = 0;
            //sizeS = size;
        };

        Stack(const Stack& oldStack): 
            top(oldStack.top),
            sizeS(oldStack.sizeS),
            S(new int[oldStack.sizeS]) {
 
            copy(oldStack);
        }

        Stack& operator=(const Stack& oldStack){
            int* newS = new int[oldStack.sizeS];
            delete [] S;
            top = oldStack.top;
            sizeS = oldStack.sizeS;
            S = newS;
            copy(oldStack);
        }

        ~Stack(){
            delete [] S;
        }

        bool stackEmpty(){
            //cout << "top =  " << top << "\n";
            if (top == 0){
                return true;
            } 
            else{
                return false;
            }
        }

        bool stackFull(){
            if (top == sizeS){
                return true;
            } 
            else{
                return false;
            }
        }

        void push(int x){
            if (stackFull() == true){
                throw std::overflow_error( "cannot push. the stack is full!");
            }
            else{
                top ++;
                S[top] = x;
                //top++;
            }
            
        }

        int pop(){
            if (stackEmpty() == true){
                throw std::underflow_error( "cannot pop from an empty stack!" );
            }
            else {
                int poppedVal = S[top];
                top--;
                return poppedVal;
            }
        } 


    private:
        int sizeS;// = size;
        int* S;// = int[size]; // the stack
        int top;// = 0;
        
        void copy(const Stack& oldStack) {
            for (int i=0; i<oldStack.sizeS; ++i) {
                S[i] = oldStack.S[i];
            }
        }
};


int main(){
    Stack myStack(100);
    cout << myStack.stackEmpty() << "\n";
    myStack.push(1);
    myStack.push(3);
    Stack myStack2 = myStack;
    myStack2 = myStack;
    int s1 = myStack.pop();
    cout << myStack.stackEmpty() << " " << s1 << "\n";
    int s2 = myStack.pop();
    cout << s2 << " " << myStack.stackEmpty() << "\n";
    //cout << myStack.pop() << "\n";

    return 0;
}