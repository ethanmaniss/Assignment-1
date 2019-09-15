#include "Assignment1.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{

    if(argc > 1)
    {

        ifstream infile; // use for incoming data
        ofstream outfile; // use for outgoing data

        outfile.open("ethanmaniss.out"); // creates .out file to output results

        outfile << "Ethan Maniss" << endl; // outputs student info first to the file
        outfile << "2324967" << endl;
        outfile << "CPSC 350" << endl;
        outfile << "Assignment 1" << endl;
        outfile << "\n" << endl;

        while(true)
        {
            string text = ""; // create string variable

            cout << "Enter the text file name: " << endl; // prompts user for text file name
            cin >> text; // user inputs the name of a text file

            infile.open(text.c_str()); // turns string into a char[]

            Assignment1 A1; // creates Assignment1 object

            A1.Counter(infile);
            A1.Sum(outfile);
            A1.Mean(outfile);
            A1.Variance(outfile);
            A1.StdDev(outfile);
            A1.Probability(outfile);
            A1.GaussianDistribution(outfile);

            infile.close(); // close stream for file input

            char choice;
            while(true) // will prompt user to find out if another list should be processed
            {
                cout << "Process another list? 'Y' for yes or 'N' for no: " << endl;
                cin >> choice;

                if(tolower(choice) == 'y')
                {
                    break;
                }
                else if(tolower(choice) == 'n')
                {
                    outfile.close(); // close this after user decides there are no more lists to process
                    return 0; // program will end
                }
                else
                {
                    cout << "Please enter either 'Y' for yes or 'N' for no: " << endl;
                    break;
                }
            }
        }
    }
    else
    {
        cout << "Please enter the name of a text file." << endl;
    }

    cout << "Program exited successfully." << endl;

    return 0;
}
