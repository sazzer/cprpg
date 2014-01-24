#include "vfs/vfs.h"
#include <map>
#include <list>
#include "logging/logger.h"

static Logging::Logger LOG("cprpg.vfs.vfs");

namespace VFS {
    /**
     * The actual implementation of the VFS
     */
    struct VFS::Impl {
        public:
            void addRoot(std::shared_ptr<Root> root) {
                LOG(Logging::Level::INFO, "Adding new root: " + root->name());
                rootsByName[root->name()] = root;
                roots.push_back(root);
            }
            bool exists(const Filename& filename) const {
                LOG(Logging::Level::TRACE, "Checking existance of file: " + (std::string)filename);
                std::shared_ptr<Root> root = findRoot(filename);
                return root && root->exists(filename.path());
            }
            const std::shared_ptr<Root> findRoot(const Filename& filename) const {
                std::shared_ptr<Root> result;
                const std::string& rootName = filename.root();
                if (rootName.empty()) {
                    for (auto i = roots.begin(); !result && i != roots.end(); ++i) {
                        const std::shared_ptr<Root> root = *i;
                        if (root->exists(filename.path())) {
                            result = root;
                        }
                    }
                } else {
                    auto found = rootsByName.find(rootName);
                    if (found != rootsByName.end()) {
                        result = found->second;
                    }
                }

                if (result) {
                    LOG(Logging::Level::DEBUG, "Found file in root: " + result->name());
                } else {
                    LOG(Logging::Level::DEBUG, "Didn't find file in any root: " + (std::string)filename);
                }
                return result;
            }
            std::unique_ptr<File> load(const Filename& filename) const {
                LOG(Logging::Level::TRACE, "Loading file" + (std::string)filename);
                std::shared_ptr<Root> root = findRoot(filename);
                std::unique_ptr<File> result;
                if (root) {
                    result = root->load(filename.path());
                }
                return result;
            }
        protected:
        private:
            /** The list of roots in priority order */
            std::list<std::shared_ptr<Root> > roots;
            /** The map of roots by name */
            std::map<std::string, std::shared_ptr<Root> > rootsByName;
    };

    /**
     * Default constructor
     */
    VFS::VFS() : pImpl(new VFS::Impl) {
    }
    /**
     * Add a new root to the VFS
     * @param root The root to add
     */
    void VFS::addRoot(std::shared_ptr<Root> root) {
        pImpl->addRoot(root);
    }

    /**
     * Determine if the given file exists in this root
     * @param filename The name of the file to resolve
     * @return true if the file exists. False if not
     */
    bool VFS::exists(const Filename& filename) const {
        return pImpl->exists(filename);
    }

    /**
     * Attempt to load the given file.
     * @param filename The name of the file to load
     * @return The loaded file, or an empty pointer if it doesn't exist
     */
    std::unique_ptr<File> VFS::load(const Filename& filename) const {
        return pImpl->load(filename);
    }
}
