#version 330

in vec3 Color;

uniform vec3 SolidColor = vec3(-1,-1,-1);
uniform int complimentary = 0;

out vec4 Fragment;

void main()
{
	if(complimentary == 1)
	{
		Fragment = vec4(1.0 - Color,1);
	}
	else
	{
		if(SolidColor.r != -1.0 && SolidColor.g != -1.0 && SolidColor.b != -1.0)
		{
			Fragment = vec4(SolidColor, 1);
		}
		else
			Fragment = vec4(Color,1);
	}

	return;
}