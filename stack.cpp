#include<iostream>
using namespace std;

class Stack{
    public:
        int *array;
        int top,capacity;

    Stack(int capacity)
    {
        this->capacity = capacity;
        this->array = new int[this->capacity];
        this->top = -1;
    }

    ~Stack()
    {
        delete[] array;
    }

    void push(int element);
    void pop();
    void peek();
    bool isEmpty();
    bool isFull();
    int size();
    void display();
};

    void Stack::push(int element)
    {
        if(!isFull())
        {
            this->top++;
            this->array[this->top] = element;
        }
        else
        {
            cout<<"Stack is overflow!";
        }
    }

    void Stack::pop()
    {
        if(!isEmpty())
        {
            this->top--;
        }
        else
        {
            cout<<"Stack is underflow!";
        }
    }

    void Stack::peek()
    {
        if(isEmpty())
        {
            cout<<"Stack is underflow!";
        }
        else
        {
            cout<<this->array[this->top]<<endl;
        }
    }

    bool Stack::isEmpty()
    {
        return this->top == -1;
    }

    bool Stack::isFull()
    {
        return this->top == this->capacity -1;
    }

    int Stack::size()
    {
        return this->top + 1;
    }

    void Stack:: display()
    {
        cout<<"Stack is: ";
        for(int i = 0; i <= top; i++)
        {
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }

int main()
{
    int capacity;

    cout<<"Enter the capacity of the stack: ";
    cin>>capacity;

    Stack s(capacity);

    int choice,element;

    do{

        cout<<endl<<"--------------------"<<endl;
        cout<<"Enter 1 for push element"<<endl;
        cout<<"Enter 2 for pop element"<<endl;
        cout<<"Enter 3 for peek element"<<endl;
        cout<<"Enter 4 for size element"<<endl;
        cout<<"Enter 5 for display element"<<endl;
        cout<<"Enter 0 for exit"<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element to push: ";
            cin>>element;
            s.push(element);
        break;

        case 2:
            s.pop();
        break;

        case 3:
            s.peek();
        break;

        case 4:
            cout<<"Stack size is: "<<s.size()<<endl;
        break;

        case 5:
            s.display();
        break;

        case 0:
            cout<<"Exiting..";
        break;
        
        default:
            cout<<"wrong choice!";
        break;
        }

    }while(choice != 0);

    return 0;
}