#ifndef CPRPG_VFS_DIRECTORY_ROOT_H
#define CPRPG_VFS_DIRECTORY_ROOT_H

#include "vfs/root.h"

namespace VFS {
    namespace Roots {
        /**
         * VFS Root that represents a directory on disk
         */
        class Directory : public Root {
            public:
                /**
                 * Default constructor
                 */
                Directory() = default;

                /** Default copy constructor */
                Directory(const Directory& other) = default;

                /** Default move constructor */
                Directory(Directory&& other) = default;
                /**
                 * Virtual destructor
                 */
                virtual ~Directory() {}

                /**
                 * Determine if the given file exists in this root
                 * @param filename The name of the file to resolve
                 * @return true if the file exists. False if not
                 */
                virtual bool exists(const std::string& filename);

                /**
                 * Attempt to load the given file.
                 * @param filename The name of the file to load
                 * @return The loaded file, or an empty pointer if it doesn't exist
                 */
                virtual std::unique_ptr<File> load(const std::string& filename);
            protected:
            private:
        };
    }
}

#endif
