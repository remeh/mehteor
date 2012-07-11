#version 130

in vec2 meh_position;

void main()
{
        gl_Position = vec4(meh_position, 0.0, 1.0);
}
