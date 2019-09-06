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
class Stack
{
  node<T> *top;

public:
  // Constructor
  Stack()
  {
    top = nullptr;
  }
  // Destructor
  ~Stack()
  {
    delete top;
  }

  // Function to insert data in Stack
  void push(T data);
  // Function to display all elements of stack
  void display();
  // Function to pop element from stack
  T pop();
};

template <class T>
void Stack<T>::push(T data)
{
  node<T> *temp = new node<T>;
  temp->data = data;
  temp->next = top;
  top = temp;
}

template <class T>
void Stack<T>::display()
{
  if (top == nullptr)
  {
    cout << "Cannot Display: Stack Empty \n";
    exit(1);
  }
  else
  {
    node<T> *temp;
    temp = top;
    while (temp != nullptr)
    {
      cout << temp->data << endl;
      temp = temp->next;
    }
    delete temp;
  }
}

template <class T>
T Stack<T>::pop()
{
  if (top == nullptr)
  {
    cout << "Cannot Pop: Stack Empty \n";
    exit(1);
  }
  node<T> *temp;
  temp = top;
  top = temp->next;
  // Save popped data in a temporary variable
  T popped = temp->data;
  // Delete the popped node
  delete temp;
  // Return the popped data
  return popped;
}

int main()
{
  Stack<char> s;
  s.push('a');
  s.push('b');
  s.push('c');
  s.push('d');
  s.display();
  s.pop();
  s.display();
  s.pop();
  s.pop();
  s.pop();
  s.display();

  return 0;
}