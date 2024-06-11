#include <vector>
#include "head_folders/screen.h"

class window_mgr {
private:
    /* data */
    // vector 初始化
    std::vector<Screen> screens{
        Screen(23, 80, ' ')
    };
public:
    window_mgr(/* args */);
    ~window_mgr();
};

window_mgr::window_mgr(/* args */) {
}

window_mgr::~window_mgr() {
}
