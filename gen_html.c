
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pasuli_cfg.h"
#include "pasuli_desc_parser.h"
#include "cylinder/cylinder.h"

char *head = "<html>\n<head>\n\
<meta charset=\"utf-8\">\n\
<title>Three.js app</title>\n\
<style>\n\
  body { margin: 0; background-color: #CCC; }\n\
</style>\n\n\
<!--<script src=\"three.js\"></script>\n-->";
char *headEnd = "</head>\n<body>\n\n";
char *bodyEnd = "\n</body>\n</html>";
char *scriptStart = "\n<script>\n\n";
char *scriptThreeJS = "\n<script type=\"module\">\n\n\
  import * as THREE from 'https://unpkg.com/three/build/three.module.js';\n\
\n\
  const scene = new THREE.Scene();\n\
  var ratio = window.innerWidth / window.innerHeight;\n\
  const camera = new THREE.PerspectiveCamera( 75, ratio , 0.1, 1000 );\n\
\n\
  const renderer = new THREE.WebGLRenderer();\n\
  renderer.setSize( window.innerWidth, window.innerHeight );\n\
  document.body.appendChild( renderer.domElement );\n\
\n\
const geometry = new THREE.BoxGeometry();\n\
const material = new THREE.MeshBasicMaterial( { color: 0x00ff00 } );\n\
const cube = new THREE.Mesh( geometry, material );\n\
scene.add( cube );\n\
createGeometry(scene)\n\
\
camera.position.z = 5;\n\
\
function animate() {\n\
	requestAnimationFrame( animate );\n\
	renderer.render( scene, camera );\n\
    cube.rotation.x += 0.001;\n\
    cube.rotation.y += 0.02;\n\
}\n\
animate();\n\
";

char *createGeometryFn = "\n\
function createGeometry(scene) {\n\
\n\
  const MAX_POINTS = 500;\n\
  // geometry\n\
  const geometry = new THREE.BufferGeometry();\n\
  // attributes\n\n\
  // 3 vertices per point\n\
  const positions = new Float32Array( MAX_POINTS * 3 );\n\
geometry.setAttribute( 'position', new THREE.BufferAttribute( positions, 3 ) );\n\
\n\
// draw range\n\
const drawCount = 5; // draw the first 2 points, only\n\
geometry.setDrawRange( 0, drawCount );\n\
// material\n\
const material = new THREE.LineBasicMaterial( { color: 0xff0000 } );\n\
\n\
// line\n\
const line = new THREE.Line( geometry,  material );\n\
addPoints(line, MAX_POINTS);\n\
scene.add( line );\n\
return line;\n\
}\n\n\
\n\
\n\
function addPoints(line, maxPoints) {\n\
const positions = line.geometry.attributes.position.array;\n\
\n\
var x=0, y=0, z=0, index=0;\n\
\n\
  for (var i = 0; i < maxPoints; i++ ) {\n\
\n\
    positions[ index++ ] = x;\n\
    positions[ index++ ] = y;\n\
    positions[ index++ ] = z;\n\
\n\
    x += ( Math.random() - 0.5 ) * 2;\n\
    y += ( Math.random() - 0.5 ) * 2;\n\
    z += ( Math.random() - 0.5 ) * 2;\n\
  }\n\
\n\
}\n";

char *scriptEnd = "\n\n</script>\n";

char *writeMode = "w";

PaSuLiFunctionDescription desc;

int createCodeFromDescription(char *name, char *description, char *pResult, int size)
{
    char *tmpl = "function %s() {\n\
    \n}";

    sprintf(pResult, tmpl, name);

    parseDescription(description, &desc);
    printDescription(&desc);

    return 0;
}

#define BUFFER_SIZE 2048
char buffer[BUFFER_SIZE];

int writeToFile(char *path)
{
    FILE *f = fopen(path, "w");
    if (f == 0)
    {
        printf("Failed to open file %s\n", path);
        return -1;
    }

    fwrite(head, 1, strlen(head), f);

    int res = createCodeFromDescription("Cylinder",
                                        descCylinder,
                                        buffer,
                                        BUFFER_SIZE);

    printf("Created html %d\n", res);

    fwrite(scriptStart, 1, strlen(scriptStart), f);

    fwrite(buffer, 1, strlen(buffer), f);

    fwrite(scriptEnd, 1, strlen(scriptEnd), f);

    fwrite(scriptThreeJS, 1, strlen(scriptThreeJS), f);

    fwrite(createGeometryFn, 1, strlen(createGeometryFn), f);

    fwrite(scriptEnd, 1, strlen(scriptEnd), f);

    fwrite(headEnd, 1, strlen(headEnd), f);

    fwrite(bodyEnd, 1, strlen(bodyEnd), f);

    fclose(f);

    return 0;
}

int main()
{
    char *asHtml = "example.html";

    int res = writeToFile(asHtml);

    return 0;
}