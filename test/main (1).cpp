#include <iostream>
#include <cassert>
#include <cstring>
#include "mystring.h"

void
test_strlen ()
{
  char str[] = "Hello";
  int length = my_strlen (str);
  assert (length == 5 && "Test 1 for strlen failed!");
  std::cout << "Test 1 for strlen passed!" << std::endl;
}


void
test_strcpy ()
{
  char src[] = "Hello";
  char dest[50];
  my_strcpy (dest, src);
  assert (strcmp(dest, src) == 0 && "Test for strcpy failed!");
  std::cout << "Test for strcpy passed!" << std::endl;
}
/*
void
test_strcat ()
{
  char str1[] = "Hello";
  char str2[] = " World";
  char dest[50];
  my_strcpy (dest, str1);
  my_strcat (dest, str2);
  assert (strcmp (dest, "Hello World") == 0 && "Test for strcat failed!");
  std::cout << "Test for strcat passed!" << std::endl;
}

void
test_strchr ()
{
  char str[] = "Hello";
  char ch = 'e';
  char *result = my_strchr (str, ch);
  assert (result - str == 1 && "Test for strchr failed!");
  std::cout << "Test for strchr passed!" << std::endl;
  
  ch = 'x';
  result = my_strchr (str, ch);
  assert (result == 0 && "Test for strchr failed!");
  std::cout << "Test for strchr passed!" << std::endl;
  
}

void
test_substr ()
{
  char str[] = "Hello, World!";
  int start = 7, end = 12;
  char *result = my_substr (str, start, end);
  assert (strcmp(result,"World!") ==0 && "Test for substr failed!");

  start = 8;
  end = 1;
  result = my_substr (str, start, end);
  assert (result == nullptr && "Test for substr failed!");

  delete[]result;				
  std::cout << "Test for substr passed!" << std::endl;
}

void test_reverse() {
    char str1[] = "Hello";
    my_reverse(str1);
    assert(strcmp(str1, "olleH") == 0 && "Test for reverse failed!");

    char str2[] = "World!";
    my_reverse(str2);
    assert(strcmp(str2, "!dlroW") == 0 && "Test for reverse failed!");

    char str3[] = "12345";
    my_reverse(str3);
    assert(strcmp(str3, "54321") == 0 && "Test for reverse failed!");

    std::cout << "Test for reverse passed!" << std::endl;
}


void test_strtok() {
    char str[] = "apple,banana,cherry";
    char* token = my_strtok(str, ",");
    assert(strcmp(token, "apple") == 0 && "Test for strtok failed!");

    token = my_strtok(nullptr, ",");
    assert(strcmp(token, "banana") == 0 && "Test for strtok failed!");

    token = my_strtok(nullptr, ",");
    assert(strcmp(token, "cherry") == 0 && "Test for strtok failed!");

    token = my_strtok(nullptr, ",");
    assert(token == nullptr && "Test for strtok failed!");

    std::cout << "Test for strtok passed!" << std::endl;
}
*/
int
main ()
{
  std::cout << "Testing mystring functions..." << std::endl;

  test_strlen ();
  
  test_strcpy ();
  /*
  test_strcat ();
  test_strchr ();
  test_substr ();
  test_reverse();
  test_strtok();

  std::cout << "All tests passed successfully!" << std::endl;
  */
  return 0;
}
