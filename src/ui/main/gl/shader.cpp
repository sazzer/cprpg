#include "ui/main/gl/shader.h"
#include "ui/main/gl/gl.h"
#include "logging/logger.h"

namespace UI {
    namespace GL {
        static const Logging::Logger LOG("cprpg.ui.gl.shader");
        /**
         * Create the shader
         */
        Shader::Shader(const ShaderType type) {
            GLenum shaderType;
            switch (type) {
                case ShaderType::VERTEX:
                    shaderType = GL_VERTEX_SHADER;
                    break;
                case ShaderType::FRAGMENT:
                    shaderType = GL_FRAGMENT_SHADER;
                    break;
            }

            id_ = glCreateShader(shaderType);
            if (id_ != 0) {
                LOG(Logging::Level::TRACE, boost::format("Created shader: %d") % id_);
            } else {
                LOG(Logging::Level::ERROR, "Failed to create shader");
            }
        }
        /**
         * Destroy the shader
         */
        Shader::~Shader() {
            glDeleteShader(id_);
            int err = glGetError();
            if (err == GL_NO_ERROR) {
                LOG(Logging::Level::TRACE, boost::format("Destroyed shader: %d") % id_);
            } else {
                LOG(Logging::Level::ERROR, boost::format("Failed to delete shader: %d") % id_);
            }
        }
        /**
         * Set the source of the shader
         * @param source The source of the shader
         */
        void Shader::source(const std::string& source) {
            int len = source.length();
            const char* src = source.c_str();
            glShaderSource(id_, 1, &src, &len);
            int err = glGetError();
            if (err == GL_NO_ERROR) {
                LOG(Logging::Level::TRACE, boost::format("Set the source code shader: %d") % id_);
                glCompileShader(id_);
                glGetShaderiv(id_, GL_COMPILE_STATUS, &err);

                if (err == GL_TRUE) {
                    LOG(Logging::Level::TRACE, boost::format("Compiled shader: %d") % id_);
                } else {
                    LOG(Logging::Level::ERROR, boost::format("Failed to compile shader: %d") % id_);
                    char infoLog[1024];
                    glGetShaderInfoLog(id_, 1024, &err, infoLog);
                    LOG(Logging::Level::ERROR, infoLog);
                }
            } else {
                LOG(Logging::Level::ERROR, boost::format("Failed to set source code for shader: %d") % id_);
            }
        }
    }
}
