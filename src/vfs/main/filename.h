#ifndef CPRPG_VFS_FILENAME_H
#define CPRPG_VFS_FILENAME_H

#include <string>

namespace VFS {
    /**
     * Representation of a filename, optionally including the root name, in the VFS.
     * Filenames are represented as URIs, with a scheme that is optional but is the name
     * of the root that is required for the file if the file must be loaded from that root.
     */
    class Filename {
        public:
            /**
             * Construct the filename object by parsing the provided filename string
             * If the string contains a : character then the string before it is the
             * schema, or the VFS root to use, and the bit after it is the path to use.
             * If the string does not contain a : character then there is no VFS root
             * and the entire string is the path to use
             * @param filename The filename to parse
             */
            Filename(const std::string& filename);
            /**
             * Construct the filename from component parts
             * @param root The root to use. May be empty
             * @param path The path to use
             */
            Filename(const std::string& root, const std::string& path);
            /**
             * Get the root
             * @return the root to use. May be empty
             */
            const std::string& root() const {
                return root_;
            }

            /**
             * Get the path
             * @return the path to use
             */
            const std::string& path() const {
                return path_;
            }

            /**
             * Generate the URI syntax string for this filename
             * @return the URI syntax string for this filename
             */
            operator std::string() const;
        protected:
        private:
            /** The root to look in for the file. May be empty */
            std::string root_;
            /** The path to the file. */
            std::string path_;
    };
}

#endif
