#include <ios>
#include <iostream>
#include <string>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::string;

// In a Linux terminal, pressing Ctrl+D sends an EOF (End Of File) signal. This
// signal indicates that no more input is available from a data stream. When
// used with terminal-based input (like reading from stdin in a program), it
// effectively tells the program that it has reached the end of the input. This
// can be used to signal the end of input when a program is reading from the
// terminal interactively, as it would with the cin object in a C++ program.
//
// Ctrl+D is not a signal, it's EOF (End-Of-File). It closes the stdin pipe. If
// read(STDIN) returns 0, it means stdin closed, which means Ctrl+D was hit
// (assuming there is a keyboard at the other end of the pipe).
//
// lsof -p 16161
// COMMAND     PID             USER     FD     TYPE DEVICE     SIZE/OFF
// a.out     16161 zhangzhong        0r     CHR     16,5                0t0            859 /dev/ttys005
// a.out     16161 zhangzhong        1w     CHR     16,5            0t219            859 /dev/ttys005
// a.out     16161 zhangzhong        2w     CHR     16,5                0t0            859 /dev/ttys005
// lsof可以看到进程打开的fd 可以看到 0 1 2 分别表示 stdin stdout stderr
//
// ctrl+d标识了stdin已经关闭，所以所有后续的读取都会失败，重置状态只是重置了一个iostream中表示状态的变量而已
// 他不能重新打开已经关闭的stdin，所以再次尝试读取又会将流重置为EOF状态
istream &ReadStream(istream &is) {
    cout << "Stream state before reset: " << is.rdstate() << endl;

    string info;
    while (is >> info) {
        cout << info << endl;
    }
    cout << "Stream end state: " << is.rdstate() << endl;
    is.clear(is.rdstate() & ~is.failbit & ~is.eofbit);
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    cout << "Stream state after reset: " << is.rdstate() << endl;
    return is;
}

int main() {

    // 6 = eofbit + badbit
    cout << "goodbit: " << std::ios::goodbit << endl;
    cout << "failbit: " << std::ios::failbit << endl;
    cout << "eofbit: " << std::ios::eofbit << endl;
    cout << "badbit: " << std::ios::badbit << endl;

    cout << "First read from cin:" << endl;
    ReadStream(cin);

    cout << "Second read from cin after reset:" << endl;
    ReadStream(cin);

    return 0;
}