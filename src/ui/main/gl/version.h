#ifndef CPRPG_UI_GL_VERSION_H
#define CPRPG_UI_GL_VERSION_H

#include <string>
#include <set>

namespace UI {
    namespace GL {
        /**
         * Enumeration of the possible Open GL Versions to check against
         */
        enum class OpenGLVersions {
            OPENGL_1_0,
            OPENGL_1_1,
            OPENGL_1_2,
            OPENGL_1_3,
            OPENGL_1_4,
            OPENGL_1_5,
            OPENGL_2_0,
            OPENGL_2_1,
            OPENGL_3_0,
            OPENGL_3_1,
            OPENGL_3_2,
            OPENGL_3_3,
            OPENGL_4_0,
            OPENGL_4_1,
            OPENGL_4_2,
            OPENGL_4_3,
            OPENGL_4_4,
            UNKNOWN
        };
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
                 * Compare the version to the given major and minor versions
                 * @param major The major version to look for
                 * @param minor The minor version to look for
                 * @return true if we have at least this version. False otherwise
                 */
                bool compare(const int major, const int minor) const;
                /**
                 * Compare the version to the given major and minor versions
                 * @param version The version to look for
                 * @return true if we have at least this version. False otherwise
                 */
                bool compare(OpenGLVersions version) const;
                /**
                 * Get the enum representing the OpenGL version that is available
                 * @return the version
                 */
                OpenGLVersions getVersion() const;
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
                /**
                 * Get the name of the vendor that produced the implementation
                 * @return the vendor
                 */
                const std::string& vendor() const {
                    return vendor_;
                }
                /**
                 * Get the name of the renderer
                 * @return the renderer
                 */
                const std::string& renderer() const {
                    return renderer_;
                }
                /**
                 * Get the set of extensions
                 * @return the set of extensions
                 */
                const std::set<std::string>& extensions() const {
                    return extensions_;
                }
                /**
                 * Check if the given extension is present
                 * @param ext The extension to look for
                 * @return true if the extension is present. False if not
                 */
                bool hasExtension(const std::string& ext) const {
                    return extensions_.find(ext) != extensions_.end();
                }
            protected:
            private:
                /** The major version number */
                int major_;
                /** The minor version number */
                int minor_;
                /** The name of the vendor */
                std::string vendor_;
                /** The name of the renderer */
                std::string renderer_;
                /** The set of extensions */
                std::set<std::string> extensions_;
        };
    }
}
#endif
