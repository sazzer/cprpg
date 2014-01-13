#ifndef CPRPG_VFS_ROOT_H
#define CPRPG_VFS_ROOT_H

#include <string>

namespace VFS {
    /**
     * Representation of a VFS Root
     */
    class Root {
        public:
            /**
             * Default constructor
             */
            Root() : name_(""), 
                root_(""),
                priority_(0) {}

            /** Default copy constructor */
            Root(const Root& other) = default;

            /** Default move constructor */
            Root(Root&& other) = default;
            /**
             * Virtual destructor
             */
            virtual ~Root() {}
            /**
             * Get the name of root
             * @return the name of root
             */
            const std::string name() const {
                return name_;
            };
            /**
             * Set the name of root
             * @param value The name of root
             */
            void name(std::string value) {
                name_ = value;
            }
            /**
             * Get the actual value of the root
             * @return the actual value of the root
             */
            const std::string& root() const {
                return root_;
            }
            /**
             * Set the actual value of the root
             * @param value the actual value of the root
             */
            void root(const std::string& value) {
                root_ = value;
            }
            /**
             * Get the priority of the root
             * @return the priority of the root
             */
            const int priority() const {
                return priority_;
            }
            /**
             * Set the priority of the root
             * @param value The priority
             */
            void priority(int value) {
                priority_ = value;
            }
        protected:
        private:
            /** The name of root */
            std::string name_;
            /** The actual location of the root */
            std::string root_;
            /** The priority of the root */
            int priority_;
    };
}
#endif
