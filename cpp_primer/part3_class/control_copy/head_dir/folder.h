#ifndef FOLDER_H
#define FOLDER_H
#include <set>

class Message;

class Folder {
    friend class Message;
    friend void swap(Folder &lhs, Folder &rhs); // Make swap function of Folder a friend
    friend void swap(Message& lhs, Message& rhs); // Make swap function of Message a friend
private:
    std::set<Message*> set_msg_;
    void AddMsg(Message* msg) {  // Add a message to the folder
        set_msg_.insert(msg);
    }

    void RemoveMsg(Message* msg) {  // Remove a message from the folder
        set_msg_.erase(msg);
    }
public:
    Folder() = default;
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    void Save(Message&);
    void remove(Message&);
    ~Folder();
};

#endif // FOLDER_H
