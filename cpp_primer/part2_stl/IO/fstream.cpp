#include <fstream>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
/**
 * ifstream对象：被读文件
 * ofstream对象：被写对象
 */

void WriteFileByFile(std::ofstream &os, const std::string &input_file_name, const std::string &output_file_name) {
    // 将input_file_name的内容写入output_file_name文件中
    std::ifstream ifile(input_file_name);
    char buf[1024] = {0};
    os << "This file name is: " + output_file_name + "\n";
    if (ifile.is_open()) { //判断输入文件是否打开
        int i = 1;
        while (ifile.getline(buf, sizeof(buf))) { // 按行写入
            cout << i++ << ": "
                 << buf << "（已写入）\n";
            os << buf << "\n";
        }
    } else {
        std::cerr << "couldn't open the input file: " << output_file_name << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        
    } else {
        // 通过参数列表创建文件，把输入文件的内容写入到新建的文件中
        std::string input_file = "file1.txt";
        for (auto p = argv + 1; p != argv + argc; ++p) {
            std::ofstream output(*p);
            std::string output_file = std::string(*p);
            if (output) { // 如果文件打开成功
                WriteFileByFile(output, input_file, output_file);
            } else {
                std::cerr << "could't open: " + output_file;
            }
        }
    }
    return 0;
}