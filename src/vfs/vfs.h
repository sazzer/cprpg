#ifndef CPRPG_VFS_VFS_H
#define CPRPG_VFS_VFS_H

#include "vfs/root.h"
#include "vfs/filename.h"
#include "vfs/file.h"
#include <memory>

namespace VFS {
    /**
     * The actual core Virtual Filesystem
     */
    class VFS {
        public:
            /**
             * Default constructor
             */
            VFS();
            /** Defautl destructor. Needed for pImpl */
            ~VFS() = default;
            
            /** No copy constructor */
            VFS(const VFS& other) = delete;
            /** No move constructor */
            VFS(const VFS&& other) = delete;
            /** No assignment operator */
            void operator=(const VFS& other) = delete;
            /** No assignment operator */
            void operator=(const VFS&& other) = delete;

            /**
             * Add a new root to the VFS
             * @param root The root to add
             */
            void addRoot(std::shared_ptr<Root> root);

            /**
             * Determine if the given file exists in this root
             * @param filename The name of the file to resolve
             * @return true if the file exists. False if not
             */
            bool exists(const Filename& filename) const;

            /**
             * Attempt to load the given file.
             * @param filename The name of the file to load
             * @return The loaded file, or an empty pointer if it doesn't exist
             */
            std::unique_ptr<File> load(const Filename& filename) const;
        protected:
        private:
            /** Structure for pImpl */
            struct Impl;
            /** The actual pImpl. This is a shared_ptr because unique_ptr needs the full definition of Impl */
            std::shared_ptr<Impl> pImpl;
    };
}

#endif
