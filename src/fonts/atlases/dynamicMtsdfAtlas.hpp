#pragma once

// Includes from standard
#include <unordered_set>

// Includes from third party libraries
#include <msdf-atlas-gen/msdf-atlas-gen.h>

// Includes from personal libraries


// Includes from project
#include "mtsdfAtlas.hpp"

// Forward declarations


// Type aliases
typedef unsigned int GLuint;

namespace NLUT {
    namespace Fonts {
        class DynamicMtsdfAtlas : MtsdfAtlas {
        private:
            using BitmapStorage = msdf_atlas::BitmapAtlasStorage<msdf_atlas::byte, 3>;    
            using Generator     = msdf_atlas::ImmediateAtlasGenerator<float, 3, msdf_atlas::msdfGenerator, BitmapStorage>;
            using DynamicAtlas  = msdf_atlas::DynamicAtlas<Generator>;
            using GlyphGeometry = msdf_atlas::GlyphGeometry;

            using FontHandle    = msdfgen::FontHandle;


            FontHandle   *const font  = nullptr;
            DynamicAtlas *const atlas = nullptr;

            std::unordered_map<uint32_t, GlyphGeometry> geometry;
            std::unordered_map<uint32_t, Glyph>         glyphs;
            std::unordered_set<uint32_t>                missing;

            GLuint textureID = 0;
            bool   textureDirty = false;

        protected:

        public:
    
        };
    }
}