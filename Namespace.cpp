#include <iostream>

namespace ns1
{
  int num = 28;

  class A
  {
  public:
    void print()
    {
      std::cout << "Classe A do ns1" << std::endl;
    }
  };
}

namespace ns2
{
  int num = 19;

  class A
  {
  public:
    void print()
    {
      std::cout << "Classe A do ns2" << std::endl;
    }
  };
}

int main(int argc, char const *argv[])
{
  ns1::A ns1A;
  ns2::A ns2A;
  ns1A.print();
  ns2A.print();
  return 0;
}
