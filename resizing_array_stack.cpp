#include <iostream>
#include <cstdlib>

using namespace std;

class Stack
{
  int *arr;
  int top, sz;

  void resizeStack(int new_size);

public:
  Stack(int stack_size)
  {
    top = -1;
    arr = new int[stack_size];
    sz = stack_size;
  }
  ~Stack()
  {
    delete[] arr;
  }

  void push(int item);
  int pop();
  void display();
};

void Stack::resizeStack(int new_size)
{
  int *temp = new int[new_size];
  memmove(temp, arr, sz * sizeof(int));
  delete[] arr;
  arr = temp;
  sz = new_size;
}

void Stack::push(int item)
{
  if (top == sz - 1)
    resizeStack(2 * sz);
  arr[++top] = item;
}

int Stack::pop()
{
  if (top == -1)
  {
    cout << "Cannot pop: Stack Empty \n";
    exit(1);
  }
  int popped = arr[top--];

  if (top <= sz / 4)
    resizeStack(sz / 2);

  return popped;
}

void Stack::display()
{
  for (int i = top; i >= 0; i--)
    cout << arr[i] << endl;
}

int main()
{
  Stack S(10);
  for (int i = 0; i < 15; i++)
    S.push(i);

  // S.display();
  S.pop();
  S.pop();
  S.pop();
  S.display();
  return 0;
}