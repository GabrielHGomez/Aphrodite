#version 330
out vec4 FragColor;
in vec2 TexCoord;

uniform sampler2D image;

void main()
{
  vec4 c = texture(image, TexCoord);
  float grey = dot(c.rgb, vec3(0.299, 0.589, 0.114));
  FragColor = vec4(vec3(grey), c.a);
}
