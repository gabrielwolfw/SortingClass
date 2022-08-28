#include <iostream>
#include <fstream>

using namespace std;




int openingFile(){
    ifstream filing;
    string line;
    filing.open("archivo.txt");
    while(filing){
        getline(filing,line);
        
        cout<< "Content inside:" << line;
        cout << "\n";

    }
    filing.close();
    return 0;
}





//To open a file
int main(){
    openingFile();
}