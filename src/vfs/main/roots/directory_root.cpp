#include "vfs/directory_root.h"
#include <boost/filesystem.hpp>
#include "vfs/main/files/disk.h"

namespace VFS {
    namespace Roots {
        /**
         * Determine if the given file exists in this root
         * @param filename The name of the file to resolve
         * @return true if the file exists. False if not
         */
        bool Directory::exists(const std::string& filename) {
            boost::filesystem::path p = boost::filesystem::path(root()) / filename;
            return boost::filesystem::exists(p);
        }

        /**
         * Attempt to load the given file.
         * @param filename The name of the file to load
         * @return The loaded file, or an empty pointer if it doesn't exist
         */
        std::unique_ptr<File> Directory::load(const std::string& filename) {
            std::unique_ptr<File> result;
            boost::filesystem::path p = boost::filesystem::path(root()) / filename;
            if (boost::filesystem::exists(p)) {

            }

            return result;
        }
    }
}
