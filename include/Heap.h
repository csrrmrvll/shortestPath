#ifndef HEAP_H
#define HEAP_H

#include <algorithm>
#include <utility>
#include <vector>

template<typename T,typename Compare = std::less<T>,typename Container = std::vector<T>>
class Heap;

template<typename T>
using MaxHeap = Heap<T>;

template<typename T>
using MinHeap = Heap<T,std::greater<T>>;

template<typename T,typename Compare,typename Container>
class Heap
{
public:
    explicit Heap()
    :   cont_{},
        comp_{}
    {
    }

    explicit Heap(const Compare & comp)
    :   cont_{},
        comp_{comp}
    {
    }

    explicit Heap(Compare && comp)
    :   cont_{},
        comp_{std::move(comp)}
    {
    }

    explicit Heap(const Container & cont, const Compare & comp)
    :   cont_{cont},
        comp_{comp}
    {
    }

    explicit Heap(const Container & cont, Compare && comp)
    :   cont_{cont},
        comp_{std::move(comp)}
    {
    }

    explicit Heap(Container && cont, const Compare & comp)
    :   cont_{std::move(cont)},
        comp_{comp}
    {
    }

    explicit Heap(Container && cont, Compare && comp)
    :   cont_{std::move(cont)},
        comp_{std::move(comp)}
    {
    }

    Heap(const Heap & other) = default;
    Heap(Heap && other) = default;
    Heap & operator=(const Heap & other) = default;
    Heap & operator=(Heap && other) = default;
    ~Heap() = default;

    template<class Alloc>
    explicit Heap(const Alloc & alloc)
    :   cont_{alloc},
        comp_{}
    {
    }

    template<class Alloc>
    explicit Heap(const Alloc & alloc, const Compare & comp)
    :   cont_{alloc},
        comp_{comp}
    {
    }

    template<class Alloc>
    explicit Heap(const Alloc & alloc, Compare && comp)
    :   cont_{alloc},
        comp_{std::move(comp)}
    {
    }

    template<class Alloc>
    Heap(const Container & cont, const Alloc & alloc)
    :   cont_{cont, alloc},
        comp_{}
    {
    }

    template<class Alloc>
    Heap(const Container & cont, const Alloc & alloc, const Compare & comp)
    :   cont_{cont, alloc},
        comp_{comp}
    {
    }

    template<class Alloc>
    Heap(const Container && cont, const Alloc & alloc, Compare && comp)
    :   cont_{cont, alloc},
        comp_{std::move(comp)}
    {
    }

    template<class Alloc>
    Heap(Container && cont, const Alloc & alloc, const Compare & comp)
    :   cont_{std::move(cont), alloc},
        comp_{comp}
    {
    }

    template<class Alloc>
    Heap(Container && cont, const Alloc & alloc, Compare && comp)
    :   cont_{std::move(cont), alloc},
        comp_{std::move(comp)}
    {
    }

    template<class Alloc>
    Heap(const Heap & other, const Alloc & alloc)
    :   cont_{other.cont_, alloc},
        comp_{other.comp_}
    {
    }

    template<class Alloc>
    Heap(Heap && other, const Alloc & alloc)
    :   cont_{std::move(other.cont_), alloc},
        comp_{std::move(other.comp_)}
    {
    }

    using container_type = Container;
    using iterator = typename Container::iterator;
    using reference = typename Container::reference;
    using const_reference = typename Container::const_reference;
    using size_type = typename Container::size_type;
    using value_type = typename Container::value_type;

    reference top() { return this->cont_.front(); }
    const_reference top() const { return this->cont_.front(); }

    bool empty() const { return this->cont_.empty(); }

    size_type size() const { return this->cont_.size(); }

    void push(const value_type & v)
    {
        this->cont_.push_back(v);
        push_heap(begin(this->cont_),end(this->cont_),this->comp_);
    }

    void push(value_type && v)
    {
        this->cont_.push_back(std::move(v));
        push_heap(begin(this->cont_),end(this->cont_),this->comp_);
    }

    template<typename... Args>
    reference emplace(Args && ...args)
    {
        auto v = this->cont_.emplace_back(std::forward<Args>(args)...);
        push_heap(begin(this->cont_),end(this->cont_),this->comp_);
        return v;
    }

    value_type pop()
    {
        auto v = this->top();
        pop_heap(begin(this->cont_),end(this->cont_),this->comp_);
        this->cont_.pop_back();
        return v;
    }

    iterator erase(const value_type & v)
    {
        auto    first = lower_bound(begin(this->cont_),end(this->cont_),v,this->comp_),
                last = upper_bound(begin(this->cont_),end(this->cont_),v,this->comp_);
        return this->cont_.erase(first,last);
    }

private:
    Container cont_;
    Compare comp_;
};

#endif // HEAP_H
