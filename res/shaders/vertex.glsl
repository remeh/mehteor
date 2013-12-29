#version 120

attribute vec2 meh_texcoord;
attribute vec3 meh_position;
attribute vec4 meh_tintcolor;

varying vec2 Texcoord;
varying vec4 TintColor;

uniform mat4 meh_modelViewMatrix;

void main()
{
        gl_Position = meh_modelViewMatrix * vec4(meh_position, 1.0);
        TintColor = meh_tintcolor;
        Texcoord = meh_texcoord;
}
