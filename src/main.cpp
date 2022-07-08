#include <cstring>
#include <iostream>

// #include <string>
// #include <vector>
using namespace std;

class MyString
{
private:
  char *str;
  int length;

public:
  MyString()
  {
    str = nullptr;
    length = 0;
  }

  MyString(char *str)
  {
    length = strlen(str);
    this->str = new char[length + 1];
    for (int i = 0; i < length; i++)
      this->str[i] = str[i];
    this->str[length] = '\0';
  }
  // Конструктор копирования
  MyString(const MyString &other)
  {
    length = strlen(other.str);
    this->str = new char[length + 1];
    for (int i = 0; i < length; i++)
      this->str[i] = other.str[i];
    this->str[length] = '\0';
  }
  // Конструктор перемещения
  MyString(MyString &&other)
  {
    this->length = other.length;
    this->str = other.str;
    other.str = nullptr;
  }

  ~MyString()
  {
    delete[] this->str;
  }

  MyString &operator=(const MyString &other)
  {
    if (this->str != nullptr)
      delete[] str;

    length = strlen(other.str);
    this->str = new char[length + 1];
    for (int i = 0; i < length; i++)
      this->str[i] = other.str[i];

    this->str[length] = '\0';
    return *this;
  }

  MyString operator+(const MyString &other)
  {
    MyString newStr;
    int thisLength = strlen(this->str);
    int otherLength = strlen(other.str);

    newStr.length = thisLength + otherLength;
    newStr.str = new char[thisLength + otherLength + 1];
    int i = 0;
    for (; i < thisLength; i++)
      newStr.str[i] = this->str[i];

    for (int j = 0; j < otherLength; j++, i++)
      newStr.str[i] = other.str[j];

    newStr.str[thisLength + otherLength] = '\0';
    return newStr;
  }

  bool operator==(const MyString &other)
  {
    if (this->length != other.length)
      return false;

    for (int i = 0; i < this->length; i++)
      if (this->str[i] != other.str[i])
        return false;

    return true;
  }

  bool operator!=(const MyString &other)
  {
    return !(this->operator==(other));
  }

  char &operator[](int index)
  {
    return this->str[index];
  }

  void Print()
  {
    cout << str;
    cout << endl;
  }

  int Length()
  {
    return length;
  }
};

int main()
{
  MyString str("Hello");
  MyString str2("World");
  MyString result;
  result = str + " " + str2;
  result.Print();

  cout << "str - " << str.Length() << endl;
  cout << "str2 - " << str2.Length() << endl;
  cout << "result - " << result.Length() << endl;

  if (str == str2)
    cout << "Equal" << endl;
  else if (str != str2)
    cout << "No equal" << endl;

  result[0] = 'Q';
  result.Print();

  return 0;
}

// #define DEBUG
// #define MY_CLASS

#ifdef MY_CLASS
class MyClass
{
private:
  int Size;
  std::vector<std::string> *vStr;
  char *str;

public:
  MyClass(int size)
  {
    std::cout << "Constructor " << this << std::endl;
    this->Size = size;
    this->vStr = new std::vector<std::string>;
    // for (int i = 0; i < size; i++)
    // {
    std::cin >> str;
    vStr->push_back(*str);
    // }
#ifdef DEBUG
    std::cout << std::endl;
    std::cout << "Vector from the [Constructor]" << std::endl;
    for (std::vector<int>::iterator it = vStr->begin(); it != vStr->end(); it++)
    {
      std::cout << (*it) << " ";
    }
    std::cout << std::endl;
#endif
  }

  // MyClass(const MyClass &other)
  // {
  //   std::cout << "Constructor copy " << this << std::endl;
  //   this->Size = other.Size;
  //   this->vStr = new int[other.Size];

  //   for (int i = 0; i < other.Size; i++)
  //   {
  //     this->data[i] = other.data[i];
  //   }
  // }

  void fillList(std::vector<char> *vStr, int size);
  void showList(int size);

  ~MyClass()
  {
    std::cout << "Destructor " << this << std::endl;
    delete vStr;
  }
};
#endif
#ifdef MY_CLASS
void MyClass::fillList(std::vector<char> *vStr, int size)
{
  for (int i = 0; i < vStr->size(); i++)
  {
    vStr->push_back(i);
  }
}

void MyClass::showList(int size)
{
  std::cout << "Vector from the [MyClass::showList]" << std::endl;

  for (std::vector<char>::iterator it = vStr->begin(); it != vStr->end(); it++)
  {
    std::cout << (*it) << " ";
  }
  std::cout << std::endl;
}

int main()
{
  std::cout << "Test Targer Games" << std::endl;
  MyClass myClass(10);
  // myClass.fillList(&vStr, 10);s
  myClass.showList(10);

  char *tmpStr;
  std::vector<std::string> vTmpStr;
  // std::cin >> tmpStr;
  vTmpStr->push_back(tmpStr);
  // for (std::vector<std::string>::iterator it = vTmpStr->begin(); it != vTmpStr->end(); it++)
  // {
  //   std::cout << (*it) << " ";
  // }
  // for (int i = 0; i < 10; i++)
  // std::cout << (void *)tmpStr << " ";

  return 0;
}
#endif

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
