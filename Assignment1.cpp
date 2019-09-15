#include "Assignment1.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>

using namespace std;

Assignment1::Assignment1() // constructor
{
    string text;

    ofstream outfile; // use for outgoing data
    ifstream infile; // use for incoming data

    int stringLength;
    int lineCount;

    double sum; // sum variable and amount of total nucleotides
    double mean; // mean variable
    double variance; // variance variable
    double stdDev; // standard deviation variable

    double Acount = 0; // number of A's
    double Ccount = 0; // number of C's
    double Tcount = 0; // number of T's
    double Gcount = 0; // number of G's


    double probA; // probability of A
    double probC; // probability of C
    double probT; // probablility of T
    double probG; // probability of G
    double probAA = 0; // probability of AA
    double probAC = 0; // probability of AC
    double probAT = 0; // probability of AT
    double probAG = 0; // probability of AG
    double probCA = 0; // probability of CA
    double probCC = 0; // probability of CC
    double probCT = 0; // probability of CT
    double probCG = 0; // probability of CG
    double probTA = 0; // probability of TA
    double probTC = 0; // probability of TC
    double probTT = 0; // probability of TT
    double probTG = 0; // probability of TG
    double probGA = 0; // probability of GA
    double probGC = 0; // probability of GC
    double probGT = 0; // probability of GT
    double probGG = 0; // probability of GG

}
Assignment1::~Assignment1() // destructor
{
    cout << "object deleted" << endl;
}

void Assignment1::Counter(ofstream outfile) // adds up amount of total and individual nucleotides
{
    lineCount = 0;
    for(int i = 0; i < outfile.size(); ++i)
    {
        char c = tolower(outfile[i]); // makes the nucleotides lowercase
        if(c == 'a')
            Acount++; // adds to amount of A's
        else if(c == 'c')
            Ccount++; // adds to total amount of C's
        else if(c == 't')
            Tcount++; // adds to total amount of T's
        else if(c == 'g')
            Gcount++; // adds to total amount of G's
        else if(c == '\n')
            lineCount++; // adds to total amount of lines
    }
}


void Assignment1::Sum(ofstream outfile) // sum function defintion
{
    cout << "A's: " << Acount << endl; // prints out total amount of each nucleotide
    cout << "C's: " << Ccount << endl;
    cout << "T's: " << Tcount << endl;
    cout << "G's: " << Gcount << endl;

    sum = Acount + Ccount + Tcount + Gcount;

    cout << "Sum: " << sum << endl;
}

void Assignment1::Mean(ofstream outfile) // mean function definition
{
    mean = sum / lineCount;

    cout << "Mean: " << mean << endl;
}

void Assignment1::Variance(ofstream outfile) // variance function definition
{
    variance = 0;
    int count = 0;
    for(int j = 0; j < outfile.size(); ++j) // must iterate through text to find line lengths
    {
        if(outfile[j] != '\n')
        {
            count++;
        }
        else if(outfile[j] == '\n')
        {
            stringLength = count;
            variance = variance + pow((stringLength - mean), 2);
            count = 0;

        }
    }
    variance = variance/lineCount; // divides the summation by the num of lines to find variance

    cout << "Variance: " << variance << endl;
}

void Assignment1::StdDev(ofstream outfile) // standard deviation function definition
{
    stdDev = sqrt(variance);

    cout << "Standard Deviation: " << stdDev << endl;
}

