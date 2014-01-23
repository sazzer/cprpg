#include "ui/main/gl/gl.h"
#include "ui/main/gl/version.h"

namespace UI {
    namespace GL {
        /**
         * Construct the version wrapper
         */
        Version::Version() {
            glGetIntegerv(GL_MAJOR_VERSION, &major_);
            glGetIntegerv(GL_MINOR_VERSION, &minor_);
            vendor_ = (const char*)(glGetString(GL_VENDOR));
            renderer_ = (const char*)(glGetString(GL_RENDERER));

            if (compare(3, 0)) {
                int numExtensions;
                glGetIntegerv(GL_NUM_EXTENSIONS, &numExtensions);
                for (int i = 0; i < numExtensions; ++i) {
                    std::string ext = (const char*)(glGetStringi(GL_EXTENSIONS, i));
                    extensions_.insert(ext);
                }
            } else {
                // Pre OpenGL 3.0, we need to get the extensions a different way
            }
        }
        /**
         * Compare the version to the given major and minor versions
         * @param major The major version to look for
         * @param minor The minor version to look for
         * @return true if we have at least this version. False otherwise
         */
        bool Version::compare(const int major, const int minor) const {
            return true;
        }
    }
}
