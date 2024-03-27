/**
 * 通讯录管理系统：
 * 增删改查 + 修改 清空 退出
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iterator>
using namespace std;

const int MAX_SIZE = 1024; // Maximum size of user_vector
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

void add_user(vector<User> &user_vector) {
    if (user_vector.size() >= MAX_SIZE) {
        cout << "通讯录已满，无法添加更多联系人。" << endl;
        return;
    }
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

    User new_user;
    new_user.name = name;
    new_user.name = name;
    new_user.sex = (sex == "0") ? false : true;
    new_user.age = stoi(age);
    new_user.tel = tel;
    new_user.addr = addr;
    user_vector.push_back(new_user);
    cout << "联系人添加成功！" << endl;
}

vector<User>::iterator find_user(vector<User>::iterator b, vector<User>::iterator e, string name) {
    vector<User>::iterator it = b;
    while(it != e) {
        if (it->name == name) {
            return it;
        }
        ++it;
    }
    return it;
}

void show_user(vector<User>::iterator b, vector<User>::iterator e) {
    vector<User>::iterator it = b;
    while (it != e) {
        string s = it->sex ? "男" : "女";
        cout << "姓名：" << it->name
             << "\t性别：" << s
             << "\t年龄：" << it->age
             << "\t电话：" << it->tel
             << "\t住址：" << it->addr << endl;
        ++it;
    }
    
}

bool delete_user(vector<User> &user_vector, string name) {
    vector<User>::iterator it = find_user(user_vector.begin(), user_vector.end(), name);
    if (it == user_vector.end()) {
        return false;
    }
    user_vector.erase(it);
    return true;
}

void update_user(vector<User> &user_vector, string name) {
    if(delete_user(user_vector, name)) {
        add_user(user_vector);
    } else {
        cout << "查无此人" << endl;
    }
}

void clear_user(vector<User> &user_vector) {
    user_vector.clear();
    cout << "通讯录内容已全部清除" << endl;
}

int main() {
    bool more = true;
    char command = ' ';
    string name = " ";
    vector<User>::iterator it;
    vector<User> user_vector;

    while (more) {
        show_ui();
        cin >> command;

        switch (command) {
            case '1':
                add_user(user_vector);
                break;
            case '2':
                show_user(user_vector.begin(), user_vector.end());
                break;
            case '3':
                cout << "输入需要删除的用户名：" << endl;
                cin >> name;
                if (delete_user(user_vector, name)) {
                    cout << name << "删除成功" << endl;
                } else {
                    cout << "查无此人" << endl;
                }
                break;
            case '4':
                cout << "输入需要查找的用户名：" << endl;
                cin >> name;
                it = find_user(user_vector.begin(), user_vector.end(), name);
                show_user(it, it+1);
                break;
            case '5':
                cout << "输入需要查找的用户名：" << endl;
                cin >> name;
                update_user(user_vector, name);
                break;
            case '6':
                clear_user(user_vector);
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