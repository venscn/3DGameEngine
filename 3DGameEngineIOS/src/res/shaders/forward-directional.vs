attribute vec3 position;
attribute vec2 texCoord;
attribute vec3 normal;

varying highp vec2 texCoord0;
varying highp vec3 normal0;
varying highp vec3 worldPos0;

uniform highp mat4 T_model;
uniform highp mat4 T_MVP;

void main()
{
    gl_Position = T_MVP * vec4(position, 1.0);
    texCoord0 = texCoord;
    normal0 = (T_model * vec4(normal, 0.0)).xyz;
    worldPos0 = (T_model * vec4(position, 1.0)).xyz;
}
