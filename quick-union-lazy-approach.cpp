#include <iostream>
using namespace std;

class QuickUnionUF
{
  int *id;
  int idSize;

  int root(int i)
  {
    while (i != id[i])
      i = id[i];

    return i;
  }

public:
  QuickUnionUF(int N)
  {
    id = new int[N];
    idSize = N;
    for (int i = 0; i < N; i++)
      id[i] = i;
  }

  bool connected(int p, int q)
  {
    return (root(p) == root(q));
  }

  void Union(int p, int q)
  {
    int rootp = root(p);
    int rootq = root(q);

    id[rootp] = rootq;
  }
};