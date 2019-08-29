#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

#include "weighted-quick-union.h"

int main()
{
  srand(time(0));

  int N, total_els, iter = 0;
  double probability;
  cout << "Enter size of matrix: ";
  cin >> N;
  total_els = N * N;
  int rand_hash[total_els];

  // Added 2 because last 2 elements will be treated as virtual top and bottom respectively.
  WQuickUnionUF U1(total_els + 2);
  int v_top = total_els;
  int v_bottom = total_els + 1;

  for (int i = 0; i < total_els; i++)
    rand_hash[i] = 0;

  while (!U1.connected(v_top, v_bottom))
  {
    int r = rand() % total_els;
    if (!rand_hash[r])
    {
      // cout << r << endl;
      rand_hash[r] = 1;
      iter++;

      // Top connection
      if (r < N)
      {
        U1.Union(v_top, r);
        // cout << "v_top \n";
      }
      else if (rand_hash[r - N])
      {
        U1.Union(r - N, r);
        // cout << "top_connect \n";
      }

      // Botton connection
      if (r + N > total_els - 1)
      {
        U1.Union(v_bottom, r);
        // cout << "v_bottom \n";
      }
      else if (rand_hash[r + N])
      {
        U1.Union(r + N, r);
        // cout << "bottom_connect \n";
      }
      // Left connection
      if (r % N > 0 && rand_hash[r - 1] == 1)
      {
        U1.Union(r - 1, r);
        // cout << "Left connect \n";
      }
      // Right connection
      if (r % N < N - 1 && rand_hash[r + 1] == 1)
      {
        U1.Union(r + 1, r);
        // cout << "Right connect \n";
      }
    }
  }
  probability = (float)iter / (float)total_els;
  cout << probability << endl;

  return 0;
}