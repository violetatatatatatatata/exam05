#include "bigint.hpp"

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

int main(void)
{
  const bigint a(42);
  bigint b(21), c, d(1337), e(d);

  std::cout << BLUE << "++++ SHOW OBJECTS ++++" << RESET << std::endl;
  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
  std::cout << "c = " << c << std::endl;
  std::cout << "d = " << d << std::endl;
  std::cout << "e = " << e << std::endl;
  std::cout << std::endl;

  std::cout << YELLOW << "++++ ADD OBJECTS ++++" << RESET << std::endl;

  std::cout << "a + b = " << a + b << std::endl;       // 63
  std::cout << "a + c = " << a + c << std::endl;       // 42
  std::cout << "(c += a) = " << (c += a) << std::endl; // 42
  std::cout << std::endl;

  std::cout << BLUE << "++++ INCREMENT OBJECTS ++++" << RESET << std::endl;
  std::cout << "b = " << b << std::endl;     // 21
  std::cout << "++b = " << ++b << std::endl; // 22
  std::cout << "b++ = " << b++ << std::endl; // 22
  std::cout << "b = " << b << std::endl;     // 23
  std::cout << std::endl;

  std::cout << YELLOW << "++++ << OPERAND ++++" << RESET << std::endl;
  // b = 23, b << 10 -> 23000000000 + 42 = 23000000042
  std::cout << "(b << 10): " << (b << 10) << std::endl;
  std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << std::endl;

  std::cout << std::endl;

  std::cout << BLUE << "++++ <<= OBJECTS ++++" << RESET << std::endl;
  std::cout << "(d <<= 4) = " << (d <<= 4) << ", d: " << d << std::endl;
  std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << ", d: " << d << std::endl;
  std::cout << std::endl;

  std::cout << YELLOW << "++++ = OPERAND ++++" << RESET << std::endl;
  std::cout << "a = " << a << std::endl; // a = 42
  std::cout << "d = " << d << std::endl; // d = 133700
  std::cout << std::endl;

  std::cout << BLUE << "++++ OTHER OPERANDS ++++" << RESET << std::endl;
  std::cout << "(d < a) = " << (d < a) << std::endl;   // (d < a) = 0
  std::cout << "(d > a) = " << (d > a) << std::endl;   // (d > a) = 1
  std::cout << "(d == d) = " << (d == d) << std::endl; // (d == d) = 1
  std::cout << "(d != a) = " << (d != a) << std::endl; // (d != a) = 1
  std::cout << "(d <= a) = " << (d <= a) << std::endl; // (d <= a) = 0
  std::cout << "(d >= a) = " << (d >= a) << std::endl; // (d >= a) = 1
  std::cout << std::endl;

  std::cout << YELLOW << "++++ EXTRA ++++" << RESET << std::endl;
  bigint x(12345678);
  bigint y(5);
  std::cout << "(x << y) = " << (x << y) << ", x: " << x << ", y: " << y << std::endl;
  std::cout << "(x >>= y) = " << (x >>= y) << ", x: " << x << ", y: " << y << std::endl;
  std::cout << "(x >= y) = " << (x >= y) << ", x: " << x << ", y: " << y << std::endl;

  std::cout << "x= " << (x <<= 5) << ", y= " << (y <<= 12) << std::endl;
  std::cout << "(x >= y) = " << (x >= y) << ", x: " << x << ", y: " << y << std::endl;

  return (0);
}
