#include "vfs/file.h"

namespace VFS {
    /**
     * Helper to read from the given stream and write to the given output source
     * @param stream The stream to read from
     * @param output The output to write to
     */
    template <typename T>
    void readFile(std::istream& stream, T& output) {
        char c;
        while (!stream.eof()) {
            stream.get(c);
            if (!stream.eof()) {
                output.push_back(c);
            }
        }
    }

    /**
     * Read the entire file as a text file
     * @return the text contents of the file
     */
    std::string File::readAsText() const {
        std::unique_ptr<std::istream> stream = open();
        std::string result;
        readFile(*stream, result);
        return result;
    }

    /**
     * Read the entire file as a binary file
     * @return the binary contents of the file
     */
    std::vector<char> File::readAsBinary() const {
        std::unique_ptr<std::istream> stream = open();
        std::vector<char> result;
        readFile(*stream, result);
        return result;
    }
}
