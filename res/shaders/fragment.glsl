#version 120

varying vec2 Texcoord;

varying vec4 TintColor;

uniform sampler2D meh_texture;

void main()
{
        gl_FragColor = texture2D(meh_texture,Texcoord)*TintColor;
}
