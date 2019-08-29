class WQuickUnionUF
{
  int *id, *size;
  int idSize;

  int root(int i)
  {
    while (i != id[i])
    {
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
  ~WQuickUnionUF()
  {
    delete id;
    delete size;
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