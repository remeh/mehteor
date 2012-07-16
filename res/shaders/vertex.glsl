#version 130

in vec2 meh_texcoord;
in vec2 meh_position;

out vec2 Texcoord;

void main()
{
        Texcoord = meh_texcoord;
        gl_Position = vec4(meh_position, 0.0, 1.0);
}
