#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>

class Array {   
    private:
        T* _array;
        size_t _size;
    public:
        Array(void); // No parameter constructor
        Array(unsigned int n);
        Array(const Array& other);
        ~Array(void);
        Array& operator=(const Array& other);
        T& operator[](size_t index);
        const T& operator[](size_t index) const;
        size_t size(void) const;
};

template <typename T>
Array<T>::Array(void): _array(NULL), _size(0) {

}
template <typename T>// No parameter constructor
Array<T>::Array(unsigned int n): _array(new T[n]), _size(n){

}

template <typename T>
Array<T>::Array(const Array& other): _array(NULL), _size(0){
    *this = other;
}

template <typename T>
Array<T>::~Array(void){
    delete[] _array;
    _array = NULL;  // Safety: prevent dangling pointer
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other){
    if(this != &other){
        delete[] _array;  // CRITICAL: Delete old array to prevent memory leak
        _size = other._size;
        _array = new T[_size];
        for (size_t i = 0; i < _size; i++)
        {
            _array[i] = other._array[i];
        }
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](size_t index){
    if(index >= _size){
        throw std::out_of_range("Index out of range");
    }
    return _array[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const{
    if(index >= _size){
        throw std::out_of_range("Index out of range");
    }
    return _array[index];
}

template <typename T>
size_t Array<T>::size(void) const{
    return _size;
}



#endif