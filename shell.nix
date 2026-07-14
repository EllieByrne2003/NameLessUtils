{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
    buildInputs = with pkgs; [
        git
        gcc
        gdb
        gnumake
        bear

        libGL
        glfw
        glew
        glm
        nlohmann_json
    ];
}