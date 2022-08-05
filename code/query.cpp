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

    string tar = *argv;
    string file = *(++argv);
    query(tar, file, fullprint);
    exit(EXIT_SUCCESS);
}

void query(string target, string filename, bool fullprint){
    map<int, string> result;
    ifstream file(filename);  // not done as an argument because original name is needed
    string line, word;
    int line_number, occurrences;

    while(getline(file, line)){
        stringstream linestream(line);

        while(linestream >> word){
            if(!word.compare(target)){
                result[line_number] = line;
                ++occurences;
            }
        }

        ++line_number;
    }

    cout << occurences << " occurences of keyword \"" << target << "\""
         << " in file \"" << filename << "\"" << endl;
    if (!fullprint) return;

    for(auto pair : result){
        cout << "(" << pair.first << ") " << pair.second;
        cout << "\n";
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