#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
int main(int argc, char** argv)
{
  char tempLetter;
  char firstLetter;
  char secondLetter;
  int sum; // total number of characters in the file
  int tempSum; // temporary sum for each line in the file
  int number_of_strings; // number of lines in the file
  int tempNum;
  int counter = 0;
  float mean; // sum / number_of_strings
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
  double variance; // Measure of distance from mean for each value
  double standard_deviation; // Square root of variance
  double a, b, c, d;
  const double pi = 3.141592653;
  char inputC;
  string input = argv[1];
  ofstream outputFile;

  //Prepares file to be read
  ifstream myFile;
  string line;

  while (true)
  {
    //resetting to 0
    sum = 0;
    mean = 0.0f;
    variance = 0.0;
    standard_deviation = 0.0;
    number_of_strings = 0;
    tempSum = 0;
    A_probability = 0.0f;
    C_probability = 0.0f;
    T_probability = 0.0f;
    G_probability = 0.0f;
    AA_probability = 0.0f;
    AC_probability = 0.0f;
    AT_probability = 0.0f;
    AG_probability = 0.0f;
    CA_probability = 0.0f;
    CC_probability = 0.0f;
    CT_probability = 0.0f;
    CG_probability = 0.0f;
    TA_probability = 0.0f;
    TC_probability = 0.0f;
    TT_probability = 0.0f;
    TG_probability = 0.0f;
    GA_probability = 0.0f;
    GC_probability = 0.0f;
    GT_probability = 0.0f;
    GG_probability = 0.0f;
    
    myFile.open(input);
    //Loops through first time to determine sum, mean, number of lines, and probability of each single nucleotide
    while(getline(myFile, line))
    {
      number_of_strings++;
      for (int i = 0; i < line.length()-1; ++i)
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

    myFile.open(input);
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

    myFile.open(input);
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


    if (counter == 0)
    {
      outputFile.open("alexjoseph.out");
    }
    else
    {
      outputFile.open("alexjoseph.out", ofstream::app);
      outputFile << endl;
    }

    // Writing output
    outputFile << "Name: Alex Joseph" << endl;
    outputFile << "ID: 2307047" << endl;
    outputFile << endl;
    outputFile << "Sum: " << sum << endl;
    outputFile << "Mean: " << mean << endl;
    outputFile << "Variance: " << variance << endl;
    outputFile << "Standard Deviation: " << standard_deviation << endl;
    outputFile << "Probability of \"A\" nucleotide: " << A_probability << "%" << endl;
    outputFile << "Probability of \"C\" nucleotide: " << C_probability << "%" << endl;
    outputFile << "Probability of \"T\" nucleotide: " << T_probability << "%" << endl;
    outputFile << "Probability of \"G\" nucleotide: " << G_probability << "%" << endl;
    outputFile << "Probability of \"AA\" pair: " << AA_probability << "%" << endl;
    outputFile << "Probability of \"AC\" pair: " << AC_probability << "%" << endl;
    outputFile << "Probability of \"AT\" pair: " << AT_probability << "%" << endl;
    outputFile << "Probability of \"AG\" pair: " << AG_probability << "%" << endl;
    outputFile << "Probability of \"CA\" pair: " << CA_probability << "%" << endl;
    outputFile << "Probability of \"CC\" pair: " << CC_probability << "%" << endl;
    outputFile << "Probability of \"CT\" pair: " << CT_probability << "%" << endl;
    outputFile << "Probability of \"CG\" pair: " << CG_probability << "%" << endl;
    outputFile << "Probability of \"TA\" pair: " << TA_probability << "%" << endl;
    outputFile << "Probability of \"TC\" pair: " << TC_probability << "%" << endl;
    outputFile << "Probability of \"TT\" pair: " << TT_probability << "%" << endl;
    outputFile << "Probability of \"TG\" pair: " << TG_probability << "%" << endl;
    outputFile << "Probability of \"GA\" pair: " << GA_probability << "%" << endl;
    outputFile << "Probability of \"GC\" pair: " << GC_probability << "%" << endl;
    outputFile << "Probability of \"GT\" pair: " << GT_probability << "%" << endl;
    outputFile << "Probability of \"GG\" pair: " << GG_probability << "%" << endl;
    outputFile << endl;
    outputFile.close();

    outputFile.open("alexjoseph.out", ofstream::app);
    //Gaussian distribution calculation and output
    srand (time(NULL));
    for (int i = 0; i < 1000; ++i)
    {
      a = (double) (rand() % 100) / 100.0;
      //Fixes issue where a = 0 and it takes the ln(0) which results in a string length of infinity
      while (a == 0.0)
      {
        a = (double) (rand() % 100) / 100.0;
      }
      b = (double) (rand() % 100) / 100.0;
      c = sqrt(-2.0 * log(a)) * cos(2.0 * pi * b);
      d = (standard_deviation * c) + mean;
      for (int k = 0; k < d; ++k)
      {
        tempNum = (rand() % 100) + 1;
        if (tempNum <= A_probability)
        {
          outputFile << 'A';
        }
        else if (tempNum > A_probability && tempNum <= A_probability + C_probability)
        {
          outputFile << 'C';
        }
        else if (tempNum > A_probability + C_probability && tempNum <= A_probability + C_probability + T_probability)
        {
          outputFile << 'T';
        }
        else
        {
          outputFile << 'G';
        }
      }
      outputFile << endl;
    }
    outputFile.close();
    cout << "Would you like to process another list? (Y/N)" << endl;
    cin >> inputC;
    if (inputC == 'Y')
    {
      cout << "What file would you like to process?" << endl;
      cin >> input;
      ++counter;
    }
    else if (inputC == 'N')
    {
      cout << "Analysis over." << endl;
      break;
    }
    else
    {
      cout << "Invalid input. Ending analysis." << endl;
      break;
    }
  }
  return 0;
}
