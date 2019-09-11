#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
int main(int argc, char** argv)
{
  int sum = 0; // total number of characters in the file
  int tempSum = 0; // temporary sum for each line in the file
  int number_of_strings = 0; // number of lines in the file
  float mean = 0.0f; // sum / number_of_strings
  double variance = 0.0; // Measure of distance from mean for each value
  double standard_deviation = 0.0; // Square root of variance
  float A_probability = 0.0f; //Probability of an 'A' nucleotide
  float C_probability = 0.0f; //Probability of a 'C' nucleotide
  float T_probability = 0.0f; //Probability of a 'T' nucleotide
  float G_probability = 0.0f; //Probability of a 'G' nucleotide
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
  char tempLetter;

  //Prepares file to be read
  ifstream myFile;
  string line;
  myFile.open(argv[1]);

  //Loops through first time to determine sum, mean, and number of lines
  while(getline(myFile, line))
  {
    number_of_strings++;
    for (int i = 0; i < line.length(); ++i)
    {
      //counts up number of nucleotides in file
      sum++;

      //grabs current character from the line and uppercases
      tempLetter = line[i];
      toupper(tempLetter);

      //counts up how many of each nucleotide are in the file
      switch (tempLetter)
      {
        case 'A': A_probability++;
                  break;
        case 'C': C_probability++;
                  break;
        case 'T': T_probability++;
                  break;
        case 'G': G_probability++;
                  break;
        default:
                  break;
      }
    }
  }

  A_probability = (A_probability / (float) sum) * 100.0f;
  C_probability = (C_probability / (float) sum) * 100.0f;
  T_probability = (T_probability / (float) sum) * 100.0f;
  G_probability = (G_probability / (float) sum) * 100.0f;

  myFile.close();

  mean = (float) sum / (float) number_of_strings;

  myFile.open(argv[1]);
  //Loops through second time
  while(getline(myFile, line))
  {
    for (int i = 0; i < line.length(); ++i)
    {
      tempSum++;
    }
    variance += pow((double)tempSum - mean, 2.0);
    tempSum = 0;
  }
  variance /= (double) number_of_strings;
  standard_deviation = sqrt(variance);
  myFile.close();
  return 0;
}
