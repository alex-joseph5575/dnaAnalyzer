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
  float AA_probability = 0.0f; //Probability of an 'AA' nucleotide pair
  float AC_probability = 0.0f; //Probability of an 'AC' nucleotide pair
  float AT_probability = 0.0f; //Probability of an 'AT' nucleotide pair
  float AG_probability = 0.0f; //Probability of an 'AG' nucleotide pair
  float CA_probability = 0.0f; //Probability of an 'CA' nucleotide pair
  float CC_probability = 0.0f; //Probability of an 'CC' nucleotide pair
  float CT_probability = 0.0f; //Probability of an 'CT' nucleotide pair
  float CG_probability = 0.0f; //Probability of an 'CG' nucleotide pair
  float TA_probability = 0.0f; //Probability of an 'TA' nucleotide pair
  float TC_probability = 0.0f; //Probability of an 'TC' nucleotide pair
  float TT_probability = 0.0f; //Probability of an 'TT' nucleotide pair
  float TG_probability = 0.0f; //Probability of an 'TG' nucleotide pair
  float GA_probability = 0.0f; //Probability of an 'GA' nucleotide pair
  float GC_probability = 0.0f; //Probability of an 'GC' nucleotide pair
  float GT_probability = 0.0f; //Probability of an 'GT' nucleotide pair
  float GG_probability = 0.0f; //Probability of an 'GG' nucleotide pair
  char tempLetter;
  char firstLetter;
  char secondLetter;

  //Prepares file to be read
  ifstream myFile;
  string line;
  myFile.open(argv[1]);

  //Loops through first time to determine sum, mean, number of lines, and probability of each single nucleotide
  while(getline(myFile, line))
  {
    number_of_strings++;
    for (int i = 0; i < line.length(); ++i)
    {
      //counts up number of nucleotides in file
      sum++;
      cout << line[i] << endl;
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
  //Loops through second time to find variance
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

  myFile.open(argv[1]);
  //Loops through third time to find pair probabilities
  while(getline(myFile, line))
  {
    for (int i = 0; i < line.length() - 1; i += 2)
    {
      if (line[i+1] == 'a' || line[i+1] == 'A' || line[i+1] == 'c' || line[i+1] == 'C' || line[i+1] == 't' || line[i+1] == 'T' || line[i+1] == 'g' || line[i+1] == 'G')
      {
        firstLetter = line[i];
        secondLetter = line[i+1];
        toupper(firstLetter);
        toupper(secondLetter);
        //Checks the pairs and adds to one accordingly
        switch(firstLetter)
        {
          case 'A': if (secondLetter == 'A')
                    {
                      AA_probability++;
                    }
                    else if (secondLetter == 'C')
                    {
                      AC_probability++;
                    }
                    else if (secondLetter == 'T')
                    {
                      AT_probability++;
                    }
                    else if (secondLetter == 'G')
                    {
                      AG_probability++;
                    }
                    break;
          case 'C': if (secondLetter == 'A')
                    {
                      CA_probability++;
                    }
                    else if (secondLetter == 'C')
                    {
                      CC_probability++;
                    }
                    else if (secondLetter == 'T')
                    {
                      CT_probability++;
                    }
                    else if (secondLetter == 'G')
                    {
                      CG_probability++;
                    }
                    break;
          case 'T': if (secondLetter == 'A')
                    {
                      TA_probability++;
                    }
                    else if (secondLetter == 'C')
                    {
                      TC_probability++;
                    }
                    else if (secondLetter == 'T')
                    {
                      TT_probability++;
                    }
                    else if (secondLetter == 'G')
                    {
                      TG_probability++;
                    }
                    break;
          case 'G': if (secondLetter == 'A')
                    {
                      GA_probability++;
                    }
                    else if (secondLetter == 'C')
                    {
                      GC_probability++;
                    }
                    else if (secondLetter == 'T')
                    {
                      GT_probability++;
                    }
                    else if (secondLetter == 'G')
                    {
                      GG_probability++;
                    }
                    break;
          default: break;
        }
      }
    }
  }
  AA_probability = (AA_probability / (float) (sum / 2)) * 100.0f;
  AC_probability = (AC_probability / (float) (sum / 2)) * 100.0f;
  AT_probability = (AT_probability / (float) (sum / 2)) * 100.0f;
  AG_probability = (AG_probability / (float) (sum / 2)) * 100.0f;
  CA_probability = (CA_probability / (float) (sum / 2)) * 100.0f;
  CC_probability = (CC_probability / (float) (sum / 2)) * 100.0f;
  CT_probability = (CT_probability / (float) (sum / 2)) * 100.0f;
  CG_probability = (CG_probability / (float) (sum / 2)) * 100.0f;
  TA_probability = (TA_probability / (float) (sum / 2)) * 100.0f;
  TC_probability = (TC_probability / (float) (sum / 2)) * 100.0f;
  TT_probability = (TT_probability / (float) (sum / 2)) * 100.0f;
  TG_probability = (TG_probability / (float) (sum / 2)) * 100.0f;
  GA_probability = (GA_probability / (float) (sum / 2)) * 100.0f;
  GC_probability = (GC_probability / (float) (sum / 2)) * 100.0f;
  GT_probability = (GT_probability / (float) (sum / 2)) * 100.0f;
  GG_probability = (GG_probability / (float) (sum / 2)) * 100.0f;
  myFile.close();


  // Writing output
  ofstream outputFile("alexjoseph.out");
  outputFile << "Name: Alex Joseph" << endl;
  outputFile << "ID: 2307047" << endl;
  outputFile << endl;
  outputFile << "Sum: " << sum << endl;
  outputFile << "Mean: " << mean << endl;
  outputFile << "Variance: " << variance << endl;
  outputFile << "Standard Deviation: " << standard_deviation << endl;


  return 0;
}
