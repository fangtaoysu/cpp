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
