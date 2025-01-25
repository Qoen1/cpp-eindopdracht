//
// Created by fikkie on 05/10/24.
//

#ifndef TYPOTRAP_HPP
#define TYPOTRAP_HPP

#include <stdexcept>
#include <cstring>
#include <ostream>

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
        TypoTrap() : _used(0), _capacity(1) {
            _array = new char[_capacity];
            _array[0] = '\0';
        }

        TypoTrap(const char* from) : _used(strlen(from) + 1), _capacity(strlen(from) + 1) {
            _array = new char[_capacity];
            strcpy(_array, from);
        }

        // TypoTrap(char* from) : _used(0), _capacity(strlen(from) + 1) {
        //     _array = new char[_capacity];
        //     for(char* it = from; *it; ++it) {
        //         append(*it);
        //     }
        // }

        // void append(char value) {
        //     if(_used == _capacity - 1) {
        //         _capacity *= 2;
        //         char* newArray = new char[_capacity];
        //         std::memcpy(newArray, _array, _used);
        //         delete[] _array;
        //         _array = newArray;
        //     }
        //     _array[_used++] = value;
        //     _array[_used] = '\0';
        // }

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

        friend std::ostream & operator<<(std::ostream &os, const TypoTrap &obj) {
            return os << obj.cstring();
        }

        //rule of 5
        ~TypoTrap() {
            delete[] _array;
        }

        TypoTrap(const TypoTrap &other): _array(nullptr) {
            _array = new char[other._capacity];
            _used = other._used;
            _capacity = other._capacity;
            std::strcpy(_array, other._array);
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
                _used = other._used;
                _capacity = other._capacity;

                other._array = nullptr;
            }
            return *this;
        }

        bool operator==(const TypoTrap &name) const {
            return std::strcmp(this->cstring(), name.cstring()) == 0;
        }
    };
} // helpers

#endif //TYPOTRAP_HPP
