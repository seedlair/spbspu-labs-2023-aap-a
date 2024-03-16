#include <iostream>
#include <cstddef>
#include <stdexcept>

int main()
{
  char* cstring = nullptr;
  char* temp_cstring = nullptr;
  size_t cstr_size = 20;
  char ch = 0;
  size_t step = 0;
  
  try
  {
    cstring = new char[cstr_size]{};
  }
  catch(const std::bad_alloc& e)
  {
    std::cerr << e.what() << '\n';
    delete[] cstring;
    return 1;
  }

  std::cin >> std::noskipws;

  if(!std::cin)
  {
    std::cerr << "invalid input\n";
    delete[] cstring;
    return 1;
  }

  while(std::cin)
  {
    std::cin >> ch;

    if(!std::cin)
    {
      std::cerr << "invalid input\n";
      delete[] cstring;
      return 1;
    }

    if(step == cstr_size - 1)
    {
      cstr_size *= 2;

      try
      {
        temp_cstring = new char[cstr_size]{};
      }
      catch(const std::bad_alloc& e)
      {
        std::cerr << e.what() << '\n';
        delete[] temp_cstring;
        return 0;
      }

      for (size_t i = 0; i < step; i++)
      {
        temp_cstring[i] = cstring[i];
      }

      delete[] cstring;
      
      try
      {
        cstring = new char[cstr_size]();
      }
      catch (const std::bad_alloc& e)
      {
        std::cerr << e.what() << "\n";
        delete[] cstring;
        return 1;
      }

      for (size_t i = 0; i < step; i++)
      {
        cstring[i] = temp_cstring[i];
      }
      delete[] temp_cstring;
    }

    cstring[step] = ch;
    ++step;

    if (ch == '\n')
    {
      cstring[step - 1] = '\0';
      break;
    }
  }

  if (cstring[0] == '\0')
  {
    std::cerr << "Empty input";
    delete[] cstring;
    return 1;
  }
    
  //tasks
  delete[] cstring;
  return 0;
}
