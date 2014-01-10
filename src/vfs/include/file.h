#ifndef CPRPG_VFS_FILE_H
#define CPRPG_VFS_FILE_H

#include <string>

namespace VFS {
    /**
     * Representation of a single file on disk
     */
    class File {
        public:
            /**
             * Construct the file with the given filename
             * @param filename The filename to use
             */
            File(const std::string& filename) : filename_(filename) {}
            /**
             * Construct the file with the given filename
             * @param filename The filename to use
             */
            File(const char* filename) : filename_(filename) {}
            /**
             * Get the filename that we represent
             * @return the filename
             */
            const std::string& filename() const {
                return filename_;
            }
        protected:
        private:
            /** The filename of the file on disk */
            const std::string filename_;
    };
}

#endif
