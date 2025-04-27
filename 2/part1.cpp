#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<int> parse(string line);
bool is_safe(const vector <int>& report);

int main()
{
    string line_buf;
    int safe_reports = 0;

    ifstream input;
    input.open("../2/input");

    vector<int> current_report;
    while (getline(input, line_buf)) {
        current_report.clear();
        current_report = parse(line_buf);
        safe_reports += is_safe(current_report);
    }

    input.close();

    cout << "Amount of safe reports: " << safe_reports << endl;

    return 0;
}

vector<int> parse(string line)
{
    vector<int> nums;

    while (!line.empty()) {
        string current_num;

        if (line.find(' ') == string::npos) {
            current_num = line.substr(0, line.find('\n'));
            line = "";
        } else {
            current_num = line.substr(0, line.find(' '));
            line = line.substr(line.find(' ') + 1, line.size()-1);
        }

        nums.push_back(stoi(current_num));
    }

    return nums;
}

bool is_safe(const vector <int>& report)
{
    const bool ascending = report.at(0) < report.at(report.size()-1);

    for (int i=0; i<report.size()-1; i++) {
        int diff = abs(report.at(i) - report.at(i+1));

        if ( (ascending && report.at(i) > report.at(i+1)) ||
            (!ascending && report.at(i) < report.at(i+1)) ||
            diff<1 || diff>3 )
            return false;
    }

    return true;
}