void Assignment1::Probability(ofstream outfile) // calculates probability of nucleotides
{                                               // and nucleotide bigrams
    probA = Acount/sum * 100; // probability of A
    probC = Ccount/sum * 100; // probability of C
    probT = Tcount/sum * 100; // probability of T
    probG = Gcount/sum * 100; // probability of G

    for(int i = 0; i < outfile.size(); ++i)
    {
        char c = tolower(outfile[i]);
        char c2;
        if(i+1 <= outfile.size())
        {
            c2 = tolower(outfile[i+1]); // makes sure the index does not go out of bounds
        }
        else
        {
            break; // will exit for loop if second character cannot be indexed
        }
        if(c == 'a') // calculates amount of nucleotide bigrams starting with 'A'
        {
            if(c2 == 'a')
            {
                probAA++;
            }
            else if(c2 == 'c')
            {
                probAC++;
            }
            else if(c2 == 't')
            {
                probAT++;
            }
            else if(c2 == 'g')
            {
                probAG++;
            }
            else
            {
                break;
            }
        }
        else if(c == 'c') // calculates amount of nucleotide bigrams starting with 'C'
        {
            if(c2 == 'a')
            {
                probCA++;
            }
            else if(c2 == 'c')
            {
                probCC++;
            }
            else if(c2 == 't')
            {
                probCT++;
            }
            else if(c2 == 'g')
            {
                probCG++;
            }
            else
            {
                break;
            }
        }
        else if(c == 't') // calculates amount of nucleotide bigrams starting with 'T'
        {
            if(c2 == 'a')
            {
                probTA++;
            }
            else if(c2 == 'c')
            {
                probTC++;
            }
            else if(c2 == 't')
            {
                probTT++;
            }
            else if(c2 == 'g')
            {
                probTG++;
            }
            else
            {
                break;
            }
        }
        else if(c == 'g') // calculates amount of nucleotide bigrams starting with 'G'
        {
            if(c2 == 'a')
            {
                probGA++;
            }
            else if(c2 == 'c')
            {
                probGC++;
            }
            else if(c2 == 't')
            {
                probGT++;
            }
            else if(c2 == 'g')
            {
                probGG++;
            }
            else
            {
                break;
            }
        }
    }
    probAA = probAA/sum * 100;
    probAC = probAC/sum * 100;
    probAT = probAT/sum * 100;
    probAG = probAG/sum * 100;
    probCA = probCA/sum * 100;
    probCC = probCC/sum * 100;
    probCT = probCT/sum * 100;
    probCG = probCG/sum * 100;
    probTA = probTA/sum * 100;
    probTC = probTC/sum * 100;
    probTT = probTT/sum * 100;
    probTG = probTG/sum * 100;
    probGA = probGA/sum * 100;
    probGC = probGC/sum * 100;
    probGT = probGT/sum * 100;
    probGG = probGG/sum * 100;

    cout << "Probability of A: " << probA << endl;
    cout << "Probability of C: " << probC << endl;
    cout << "Probability of T: " << probT << endl;
    cout << "Probability of G: " << probG << endl;
    cout << "\n" << endl;
    cout << "Probability of AA: " << probAA << endl;
    cout << "Probability of AC: " << probAC << endl;
    cout << "Probability of AT: " << probAT << endl;
    cout << "Probability of AG: " << probAG << endl;
    cout << "\n" << endl;
    cout << "Probability of CA: " << probCA << endl;
    cout << "Probability of CC: " << probCC << endl;
    cout << "Probability of CT: " << probCT << endl;
    cout << "Probability of CG: " << probCG << endl;
    cout << "\n" << endl;
    cout << "Probability of TA: " << probTA << endl;
    cout << "Probability of TC: " << probTC << endl;
    cout << "Probability of TT: " << probTT << endl;
    cout << "Probability of TG: " << probTG << endl;
    cout << "\n" << endl;
    cout << "Probability of GA: " << probGA << endl;
    cout << "Probability of GC: " << probGC << endl;
    cout << "Probability of GT: " << probGT << endl;
    cout << "Probability of GG: " << probGG << endl;
}

void Assignment1::GaussianDistribution(ofstream outfile)
{
    for(int i = 0; i < 1000; ++i) // for loop will generate 1000 DNA strings
    {
        double a = ((double) rand() / (RAND_MAX)); // generates psuedorandom number between [0,1)
        double b = ((double) rand() / (RAND_MAX)); // another psuedorandom number between [0,1)
        double C = sqrt(-2ln(a)) * cos(2*b*M_PI); // Box-Mueller transform to calculate standard Gaussian
        double D = (stdDev * C) + mean; // calculates normal random variable D

        for(int j = 0; j < D; ++j) //
        {

        }
    }

}
