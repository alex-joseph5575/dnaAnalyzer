#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, char** argv)
{
  int sum = 0; // total number of characters in the file
  int tempSum = 0; // temporary sum for each line in the file
  int number_of_strings = 0; // number of lines in the file
  int mean = 0; // sum / number_of_strings
  int variance = 0;
  int standard_deviation = 0;
  int A_probability = 0;
  int C_probability = 0;
  int T_probability = 0;
  int G_probability = 0;
  int AA_probability = 0;
  int AC_probability = 0;
  int AT_probability = 0;
  int AG_probability = 0;
  int CA_probability = 0;
  int CC_probability = 0;
  int CT_probability = 0;
  int CG_probability = 0;
  int TA_probability = 0;
  int TC_probability = 0;
  int TT_probability = 0;
  int TG_probability = 0;
  int GA_probability = 0;
  int GC_probability = 0;
  int GT_probability = 0;
  int GG_probability = 0;

  //First cycle can grab sum

  ifstream myFile;
  string line;
  myFile.open(argv[1]);
  while(getline(myFile, line))
  {
    number_of_strings++;
    for (int i = 0; i < line.length(); ++i)
    {
      sum++;
    }
  }
  myFile.close();
  cout << "This is a number:" + sum;
  return 0;
}
