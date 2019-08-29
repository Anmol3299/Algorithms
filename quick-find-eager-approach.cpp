#include <iostream>
using namespace std;

class UF
{
  int *id;
  int idSize;

public:
  UF(int N);
  bool connected(int p, int q);
  void Union(int p, int q);
};

UF::UF(int N)
{
  id = new int[N];
  idSize = N;
  for (int i = 0; i < N; i++)
    id[i] = i;
}

bool UF::connected(int p, int q)
{
  return (id[p] == id[q]);
}

void UF::Union(int p, int q)
{
  int pid = id[p];
  int qid = id[q];
  for (int i = 0; i < idSize; i++)
    if (id[i] == pid)
      id[i] = qid;
}

int main()
{
  UF U1(10);

  U1.Union(4, 3);
  U1.Union(3, 8);
  U1.Union(6, 5);
  U1.Union(9, 4);
  U1.Union(2, 1);
  cout << U1.connected(8, 9) << endl;
  cout << U1.connected(5, 4) << endl;

  return 0;
}