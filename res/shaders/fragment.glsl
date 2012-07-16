#version 130

in vec2 Texcoord;

out vec4 outColor;

uniform sampler2D meh_texture;

void main()
{
        // outColor = texture2D(meh_texture,Texcoord) * vec4( 1.0, 1.0, 1.0, 1.0 );
        outColor = texture2D(meh_texture,Texcoord) * vec4( 1.0, 1.0, 1.0, 1.0 );
}
