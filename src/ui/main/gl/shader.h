#ifndef CPRPG_UI_GL_SHADER_H
#define CPRPG_UI_GL_SHADER_H

#include <string>

namespace UI {
    namespace GL {
        /**
         * Enumeration of the types of shaders that are in use
         */
        enum class ShaderType {
            VERTEX,
            FRAGMENT
        };
        /**
         * Representation of a shader
         */
        class Shader {
            public:
                /**
                 * Create the shader
                 * @param type The type of shader
                 */
                Shader(const ShaderType type);
                /**
                 * Destroy the shader
                 */
                ~Shader();
                /**
                 * Set the source of the shader
                 * @param source The source of the shader
                 */
                void source(const std::string& source);
            protected:
            private:
                int id_;
        };
    }
}
#endif
