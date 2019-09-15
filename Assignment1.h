#include <iostream>
#include <fstream>

using namespace std;

class Assignment1
{
    public: //access modifier
        Assignment1(); //constructor
        ~Assignment1(); //destructor

        void Counter(ifstream infile);

        void Sum(ofstream outfile);
        void Mean(ofstream outfile);
        void Variance(ofstream outfile);
        void StdDev(ofstream outfile);
        void Probability(ofstream outfile);
        void GaussianDistribution(ofstream outfile);


    private: // instance variables
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
};
