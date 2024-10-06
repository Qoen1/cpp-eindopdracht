//
// Created by fikkie on 05/10/24.
//

#ifndef TYPOTRAP_HPP
#define TYPOTRAP_HPP

#include <stdexcept>
#include <cstring>

namespace helpers {
    /**
     * custom implementation of a string class.
     */
    class TypoTrap {
    private:
        char* _array;
        size_t _capacity;
        size_t _used;
    public:
        TypoTrap() : _used(0), _capacity(2) {
            _array = new char[_capacity];
            _array[0] = '\0';
        }

        TypoTrap(char* from) : _used(0), _capacity(2) {
            _array = new char[std::strlen(from) + 1];
            for(char* it = from; *it; ++it) {
                append(*it);
            }
        }

        void append(char* value) {
            for(char* it = value; *it; ++it) {
                append(*it);
            }
        }

        void append(char value) {
            if(_used == _capacity - 1) {
                _capacity *= 2;
                char* newArray = new char[_capacity];
                std::memcpy(newArray, _array, _used);
                delete[] _array;
                _array = newArray;
            }
            _array[_used++] = value;
            _array[_used] = '\0';
        }

        size_t size() const {
            return _used;
        }

        char* cstring() const {
            return _array;
        }
        char get(size_t index) {
            if(index >= _used) {
                throw std::out_of_range("Index out of range");
            }
            return _array[index];
        }

        //rule of 5
        ~TypoTrap() {
            delete[] _array;
        }

        TypoTrap(const TypoTrap &other) {
            _array = new char[other._capacity];
            _used = other._used;
            _capacity = other._capacity;
            std::memcpy(_array, other._array, other._capacity);
        }

        TypoTrap(TypoTrap &&other) {
            _array = other._array;
            _capacity = other._capacity;
            _used =other._used;

            other._array = nullptr;
        }

        TypoTrap& operator=(const TypoTrap& other) {
            if(this == &other) {
                return *this;
            }
            delete[] _array;
            _capacity = other._capacity;
            _used = other._used;
            _array = new char[_capacity];
            for(size_t i = 0; i < _used; i++) {
                _array[i] = other._array[i];
            }
            return *this;
        }

        TypoTrap & operator=(TypoTrap &&other) {
            if(this != &other) {
                delete[] _array;
                _array = other._array;

                other._array = nullptr;
            }
            return *this;
        }
    };
} // helpers

#endif //TYPOTRAP_HPP
