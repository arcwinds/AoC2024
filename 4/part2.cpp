#include <regex>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int exists_ldg(char buf[][140], const string &word, int pos_x, int pos_y);
int exists_rdg(char buf[][140], const string &word, int pos_x, int pos_y);

int main() {
    string line_buf;
    char buf[140][140];
    int total_xmas = 0;

    ifstream input;
    input.open("../4/input");

    for(int y=0; y<140; y++)
        for(int x=0; x<140; x++)
            input >> buf[y][x];

    for(int y=0; y<140; y++)
        for(int x=0; x<140; x++)
            total_xmas +=  (exists_rdg(buf, "MAS", x, y)   || exists_rdg(buf, "SAM", x, y)  )
                        && (exists_ldg(buf, "MAS", x+2, y) || exists_ldg(buf, "SAM", x+2, y));


    input.close();

    cout << "Total XMAS found: " << total_xmas << endl;

    return 0;
}

int exists_ldg(char buf[][140], const string &word, const int pos_x, const int pos_y) {
    for (int i=0; i<word.size(); i++)
        if (pos_x - i < 0 || pos_y+ i >= 140 || buf[pos_y + i][pos_x - i] != word[i])
            return 0;

    return 1;
}

int exists_rdg(char buf[][140], const string &word, const int pos_x, const int pos_y) {
    for (int i=0; i<word.size(); i++)
        if (pos_x + i >= 140 || pos_y+ i >= 140 || buf[pos_y + i][pos_x + i] != word[i])
            return 0;

    return 1;
}