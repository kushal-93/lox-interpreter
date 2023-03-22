#include <iostream>
#include <fstream>
#include <vector>
#include <string>


void run(std::string source) {
  std::cout << source << std::endl;
  // TODO: scanner class
  //Scanner scanner;
  //vector<string> tokens = scanner.scanTokens();
}

void runFile(const char *filePath) {  
  std::string path = filePath;
  std::cout << path << std::endl;
  try {
    std::ifstream file(path);
    std::string content = "";
    if(file.is_open()) {
      while(true) {
        char c = file.get();
        if(file) {
          content.push_back(c);
        }
        else
          break;
      }
    }
    run(content);
  }
  catch (const std::exception e) {
    std::cout << e.what() << std::endl;
  }
}

void runPrompt() {
  for(;;) {
    std::cout << "> " ;
    std::string line;
    std::getline(std::cin, line);
    if (line.empty()) 
      break;
    run(line);
  }
}



int main(int argc, char const *argv[])
{
  
  if (argc > 2) {
    std::cout << "Usage: cpplox [script]" << std::endl;
    exit;
  }
  else if (argc == 2) {
    runFile(argv[1]);
  }
  else {
    runPrompt();
  }

  return 0;
}
