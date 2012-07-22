#version 130

in vec2 meh_texcoord;
in vec3 meh_position;

out vec2 Texcoord;

uniform mat4 meh_modelViewMatrix;

void main()
{
        // Vertex position
        gl_Position = meh_modelViewMatrix * vec4(meh_position, 1.0);
        //gl_Position = vec4(meh_position, 1.0);

        // Texture coordinate
        Texcoord = meh_texcoord;
}
