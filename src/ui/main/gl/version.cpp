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
        }
    }
}
