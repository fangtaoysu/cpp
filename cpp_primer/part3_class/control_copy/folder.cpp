#include "./head_dir/message.h"
#include "./head_dir/folder.h"

Folder::Folder(const Folder& f) : set_msg_(f.set_msg_) {
    for (auto msg : set_msg_)
        msg->Save(*this);
}

Folder& Folder::operator=(const Folder& f) {
    if (this != &f) {
        for (auto msg : set_msg_)
            msg->remove(*this);
        set_msg_ = f.set_msg_;
        for (auto msg : set_msg_)
            msg->Save(*this);
    }
    return *this;
}

void Folder::Save(Message& msg) {
    set_msg_.insert(&msg);
    msg.Save(*this);
}

void Folder::remove(Message& msg) {
    set_msg_.erase(&msg);
    msg.remove(*this);
}

Folder::~Folder() {
    for (auto msg : set_msg_)
        msg->remove(*this);
}

// Implementation of swap function for Folder
void swap(Folder& lhs, Folder& rhs) {
    using std::swap;
    for (auto msg : lhs.set_msg_) {
        msg->remove(lhs);
    }
    for (auto msg : rhs.set_msg_) {
        msg->remove(rhs);
    }
    swap(lhs.set_msg_, rhs.set_msg_);
    for (auto msg : lhs.set_msg_) {
        msg->Save(lhs);
    }
    for (auto msg : rhs.set_msg_) {
        msg->Save(rhs);
    }
}
