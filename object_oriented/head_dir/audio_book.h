#ifndef AUDIO_BOOK_H
#define AUDIO_BOOK_H

#include <string>
#include "book.h"

class AudioBook : public Book{
public:
    AudioBook(const std::string &title, const std::string &author, const std::string &player)
        : Book(title, author),  player_(player) {
        std::cout << "AudioBook::AudioBook( " << title
                  << ", " << author
                  << ", " << player << ")\n";
    }
    virtual ~AudioBook() {
        std::cout << "AudioBook::AudioBook() destructor\n";
    }
    // 虚拟调用实现多态
    virtual void Print() const {
        std::cout << "AudioBook::Print() -- I am a AudioBook object\n"
             << "title is " << title_
             << "\nauthor is " << author_ 
             << "\nplayer is " << player_ << std::endl;
    }
    const std::string& Player() const {
        return player_;
    }

private:
    std::string player_;
};

#endif