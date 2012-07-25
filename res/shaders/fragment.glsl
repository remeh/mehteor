#version 130

in vec2 Texcoord;

uniform sampler2D meh_texture;
uniform sampler2D tex;

out vec4 outColor;

const float blurSize = 10.0/512.0;

void main()
{
        outColor = texture2D(meh_texture,Texcoord);
        // outColor = mix(texture2D(meh_texture,Texcoord) , texture2D(tex, Texcoord), 0.5);

        // blur test
        /*
        vec4 sum = vec4(0.0);
        sum += texture2D(meh_texture, vec2(Texcoord.x - 4.0*blurSize, Texcoord.y)) * 0.05;
        sum += texture2D(meh_texture, vec2(Texcoord.x - 3.0*blurSize, Texcoord.y)) * 0.09;
        sum += texture2D(meh_texture, vec2(Texcoord.x - 2.0*blurSize, Texcoord.y)) * 0.12;
        sum += texture2D(meh_texture, vec2(Texcoord.x - blurSize, Texcoord.y)) * 0.15;
        sum += texture2D(meh_texture, vec2(Texcoord.x, Texcoord.y)) * 0.16;
        sum += texture2D(meh_texture, vec2(Texcoord.x + blurSize, Texcoord.y)) * 0.15;
        sum += texture2D(meh_texture, vec2(Texcoord.x + 2.0*blurSize, Texcoord.y)) * 0.12;
        sum += texture2D(meh_texture, vec2(Texcoord.x + 3.0*blurSize, Texcoord.y)) * 0.09;
        sum += texture2D(meh_texture, vec2(Texcoord.x + 4.0*blurSize, Texcoord.y)) * 0.05;
        outColor = sum;
        */
}
