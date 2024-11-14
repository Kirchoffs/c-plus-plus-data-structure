#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>

namespace syh {
    template <typename T>
    class Vector {
    public:
        Vector();
        ~Vector();

        T& at(int index);
        const T& at(int index) const;

        T& front();
        const T& front() const;

        T& back();
        const T& back() const;

        T* data();
        const T* data() const;

        T& operator[](int index);
        const T& operator[](int index) const;

        void push_back(const T& value);
        void pop_back();

        void assign(int count, const T& value);

        void swap(Vector<T>& other);

        bool empty() const;
        size_t size() const;
        size_t capacity() const;

    private:
        T* data_;
        size_t size_;
        size_t capacity_;
    };
};

#include "src/vector.inl"

#endif