#version 120

attribute vec2 meh_texcoord;
attribute vec3 meh_position;

varying vec2 Texcoord;

uniform mat4 meh_modelViewMatrix;

// this vertex shader is from AMD RenderMonkey
void main(void)
{
    gl_Position = meh_modelViewMatrix*vec4( meh_position, 1.0 );

    // Texture coordinate for screen aligned (in correct range):
    // Texcoord = (vec2( gl_Position.x, - gl_Position.y ) + vec2( 1.0 ) ) / vec2( 2.0 );
    Texcoord = meh_texcoord;
}
