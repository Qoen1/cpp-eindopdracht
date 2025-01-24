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
    class DynamicDoodad{
    private:
        T* _array;
        size_t _capacity;
        size_t _used;
    public:
        DynamicDoodad() : _used(0), _capacity(0), _array(new T[0]) {
        }

        size_t capacity() const noexcept {
            return _capacity;
        }

        // void push_back(const T& value) {
        //     if (_used == _capacity) {
        //         resize((_capacity == 0) ? 1 : 2 * _capacity);
        //     }
        //     _array[_used++] = new T(value);
        // }
        void push_back(T value) {
            if (_used == _capacity) {
                resize((_capacity == 0) ? 1 : 2 * _capacity);
            }
            _array[_used++] = T(value);
        }

        size_t size() const {
            return _used;
        }

        T get(size_t index) const {
            if(index >= _used) {
                throw std::out_of_range("Index out of range");
            }
            return _array[index];
        }

        T&& pop(size_t index) {
            if(index >= _used) {
                throw std::out_of_range("Index out of range");
            }
            T* temp = _array;
            erase(index);
            return static_cast<T&&>(*temp);
        }

        size_t indexOf(T value) {
            for(size_t i = 0; i < _used; i++) {
                if(_array[i] == value) {
                    return i;
                }
            }
            throw std::out_of_range("value not found");
        }

        void erase(T value) {
            erase(indexOf(value));
        }
        void erase(size_t index) {
            if(index >= _used) {
                throw std::out_of_range("Index out of range");
            }

            for(size_t i = index; i < _used - 1; ++i) {
                _array[i] = static_cast<T&&>(_array[i + 1]);
            }
        }

        void resize(size_t new_size) {
            if(new_size <= capacity()) return;
            T* temp = new T[new_size];
            std::memcpy(temp, _array, _used * sizeof(T));
            _array = nullptr;
            _array = temp;
            _capacity = new_size;
        }

        //rule of 5
        ~DynamicDoodad() = default;

        DynamicDoodad(const DynamicDoodad &other) = delete;/* {
            _array = new T[other._capacity];
            _used = other._used;
            _capacity = other._capacity;
            std::memcpy(_array, other._array, other._capacity);
        }*/

        DynamicDoodad(DynamicDoodad &&other) noexcept {
            for(size_t i = 0; i < other._used; i++) {
                push_back(other.pop(i));
            }
            _capacity = other._capacity;
            _used =other._used;
        }

        DynamicDoodad& operator=(const DynamicDoodad& other) = delete;/* {
            if(this == &other) {
                return *this;
            }
            delete[] _array;
            _capacity = other._capacity;
            _used = other._used;
            _array = new T[_capacity];
            for(size_t i = 0; i < _used; i++) {
                _array[i] = other._array[i];
            }
            return *this;
        }*/

        DynamicDoodad & operator=(DynamicDoodad &&other) noexcept {
            if(this != &other) {
                for(size_t i = 0; i < other._used; i++) {
                    push_back(other.pop(i));
                }
            }
            return *this;
        }
    };
} // helpers

#endif //DYNAMICDOODAD_HPP
