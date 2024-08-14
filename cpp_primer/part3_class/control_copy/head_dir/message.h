#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <set>
#include "folder.h"

class Folder; // Forward declaration

class Message {
    friend class Folder;
    friend void swap(Message& lhs, Message& rhs);
private:
    std::string contents_;
    std::set<Folder*> folders_;
    void AddToFolders(const Message&);
    void RemoveFromFolders();
public:
    explicit Message(const std::string &str = "") : contents_(str) {}
    Message(const Message&);
    Message& operator=(const Message&);
    void Save(Folder&);
    void remove(Folder&);
    ~Message();
};

// Swap function for Message
void swap(Message& lhs, Message& rhs);

#endif // MESSAGE_H
