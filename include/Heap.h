#ifndef HEAP_H
#define HEAP_H

#include <algorithm>
#include <vector>

template<typename T,typename Compare = std::less<T>>
class Heap;

template<typename T>
using MaxHeap = Heap<T>;

template<typename T>
using MinHeap = Heap<T,std::greater<T>>;

template<typename T,typename Compare>
class Heap
{
    using Container = std::vector<T>;
public:
    Heap(Compare comp = Compare())
    :   c{},
        comp{comp}
    {
        make_heap(begin(this->c),end(this->c),this->comp);
    }

    bool empty() const { return this->c.empty(); }

    using value_type = typename Container::value_type;
    using iterator = typename Container::iterator;
    iterator erase(const value_type & v)
    {
        auto    first = lower_bound(begin(this->c),end(this->c),v,this->comp),
                last = upper_bound(begin(this->c),end(this->c),v,this->comp);
        return this->c.erase(first,last);
    }

    value_type pop()
    {
        auto v = this->top();
        pop_heap(begin(this->c),end(this->c),this->comp);
        this->c.pop_back();
        return v;
    }

    void push(const value_type & v)
    {
        this->c.push_back(v);
        push_heap(begin(this->c),end(this->c),this->comp);
    }

    using size_type = typename Container::size_type;
    size_type size() const { return this->c.size(); }

    const value_type & top() const { return this->c.front(); }

private:
    Container c;
    Compare comp;
};

#endif // HEAP_H
