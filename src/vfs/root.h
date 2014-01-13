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
             * Enumeration of the type of roots that are supported
             */
            enum class Type {
                DIRECTORY,
                UNKNOWN
            };

            /**
             * Default constructor
             */
            Root() : type_(Type::UNKNOWN), 
                root_(""),
                priority_(0) {}

            /** Default copy constructor */
            Root(const Root& other) = default;

            /**
             * Move constructor to reset the one being moved from to a default state
             */
            Root(Root&& other) : type_(std::move(other.type_)), 
                root_(std::move(other.root_)), 
                priority_(std::move(other.priority_)) {

                other.type_ = Type::UNKNOWN;
                other.priority_ = 0;
            }
            /**
             * Get the type of root
             * @return the type of root
             */
            const Type type() const {
                return type_;
            };
            /**
             * Set the type of root
             * @param value The type of root
             */
            void type(Type value) {
                type_ = value;
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
            /** The type of root */
            Type type_;
            /** The actual location of the root */
            std::string root_;
            /** The priority of the root */
            int priority_;
    };
}
#endif
