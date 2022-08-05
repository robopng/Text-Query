# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <string>
# include "query.h"

# define VERSION "0.1.0\0"
# define APP "Text Query\0"

using namespace std;

int main(int argc, char *argv[]){
    bool fullprint = false;

    while(**(++argv) == '-'){
        string str = *argv;

        // if any of these are altered, remember to update print_help!
        if(!str.compare("-fp") || !str.compare("--fullprint")) fullprint = true;
        else if(!str.compare("-h") || !str.compare("--help")) print_help();
    }

    // having these directly in the query call doesn't work, pointer issue?
    string tar = *argv, file = *(++argv);
    query(tar, file, fullprint);

    exit(EXIT_SUCCESS);
}

void query(string target, string filename, bool fullprint){
    map<int, string> result;  // <line number, line>
    ifstream file(filename);  // not done as an argument because original name is needed
    string line = "", word = "";
    int line_number = 0;

    // unnecessary guard but makes program overall more readable in console
    if(!file.is_open()){
        cout << "No such file or directory!" << endl;
        exit(EXIT_FAILURE);
    }

    while(getline(file, line)){
        istringstream linestream(line);

        while(linestream >> word){
            if(!word.compare(target)){
                // automatically add nonexistent pair to result map
                result[line_number] = line;
            }
        }

        ++line_number;
    }

    // x occurences of keyword "x" in file "y"
    cout << results.size() << " occurences of keyword \"" << target << "\""
         << " in file \"" << filename << "\"" << endl;
    if (!fullprint) return;

    for(auto pair : result){
        cout << "(" << pair.first << ") " << pair.second;
        cout << "\n";  // flush is too costly here
    }
    cout << endl;
}


void print_help(){
    cout << APP << " v" << VERSION << "\n";
    // keep the bars aligned
    cout << "\t-h  || --help: Prints this statement\n";
    cout << "\t-fp || --fullprint: Prints the lines and line numbers where occurences were found\n";
    cout << endl;

    exit(EXIT_SUCCESS);
}