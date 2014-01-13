#ifndef CPRPG_VFS_FILE_H
#define CPRPG_VFS_FILE_H

#include <istream>
#include <string>
#include <vector>
#include <memory>

namespace VFS {
    /**
     * Interface that represents a file as loaded from the VFS
     */
    class File {
        public:
            /** Virtual destructor */
            virtual ~File() {}

            /**
             * Open a stream onto the file for reading
             * @return the stream to read the file with
             */
            virtual std::unique_ptr<std::istream> open() const = 0;

            /**
             * Read the entire file as a text file
             * @return the text contents of the file
             */
            virtual std::string readAsText() const;

            /**
             * Read the entire file as a binary file
             * @return the binary contents of the file
             */
            virtual std::vector<char> readAsBinary() const;
    };
}

#endif
