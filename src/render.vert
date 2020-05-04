#version 150

// dolson,2019

uniform mat4 modelViewProjectionMatrix;

in vec4 position;
in vec4 normal;
  
out vec4 vPos;
out vec3 vNormal;

float sustain(float x,float f,float k) {
float s = max(x-f,0.);
return min(x*x/(f*f),1+(2./f) * s * exp(-k*s)); 
}

void main() {
 
vec4 pos = modelViewProjectionMatrix * position;

vNormal = normal.xyz;
vPos = position;

pos.y += sin(pos.x) * sustain(pos.x,45.,.5) * 15.;

gl_Position = pos;


}
