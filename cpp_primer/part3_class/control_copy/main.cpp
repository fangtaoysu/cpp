#include <vector>
#include <string>
#include <iostream>
#include "./head_dir/sales_data.h"
#include "./head_dir/has_value.h"
#include "./head_dir/has_ptr.h"
#include "./head_dir/message.h"
#include "./head_dir/folder.h"
#include "./head_dir/str_vec.h"


void CopyInitalizate() {
    std::string dots(10, '.'); // 直接初始化
    std::string s(dots); // 直接初始化
    std::string s2 = s; // 拷贝初始化（有=运算符）
    std::string nines = std::string(100, '9'); //拷贝初始化
}

HasValue f(HasValue hp) {
    // 如果没有定义拷贝赋值运算符，此处调用合成拷贝赋值运算符
    HasValue ret = hp;
    return ret; // 离开该函数，hp和ret分别自动释放，此时会对同一对象调用两次析构函数
}

void TestLikeValue() {
    HasValue p("some values");
    f(p);
    HasValue q(p);
}

void TestLikePtr() {
    HasPtr p("look");
    HasPtr q("at");
    std::cout << p.GetPs() << "\t"
              << q.GetPs() << std::endl;
    p = q;
    std::cout << p.GetPs() << "\t"
              << q.GetPs() << std::endl;
    q = std::move(p);
}

struct NoCopy {
    NoCopy()=default;
    NoCopy(const NoCopy &)=delete; // 阻止拷贝
    NoCopy &operator=(const NoCopy &)=delete; // 阻止赋值
    ~NoCopy()=default;
}; 

void TestMsg() {
    Folder inbox;
    Folder archive;

    // Create some messages
    Message msg1("Hello, World!");
    Message msg2("Welcome to the C++ course.");
    Message msg3("This is a test message.");

    // Save messages to folders
    msg1.Save(inbox);
    msg2.Save(inbox);
    msg3.Save(archive);

    // Display initial states
    std::cout << "Initial State:" << std::endl;
    std::cout << "Inbox contains messages: ";
    inbox.Save(msg1);
    inbox.Save(msg2);
    inbox.remove(msg3);
    std::cout << "Archive contains messages: ";
    archive.Save(msg3);
    archive.remove(msg1);
    
    // Swap messages
    swap(msg1, msg3);
    std::cout << "\nAfter Swapping msg1 and msg3:" << std::endl;
    std::cout << "Inbox contains messages: ";
    inbox.Save(msg1);
    inbox.Save(msg2);
    inbox.remove(msg3);
    std::cout << "Archive contains messages: ";
    archive.Save(msg3);
    archive.remove(msg1);

    // Assign messages
    msg2 = msg3;
    std::cout << "\nAfter Assigning msg3 to msg2:" << std::endl;
    std::cout << "Inbox contains messages: ";
    inbox.Save(msg1);
    inbox.Save(msg2);
    inbox.remove(msg3);
    std::cout << "Archive contains messages: ";
    archive.Save(msg3);
    archive.remove(msg1);
}

void TestStrVec() {
    StrVec vec1;
    vec1.push_back("hi"); // 调用push_back(std::string&&)
    std::string s("look");
    vec1.push_back(s); // 调用push_back(const std::string&)
    StrVec vec2(vec1);
    vec2.push_back("abc");
    std::cout << vec1.size() << std::endl;
    std::cout << vec1.capacity() << std::endl;
    std::cout << vec2.size() << std::endl;
    std::cout << vec2.capacity() << std::endl;
    for (std::size_t i = 0; i != vec1.size(); ++i) {
        std::cout << vec1[i] << "_";
    }
    std::cout << std::endl;
    for (auto b = vec2.begin(); b!= vec2.end(); ++b) {
        std::cout << *b << "_";
    }
    std::cout << std::endl;
    StrVec vec3 = vec2;
    for (auto b = vec3.begin(); b!= vec3.end(); ++b) {
        std::cout << *b << "_";
    }
    vec1 = std::move(vec2);
    for (auto b = vec1.begin(); b!= vec1.end(); ++b) {
        std::cout << *b << "_";
    }
    std::string s1("a"), s2("b");
    s1 + s2 = "abc";

    std::cout << std::endl;
    StrVec v5;
    v5 = {"a", "b", "c", "d"};
    for (auto b = v5.begin(); b!= v5.end(); ++b) {
        std::cout << *b << "_";
    }
} 

void TestRef() {
    // && 右值引用绑定右值
    // & 左值引用绑定左值
    int &&ref1 = 4;
    int val = 1;
    // 使用move将val视为右值
    int &&ref2 = std::move(val);
    std::cout << ref1 << std::endl;
    std::cout << ref2 << std::endl;
}

int main() {
    // TestLikeValue();
    // TestLikePtr();
    // TestMsg();
    TestStrVec();
    // TestRef();
    return 0;
}  