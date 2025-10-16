#pragma once
#include <string>
#include <ostream>
#include <cstddef>

//test comment
class SequenceNode
{
    public:
    SequenceNode* next;
    SequenceNode* prev;
    std::string item;

    SequenceNode() : next(nullptr), prev(nullptr)
    {}

    SequenceNode(std::string item) : next(nullptr), prev(nullptr), item(item)
    {}

};

class Sequence
{
    public:
    //constructor
    Sequence(std::size_t sz = 0);

    //deep copy of sequence s
    Sequence(const Sequence& s);

    //destroy all items in seq and release memory
    ~Sequence();

    //current sequence released and replaced by deep copy of seq s
    Sequence& operator=(const Sequence& s);

    //if position >= 0 && position <= last_index the return val is a ref to the item at index position in the seq
    std::string& operator[](std::size_t position);

    //append to end of seq
    void push_back(std::string item);
    //remove last item in seq
    void pop_back();

    //insert at index
    void insert(std::size_t position, std::string item);

    //return first element in seq
    std::string front() const;

    //return last element in seq
    std::string back() const;

    //return true when seq is empty, otherwise false
    bool empty() const;

    //return num of elements in seq
    std::size_t size() const;

    //remove all elements in seq
    void clear();

    //remove element at position
    void erase(std::size_t position);

    //erase count elemnts at position
    void erase(std::size_t position, std::size_t count);

    //friend function to output all elements as a string to the output stream
    friend std::ostream& operator<<(std::ostream& os, const Sequence& s);

    private:
    SequenceNode* head = nullptr;
    SequenceNode* tail = nullptr;
    std::size_t count = 0;
};