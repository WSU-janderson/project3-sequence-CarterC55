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
    for (SequenceNode* cur = s.head; cur; cur = cur->next)
    {
        push_back(cur->item);
    }
}

Sequence& Sequence::operator=(const Sequence& s)
{
    if (this == &s) return *this;
    clear();
    for (SequenceNode* cur = s.head; cur; cur = cur->next)
    {
        push_back(cur->item);
    }
    return *this;
}

Sequence::~Sequence()
{
    clear();
}

std::string& Sequence::operator[](std::size_t position)
{
    if (position >= count) throw std::out_of_range("operator[] index out of range");
    //if target is in first half start from head otherwise start from tail
    if (position <= count / 2)
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
    if (empty()) throw std::runtime_error("pop_back() empty sequence");
    //if seq is only 1 item, clear it and set count to 0 otherwise pop last item
    if (count == 1)
    {
        delete tail;
        head = tail = nullptr;
        count = 0;
        return;
    }

    SequenceNode* old = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete old;
    count--;
}

void Sequence::insert(std::size_t position, std::string item)
{
    if (position > count) throw std::out_of_range("insert() position out of range");

    if (position == count)
    {
        push_back(item);
        return;
    }
    //find current position, then insert before it
    SequenceNode* here;
    if (position <= count / 2)
    {
        here = head;
        for (std::size_t i = 0; i < position; i++) here = here->next;
    } else
    {
        here = tail;
        for (std::size_t i = count -1; i > position; i--) here = here->prev;
    }

    SequenceNode* before = here ->prev;
    SequenceNode* n = new SequenceNode(item);

    n->next = here;
    n->prev = before;

    if (before) before->next = n; //new head if ins at position 0
    else head = n;
    here->prev = n;

    count++;
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
    SequenceNode* cur = head;
    while (cur)
    {
        SequenceNode* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    head = tail = nullptr;
    count = 0;
}

void Sequence::erase(std::size_t position)
{
    erase(position, 1);
}

void Sequence::erase(std::size_t position, std::size_t cnt)
{
    if (cnt == 0) return;
    if (position >= count) throw std::out_of_range("erase() position out of range");
    if (position + cnt > count) throw std::out_of_range("erase() range exceeds size");

    SequenceNode* first;
    if (position <= count / 2)
    {
        first = head;
        for (std::size_t i = 0; i < position; i++) first = first->next;
    } else
    {
        first = tail;
        for (std::size_t i = count -1; i > position; i--) first = first->prev;
    }

    SequenceNode* last = first;
    for (std::size_t i = 1; i < cnt; i++) last = last->next;

    SequenceNode* before = first->prev;
    SequenceNode* after = last->next;

    if (before) before->next = after; else head = after;
    if (after) after->prev = before; else tail = before;

    SequenceNode* cur = first;
    for (std::size_t i = 0; i < cnt; i++)
    {
        SequenceNode* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    count -= cnt;
}

std::ostream& operator<<(std::ostream& os, const Sequence& s)
{
    os << "<";
    SequenceNode* cur = s.head;
    for (std::size_t i = 0; i < s.count; i++)
    {
        os << cur->item;
        if (i + 1 < s.count) os << ", ";
        cur = cur->next;
    }
    os << ">";
    return os;
}



