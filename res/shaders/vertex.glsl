#version 130

in vec2 meh_texcoord;
in vec2 meh_position;

out vec2 Texcoord;

uniform mat4 meh_projViewMatrix;

void main()
{
        Texcoord = meh_texcoord;
        gl_Position = meh_projViewMatrix * vec4(meh_position, 0.0, 1.0);
}
