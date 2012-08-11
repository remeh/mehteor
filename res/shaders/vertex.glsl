#version 120

attribute vec2 meh_texcoord;
attribute vec3 meh_position;

varying vec2 Texcoord;

uniform mat4 meh_modelViewMatrix;

void main()
{
        gl_Position = meh_modelViewMatrix * vec4(meh_position, 1.0);
        Texcoord = meh_texcoord;
}
