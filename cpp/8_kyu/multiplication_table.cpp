//main.cpp https://www.codewars.com/kata/5a2fd38b55519ed98f0000ce
#include <string>
#include <iostream>

std::string multi_table(int Number)
{
  std::string Table{};
  int Response{};
    for(int i=1;i<=10;i++)
      {
      Response = Number * i;
      std::string sNumber = std::to_string(Number);
      std::string sResponse = std::to_string(Response);
      std::string sInt = std::to_string(i);
      if (i == 10)
        {
        Table += sInt + " * " + sNumber + " = " + sResponse;
        }
      else
        {
        Table += sInt + " * " + sNumber + " = " + sResponse + "\n";
        }
      }
    return Table;
}
