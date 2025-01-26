#ifndef OWNINGDYNAMICDOODAD_HPP
#define OWNINGDYNAMICDOODAD_HPP
#include "BigBrainPointer.hpp"
#include <cstddef>
#include <stdexcept>

namespace helpers {
    template <typename T>
class OwningDynamicDoodad {
private:
        BigBrainPointer<T>* _array;
        size_t _capacity;
        size_t _used;
    public:
        OwningDynamicDoodad() : _used(0), _capacity(0), _array(new BigBrainPointer<T>[0]) {
        }

        size_t capacity() const noexcept {
            return _capacity;
        }

        // void push_back(T* value) {
        //     if (_used >= _capacity) {
        //         resize((_capacity == 0) ? 1 : 2 * _capacity);
        //     }
        //     _array[_used++] = BigBrainPointer<T>(value);
        // }

        void push_back(BigBrainPointer<T>&& value) {
            if (_used >= _capacity) {
                resize((_capacity == 0) ? 1 : 2 * _capacity);
            }
            _array[_used] = nullptr;
            _array[_used++] = BigBrainPointer<T>(static_cast<BigBrainPointer<T>&&>(value));
        }

        // void emplace_at(size_t index, T value) {
        //     if(index >= capacity()) {
        //         throw std::out_of_range("Index out of range");
        //     }
        //     _array[index] = value;
        //     _used++;
        // }

        size_t size() const {
            return _used;
        }

        T& get(size_t index) const {
            if(index >= _used) {
                throw std::out_of_range("Index out of range");
            }
            return *_array[index];
        }

        BigBrainPointer<T> pop(size_t index) {
            if(index >= _used) {
                throw std::out_of_range("Index out of range");
            }
            BigBrainPointer<T> temp = static_cast<BigBrainPointer<T>&&>(_array[index]);
            erase(index);
            return temp;
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

            _array[index] = BigBrainPointer<T>(nullptr);

            _used--;

            for(size_t i = index; i < _used; ++i) {
                _array[i] = static_cast<BigBrainPointer<T>&&>(_array[i + 1]);
            }
        }

        void resize(size_t new_size) {
            if(new_size <= capacity()) return;
            auto* temp = new BigBrainPointer<T>[new_size];
            for (size_t i = 0; i < _used; ++i) {
                if (!_array[i]) continue;
                temp[i] = std::move(_array[i]); // Transfer ownership
            }
            delete[] _array;
            _array = temp;
            _capacity = new_size;
        }

        //rule of 5
        ~OwningDynamicDoodad() {
            delete[] _array;
        }

        OwningDynamicDoodad(const OwningDynamicDoodad &other) {
            _array = new BigBrainPointer<T>[other._capacity];
            _used = other._used;
            _capacity = other._capacity;
            memcpy(_array, other._array, other._capacity);
        }

        OwningDynamicDoodad(OwningDynamicDoodad &&other) noexcept {
            _array = other._array;
            other._array = nullptr;
            _capacity = other._capacity;
            _used =other._used;
        }

        // DynamicDoodad& operator=(const DynamicDoodad& other) {
        //     if(this == &other) {
        //         return *this;
        //     }
        //     delete[] _array;
        //     _capacity = other._capacity;
        //     _used = other._used;
        //     _array = new T[_capacity];
        //     for(size_t i = 0; i < _used; i++) {
        //         _array[i] = other._array[i];
        //     }
        //     return *this;
        // }

        OwningDynamicDoodad & operator=(OwningDynamicDoodad &&other) noexcept {
            if(this != &other) {
                for(size_t i = 0; i < other._used; i++) {
                    push_back(other.pop(i));
                }
            }
            _capacity = other._capacity;
            _used =other._used;
            return *this;
        }
    };
} // helpers

#endif //OWNINGDYNAMICDOODAD_HPP
