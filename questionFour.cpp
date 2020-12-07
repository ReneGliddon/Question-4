#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    //declare variables for in stream and outstream
    ifstream reading;
    ofstream writing;

    //declare character variables to hold input and output file names
    char readFilename[11];
    char writeFileName[11];

    //ask user to enter the input and output file names
    cout <<"Enter the name of the file to open (maximum 10 characters): ";
    cin >> readFilename;
    cout <<"\nEnter the name of the file to write to (maximum of 10 characters): ";
    cin >> writeFileName;

    //open the requested files and test whether they were opened successfully. If not, abort program
    reading.open(readFilename);
    if (reading.fail())
    {
        cout<<"\nError opening "<<readFilename<<". Program will close.";
        exit(1);
    }

    writing.open(writeFileName);
    if (writing.fail())
    {
        cout << "\nError opening "<<writeFileName<<". Program will close.";
        exit(1);
    }

    char ch;
    reading.get(ch);
    writing<<static_cast<char>(toupper(ch));

    while(!reading.eof())

    {

        reading.get(ch);
        if (ch == '5')
            {
               ch='s';
               writing<<ch;
            }


        else if (ch=='.')
            {
                writing<<ch;
                reading.get(ch);
                    if(ch==' ')
                        {
                            writing<<ch;
                            reading.get(ch);
                            if (ch == '5')
                                {
                                    ch='s';
               //writing<<ch;
                                }
                            writing<<static_cast<char>(toupper(ch));
                        }
            }
        else
            writing<<ch;
    }


    reading.close();
    writing.close();
    return 0;

}
