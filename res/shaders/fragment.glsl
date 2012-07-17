#version 130

in vec2 Texcoord;

uniform sampler2D meh_texture;
uniform sampler2D tex;

out vec4 outColor;

void main()
{
        outColor = mix(texture2D(meh_texture,Texcoord) , texture2D(tex, Texcoord), 0.5);
        // outColor = vec4( 1.0, 1.0, 1.0, 1.0 );
}
