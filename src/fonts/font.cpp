#include "font.hpp"

// Includes from standard


// Includes from third party libraries


// Includes from personal libraries


// Includes from project


// Forward declarations


// Type aliases
using namespace glm;

NLUT::Font::Font() {

}

NLUT::Font::~Font() {

}

void NLUT::Font::drawLine(const std::string &text, const mat4 &mvp, const vec2 &pos, const float scale) {
    // TODO need a function to convert from string to u32string
}

void NLUT::Font::drawLine(const std::string &text, const mat4 &mvp, const vec2 &pos, const vec2 &dir, const float scale) {
    // TODO need a function to convert from string to u32string
}

void NLUT::Font::drawLine(const std::u32string &text, const mat4 &mvp, const vec2 &pos, const float scale) {
    drawLine(text, mvp, vec3(pos, 0.0f), scale);
}

void NLUT::Font::drawLine(const std::u32string &text, const mat4 &mvp, const vec2 &pos, const vec2 &dir, const float scale) {
    drawLine(text, mvp, vec3(pos, 0.0f), vec3(dir, 0.0f), scale);
}

void NLUT::Font::drawLine(const std::string &text, const mat4 &mvp, const vec3 &pos, const float scale) {
    // TODO need a function to convert from string to u32string
}

void NLUT::Font::drawLine(const std::string &text, const mat4 &mvp, const vec3 &pos, const vec3 &dir, const float scale) {
    // TODO need a function to convert from string to u32string
}

void NLUT::Font::drawLine(const std::u32string &text, const mat4 &mvp, const vec3 &pos, const float scale) {
    drawLine(text, mvp, pos, vec3(1.0f, 0.0f, 0.0f), scale);
}

// void NLUT::Font::getTextSize(const std::string &text, const float scale, float &width, float &height) {
    
// }

// vec2 NLUT::Font::getTextSize(const std::string &text, const float scale) {

// }

float NLUT::Font::getTextWidth(const std::string &text, const float scale) {

}

// float NLUT::Font::getTextHeight(const std::string &text, const float scale) {

// }

// void NLUT::Font::getTextSize(const std::u32string &text, const float scale, float &width, float &height) {
//     width  = 0;
//     height = 0;

//     for(const uint32_t & codepoint : text) {
//         const vec2 glyphSize = getGlyphSize(codepoint, scale);

//         width  += glyphSize.x;
//         height += glyphSize.y;
//     }
// }

// vec2 NLUT::Font::getTextSize(const std::u32string &text, const float scale) {
//     vec2 size = vec2(0.0f, 0.0f);

//     for(const uint32_t & codepoint : text) {
//         size += getGlyphSize(codepoint, scale);
//     }

//     return size;
// }

float NLUT::Font::getTextWidth(const std::u32string &text, const float scale) {
    int width  = 0;
    int height = 0;

    for(const uint32_t & codepoint : text) {
        const vec2 glyphSize = getGlyphSize(codepoint, scale);

        width  += glyphSize.x;
        height += glyphSize.y;
    }

}

// float NLUT::Font::getTextHeight(const std::u32string &text, const float scale) {
//     width  = 0;
//     height = 0;

//     for(const uint32_t & codepoint : text) {
//         const vec2 glyphSize = getGlyphSize(codepoint, scale);

//         width  += glyphSize.x;
//         height += glyphSize.y;
//     }

//     return height;
// }

// void NLUT::Font::getGlyphSize(const uint32_t codepoint, const float scale, float &width, float &height) {
//     const Glyph &glyph = getGlyph(codepoint);

//     width  = (glyph.pos1.x - glyph.pos0.x) * scale;
//     height = (glyph.pos1.y - glyph.pos0.y) * scale;
// }

// vec2 NLUT::Font::getGlyphSize(const uint32_t codepoint, const float scale) {
//     const Glyph &glyph = getGlyph(codepoint);

//     return (glyph.pos1 - glyph.pos0) * scale;
// }

float NLUT::Font::getGlyphWidth(const uint32_t codepoint, const float scale) {
    const Glyph &glyph = getGlyph(codepoint);

    return (glyph.pos1.x - glyph.pos0.x) * scale;
}

// float NLUT::Font::getGlyphHeight(const uint32_t codepoint, const float scale) {
//     const Glyph &glyph = getGlyph(codepoint);

//     return (glyph.pos1.y - glyph.pos0.y) * scale;
// }

float NLUT::Font::getGlyphAdvance(const uint32_t codepoint, const float scale) {
    return getGlyph(codepoint).advance * scale;
}