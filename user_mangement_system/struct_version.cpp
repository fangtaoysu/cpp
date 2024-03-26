/**
 * 通讯录管理系统：
 * 增删改查 + 修改 清空 退出
*/
#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of user_array

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

void add_user(string user_array[][5], int& size) {
    string user[5];
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
    user[0] = name;
    user[1] = (sex == "0") ? "女" : "男";
    user[2] = age;
    user[3] = tel;
    user[4] = addr;

    if (size < MAX_SIZE) {
        for (int i = 0; i < 5; ++i) {
            user_array[size][i] = user[i];
        }
        ++size;
        cout << "联系人添加成功！" << endl;
    } else {
        cout << "通讯录已满，无法添加更多联系人。" << endl;
    }
}

int find_user(string user_array[][5], int size, string name) {
    cout << "查询记录的姓名？" << endl;
    cin >> name;
    int i = 0;
    for (int i = 0; i < size; ++i) {
        if (user_array[i][0] == name) {
            return i;
        }
    }
    if (i == size) {
        cout << "查无此人" << endl;
        return -1;
    }
}

void show_user(string user_array[][5], int left, int right) {
    for (int i = left; i < right; ++i) {
        cout << "姓名：" << user_array[i][0]
             << "\t性别：" << user_array[i][1]
             << "\t年龄：" << user_array[i][2]
             << "\t电话：" << user_array[i][3]
             << "\t住址：" << user_array[i++][4] << endl;
    }
    
}

bool delete_user(string user_array[][5], int& size, string name) {
    int ix = 0;
    while (ix < size) {
        if (user_array[ix][0] == name) {
            for (int j = 0; j < 5; ++j) {
                user_array[ix][j] = user_array[size-1][j];
            }
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

void update_user(string user_array[][5], int size, string name) {
    if(delete_user(user_array, size, name)) {
        add_user(user_array, size);
    }
}

void clear_user(int& size) {
    size = 0;
}

int main() {
    int size = 0; // Current size of user_array
    char command = ' ';
    int index = 0;
    string name = " ";    // 为什么必须初始化才能在switch里面赋值
    bool more = true;
    static string user_array[MAX_SIZE][5];

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

        cout << endl;
    }

    return 0;
}