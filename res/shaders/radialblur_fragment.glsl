#version 120
 
// texture coordinates passed from the vertex shader
varying vec2 Texcoord;

uniform sampler2D meh_texture;

// some const, tweak for best look
const float sampleDist = 1.0;
const float sampleStrength = 1.4; 
 
void main(void)
{
    // some sample positions
    float samples[10] =
    float[](-0.08,-0.05,-0.03,-0.02,-0.01,0.01,0.02,0.03,0.05,0.08);

    // 0.5,0.5 is the center of the screen
    // so substracting Texcoord from it will result in
    // a vector pointing to the middle of the screen
    vec2 dir = 0.5 - Texcoord; 

    // calculate the distance to the center of the screen
    float dist = sqrt(dir.x*dir.x + dir.y*dir.y); 

    // normalize the direction (reuse the distance)
    dir = dir/dist; 

    // this is the original colour of this fragment
    // using only this would result in a nonblurred version
    vec4 color = texture2D(meh_texture,Texcoord); 

    vec4 sum = color;

    // take 10 additional blur samples in the direction towards
    // the center of the screen
    for (int i = 0; i < 10; i++)
    {
        sum += texture2D( meh_texture, Texcoord + dir * samples[i] * sampleDist );
    }

    // we have taken eleven samples
    sum *= 1.0/11.0;

    // weighten the blur effect with the distance to the
    // center of the screen ( further out is blurred more)
    float t = dist * sampleStrength;
    t = clamp( t ,0.0,1.0);

    //Blend the original color with the averaged pixels
    gl_FragColor = mix( color, sum, t );
} 
