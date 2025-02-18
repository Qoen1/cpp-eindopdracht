//
// Created by koenv on 05/10/2024.
//

#ifndef UNIQUEBIGBRAINPOINTER_HPP
#define UNIQUEBIGBRAINPOINTER_HPP

namespace helpers {
    template<typename T>
    class BigBrainPointer {
    private:
        T* item;

    public:
        BigBrainPointer(): item(nullptr) {
        }

        BigBrainPointer(T* item) : item(item) {
        }

        ~BigBrainPointer() {
            delete item;
        }

        T* get() const { return item; }

        T* pop() {
            T* temp = item;
            item = nullptr;
            return temp;
        }

        explicit operator bool() const { return item != nullptr; }

        //copy constructor and assignment operator
        BigBrainPointer(const BigBrainPointer& other) = delete;

        BigBrainPointer &operator=(const BigBrainPointer& other) = delete;

        //move constructor and assignment operator
        BigBrainPointer(BigBrainPointer&& other) noexcept
            : item(other.item) {
            other.item = nullptr;
        }

        BigBrainPointer &operator=(BigBrainPointer&& other) noexcept {
            if (this == &other)
                return *this;
            delete item;
            item = other.item;
            other.item = nullptr;
            return *this;
        }

        //arrow operator
        T* operator->() const {
            return item;
        }

        //dereference operator
        T &operator*() const {
            return *item;
        }
    };
} // helpers

#endif //UNIQUEBIGBRAINPOINTER_HPP
