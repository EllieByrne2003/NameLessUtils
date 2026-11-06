#pragma once

// Includes from standard
#include <unordered_map>
#include <unordered_set>
#include <filesystem>
#include <memory>

// Includes from third party libraries
#include <msdf-atlas-gen/msdf-atlas-gen.h>

// Includes from personal libraries


// Includes from project
#include "font.hpp"

// Forward declarations


// Type aliases
typedef unsigned int GLuint;

namespace NLUT {
    namespace Fonts {
        class DynamicFont final : public Font {
        private:
            using BitmapStorage = msdf_atlas::BitmapAtlasStorage<msdf_atlas::byte, 3>;    
            using Generator     = msdf_atlas::ImmediateAtlasGenerator<float, 3, msdf_atlas::msdfGenerator, BitmapStorage>;
            using DynamicAtlas  = msdf_atlas::DynamicAtlas<Generator>;
            using GlyphGeometry = msdf_atlas::GlyphGeometry;

            using FontHandle    = msdfgen::FontHandle;

            void loadGlyph(const uint32_t codepoint);
            void refreshGlyphCache();
            void onAtlasChanged();

            FontHandle   *const font  = nullptr;
            DynamicAtlas *const atlas = nullptr;

            std::unordered_map<uint32_t, GlyphGeometry> geometry;
            std::unordered_map<uint32_t, Glyph>         glyphs;
            std::unordered_set<uint32_t>                missing;

            GLuint textureID = 0;
            bool   textureDirty = false;

        protected:
            DynamicFont();
        
            virtual const Glyph & getGlyph(const uint32_t codepoint) final;

        public:
            virtual ~DynamicFont() final;

            static std::shared_ptr<DynamicFont> load(const std::filesystem::path &path);

            DynamicFont(const DynamicFont &) = delete;
            DynamicFont & operator=(const DynamicFont &) = delete;

            // 3D functions
            virtual void drawLine(const std::u32string &text, const glm::mat4 &mvp, const glm::ivec3 &pos, const glm::ivec3 &dir, const float scale) final;
        };
    };
};