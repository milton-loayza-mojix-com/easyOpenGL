#version 410

out vec4 out_color;
in vec4 color_from_vshader;

void main() {
  out_color = color_from_vshader;
}