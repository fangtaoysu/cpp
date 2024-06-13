#include "head_folders/window_mgr.h"
#include "head_folders/screen.h"


void WindowMGR::Clear(ScreenIndex i) {
    Screen &s = screens_[i];
    s.contents_ = string(s.height_ * s.width_, ' ');
}

WindowMGR::ScreenIndex WindowMGR::AddScreen(const Screen &s) {
    screens_.push_back(s);
    return screens_.size() - 1;
}

WindowMGR::WindowMGR::WindowMGR(/* args */) : screens_{Screen(24, 80, ' ')} {
}

WindowMGR::~WindowMGR() {
}
