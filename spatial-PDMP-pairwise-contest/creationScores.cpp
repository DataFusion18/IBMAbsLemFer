#include <iostream>
#include "./code/Population.h"
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //parameters to specify

    cout << "argc = " << argc << endl;
    if (argc != 4)
        {
            cout << "3 arguments: ID cluster min, ID cluster max, ID job max" << endl;
            return -1;
        }

    string nameFile("a");
    ifstream lecture;
    string nameFileFinal("scoresCommuns.txt");
    ofstream fluxEcriture(nameFileFinal.c_str());

    for (int k(atoi(argv[1])); k <= atoi(argv[2]); k++)
    {
    for (int l(0); l <= atoi(argv[3]); l++)
    {

        ostringstream oss;
        oss << "./communs/scoresCommuns" << k << "_" << l << ".txt";
        nameFile = oss.str();
        lecture.open(nameFile.c_str(),ios::in);
        if(lecture)
        {
            string contenu;
            getline(lecture, contenu);
            fluxEcriture << contenu;
            fluxEcriture << endl;
            lecture.close();
        }

    }
    }


    return 0;
}
