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
    StrBlob b1 = {"a", "an", "the"};
    auto beg = b1.begin();
    while (beg != b1.end()) {
        std::cout << *beg++ << std::endl;
    }
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
    // std::shared_ptr<std::vector<int>> ivec_pointer = std::make_shared<std::vector<int>>(*(ReturnVec()));
    std::shared_ptr<std::vector<int>> ivec_pointer(ReturnVec()); //  使用new返回的指针初始化一个指针，与上面等价
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
    // WriteAndReadVec1();
    WriteAndReadVec2();
}

void Process(std::shared_ptr<int> p) {
    // 进入函数后，形参指向pointer所指位置，所以智能指针有两个
    // use_count 返回与p共享对象的智能指针的数量
    std::cout << p.use_count() << std::endl;
    // 函数执行完成，形参p被释放，智能指针变成一个
}

std::shared_ptr<int> ReturnIntP(int p) {
    // 传入类型和值，创建对应的shared_ptr类型
    // return std::make_shared<int>(p);
    // 根据new的指针创建shared_ptr
    return std::shared_ptr<int>(new int(p));
}

void TestMixed() {
    // 不要混用普通指针和智能指针
    std::shared_ptr<int> pointer(new int(10));
    Process(pointer);
    if (pointer.unique()) { // 当前引用值为1返回true，一般在写入之前进行判断
        std::cout << "yes" << std::endl;
    }
    std::cout << pointer.use_count() << std::endl;
    int n = *pointer;
    std::cout << n << std::endl;
    pointer.reset(); // 切断智能指针和对象地址的联系，当use_count为0，对象地址自动回收
    if (pointer.unique()) {
        std::cout << "no" << std::endl;
    }
    std::cout << pointer.use_count() << std::endl;
    pointer = ReturnIntP(5);
    std::cout << *pointer << std::endl;

    // 如果直接使用普通指针
    int* p(new int(12));
    Process(std::shared_ptr<int>(p)); // 传入符合函数类型的参数
    // 上面创建的智能指针在为形参赋值完成就销毁了，智能指针只有一个
    // 因此Process函数运行完成后,智能指针自动释放p所指的内存
    // 此时的实参p就是空悬指针
    int m = *p;
    std::cout << m << std::endl;
}

void TestGet() {
    auto sp = std::make_shared<int>();
    auto p = sp.get(); // get会返回一个普通指针，非必须，不要用
    std::cout << *sp << std::endl;
    delete p;
    std::cout << *sp << std::endl;
}

int main() {
    // TestSharedPtr();
    TestBlob();
    // TestMemory();
    // TestProblem();
    // TestMixed();
    // TestGet();

    return 0;
}