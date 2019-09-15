#include <iostream>
#include <cstdlib>
#include <ctime>

#define ull unsigned long long

using namespace std;

class Stack
{
  int *arr;
  ull int top, sz, start;

  void resizeStack(ull int new_size);

public:
  Stack(ull int stack_size)
  {
    start = time(nullptr);
    top = -1;
    arr = new int[stack_size];
    sz = stack_size;
  }
  ~Stack()
  {
    delete[] arr;
    cout << time(nullptr) - start;
  }

  void push(int item);
  int pop();
  void display();
};

void Stack::resizeStack(ull int new_size)
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
  Stack S(1);
  for (ull int i = 0; i < 1000000000; i++)
    S.push(2);

  // S.display();
  // S.pop();
  // S.pop();
  // S.pop();
  // S.display();
  return 0;
}