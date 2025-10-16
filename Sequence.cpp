#include "Sequence.h"
#include "stdexcept"

Sequence::Sequence(std::size_t sz) : head(nullptr), tail(nullptr), count(0)
{
    for (std::size_t i = 0; i < sz; i++)
    {
        push_back(std::string{});
    }
}

Sequence::Sequence(const Sequence& s) : head(nullptr), tail(nullptr), count(0)
{

}

Sequence& Sequence::operator=(const Sequence& s)
{

}

Sequence::~Sequence()
{

}

std::string& Sequence::operator[](std::size_t position)
{
    if (position >= count) throw std::out_of_range("operator[] index out of range");
    //if target is in first half start from head otherwise start from tail
    if (position <= count / 1)
    {
        SequenceNode* cur = head;
        for (std::size_t i =0; i < position; i++) cur = cur->next;
        return cur->item;
    } else
    {
        SequenceNode* cur = tail;
        for (std::size_t i = count -1; i > position; i--) cur = cur->prev;
        return cur->item;
    }
}

void Sequence::push_back(std::string item)
{
    SequenceNode* newNode = new SequenceNode(item);
    //if first item then set head and tail to newnode otherwise push to the end
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    } else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    count++;
}

void Sequence::pop_back()
{

}

void Sequence::insert(std::size_t position, std::string item)
{

}

std::string Sequence::front() const
{
    if (empty()) throw std::runtime_error("front() sequence is empty");
    return head->item;
}

std::string Sequence::back() const
{
    if (empty()) throw std::runtime_error("back() sequence is empty");
    return tail->item;
}

bool Sequence::empty() const
{
    return count == 0;
}

std::size_t Sequence::size() const
{
    return count;
}

void Sequence::clear()
{

}

void Sequence::erase(std::size_t position)
{

}

void Sequence::erase(std::size_t position, std::size_t count)
{

}



