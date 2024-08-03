#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "str_blob.h"


void WriteAndReadVec1();
void WriteAndReadVec2();
std::vector<int>* ReturnVec();
void PrintVec(const std::vector<int>& ivec);

void TestSharedPtr() {
    // 用于管理多个同类型的指针，如：std::string *p
    std::shared_ptr<std::string> p1 = std::make_shared<std::string>();
    // 如果指向空字符串，则p1为真，p1->empty()为真
    // 如果指向非空字符串，p1为真，p1-empty()为假
    if (p1 && p1->empty()) {
        *p1 = "hi";
    }
    std::cout << *p1 << std::endl;
}

void TestBlob() {
    StrBlob b1;
    StrBlob b2 = {"a", "an", "the"};
    {
        b1 = b2;
        b2.PushBack("about");
    }
    b1.Print();
    b2.Print();
}

void TestMemory() {
    // new
    int* p0 = nullptr; // 不指向任何对象 相当于0 NULL
    int *p1 =  new int; // p1指向一个动态分配的无名对象,*p1未定义
    std::cout << *p1 << std::endl;
    int *p = new int(); // 值初始化为0
    std::string *p2 = new std::string;
    int *p3 = new int(1024);
    std::string *p4 = new std::string(10, '9');
    std::vector<int> *p5 = new std::vector<int>{0, 1, 2, 3, 4, 5};
    // 如果只有一个类型，可以使用auto+括号推断类型
    // 由于出现关键字new，因此可以推断出p6是指针类型
    StrBlob obj;
    auto p6 = new auto(obj);
    if (p6->Empty()) {
        std::cout << "obj is null" << std::endl;
    }

    // 如果内存耗尽，就会分配失败，出现bad_alloc异常，可以这样写
    int *p7 = new (std::nothrow) int; // 如果分配失败，则new返回一个空指针

    // delete 的是指针所指的对象的地址，不是指针的地方
    // delete之后指针这个变量名仍然可用，指针所指地址仍然可以访问（空悬指针）
    delete p1, p2, p3, p4, p5, p6, p7;
    // 如果此时使用空悬指针，将造成错误，如果需要继续使用此指针名，需要将指针置空
    p1 = nullptr;

    // 如果不使用智能指针，对于多个指针指向相同内存的问题
    int* p8(new int(12));
    auto q = p8;
    delete p8; // 如果delete所指空间，其他指针的指向将会失效
    q = nullptr; // 此时需要将其他指针置空，来说明不指向任何对象

}

std::vector<int>* ReturnVec() {
    return new std::vector<int>{};
}

void WriteAndReadVec1() {
    std::vector<int>* ivec_pointer = ReturnVec();
    std::string word;
    while (std::cin >> word) {
        int val = std::stoi(word);
        ivec_pointer->push_back(val);
    }
    PrintVec(*ivec_pointer);
    delete ivec_pointer;
}

void WriteAndReadVec2() {
    // shared_ptr<T>p(q) p是shared_ptr的拷贝
    std::shared_ptr<std::vector<int>> ivec_pointer(ReturnVec());
    std::string word;
    while (std::cin >> word) {
        int val = std::stoi(word);
        ivec_pointer->push_back(val);
    }
    PrintVec(*ivec_pointer);
    ivec_pointer->pop_back();
}

void PrintVec(const std::vector<int>& ivec) {
    for (const auto val : ivec) {
        std::cout << val << "\t";
    }
    std::cout << std::endl;
}

void TestProblem() {
    WriteAndReadVec1();
    // WriteAndReadVec2();
}

int main() {
    // TestSharedPtr();
    // TestBlob();
    // TestMemory();
    TestProblem();
    return 0;
}