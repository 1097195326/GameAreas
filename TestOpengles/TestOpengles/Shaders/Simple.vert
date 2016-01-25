const char * SimpleVertexShader = STRINGIFY
(
 attribute vec4 Position;
 attribute vec4 SourceColor;
 attribute vec2 TextureCoord;
 
 uniform mat4 Projection;
 uniform mat4 ModelView;
 
 varying vec4 DestinationColor;
 varying vec2 TextureCoordOut;
 
 void main(void)
 {
     DestinationColor = SourceColor;
     gl_Position = Projection * ModelView * Position;
     TextureCoordOut = TextureCoord;
 }
);