#include<iostream>
using namespace std;

class Queue{
    public:
        int front, rear, capacity;
        int *array;
    
    Queue(int capacity)
    {
        this->capacity = capacity;
        this->array = new int[this->capacity];
        this->front = this->rear = -1;
    }

    ~Queue()
    {
        delete[] array;
    }

    void Enqueue(int data);
    int Dequeue();
    int Front();
    int Rear();
    bool isEmpty();
    bool isFull();
    int size();
    void display();
};

    void Queue::Enqueue(int data)
    {
        if(this->isFull())
        {
            cout<<"Queue is overflow!";
        }
        else if(this->front == -1 && this->rear == -1)
        {
            this->front = this->rear = 0;
            this->array[this->rear] = data;
        }
        else
        {
            this->array[++this->rear] = data;
        }
    }

    int Queue::Dequeue()
    {
        if(isEmpty())
        {
            return -1;
        }
        else if (this->front == this->rear)
        {
            int data = array[this->front];
            this->front = this->rear = -1;
        }
        else
        {
            return array[this->front++];
        }
    }
    
    int Queue::Front()
    {
        if(isEmpty())
        {
            return -1;
        }
        else
        {
            return array[this->front];
        }
    }

    int Queue::Rear()
    {
        if(isEmpty())
        {
            return -1;
        }
        else
        {
            return array[this->rear];
        }
    }

    bool Queue::isEmpty()
    {
        return this->front == -1;
    }

    bool Queue::isFull()
    {
        return this->rear == this->capacity - 1;
    }

    int Queue::size()
    {
        if(isEmpty())
        {
            cout<<"Queue is underflow!";
            return 0;
        }
        else
        {
            return this->rear - this->front + 1;
        }
    }

    void Queue::display()
    {
        if(isEmpty())
        {
            cout<<"Queue is underflow!";
        }
        else
        {
            cout<<"Queue is: ";
            for(int i = this->front; i <= this->rear; i++)
            {
                cout<<array[i]<<" ";
            }
            cout<<endl;
        }
    }

int main()
{
    int capacity;
    cout<<"Enter the capacity of the queue: ";
    cin>>capacity;

    Queue queue(capacity);

    int choice, element;

    do{

        cout<<endl<<"-------------------"<<endl;
        cout<<"Enter 1 for Enqueue"<<endl;
        cout<<"Enter 2 for Dequeue"<<endl;
        cout<<"Enter 3 for Front"<<endl;
        cout<<"Enter 4 for Rear"<<endl;
        cout<<"Enter 5 for Size"<<endl;
        cout<<"Enter 6 for Display"<<endl;
        cout<<"Enter 0 for Exit"<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout << "Enter element to enqueue: ";
                cin>>element;
                queue.Enqueue(element);
            break;
            case 2:
                element = queue.Dequeue();
                if (element != -1)
                    cout<<"Dequeued element: "<<element<<endl;
                else
                    cout<<"Queue is empty!"<<endl;
            break;
            case 3:
                element = queue.Front();
                if (element != -1)
                    cout<<"Front element: "<<element<<endl;
                else
                    cout<<"Queue is empty!"<<endl;
            break;
            case 4:
                element = queue.Rear();
                if (element != -1)
                    cout<<"Rear element: "<<element<<endl;
                else
                    cout<<"Queue is empty!"<<endl;
            break;
            case 5:
                cout<<"Size of queue: "<<queue.size()<<endl;
            break;
            case 6:
                queue.display();
            break;
            case 0:
                cout<<"Exiting."<<endl;
            break;
            default:
                cout<<"Wrong choice."<<endl;
            break;
        }

    }while(choice != 0);

    return 0;
}
