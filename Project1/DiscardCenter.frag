#version 330

in vec3 InterpolatedColor;

out vec4 FragColor;

void main(){
	vec2 pixelPositionInWindow = gl_FragCoord.xy;
	if(pixelPositionInWindow.x > 200 && pixelPositionInWindow.y < 200){
		discard;
	} else{
		FragColor = vec4(InterpolatedColor, 1.0f);
	}
}