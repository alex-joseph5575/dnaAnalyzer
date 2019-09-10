#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, char** argv)
{
  ifstream myFile;
  string line;
  myFile.open(argv[1]);
  while(getline(myFile, line))
  {
    cout << line << '\n';
  }
  myFile.close();

  return 0;
}
