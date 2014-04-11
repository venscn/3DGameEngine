#include "lighting.glh"

varying highp vec2 texCoord0;
varying highp vec3 normal0;
varying highp vec3 worldPos0;

uniform highp sampler2D diffuse;
uniform DirectionalLight R_directionalLight;

void main()
{
    gl_FragColor = texture2D(diffuse, texCoord0.xy) * CalcDirectionalLight(R_directionalLight, normalize(normal0), worldPos0);
}
