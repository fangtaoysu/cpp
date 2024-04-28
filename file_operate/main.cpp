#include <fstream>
#include <iostream>


using namespace std;

void WriteFile() {
    // 创建流对象
    ofstream ofs;
    string file_path = "file1.txt";
    /***
     * ios::in - 读
     * ios::out - 写
     * ios::ate - 初始位置：文件尾
     * ios::app - 追加
     * ios::trunc - 覆盖
     * ios::binary - 二进制
     * */
    // 写文件
    ofs.open(file_path, ios::ate); 
    ofs << "hello, fi  le1";
    ofs.close();
}

void ReadFile() {
    ifstream ifs;
    string file_path = "file1.txt";
    ifs.open(file_path, ios::in);
    if(!ifs.is_open()) {
        cout << "open error" << endl;
        return;
    } 
    // 一行一行读
    // char buf[1024] = {0};
    // while (ifs.getline(buf, sizeof(buf))) {
    //     cout << buf << endl;
    // }
    // 一块一块读，遇到特殊字符会换行
    // char buf[1024] = {0};
    // while (ifs >> buf) {
    //     cout << buf << endl;
    // }
    // 一行一行读
    // string buf;
    // while (getline(ifs, buf)) {
    //     cout << buf << endl;
    // }
    // 一个一个读
    char c;
    while ((c = ifs.get()) != EOF) { // end of file
        cout << c << endl; 
    }
    ifs.close();
}

class Person {
    public:
        char name[64];
        int age;
};

void ReadBinary() {
    string file_path = "text2.txt";
    ofstream ofs(file_path, ios::out | ios::binary);
    Person p = {"arsion", 30};
    // 需要使用const char * 类型
    ofs.write((const char *)&p, sizeof(Person));
}

void WriteBinary() {
    string file_path = "text2.txt";
    ifstream ifs(file_path, ios::in | ios::binary);
    Person s;
    if (!ifs.is_open()) {
        cout << "open error" << endl;
        return;
    }
    ifs.read((char *)&s, sizeof(Person));
    cout << s.name << endl;
    cout << s.age << endl;
}

int main() {
    ReadFile();
    WriteFile();
    WriteFile();
    WriteBinary();
    return 0;
}