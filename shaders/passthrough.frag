// passthrough.frag — the simplest shader the playground will accept.
// Use this as your starting template when building a new effect.

#version 330 core

in  vec2 uv;
out vec4 fragColor;

uniform sampler2D image;

void main() {
    fragColor = texture(image, uv);
}
