#include "./head_dir/folder.h"
#include "./head_dir/message.h"

Message::Message(const Message& msg) : contents_(msg.contents_), folders_(msg.folders_) {
    AddToFolders(msg);
}

Message& Message::operator=(const Message& rhs) {
    if (this != &rhs) {
        RemoveFromFolders();
        contents_ = rhs.contents_;
        folders_ = rhs.folders_;
        AddToFolders(rhs);
    }
    return *this;
}

void Message::Save(Folder& f) {
    folders_.insert(&f);
    f.AddMsg(this);
}

void Message::remove(Folder& f) {
    folders_.erase(&f);
    f.RemoveMsg(this);
}

void Message::AddToFolders(const Message& msg) {
    for (auto f : msg.folders_)
        f->AddMsg(this);
}

void Message::RemoveFromFolders() {
    for (auto f : folders_)
        f->RemoveMsg(this);
}

Message::~Message() {
    RemoveFromFolders();
}

void swap(Message& lhs, Message& rhs) {
    using std::swap;
    for (auto f : lhs.folders_) {
        f->RemoveMsg(&lhs);
    }
    for (auto f : rhs.folders_) {
        f->RemoveMsg(&rhs);
    }
    swap(lhs.contents_, rhs.contents_);
    swap(lhs.folders_, rhs.folders_);
    for (auto f : lhs.folders_) {
        f->AddMsg(&lhs);
    }
    for (auto f : rhs.folders_) {
        f->AddMsg(&rhs);
    }
}


void Message::MoveFolders(Message* m) {
    folders_ = std::move(m->folders_);
    for (auto f : folders_) {
        f->RemoveMsg(m); // 移除参数中的msg
        f->AddMsg(this); // 将当前对象添加到参数对象的folder中
    }
    m->folders_.clear();
}

Message::Message(Message &&m) : contents_(std::move(m.contents_)) {
    MoveFolders(&m);
}

Message& Message::operator=(Message &&rhs) {
    if (this != &rhs) {
        RemoveFromFolders(); // 释放当前对象指针所指地址
        contents_ = std::move(rhs.contents_);
        MoveFolders(&rhs); // 给当前对象指针赋值新地址
    }
    return *this;
}