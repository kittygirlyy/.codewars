//main.cpp https://www.codewars.com/kata/5265326f5fda8eb1160004c8
#include <string>
#include <iostream>

std::string number_to_string(int Number) {
  return (Number) ? std::to_string(Number) : std::to_string(Number);
}
