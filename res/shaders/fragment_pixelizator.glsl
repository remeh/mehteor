#version 120

varying vec2 Texcoord;

varying vec4 TintColor;

uniform sampler2D meh_texture;

void main()
{
    if (!(mod(gl_FragCoord.x, 5) <= 1.0) && !(mod(gl_FragCoord.y, 5) <= 1.0))
    {
        gl_FragColor = texture2D(meh_texture,Texcoord)*TintColor;
    }
    else
    {
        gl_FragColor = texture2D(meh_texture,Texcoord)*TintColor*vec4(0.7f, 0.7f, 0.7f, 1.0f);
    }
}
