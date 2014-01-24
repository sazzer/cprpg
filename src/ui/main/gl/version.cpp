#include "ui/main/gl/gl.h"
#include "ui/main/gl/version.h"
#include <type_traits>

namespace UI {
    namespace GL {
        static const int OPENGL_MAJOR_VERSIONS[] = {
            1, 1, 1, 1, 1, 1,
            2, 2, 
            3, 3, 3, 3,
            4, 4, 4, 4, 4,
            9
        };
        static const int OPENGL_MINOR_VERSIONS[] = {
            0, 1, 2, 3, 4, 5, 
            0, 1, 
            0, 1, 2, 3,
            0, 1, 2, 3, 4,
            9
        };
        /**
         * Construct the version wrapper
         */
        Version::Version() {
            glGetIntegerv(GL_MAJOR_VERSION, &major_);
            glGetIntegerv(GL_MINOR_VERSION, &minor_);
            vendor_ = (const char*)(glGetString(GL_VENDOR));
            renderer_ = (const char*)(glGetString(GL_RENDERER));

            if (compare(OpenGLVersions::OPENGL_3_0)) {
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
            bool result;
            if (major_ > major) {
                result = true;
            } else if (major_ == major && minor_ >= minor) {
                result = true;
            } else {
                // Either major < requested or major == requested and minor < requested
                result = false;
            }
            return result;
        }
        /**
         * Compare the version to the given major and minor versions
         * @param version The version to look for
         * @return true if we have at least this version. False otherwise
         */
        bool Version::compare(OpenGLVersions version) const {
            typedef std::underlying_type<OpenGLVersions>::type utype;
            utype a = static_cast<utype>(version);

            int major = OPENGL_MAJOR_VERSIONS[a];
            int minor = OPENGL_MINOR_VERSIONS[a];
            return compare(major, minor);
        }
        /**
         * Get the enum representing the OpenGL version that is available
         * @return the version
         */
        OpenGLVersions Version::getVersion() const {
            typedef std::underlying_type<OpenGLVersions>::type utype;
            OpenGLVersions result = OpenGLVersions::UNKNOWN;
            for (utype v = static_cast<utype>(OpenGLVersions::OPENGL_1_0); 
                v < static_cast<utype>(OpenGLVersions::UNKNOWN);
                ++v) {
                OpenGLVersions ver = static_cast<OpenGLVersions>(v);
                if (compare(ver)) {
                    result = ver;
                }
            }
            return result;
        }
    }
}
