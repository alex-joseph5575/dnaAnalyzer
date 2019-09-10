#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, char** argv)
{
  ifstream myFile;
  string line;
  myFile.open("TestFile.txt");
  while(getLine(myFile, line))
  {
    cout << line << '\n';
  }
  myFile.close();

  return 0;
}
