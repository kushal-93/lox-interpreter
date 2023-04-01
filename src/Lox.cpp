#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Lox {
  private:

    void report(int line, std::string where, std::string message) {
      std::cout << "[line " << line << "] Error" + where + ": " + message << std::endl;
      hadError = true;
    }

    void run(std::string source) {
      std::cout << source << std::endl;
      // TODO: scanner class
      //Scanner scanner;
      //vector<string> tokens = scanner.scanTokens();
    }

  public:
    bool hadError;

    void error(int line, std::string message) {
      report(line, "", message);
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
        if (hadError)
          exit(65);
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
        hadError = false;
      }
    }

};

int main(int argc, char const *argv[]) {
  Lox lox;
  lox.hadError = false;
  
  if (argc > 2) {
    std::cout << "Usage: cpplox [script]" << std::endl;
    exit(64);
  }
  else if (argc == 2) {
    lox.runFile(argv[1]);
  }
  else {
    lox.runPrompt();
  }

  return 0;
}
