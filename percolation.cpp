#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

#include "weighted-quick-union.h"
#include "generate-random.h"

int main()
{
  int start = time(nullptr);

  unsigned int N;
  unsigned long int total_els, iter = 0;
  float probability;
  cout << "Enter size of matrix: ";
  cin >> N;
  total_els = N * N;
  unsigned int *rand_hash = new unsigned int[total_els];

  // Added 2 because last 2 elements will be treated as virtual top and bottom respectively.
  WQuickUnionUF U1(total_els + 2);
  unsigned long int v_top = total_els;
  unsigned long int v_bottom = total_els + 1;

  memset(rand_hash, 0, total_els);

  while (1)
  {
    unsigned long int r = getRandomNumber(total_els);
    if (!rand_hash[r])
    {
      rand_hash[r] = 1;
      iter++;

      // Top connection
      if (r < N)
        U1.Union(v_top, r);
      else if (rand_hash[r - N])
        U1.Union(r - N, r);

      // Botton connection
      if (r + N > total_els - 1)
        U1.Union(v_bottom, r);
      else if (rand_hash[r + N])
        U1.Union(r + N, r);

      // Left connection
      if (r % N > 0 && rand_hash[r - 1] == 1)
        U1.Union(r - 1, r);

      // Right connection
      if (r % N < N - 1 && rand_hash[r + 1] == 1)
        U1.Union(r + 1, r);

      probability = (float)iter / (float)total_els;
      if (probability > 0.5 && U1.connected(v_top, v_bottom))
        break;
    }
  }
  delete[] rand_hash;

  probability = (float)iter / (float)total_els;
  cout << probability << endl;

  int end = time(nullptr);
  cout << end - start << endl;

  return 0;
}