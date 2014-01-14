#include "vfs/main/filename.h"

namespace VFS {
    /**
     * Construct the filename object by parsing the provided filename string
     * If the string contains a : character then the string before it is the
     * schema, or the VFS root to use, and the bit after it is the path to use.
     * If the string does not contain a : character then there is no VFS root
     * and the entire string is the path to use
     * @param filename The filename to parse
     */
    Filename::Filename(const std::string& filename) {
        size_t schemeOffset = filename.find(":");
        if (schemeOffset == std::string::npos) {
            // No scheme
            root_ = "";
            path_ = filename;
        } else {
            root_ = filename.substr(0, schemeOffset);
            path_ = filename.substr(schemeOffset + 1);
        }
    }
    /**
     * Construct the filename from component parts
     * @param root The root to use. May be empty
     * @param path The path to use
     */
    Filename::Filename(const std::string& root, const std::string& path) : root_(root), path_(path) {
    }
    /**
     * Generate the URI syntax string for this filename
     * @return the URI syntax string for this filename
     */
    Filename::operator std::string() const {
        return root_ + ":" + path_;
    }
}
