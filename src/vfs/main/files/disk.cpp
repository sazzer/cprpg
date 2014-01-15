#include "vfs/main/files/disk.h"
#include <fstream>

namespace VFS {
    namespace Files {
        /**
         * Open a stream onto the file for reading
         * @return the stream to read the file with
         */
        std::unique_ptr<std::istream> Disk::open() const {
            std::ifstream* stream = new std::ifstream(filename(), std::ifstream::in | std::ifstream::binary);
            return std::unique_ptr<std::istream>(stream);
        }
    }
}
