#include "Sequence.h"
#include <string>
#include <ostream>
#include <cstddef>

Sequence::Sequence(std::size_t sz) : head(nullptr), tail(nullptr), count(0)
{

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

}

void Sequence::push_back(std::string item)
{

}

void Sequence::pop_back()
{

}

void Sequence::insert(std::size_t position, std::string item)
{

}

std::string Sequence::front() const
{

}

std::string Sequence::back() const
{

}

bool Sequence::empty() const
{

}

std::size_t Sequence::size() const
{

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



