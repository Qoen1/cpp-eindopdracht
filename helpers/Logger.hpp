//
// Created by koenv on 27/01/2025.
//

#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <ostream>
#include <vector>

namespace helpers {

class Logger: public std::ostream {
public:
    // Constructor
    Logger() : std::ostream(&buffer), buffer(*this) {}

    // Add a stream to the list of streams to duplicate output to
    void addStream(std::ostream& stream) {
        streams.push_back(&stream);
    }

private:
    class Buffer : public std::streambuf {
    public:
        explicit Buffer(Logger& parent) : parent(parent) {}

    protected:
        // Overriding the overflow method to handle single characters
        int overflow(int c) override {
            if (c != EOF) {
                char ch = static_cast<char>(c);
                for (auto stream : parent.streams) {
                    stream->put(ch); // Write character to each stream
                }
            }
            return c;
        }

        // Overriding sync to flush all streams
        int sync() override {
            for (auto stream : parent.streams) {
                stream->flush();
            }
            return 0;
        }

    private:
        Logger& parent;
    };

    Buffer buffer;
    std::vector<std::ostream*> streams; // List of output streams
};

} // helpers

#endif //LOGGER_HPP
