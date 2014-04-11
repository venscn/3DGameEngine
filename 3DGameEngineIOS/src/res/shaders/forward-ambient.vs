attribute vec3 position;
attribute vec2 texCoord;

varying highp vec2 texCoord0;

uniform highp mat4 T_MVP;

void main()
{
    gl_Position = T_MVP * vec4(position, 1.0);
    texCoord0 = texCoord;
}
