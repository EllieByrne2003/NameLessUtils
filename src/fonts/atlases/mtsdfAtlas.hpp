#pragma once

// Includes from standard


// Includes from third party libraries
#include <glm/glm.hpp>

// Includes from personal libraries


// Includes from project


// Forward declarations
struct Glyph;

// Type aliases
typedef unsigned int GLuint;

namespace NLUT {
    namespace Fonts {
        class MtsdfAtlas {
        private:

        protected:
            virtual const Glyph & getGlyph(const uint32_t codepoint) = 0;

        public:
            MtsdfAtlas() = default;
            
            virtual ~MtsdfAtlas() = default;
    
            MtsdfAtlas(const MtsdfAtlas &) = delete;
            MtsdfAtlas & operator=(const MtsdfAtlas &) = delete;
        };
    }
}