#version 130

in vec2 Texcoord;

uniform sampler2D meh_texture;

void main()
{
        gl_FragColor = texture2D(meh_texture,Texcoord);
}
