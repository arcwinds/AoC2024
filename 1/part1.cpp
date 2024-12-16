#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    string line_buf;
    int index = 0, total_distance = 0;

    ifstream input;
    input.open("../1/input");

    vector<int> left_col, right_col;
    while (getline(input, line_buf)) {
        string left_num = line_buf.substr(0, line_buf.find("   "));
        string right_num = line_buf.substr(line_buf.find("   ") + 3, line_buf.size());

        left_col.push_back(stoi(left_num));
        right_col.push_back(stoi(right_num));
        index++;
    }

    ranges::sort(left_col);
    ranges::sort(right_col);
    for (int i=0; i<left_col.size(); i++) {
        total_distance += abs(left_col.at(i)-right_col.at(i));
    }

    input.close();

    cout << "Total distance: " << total_distance << endl;

    return 0;
}