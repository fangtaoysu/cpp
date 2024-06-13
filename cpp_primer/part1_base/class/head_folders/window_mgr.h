#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <vector>
#include "screen.h"
class Screen;

class WindowMGR {
private:
    /* data */
    // vector 初始化
    std::vector<Screen> screens_;
public:
    using ScreenIndex = std::vector<Screen>::size_type; // 窗口每个屏幕的编号
    void Clear(ScreenIndex);
    ScreenIndex AddScreen(const Screen &); // 向窗口添加一个屏幕
    WindowMGR(/* args */);
    ~WindowMGR();
};


#endif