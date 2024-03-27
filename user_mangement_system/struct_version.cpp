/**
 * 通讯录管理系统：
 * 增删改查 + 修改 清空 退出
*/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of user_array
struct User {
    string name;
    bool sex;
    int age;
    string tel;
    string addr;
};

void show_ui() {
    cout << "*************************************************" << endl;
    cout << "***************  1、添加联系人  ******************" << endl;
    cout << "***************  2、显示联系人  ******************" << endl;
    cout << "***************  3、删除联系人  ******************" << endl;
    cout << "***************  4、查找联系人  ******************" << endl;
    cout << "***************  5、修改联系人  ******************" << endl;
    cout << "***************  6、清空联系人  ******************" << endl;
    cout << "***************  0、退出联系人  ******************" << endl;
    cout << "*************************************************" << endl;
}

bool len_check(string item, int left, int right) {
    if (item.length() < left || item.length() > right) {
        cout << "参数不合法" << endl;
        return false;
    }
    return true;
}

bool type_check(string item, string type) {
    if (type == "int") {
        for (int i = 0; i < item.length(); ++i) {
            if (item[i] > '9' || item[i] < '0') {
                cout << "不是int类型" << endl;
                return false;
            }
        }
    }
    return true;
}

void add_user(User user_array[], int& size) {
    string name, sex, age, tel, addr;
    cout << "姓名？" << endl;
    cin >> name;
    while (!len_check(name, 2, 4)) {
        cin >> name;
    }
    cout << "性别？(男1女0)" << endl;
    cin >> sex;
    while (sex != "0" && sex != "1") {
        cout << "输入不合法" << endl;
        cin >> sex;
    }
    cout << "年龄？" << endl;
    cin >> age;
    while (!len_check(age, 1, 3) || !type_check(age, "int")) {
        cin >> age;
    }
    cout << "电话？" << endl;
    cin >> tel;
    while (!len_check(tel, 11, 12) || !type_check(tel, "int")) {
        cin >> tel;
    }
    cout << "住址？" << endl;
    cin >> addr;
    while (!len_check(addr, 6, 100)) {
        cin >> addr;
    }

    if (size < MAX_SIZE) {
        user_array[size].name = name;
        user_array[size].sex = (sex == "0") ? false : true;
        user_array[size].age = stoi(age);
        user_array[size].tel = tel;
        user_array[size++].addr = addr;
        cout << "联系人添加成功！" << endl;
    } else {
        cout << "通讯录已满，无法添加更多联系人。" << endl;
    }
}

int find_user(User user_array[], int size, string name) {
    int i = 0;
    for (int i = 0; i < size; ++i) {
        if (user_array[i].name == name) {
            return i;
        }
    }
    if (i == size) {
        cout << "查无此人" << endl;
        return -1;
    }
}

void show_user(User user_array[], int left, int right) {
    for (int i = left; i < right; ++i) {
        string s = user_array[i].sex ? "男" : "女";
        cout << "姓名：" << user_array[i].name
             << "\t性别：" << s
             << "\t年龄：" << user_array[i].age
             << "\t电话：" << user_array[i].tel
             << "\t住址：" << user_array[i++].addr << endl;
    }
    
}

bool delete_user(User user_array[], int& size, string name) {
    int ix = 0;
    while (ix < size) {
        if (user_array[ix].name == name) {
            user_array[ix] = user_array[size-1];
            --size;
            cout << "删除成功" << endl;
            return true;
        }
        ++ix;
    }
    if (ix == size) {
        cout << "查无此人" << endl;
        return false;
    }
}

void update_user(User user_array[], int size, string name) {
    if(delete_user(user_array, size, name)) {
        add_user(user_array, size);
    }
}

void clear_user(int& size) {
    size = 0;
}

int main() {
    bool more = true;
    char command = ' ';
    string name = " ";
    int size = 0;
    int index = 0;
    User user_array[MAX_SIZE];

    while (more) {
        show_ui();
        cin >> command;

        switch (command) {
            case '1':
                add_user(user_array, size);
                break;
            case '2':
                show_user(user_array, 0, size);
                break;
            case '3':
                cout << "输入需要删除的用户名：" << endl;
                cin >> name;
                delete_user(user_array, size, name);
                break;
            case '4':
                cout << "输入需要查找的用户名：" << endl;
                cin >> name;
                index = find_user(user_array, size, name);
                show_user(user_array, index, index+1);
                break;
            case '5':
                cout << "输入需要查找的用户名：" << endl;
                cin >> name;
                update_user(user_array, size, name);
                break;
            case '6':
                clear_user(size);
                break;
            case '0':
                more = false;
                break;
            default:
                cout << "命令不正确" << endl;
                break;
        }
    }
    system("clear");
    return 0;
}