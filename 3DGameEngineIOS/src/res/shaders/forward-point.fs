#include "lighting.glh"

varying highp vec2 texCoord0;
varying highp vec3 normal0;
varying highp vec3 worldPos0;

uniform highp sampler2D diffuse;
uniform PointLight R_pointLight;

void main()
{
    gl_FragColor = texture2D(diffuse, texCoord0.xy) * CalcPointLight(R_pointLight, normalize(normal0), worldPos0);
}
