#include "lighting.glh"

varying highp vec2 texCoord0;
varying highp vec3 normal0;
varying highp vec3 worldPos0;

uniform highp sampler2D diffuse;
uniform SpotLight R_spotLight;

void main()
{
    gl_FragColor = texture2D(diffuse, texCoord0.xy) * CalcSpotLight(R_spotLight, normalize(normal0), worldPos0);
}
