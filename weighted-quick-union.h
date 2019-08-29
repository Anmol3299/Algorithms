class WQuickUnionUF
{
  unsigned long int *id, *size;
  unsigned long int idSize;

  unsigned long int root(unsigned long int i)
  {
    while (i != id[i])
    {
      id[i] = id[id[i]];
      i = id[i];
    }
    return i;
  }

public:
  // Constructor
  WQuickUnionUF(unsigned long int N)
  {
    id = new unsigned long int[N];
    size = new unsigned long int[N];
    idSize = N;
    for (unsigned long int i = 0; i < N; i++)
    {
      id[i] = i;
      size[i] = 1;
    }
  }
  // Destructor
  ~WQuickUnionUF()
  {
    delete[] id;
    delete[] size;
  }

  bool connected(unsigned long int p, unsigned long int q)
  {
    return (root(p) == root(q));
  }

  void Union(unsigned long int p, unsigned long int q)
  {
    unsigned long int rootp = root(p);
    unsigned long int rootq = root(q);

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