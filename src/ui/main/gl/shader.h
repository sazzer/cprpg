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
        // Forward declaration
        class Program;
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
                /**
                 * Get the type of the shader
                 * @return the type of the shader
                 */
                ShaderType type() const {
                    return type_;
                }
            protected:
            private:
                /** The ID of the shader */
                int id_;
                /** The type of the shader */
                ShaderType type_;
                /** Programs are friends */
                friend class Program;
        };
    }
}
#endif
