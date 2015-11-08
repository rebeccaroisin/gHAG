#include <iostream>
using namespace std;
#include <stdexcept>
#include <string>

template<class T> class Stack{
    public:
        Stack(int size): 
            top(0), 
            sizeS(size), 
            S(new T[size]) {
            //S = new int[size];
            //top = 0;
            //sizeS = size;
        };

        Stack(const Stack& oldStack): 
            top(oldStack.top),
            sizeS(oldStack.sizeS),
            S(new T[oldStack.sizeS]) {
 
            copy(oldStack);
        }

        Stack& operator=(const Stack& oldStack){
            T* newS = new T[oldStack.sizeS];
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

        void push(T x){
            if (stackFull() == true){
                throw std::overflow_error( "cannot push. the stack is full!");
            }
            else{
                top ++;
                S[top] = x;
                //top++;
            }
            
        }

        T pop(){
            if (stackEmpty() == true){
                throw std::underflow_error( "cannot pop from an empty stack!" );
            }
            else {
                T poppedVal = S[top];
                top--;
                return poppedVal;
            }
        } 


    private:
        int sizeS;// = size;
        T* S;// = int[size]; // the stack
        int top;// = 0;
        
        void copy(const Stack& oldStack) {
            for (int i=0; i<oldStack.sizeS; ++i) {
                S[i] = oldStack.S[i];
            }
        }
};


int main(){
    Stack<string> myStack(100);
    cout << myStack.stackEmpty() << "\n";
    myStack.push("foo");
    myStack.push("bar");
    Stack<string> myStack2 = myStack;
    myStack2 = myStack;
    string s1 = myStack.pop();
    cout << myStack.stackEmpty() << " " << s1 << "\n";
    string s2 = myStack.pop();
    cout << s2 << " " << myStack.stackEmpty() << "\n";
    //cout << myStack.pop() << "\n";

    return 0;
}