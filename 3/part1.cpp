#include <regex>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string line_buf;
    int sum = 0;

    ifstream input;
    input.open("../3/input");


    const regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
    smatch match;

    while (getline(input, line_buf)) {

        string::const_iterator search_start = line_buf.begin();
        const string::const_iterator search_end = line_buf.end();

        while ( regex_search(search_start, search_end, match, pattern) ) {
            sum += stoi(match[1]) * stoi(match[2]);
            search_start = match.suffix().first;
        }
    }

    input.close();

    cout << "Sum of multiplications: " << sum << endl;

    return 0;
}