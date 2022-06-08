#include <iostream>

class Test
{
private:
public:
  Test()
  {
    std::cout << "Constructor" << std::endl;
  }
  Test(const Test &testTmp)
  {
    std::cout << "Constructor copy" << std::endl;
  }
  ~Test()
  {
    std::cout << "Destructor" << std::endl;
  }

  char *ch;
};
void funcShow(Test object)
{
  std::cout << "\nThe function accepts the object as a parameter\n";
}

Test funcReturnObject()
{
  Test object;
  std::cout << "\nThe function returns the object\n";
  return object;
}

int main()
{
  std::cout << "Name Project" << std::endl;
  Test test;
  funcShow(test);
  funcReturnObject();

  test.ch = new char;
  // std::cin >> test.ch;
  // std::cout << test.ch << std::endl;
  // delete test.ch;
  return 0;
}

// Реализовать класс динамических строк, который:
// 1. Написан на C++11 без каких либо сторонних библиотек. Не использует в своей
// основе какую-либо другую реализацию динамических строк, контейнеров или умных
// указателей STL.

// 2. Класс не шаблонный. Поддерживает строки произвольного размера, используя
// базовые операции работы с динамическим хипом (функции malloc()/free() или
// операторы new/delete) для манипуляции последовательностями символов типа char.

// 3. Имеет конструктор копирования, оператор присваивания и поддерживает
// move-семантику.

// У класса есть "внешний" оператор сложения двух строк.

// Нет необходимости использовать какие-то изощренные методы оптимизации (типа
// COW и многопоточной поддержки).

// Написать пример с использованием этого класса строк и какого-либо контейнера STL.

// Программа должна принимать список строк, затем выдавать его в порядке, обратном
// лексикографическому без учета регистра.

// Программа-пример работает из командной строки.