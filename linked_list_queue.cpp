#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
struct node
{
  T data;
  node<T> *next;
};

template <class T>
class Queue
{
  node<T> *front, *rear;

public:
  Queue()
  {
    front = nullptr;
    rear = nullptr;
  }
  ~Queue()
  {
    if (front != nullptr)
    {
      node<T> *temp = front->next;
      delete front;
      front = temp;
    }
    delete front;
  }

  void enqueue(T data);
  T dequeue();
  void display();
};

template <class T>
void Queue<T>::enqueue(T data)
{
  node<T> *temp = new node<T>;
  temp->data = data;
  temp->next = nullptr;

  if (front == nullptr)
    front = temp;
  else
    rear->next = temp;

  rear = temp;
}

template <class T>
T Queue<T>::dequeue()
{
  if (front == nullptr)
  {
    cout << "Cannot Dequeue: Queue Empty";
    exit(1);
  }
  else
  {
    node<T> *temp = front;
    front = temp->next;
    T popped = temp->data;
    delete temp;
    return popped;
  }
}

template <class T>
void Queue<T>::display()
{
  if (front == nullptr)
  {
    cout << "Cannot Display: Queue Empty";
    exit(1);
  }
  else
  {
    node<T> *temp = front;
    while (temp != nullptr)
    {
      cout << temp->data << endl;
      temp = temp->next;
    }
  }
}

int main()
{
  Queue<int> Q;

  for (int i = 0; i < 5; i++)
    Q.enqueue(i);

  Q.dequeue();
  Q.dequeue();
  Q.dequeue();
  Q.dequeue();
  Q.dequeue();

  Q.display();

  return 0;
}
