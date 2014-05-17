static const char* layerrenderer_ps_gl = R"(

varying vec4 vaTexCoord;
varying vec4 vaColor;

uniform sampler2D g_texture;

void main() 
{
	// varying(in) �͕ύX�s��(Radeon)

	// gl only
	vec4 vaTexCoord_ = vaTexCoord;
	vaTexCoord_.y = 1.0 - vaTexCoord_.y;

	gl_FragColor = texture2D(g_texture, vaTexCoord_.xy) * vaColor;
}

)";
