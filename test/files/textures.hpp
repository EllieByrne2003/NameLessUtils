#pragma once

// Includes from standard
#include <string>

// Includes from third party libraries
#include <GL/glew.h>
#include <GL/gl.h>

#include <glm/glm.hpp>
using namespace glm;

// Includes from personal libraries


// Includes from project


// Forward declarations


// Type aliases
typedef unsigned int GLuint;

namespace NLUT {
    enum class TextureWrap : GLenum {
        Repeat         = GL_REPEAT,
        ClampToEdge    = GL_CLAMP_TO_EDGE,
        MirroredRepeat = GL_MIRRORED_REPEAT,
        ClampToBorder  = GL_CLAMP_TO_BORDER
    };

    enum class TextureFilter : GLenum {
        NearestTexel              = GL_NEAREST,
        LinearBlend               = GL_LINEAR,
        NearestMipmapNearestTexel = GL_NEAREST_MIPMAP_NEAREST,
        NearestMipmapLinearBlend  = GL_NEAREST_MIPMAP_LINEAR,
        LinearMipmapNearestTexel  = GL_LINEAR_MIPMAP_NEAREST,
        LinearMipmapLinearBlend   = GL_LINEAR_MIPMAP_LINEAR,
    };

    GLuint loadTexture1D(const std::string &path, int &width, int &height, int &nChannels);
    GLuint loadTexture2D(const std::string &path, int &width, int &height, int &nChannels);
    GLuint loadTexture3D(const std::string &path, int &width, int &height, int &nChannels);

    void generateMipMap1D(const GLuint textureID);
    void generateMipMap2D(const GLuint textureID);
    void generateMipMap3D(const GLuint textureID);

    void setFilter1D(const GLuint textureID, const TextureFilter minFilter, const TextureFilter magFilter);
    void setFilter2D(const GLuint textureID, const TextureFilter minFilter, const TextureFilter magFilter);
    void setFilter3D(const GLuint textureID, const TextureFilter minFilter, const TextureFilter magFilter);

    void setWrap1D(const GLuint textureID, const TextureWrap wrapS);
    void setWrap2D(const GLuint textureID, const TextureWrap wrapS, const TextureWrap wrapT);
    void setWrap3D(const GLuint textureID, const TextureWrap wrapS, const TextureWrap wrapT, const TextureWrap wrapR);

    void setAnisotropy1D(const GLuint textureID, const float level);
    void setAnisotropy2D(const GLuint textureID, const float level);
    void setAnisotropy3D(const GLuint textureID, const float level);

    void setLodBias1D(const GLuint textureID, const float bias);
    void setLodBias2D(const GLuint textureID, const float bias);
    void setLodBias3D(const GLuint textureID, const float bias);

    void setBorder1D(const GLuint textureID, const vec4 &colour);
    void setBorder2D(const GLuint textureID, const vec4 &colour);
    void setBorder3D(const GLuint textureID, const vec4 &colour);
};