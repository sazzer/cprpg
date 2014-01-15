#ifndef CPRPG_VFS_FILES_DISK_H
#define CPRPG_VFS_FILES_DISK_H

#include "vfs/file.h"
#include <string>
#include <istream>

namespace VFS {
    namespace Files {
        /**
         * Representation of a single file on disk
         */
        class Disk : public File {
            public:
                /**
                 * Construct the file with the given filename
                 * @param filename The filename to use
                 */
                Disk(const std::string& filename) : filename_(filename) {}
                /**
                 * Get the filename that we represent
                 * @return the filename
                 */
                const std::string& filename() const {
                    return filename_;
                }

                /**
                 * Open a stream onto the file for reading
                 * @return the stream to read the file with
                 */
                virtual std::unique_ptr<std::istream> open() const;

            protected:
            private:
                /** The filename of the file on disk */
                const std::string filename_;
        };
    }
}

#endif
