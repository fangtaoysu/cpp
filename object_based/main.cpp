/**
 * triangular complish a class
 * TriangularIterator complish class iterator 
*/
#include "stack.h"
#include "../tool/tool.h"
#include "triangular.h"
#include "triangular_iterator.h"
// #include "num_sequence.h"


using namespace std;

int Sum(const Triangular &train) {
    int beg_pos = train.BegPos();
    int length = train.Length();
    int sum = 0;
    for (int ix = 0; ix < length; ++ix) {
        sum += train.Elem(beg_pos+ix);
    }
    return sum;
}

void TestStack() {
    /**
     * 栈的测试程序
    */
    Stack st;
    string str;

    while(cin >> str && !st.Full()) {
        st.Push(str);
    }

    if (st.Empty()) {
        cout << "Oops, no strings were read" << endl;
        return;
    }
    st.Peek(str);
    cout << str << " is stack top elemnt, and stack has " << st.size() << " elements.\n";
    cout << "reverse output stack\n";

    while (st.size()) {
        if (st.Pop(str)) {
            cout << str << " ";
        }
    }
}

void TestTriangularConstructor() {
    /**
     * Triangular序列的构造函数测试程序
    */
    Triangular tri1(4);
    cout << "tri1" << endl;
    Triangular::Display(tri1.Length(), tri1.BegPos());
    cout << "sum of elements: " << Sum(tri1) << endl;

    Triangular tri2(4, 3);
    cout << "tri2" << endl;
    Triangular::Display(tri2.Length(), tri2.BegPos());
    cout << "sum of elements: " << Sum(tri2) << endl;

    Triangular tri3(4, 8);
    cout << "tri3" << endl;
    Triangular::Display(tri3.Length(), tri3.BegPos());
    cout << "sum of elements: " << Sum(tri3) << endl;
}

void FindTriangular() {
    char ch;
    bool more = true;

    while(more) {
        cout << "Enter value: ";
        int ival;
        cin >> ival;

        bool is_elem = Triangular::IsElem(ival);
        cout << ival
             << (is_elem ? " is " : " is not ")
             << "an element in the Trianular series.\n"
             << "Another value?(y/n)";

        cin >> ch;
        if (ch == 'n' || ch == 'N') {
            more = false;
        }
    }
}

void TestIterator() {
    // issue function
    Triangular train(8, 1);
    Triangular::iterator it = train.begin();
    while (it != train.end()) {
        cout << *(it++) << ' ';
    }
    cout << "\n";
}

void TestOperator() {
    /**
     * 测试重载 << 和 >>
    */
    Triangular tri1(3, 6);
    cout << tri1 << "\n";
    
    Triangular tri2;
    cin >> tri2;
    cout << tri2;
}

void TestPointers() {
    // NumSequence ns;
    // const int pos = 8;
    // for (int ix = 0; ix < NumSequence::NumOfSequence(); ++ix) {
    //     ns.SetSquence(NumSequence::(ix));
    //     int elem_val = ns.Elem(pos);
    //     Display(ns, pos, elem_val);
    // }
}

int main() {
    // TestStack();
    
    // TestTriangularConstructor();

    // FindTriangular();

    // TestIterator();

    // TestOperator();

    TestPointers();
    return 0;
}