namespace syh { 
    template <typename T>
    Vector<T>::Vector() : data_(nullptr), size_(0), capacity_(0) {}

    template <typename T>
    Vector<T>::~Vector() {
        if (data_ != nullptr) {
            delete[] data_;
        }

        size_ = 0;
        capacity_ = 0;
    }

    template <typename T>
    T& Vector<T>::at(int index) {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of bounds");
        }
        return data_[index];
    }

    template <typename T>
    const T& Vector<T>::at(int index) const {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of bounds");
        }
        return data_[index];
    }

    template <typename T>
    T& Vector<T>::front() {
        if (size_ == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return data_[0];
    }

    template <typename T>
    const T& Vector<T>::front() const {
        if (size_ == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return data_[0];
    }

    template <typename T>
    T& Vector<T>::back() {
        if (size_ == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return data_[size_ - 1];
    }

    template <typename T>
    const T& Vector<T>::back() const {
        if (size_ == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return data_[size_ - 1];
    }

    template <typename T>
    T* Vector<T>::data() {
        return data_;
    }

    template <typename T>
    const T* Vector<T>::data() const {
        return data_;
    }

    template <typename T>
    T& Vector<T>::operator[](int index) {
        return data_[index];
    }

    template <typename T>
    const T& Vector<T>::operator[](int index) const {
        return data_[index];
    }

    template <typename T>
    void Vector<T>::push_back(const T& value) {
        if (size_ == capacity_) {
            capacity_ = capacity_ == 0 ? 1 : capacity_ * 2;
            T* new_data_ = new T[capacity_];
            for (size_t i = 0; i < size_; i++) {
                new_data_[i] = data_[i];
            }

            if (data_ != nullptr) {
                delete[] data_;
            }

            data_ = new_data_;
        }

        data_[size_++] = value;
    }
    
    template <typename T>
    void Vector<T>::pop_back() {
        if (size_ == 0) {
            throw std::out_of_range("Vector is empty");
        }
        size_--;
    }

    template <typename T>
    void Vector<T>::assign(int count, const T& value) {
        if (count > capacity_) {
            if (capacity_ == 0) {
                capacity_ = 1;
            }

            while (capacity_ < count) {
                capacity_ *= 2;
            }

            T* new_data_ = new T[capacity_];
            if (data_ != nullptr) {
                delete[] data_;
            }
            data_ = new_data_;
        }

        size_ = count;
        for (size_t i = 0; i < size_; i++) {
            data_[i] = value;
        }
    }

    template <typename T>
    void Vector<T>::swap(Vector<T>& other) {
        if (this == &other) {
            return;
        }

        std::swap(data_, other.data_);
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
    }

    template <typename T>
    bool Vector<T>::empty() const {
        return size_ == 0;
    }

    template <typename T>
    size_t Vector<T>::size() const {
        return size_;
    }

    template <typename T>
    size_t Vector<T>::capacity() const {
        return capacity_;
    }
};
