/*
#include "inputOfString.h"

char *shabalin::inputOfString(std::istream &input, size_t stringSize)
{
  char *inputString = nullptr;
  try
  {
    char *inputString = new char[stringSize];
  }
  catch (std::bad_alloc &e)
  {
    delete[] inputString;
    std::cerr << "Error: " << e.what() << '\n';
    throw;
  }
  size_t index = 0;

  inputString = new char[stringSize];
  char currentSymbol = 0;
  input >> std::noskipws;

  while (input >> currentSymbol && currentSymbol != '\n')
  {
    inputString[index] = currentSymbol;
    index += 1;
    if (index + 1 == stringSize)
    {
      try
      {
        char *temporaryString = new char[stringSize + 10];
        for (size_t i = 0; i < stringSize; ++i)
        {
          temporaryString[i] = inputString[i];
        }
        delete[] inputString;
        inputString = temporaryString;
        stringSize += 10;
      }
      catch (const std::bad_alloc &e)
      {
        input >> std::skipws;
        delete[] inputString;
        throw;
      }
    }
    ++index;
  }
  inputString[index] = '\0';
  input >> std::skipws;
  return inputString;
}
*/

#include "inputOfString.h"
#include <stdexcept>

char * shabalin::inputOfString(std::istream& input)
{
  size_t stringSize = 10;
  size_t count = 0;
  char * initialArray = new char[stringSize];
  char currentChar = 0;
  input >> std::noskipws;
  while ((input >> currentChar) && (currentChar != '\n'))
  {
    initialArray[count] = currentChar;
    count += 1;
    if (count == stringSize)
    {
      try
      {
        stringSize += 10;
        char * newArray = new char[stringSize];
        for (size_t i = 0; i < stringSize - 10; ++i)
        {
          newArray[i] = initialArray[i];
        }
        delete [] initialArray;
        initialArray = newArray;
      }
      catch (const std::bad_alloc& e)
      {
        input >> std::skipws;
        delete[] initialArray;
        throw;
      }
    }
  }
  initialArray[count] = '\0';
  input >> std::skipws;
  return initialArray;
}
