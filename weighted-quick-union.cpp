#include <iostream>
using namespace std;

class WQuickUnionUF
{
  int *id, *size;
  int idSize;

  int root(int i)
  {
    while (i != id[i])
    {
      /*
        EDIT 2
        Added line 17 to improve the code by reducing the length to HALF the original length by linking the node to its grandparent.
      */
      id[i] = id[id[i]];
      i = id[i];
    }

    return i;
  }

public:
  WQuickUnionUF(int N)
  {
    id = new int[N];
    size = new int[N];
    idSize = N;
    for (int i = 0; i < N; i++)
    {
      id[i] = i;
      size[i] = 1;
    }
  }

  bool connected(int p, int q)
  {
    return (root(p) == root(q));
  }

  void Union(int p, int q)
  {
    int rootp = root(p);
    int rootq = root(q);

    if (rootp == rootq)
      return;

    /*
      EDIT 1
      id[rootp] = rootq
      NOTE: Replaced with the following code to improve perf by a great deal.
    */

    if (size[rootp] > size[rootq])
    {
      id[rootq] = rootp;
      size[rootp] += size[rootq];
    }
    else
    {
      id[rootp] = rootq;
      size[rootq] += size[rootp];
    }
  }
};

int main()
{
  WQuickUnionUF U1(10);

  U1.Union(1, 2);
  U1.Union(3, 4);
  U1.Union(5, 6);
  U1.Union(7, 8);
  U1.Union(7, 9);
  U1.Union(2, 8);
  // U1.Union(7, 9);
  cout << U1.connected(8, 9) << endl;
  cout << U1.connected(7, 1) << endl;

  return 0;
}