#pragma once

// Includes from standard
#include <string>

// Includes from third party libraries
#define GLM_FORCE_EXPLICIT_CTOR
#include <glm/glm.hpp>

// Includes from personal libraries


// Includes from project


// Forward declarations


// Type aliases


// TODO create function prototypes for drawing separate lines (can call upon drawLine ones)
namespace NLUT {
    class Font {
    private:

    protected:
        Font();

        struct Glyph {
            float advance = 0.0f;

            glm::vec2 pos0 = glm::vec2(0.0f); // Bottom left position
            glm::vec2 pos1 = glm::vec2(0.0f); // Top right position

            glm::vec2 uv0  = glm::vec2(0.0f); // Bottom left atlas co-oridinate
            glm::vec2 uv1  = glm::vec2(0.0f); // Top right atlas co-ordinate

            bool isWhitespace = false;
        };
        
        virtual const Glyph & getGlyph(const uint32_t codepoint) = 0;

    public:
        virtual ~Font() = 0;

        Font(const Font &) = delete;
        Font & operator=(const Font &) = delete;

        // 2D functions
        void drawLine(const std::string &text, const glm::mat4 &mvp, const glm::vec2 &pos, const float scale);
        void drawLine(const std::string &text, const glm::mat4 &mvp, const glm::vec2 &pos, const glm::vec2 &dir, const float scale);

        void drawLine(const std::u32string &text, const glm::mat4 &mvp, const glm::vec2 &pos, const float scale);
        void drawLine(const std::u32string &text, const glm::mat4 &mvp, const glm::vec2 &pos, const glm::vec2 &dir, const float scale);

        // 3D functions
        void drawLine(const std::string &text, const glm::mat4 &mvp, const glm::vec3 &pos, const float scale);
        void drawLine(const std::string &text, const glm::mat4 &mvp, const glm::vec3 &pos, const glm::vec3 &dir, const float scale);

        void drawLine(const std::u32string &text, const glm::mat4 &mvp, const glm::vec3 &pos, const float scale);

        // Single function all other drawLines can be defined in terms of
        // virtual void drawLine(const std::u32string &text, const glm::mat4 &mvp, const glm::vec3 &pos, const glm::vec3 &dir, const float scale) = 0;

        // Text size functions
        void getTextSize(const std::string &text, const float scale, float &width, float &height);
        glm::vec2 getTextSize(const std::string &text, const float scale);
        float getTextWidth(const std::string &text, const float scale);
        float getTextHeight(const std::string &text, const float scale);

        void getTextSize(const std::u32string &text, const float scale, float &width, float &height);
        glm::vec2 getTextSize(const std::u32string &text, const float scale);
        float getTextWidth(const std::u32string &text, const float scale);
        float getTextHeight(const std::u32string &text, const float scale);

        // Glyph size functions // TODO height should just be line height, not glyph specific, some should be hidden from users too, maybe all glyph ones
        void getGlyphSize(const uint32_t codepoint, const float scale, float &width, float &height);
        glm::vec2 getGlyphSize(const uint32_t codepoint, const float scale);
        float getGlyphWidth(const uint32_t codepoint, const float scale);
        float getGlyphHeight(const uint32_t codepoint, const float scale);

        float getGlyphAdvance(const uint32_t codepoint, const float scale);
    };
};