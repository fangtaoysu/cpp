#ifndef PRINT_IT_H
#define PRINT_IT_H
#include <ostream>


template <typename OutStream>
class PrintIt {
public:
    PrintIt(OutStream &os)
        : os_ (os) {
    };
    // 成员模版函数
    template <typename elemType>
    void Print(const elemType &elem, char delimiter = '\n') {
        os_ << elem << delimiter;
    }
private:
    OutStream& os_;
};


#endif