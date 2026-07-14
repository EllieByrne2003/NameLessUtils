#include "textures.hpp"

// Includes from standard


// Includes from third party libraries
#define STB_IMAGE_IMPLEMENTATION
#include "../../lib/stb_image.h"

// Includes from personal libraries


// Includes from project


// Forward declarations


// Type aliases


GLuint NLUT::loadTexture1D(const std::string &path, int &width, int &height, int &nChannels) {
    // TODO implement

    return 0;
}

GLuint NLUT::loadTexture2D(const std::string &path, int &width, int &height, int &nChannels) {
    // Create texture
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // TODO should support more filetypes (stbi isn't inclusive)
    // TODO need check that filetype is supported
    // Load data
    unsigned char *data = stbi_load(path.c_str(), &width, &height, &nChannels, 0);
    if(data == nullptr) {
        glDeleteTextures(1, &textureID);

        return 0;
    }

    // Send data across
    if(nChannels == 4) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

        stbi_image_free(data);
    } else if(nChannels == 3) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

        stbi_image_free(data);
    } else if(nChannels == 1) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, width, height, 0, GL_RED, GL_UNSIGNED_BYTE, data);

        stbi_image_free(data);
    } else {
        stbi_image_free(data);
        glDeleteTextures(1, &textureID);

        // TODO log unsupported channel number

        return 0;
    }

    // Return texture
    return textureID;
}

GLuint NLUT::loadTexture3D(const std::string &path, int &width, int &height, int &nChannels) {
    // TODO implement
    
    return 0;
}

void NLUT::generateMipMap1D(const GLuint textureID) {
    // Bind texture
    glBindTexture(GL_TEXTURE_1D, textureID);

    glGenerateMipmap(GL_TEXTURE_1D);
}

void NLUT::generateMipMap2D(const GLuint textureID) {
    // Bind texture
    glBindTexture(GL_TEXTURE_2D, textureID);

    glGenerateMipmap(GL_TEXTURE_2D);
}

void NLUT::generateMipMap3D(const GLuint textureID) {
    // Bind texture
    glBindTexture(GL_TEXTURE_3D, textureID);

    glGenerateMipmap(GL_TEXTURE_3D);
}

void NLUT::setFilter1D(const GLuint textureID, const TextureFilter minFilter, const TextureFilter magFilter) {
    // Bind texture
    glBindTexture(GL_TEXTURE_1D, textureID);

    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, static_cast<GLenum>(minFilter));
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, static_cast<GLenum>(minFilter));
}

void NLUT::setFilter2D(const GLuint textureID, const TextureFilter minFilter, const TextureFilter magFilter) {
    // Bind texture
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, static_cast<GLenum>(minFilter));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, static_cast<GLenum>(magFilter));  
}

void NLUT::setFilter3D(const GLuint textureID, const TextureFilter minFilter, const TextureFilter magFilter) {
    // Bind texture
    glBindTexture(GL_TEXTURE_3D, textureID);

    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, static_cast<GLenum>(minFilter));
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, static_cast<GLenum>(minFilter));
}

void NLUT::setWrap1D(const GLuint textureID, const TextureWrap wrapS) {
    // Bind texture
    glBindTexture(GL_TEXTURE_1D, textureID);

    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, static_cast<GLenum>(wrapS));
}

void NLUT::setWrap2D(const GLuint textureID, const TextureWrap wrapS, const TextureWrap wrapT) {
    // Bind texture
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, static_cast<GLenum>(wrapS));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, static_cast<GLenum>(wrapT));
}

void NLUT::setWrap3D(const GLuint textureID, const TextureWrap wrapS, const TextureWrap wrapT, const TextureWrap wrapR) {
    // Bind texture
    glBindTexture(GL_TEXTURE_3D, textureID);

    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, static_cast<GLenum>(wrapS));
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, static_cast<GLenum>(wrapT));
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, static_cast<GLenum>(wrapR));
}

void NLUT::setAnisotropy1D(const GLuint textureID, const float level) {
    if(GLEW_EXT_texture_filter_anisotropic) {
        // Bind texture
        glBindTexture(GL_TEXTURE_1D, textureID);
        
        glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_MAX_ANISOTROPY, level);
    }
}

void NLUT::setAnisotropy2D(const GLuint textureID, const float level) {
    if(GLEW_EXT_texture_filter_anisotropic) {
        // Bind texture
        glBindTexture(GL_TEXTURE_2D, textureID);
        
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY, level);
    }
}

void NLUT::setAnisotropy3D(const GLuint textureID, const float level) {
    if(GLEW_EXT_texture_filter_anisotropic) {
        // Bind texture
        glBindTexture(GL_TEXTURE_3D, textureID);
        
        glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_MAX_ANISOTROPY, level);
    }
}

void NLUT::setLodBias1D(const GLuint textureID, const float bias) {
    // Bind texture
    glBindTexture(GL_TEXTURE_1D, textureID);

    glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_LOD_BIAS, bias);
}

void NLUT::setLodBias2D(const GLuint textureID, const float bias) {
    // Bind texture
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_LOD_BIAS, bias);
}

void NLUT::setLodBias3D(const GLuint textureID, const float bias) {
    // Bind texture
    glBindTexture(GL_TEXTURE_3D, textureID);

    glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_LOD_BIAS, bias);
}

void NLUT::setBorder1D(const GLuint textureID, const vec4 &colour) {
    // Bind texture
    glBindTexture(GL_TEXTURE_1D, textureID);

    glTexParameterfv(GL_TEXTURE_1D, GL_TEXTURE_BORDER_COLOR, &colour[0]);
}

void NLUT::setBorder2D(const GLuint textureID, const vec4 &colour) {
    // Bind texture
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, &colour[0]);
}

void NLUT::setBorder3D(const GLuint textureID, const vec4 &colour) {
    // Bind texture
    glBindTexture(GL_TEXTURE_3D, textureID);

    glTexParameterfv(GL_TEXTURE_3D, GL_TEXTURE_BORDER_COLOR, &colour[0]);
}