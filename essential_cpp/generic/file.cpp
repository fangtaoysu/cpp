#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;

int main() {
    ifstream in_file("input_file.txt");
    ofstream out_file("output_file.txt");

    if (!in_file || !out_file) {
        cerr << "Oops, unable to open the necessary files." << endl;
        return -1;
    }
    istream_iterator<string> is(in_file);
    istream_iterator<string> eof;
    
    vector<string> text;
    copy(is, eof, back_inserter(text));

    sort(text.begin(), text.end());

    ostream_iterator<string> os(out_file, " ");
    copy(text.begin(), text.end(), os);
}