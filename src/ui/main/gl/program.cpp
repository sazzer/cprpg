#include "ui/main/gl/program.h"
#include "ui/main/gl/gl.h"
#include "logging/logger.h"

namespace UI {
    namespace GL {
        static const Logging::Logger LOG("cprpg.ui.gl.program");
        /**
         * Create the program
         */
        Program::Program() {
            id_ = glCreateProgram();
            if (id_ != 0) {
                LOG(Logging::Level::TRACE, "Created program");
            } else {
                LOG(Logging::Level::ERROR, "Failed to create program");
            }
        }
        /**
         * Destroy the program
         */
        Program::~Program() {
            glDeleteProgram(id_);
            int err = glGetError();
            if (err == GL_NO_ERROR) {
                LOG(Logging::Level::TRACE, "Destroyed program");
            } else {
                LOG(Logging::Level::ERROR, "Failed to delete program");
            }
        }
        /**
         * Add a new shader to the program. This will replace an existing shader
         * of the same type
         * @param shader The shader to add
         */
        void Program::addShader(std::shared_ptr<Shader> shader) {
            auto old = shaders_.find(shader->type());
            if (old != shaders_.end()) {
                LOG(Logging::Level::DEBUG, "Removing old shader of same type from program");
                glDetachShader(id_, old->second->id_);
            }
            LOG(Logging::Level::DEBUG, "Adding shader to program");
            shaders_[shader->type()] = shader;
            glAttachShader(id_, shader->id_);

            int err = glGetError();
            if (err == GL_NO_ERROR) {
                glLinkProgram(id_);
                err = glGetError();
                if (err == GL_NO_ERROR) {
                    LOG(Logging::Level::DEBUG, "Linked program");
                } else {
                    LOG(Logging::Level::ERROR, "Failed to link program");
                }
            } else {
                LOG(Logging::Level::ERROR, "Error adding shader to program");
            }
        }
    }
}

