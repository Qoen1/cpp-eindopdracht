//
// Created by fikkie on 05/10/24.
//

#ifndef DYNAMICDOODAD_HPP
#define DYNAMICDOODAD_HPP

#include <cstddef>
#include <stdexcept>
#include <cstring>

namespace helpers {
    template <typename T>
    /**
     * custom implementation of the vector class
     */
    class DynamicDoodad<T>{
    private:
        T* _array;
        size_t _capacity;
        size_t _used;
    public:
        DynamicDoodad(const size_t initSize) : _used(0), _capacity(1) {
            if(initSize > _capacity) {
                _capacity {initSize};
            }
            _array = new T[_capacity];
        }

        size_t capacity() const noexcept {
            return _capacity;
        }

        void push_back(T value) {
            _array[_used++] = value;
        }

        size_t size() const {
            return _used;
        }

        T& get(size_t index) {
            if(index >= _used) {
                throw std::out_of_range("Index out of range");
            }
            return _array[index];
        }

        //rule of 5
        DynamicDoodad::~DynamicDoodad() {
            delete[] _array;
        }

        DynamicDoodad::DynamicDoodad(const DynamicDoodad &other) {
            _array = new int[other._capacity];
            _used = other._used;
            _capacity = other._capacity;
            std::memcpy(_array, other._array, other._capacity);
        }

        DynamicDoodad::DynamicDoodad(DynamicDoodad &&other) noexcept {
            _array = other._array;
            _capacity = other._capacity;
            _used =other._used;

            other._array = nullptr;
        }

        DynamicDoodad& DynamicDoodad::operator=(const DynamicDoodad& other) {
            if(this == &other) {
                return *this;
            }
            delete[] _array;
            _capacity = other._capacity;
            _used = other._used;
            _array = new int[_capacity];
            for(size_t i = 0; i < _used; i++) {
                _array[i] = other._array[i];
            }
            return *this;
        }

        DynamicDoodad & DynamicDoodad::operator=(DynamicDoodad &&other) noexcept {
            if(this != &other) {
                delete[] _array;
                _array = other._array;

                other._array = nullptr;
            }
            return *this;
        }
    };
} // helpers

#endif //DYNAMICDOODAD_HPP
