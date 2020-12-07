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
    char readFilename[12];
    char writeFileName[12];

    //ask user to enter the input and output file names
    cout <<"Enter the name of the file to open (maximum 11 characters): ";
    cin >> readFilename;
    cout <<"\nEnter the name of the file to write to (maximum of 11 characters): ";
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

    //Get the first character and make it into upper case and write to new file
    char ch;
    reading.get(ch);
    writing<<static_cast<char>(toupper(ch));

    //while loop to read the input file until end of file is reached
    while(!reading.eof())

    {
        //get each character
        reading.get(ch);
        //if the character is a '5', convert it to an 's' and write to the file
        if (ch == '5')
            {
               ch='s';
               writing<<ch;
            }

        //check for the end of sentences
        else if (ch=='.')
            {
                //write the period to the new file, then get the next character
                writing<<ch;
                reading.get(ch);
                //if the next character is a space, then write it to the new file and get the next character
                    if(ch==' ')
                        {
                            writing<<ch;
                            reading.get(ch);
                            //if that character is a five, convert it to an 's'
                            if (ch == '5')
                                {
                                    ch='s';
                                }
                            //convert the character to an upper case letter and write to the new file
                            writing<<static_cast<char>(toupper(ch));
                        }
            }
        else
            //if it is neither a 5 nor the start of a new sentence, simply write to a new file as is
            writing<<ch;
    }

//close the files
    reading.close();
    writing.close();


    return 0;

}
