#include <iostream>
#include <string>
#include "ItemProcessor.h"

int main(int argc, char **argv) {
  ItemProcessor *processor = new ItemProcessor();
  processor->load("input.txt");
  
  std::cout << processor->pvp(); // Imprime el total
  std::string s = processor->generateTicket(); // Genera el ticket
  std::cout << s;

  delete processor;
}

