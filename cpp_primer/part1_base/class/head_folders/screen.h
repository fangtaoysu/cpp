#ifndef SCREEN_H
#define SCREEN_H
#include <string>
#include "window_mgr.h"

using std::string;

class Screen {
friend class WindowMGR;
// friend void WindowMGR::Clear(ScreenIndex);
public:
    typedef string::size_type pos_;
    Screen() = default;
    Screen(pos_ ht, pos_ wd, char c)
        : height_(ht), width_(wd), contents_(ht * wd, c) { }
    char Get() const {
        return contents_[cursor_];
    }
    // 在类中声明内联
    inline char Get(pos_ ht, pos_ wd) const;
    Screen &Move(pos_ r, pos_ c);
    void SomeMember() const;
    Screen &Set(char); // 设置字符位置
    Screen &Set(pos_, pos_, char);
    Screen &Display(std::ostream &os) {
        DoDisplay(os);
        return *this;
    }
    const Screen &Display(std::ostream &os) const {
        DoDisplay(os);
        return *this;
    }

private:
    pos_ cursor_ = 0;
    pos_ height_ = 0, width_ = 0;
    string contents_;
    mutable size_t access_ctr_; // mutable保证该对象在const对象内也能被修改
    void DoDisplay(std::ostream &os) const {
        os << contents_;
    }
};

// 在类外声明内联
inline Screen &Screen::Move(pos_ r, pos_ c) {
    pos_ row = r * width_;
    cursor_ = row + c;
    return *this;
}

char Screen::Get(pos_ r, pos_ c) const {
    pos_ row = r * width_;
    return contents_[row + c];
}

inline Screen &Screen::Set(char c) {
    contents_[cursor_] = c; // 设置当前光标所在位置的新值
    return *this;
}

inline Screen &Screen::Set(pos_ r, pos_ col, char ch) {
    contents_[r*width_ + col] = ch; // 设置指定位置的新值
    return *this;
}

#endif