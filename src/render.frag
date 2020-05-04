#version 150

// dolson,2019

uniform vec3 u_light_pos;
uniform vec4 u_color;

out vec4 out_FragColor; 

in vec4 vPos;
in vec3 vNormal;

void main() {
 
vec4 color = u_color;

vec3 lig_dir = normalize(u_light_pos - vPos.xyz);      
float d = max(.4,dot(vNormal,lig_dir));
out_FragColor = vec4(vec3(color) * vec3(d),1.0);

}
