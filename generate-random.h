#include <random>
#include <ctime>

namespace MyRandom
{
std::mt19937 mersenne(static_cast<std::mt19937::result_type>(std::time(nullptr)));
}

int getRandomNumber(unsigned long int max)
{
  std::uniform_int_distribution<unsigned long int> die(0, max - 1);
  return die(MyRandom::mersenne);
}