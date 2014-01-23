#ifndef CPRPG_UI_GL_VERSION_H
#define CPRPG_UI_GL_VERSION_H

namespace UI {
    namespace GL {
        /**
         * Encapsulation of the version of OpenGL that is installed. This includes both the version
         * number and the extensions that are available
         */
        class Version {
            public:
                /**
                 * Construct the version wrapper
                 */
                Version();
                /**
                 * Get the major version number
                 * @return the major version number
                 */
                int major() const {
                    return major_;
                }
                /**
                 * Get the minor version number
                 * @return the minor version number
                 */
                int minor() const {
                    return minor_;
                }
            protected:
            private:
                /** The major version number */
                int major_;
                /** The minor version number */
                int minor_;
        };
    }
}
#endif
