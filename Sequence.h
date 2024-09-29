//Author Name: Marco Coscoy
//UID: 705960849

#ifndef SEQUENCE
#define SEQUENCE
#include <iostream>
#include <string>

using ItemType = std::string;

class Sequence
{
public:
    Sequence();
    bool empty() const;
    int size() const;
    int insert(int pos, const ItemType& value);
    int insert(const ItemType& value);
    bool erase(int pos);
    int remove(const ItemType& value);
    bool get(int pos, ItemType& value) const;
    bool set(int pos, const ItemType& value);
    int find(const ItemType& value) const;
    void swap(Sequence& other);
    void dump() const;
    ~Sequence();
    Sequence(const Sequence& old);
    Sequence operator=(const Sequence& old);

private:
    struct Node {
        Node* forward;
        Node* back;
        ItemType value;
        int pos;
    };
    Node head;
    Node tail;
    int m_size;
};

int subsequence(const Sequence& seq1, const Sequence& seq2);
void concatReverse(const Sequence& seq1, const Sequence& seq2, Sequence& result);

#endif