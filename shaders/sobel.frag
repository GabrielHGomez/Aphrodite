#version 330 core
out vec4 FragColor;
in vec2 TexCoord;

uniform sampler2D image;

float luma(vec2 uv){
    vec3 c = texture(image, uv).rgb;
    return dot(c, vec3(0.299, 0.587, 0.114));
}

void main()
{
    vec2 texel = 1.0 / vec2(textureSize(image, 0));

    float tl = luma(TexCoord + texel * vec2(-1.0,  1.0));
    float  t = luma(TexCoord + texel * vec2( 0.0,  1.0));
    float tr = luma(TexCoord + texel * vec2( 1.0,  1.0));
    float  l = luma(TexCoord + texel * vec2(-1.0,  0.0));
    float  r = luma(TexCoord + texel * vec2( 1.0,  0.0));
    float bl = luma(TexCoord + texel * vec2(-1.0, -1.0));
    float  b = luma(TexCoord + texel * vec2( 0.0, -1.0));
    float br = luma(TexCoord + texel * vec2( 1.0, -1.0));

    
    float gx = -tl - 2.0*l - bl + tr + 2.0*r + br; 
    float gy = -tl - 2.0*t - tr + bl + 2.0*b + br;   

    float edge = sqrt(gx*gx + gy*gy);

    FragColor = vec4(vec3(edge), 1.0);   
}

