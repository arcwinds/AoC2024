#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    string line_buf;
    int index = 0, similarity_score = 0;

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
    for (int left_num : left_col) {
        similarity_score += left_num * ranges::count(right_col, left_num);
    }

    input.close();

    cout << "Similarity score: " << similarity_score << endl;

    return 0;
}