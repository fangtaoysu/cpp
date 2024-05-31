#ifndef SCREEN_H
#define SCREEN_H
#include <string>

using std::string;

class Screen {
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

private:
    pos_ cursor_ = 0;
    pos_ height_ = 0, width_ = 0;
    string contents_;
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

#endif