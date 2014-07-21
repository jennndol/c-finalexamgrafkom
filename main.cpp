#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/GLAux.h>
#include <GL/gl.h>
#include "imageloader.h"
#include "vec3f.h"

static GLfloat spin, spin2 = 0.0;
float angle = 0;
using namespace std;
float lastx, lasty;
GLint stencilBits;
static int viewx = -110;
static int viewy = 40;
static int viewz =160;
float rot = 0;

void initRendering() {//inisialisasi
	glEnable(GL_DEPTH_TEST);//kedalaman
	glEnable(GL_COLOR_MATERIAL);//warna
	glEnable(GL_LIGHTING);//cahaya
	glEnable(GL_LIGHT0);//lampu
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
}

const GLfloat light_ambient[] = { 0.3f, 0.3f, 0.3f, 1.0f };
const GLfloat light_diffuse[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_ambient2[] = { 0.3f, 0.3f, 0.3f, 0.0f };
const GLfloat light_diffuse2[] = { 0.3f, 0.3f, 0.3f, 0.0f };
const GLfloat mat_ambient[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void toko(void) {

    //Lantai Halaman
    glPushMatrix();
    glScaled(5.0, 0.0, 4.7);
    glTranslatef(0.0, 0.0, 0.0);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

    glColor3f(0.3402, 0.3412, 0.3117);
    glutSolidCube(5.0);
    glPopMatrix();

    //Atap
    glPushMatrix();
    glScaled(1.015, 0.03, 1.8);
    glTranslatef(0.0,160, 0.3);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3f(0.3402, 0.3412, 0.3117);
    glutSolidCube(5.0);
    glPopMatrix();

  //Dinding Kiri Bawah
    glPushMatrix();
    glScaled(0.035, 0.5, 1.6);
    glTranslatef(-70.0, 2.45, 0.0);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3f(0.4613, 0.4627, 0.4174);
    glutSolidCube(5.0);
    glPopMatrix();

    //Pembatas Bawah
    glPushMatrix();
    glScaled(0.035, 0.5, 1.6);
    glTranslatef(-75.0, 2.45, 0.4);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3f(0.3400, 0.3400, 0.3400);
    glutSolidCube(5.0);
    glPopMatrix();
    //Pembatas Atas
    glPushMatrix();
    glScaled(0.035, 0.5, 1.6);
    glTranslatef(-75.0, 7.45, 0.2);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3f(0.3400, 0.3400, 0.3400);
    glutSolidCube(5.0);
    glPopMatrix();

  //Dinding Kanan Bawah
    glPushMatrix();
    glScaled(0.035, 0.5, 1.6);
    glTranslatef(70.0, 2.45, 0.0);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3f(0.4613, 0.4627, 0.4174);
    glutSolidCube(5.0);
    glPopMatrix();

//Dinding Kiri Atas
    glPushMatrix();
    glScaled(0.035, 0.5, 1.6);
    glTranslatef(-70.0, 7.45, 0.0);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3f(0.4613, 0.4627, 0.4174);
    glutSolidCube(5.0);
    glPopMatrix();

//Dinding Kanan Atas
    glPushMatrix();
    glScaled(0.035, 0.5, 1.6);
    glTranslatef(70.0, 7.45, 0.0);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3f(0.4613, 0.4627, 0.4174);
    glutSolidCube(5.0);
    glPopMatrix();

  //Dinding Belakang bawah
    glPushMatrix();
    glScaled(1.015, 0.5, 0.07);
    glTranslatef(0, 2.45,-58);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3f(0.4613, 0.4627, 0.4174);
    glutSolidCube(5.0);
    glPopMatrix();

  //Dinding Belakang atas
    glPushMatrix();
    glScaled(1.015, 0.5, 0.07);
    glTranslatef(0, 7.45,-58);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3f(0.4613, 0.4627, 0.4174);
    glutSolidCube(5.0);
    glPopMatrix();

  //Dinding Depan bawah
    glPushMatrix();
    glScaled(1.015, 0.5, 0.035);
    glTranslatef(0, 2.45,116);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3f(0.4613, 0.4627, 0.4174);
    glutSolidCube(5.0);
    glPopMatrix();

  //Dinding Depan atas
    glPushMatrix();
    glScaled(1.015, 0.5, 0.035);
    glTranslatef(0, 7.45,116);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3f(0.4613, 0.4627, 0.4174);
    glutSolidCube(5.0);
    glPopMatrix();

  //Kaca
    glPushMatrix();
    glScaled(0.35, 0.43, 0.035);
   glTranslatef(1, 3.5,124);
   glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3f(0.1412, 0.1389, 0.1356);
    glutSolidCube(5.0);
    glPopMatrix();

  //Pintu
    glPushMatrix();
    glScaled(0.18, 0.35, 0.035);
   glTranslatef(-8, 2.5,118);
   glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3f(0.0980, 0.0608, 0.0077);
    glutSolidCube(5.0);
    glPopMatrix();

   //note
    glPushMatrix();
    glScaled(0.18, 0.35, 0.035);
   glTranslatef(-4, 4.5,118);
   glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3f(0.0980, 0.0608, 0.0077);
    glutSolidCube(1.0);
    glPopMatrix();

    //lampu kanan atas
    glPushMatrix();
    glScaled(0.05, 0.05, 0.05);
    glTranslatef(34.5, 95.4, 96);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE); //untuk memunculkan warna
    glColor3ub(252, 243, 169);
    glutSolidSphere(2.0,20,50);
    glPopMatrix();

    //lampu kiri atas
    glPushMatrix();
    glScaled(0.05, 0.05, 0.05);
    glTranslatef(-34.5, 95.4, 96);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE); //untuk memunculkan warna
    glColor3ub(252, 243, 169);
    glutSolidSphere(2.0,20,50);
    glPopMatrix();

    //lampu kiri atas
    glPushMatrix();
    glScaled(0.05, 0.05, 0.05);
    glTranslatef(-32.5, 47, 90);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3ub(0, 0, 0);
    glutSolidSphere(2.0,20,50);
    glPopMatrix();
}

void toko2(void) {
    //Lantai Halaman
    glPushMatrix();
    glScaled(5.0, 0.0, 4.7);
    glTranslatef(0.0, 0.0, 0.0);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3f(0.3402, 0.3412, 0.3117);
    glutSolidCube(5.0);
    glPopMatrix();
    //ATAP
    glPushMatrix();
    glScaled(1.015, 0.03, 1.8);
    glTranslatef(0.0,160, 0.3);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3f(0.3402, 0.3412, 0.3117);
    glutSolidCube(5.0);
    glPopMatrix();

  //Dinding Kiri Bawah
    glPushMatrix();
    glScaled(0.035, 0.5, 1.6);
    glTranslatef(-70.0, 2.45, 0.0);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3f(0.4613, 0.4627, 0.4174);
    glutSolidCube(5.0);
    glPopMatrix();

  //Dinding Kanan Bawah
    glPushMatrix();
    glScaled(0.035, 0.5, 1.6);
    glTranslatef(70.0, 2.45, 0.0);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3f(0.4613, 0.4627, 0.4174);
    glutSolidCube(5.0);
    glPopMatrix();

//Dinding Kiri Atas
    glPushMatrix();
    glScaled(0.035, 0.5, 1.6);
    glTranslatef(-70.0, 7.45, 0.0);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3f(0.4613, 0.4627, 0.4174);
    glutSolidCube(5.0);
    glPopMatrix();

//Dinding Kanan Atas
    glPushMatrix();
    glScaled(0.035, 0.5, 1.6);
    glTranslatef(70.0, 7.45, 0.0);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3f(0.4613, 0.4627, 0.4174);
    glutSolidCube(5.0);
    glPopMatrix();

  //Dinding Belakang bawah
    glPushMatrix();
    glScaled(1.015, 0.5, 0.07);
    glTranslatef(0, 2.45,-58);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3f(0.4613, 0.4627, 0.4174);
    glutSolidCube(5.0);
    glPopMatrix();

  //Dinding Belakang atas
    glPushMatrix();
    glScaled(1.015, 0.5, 0.07);
    glTranslatef(0, 7.45,-58);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3f(0.4613, 0.4627, 0.4174);
    glutSolidCube(5.0);
    glPopMatrix();

  //Dinding Depan bawah
    glPushMatrix();
    glScaled(1.015, 0.5, 0.035);
    glTranslatef(0, 2.45,116);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3f(0.4613, 0.4627, 0.4174);
    glutSolidCube(5.0);
    glPopMatrix();

  //Dinding Depan atas
    glPushMatrix();
    glScaled(1.015, 0.5, 0.035);
    glTranslatef(0, 7.45,116);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3f(0.4613, 0.4627, 0.4174);
    glutSolidCube(5.0);
    glPopMatrix();

    //lampu kanan atas
    glPushMatrix();
    glScaled(0.05, 0.05, 0.05);
    glTranslatef(34.5, 95.4, 96);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE); //untuk memunculkan warna
    glColor3ub(252, 243, 169);
    glutSolidSphere(2.0,20,50);
    glPopMatrix();

    //lampu kiri atas
    glPushMatrix();
    glScaled(0.05, 0.05, 0.05);
    glTranslatef(-34.5, 95.4, 96);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE); //untuk memunculkan warna
    glColor3ub(252, 243, 169);
    glutSolidSphere(2.0,20,50);
    glPopMatrix();

    //lampu kiri atas
    glPushMatrix();
    glScaled(0.05, 0.05, 0.05);
    glTranslatef(-32.5, 47, 90);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3ub(0, 0, 0);
    glutSolidSphere(2.0,20,50);
    glPopMatrix();
}

void display(void){
//    glutSwapBuffers();
	glClearStencil(0); //clear the stencil buffer
	glClearDepth(1.0f);

	glClearColor(0.0, 0.6, 0.8, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glLoadIdentity();//reset posisi
	gluLookAt(viewx, viewy, viewz, 0.0, 0.0, -100.0, 0.0, 1.0, 0.0);

    //Toko Besar 1
    glPushMatrix();
    glTranslatef(0,5,-10);
    glScalef(20, 20, 20);
    toko();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-100,5,-10);
    glScalef(20, 20, 20);
    toko2();
    glPopMatrix();

    //Toko Besar 2
    glPushMatrix();
    glTranslatef(-200,5,-10);
    glScalef(20, 20, 20);
    toko();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-300,5,-10);
    glScalef(20, 20, 20);
    toko2();
    glPopMatrix();

    //Toko Kecil
    glPushMatrix();
    glTranslatef(-400,5,-10);
    glScalef(20, 20, 20);
    toko();
    glPopMatrix();

    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); //disable the color mask
	glDepthMask(GL_FALSE); //disable the depth mask
    glEnable(GL_STENCIL_TEST); //enable the stencil testing
    glStencilFunc(GL_ALWAYS, 1, 0xFFFFFFFF);
	glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE); //set the stencil buffer to replace our next lot of data
    //tanah(); //set the data plane to be replaced
	glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE); //enable the color mask
	glDepthMask(GL_TRUE); //enable the depth mask
    glStencilFunc(GL_EQUAL, 1, 0xFFFFFFFF);
	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP); //set the stencil buffer to keep our next lot of data
    glDisable(GL_DEPTH_TEST); //disable depth testing of the reflection
	// glPopMatrix();
	glEnable(GL_DEPTH_TEST); //enable the depth testing
	glDisable(GL_STENCIL_TEST); //disable the stencil testing
	//end of ground
	glEnable(GL_BLEND); //enable alpha blending
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //set the blending function
	glRotated(1, 0, 0, 0);
	glDisable(GL_BLEND);
    glutSwapBuffers();//buffeer ke memory
	glFlush();//memaksa untuk menampilkan
	rot++;
	angle++;
//glDisable(GL_COLOR_MATERIAL);
}

    void init(void){
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = {50.0};
    GLfloat light_position[] = {1.0, 1.0, 1.0, 1.0};
    glClearColor(0.0,0.0,0.0,0.0);
    //glShadeModel(GL_FLAT);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LESS);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    initRendering();


	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);


}

void reshape(int w, int h){
glViewport(0, 0 , (GLsizei) w,(GLsizei)h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
//glFrustum(-1.0,1.0,-1.0,1.0,1.5,20.0);
gluPerspective(60, (GLfloat) w / (GLfloat) h, 0.1, 1000.0);
glMatrixMode(GL_MODELVIEW);
//glLoadIdentity();
//gluLookAt(100.0,0.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
}

static void kibor(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_HOME:
		viewy++;
		break;
	case GLUT_KEY_END:
		viewy--;
		break;
	case GLUT_KEY_UP:
		viewz--;
		break;
	case GLUT_KEY_DOWN:
		viewz++;
		break;
	case GLUT_KEY_RIGHT:
		viewx++;
		break;
	case GLUT_KEY_LEFT:
		viewx--;
		break;
	case GLUT_KEY_F1: {
		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	}
		;
		break;
	case GLUT_KEY_F2: {
		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient2); //untuk lighting
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse2);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	}
		;
		break;
	default:
		break;
	}
}

void keyboard(unsigned char key, int x, int y) {
	if (key == 'q') {
		viewz++;
	}
	if (key == 'e') {
		viewz--;
	}
	if (key == 's') {
		viewy--;
	}
	if (key == 'w') {
		viewy++;
	}
}

int main(int argc, char** argv){
glutInit(&argc, argv);
//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_STENCIL | GLUT_DEPTH); //add a stencil buffer to the window
glutInitWindowSize(800,600);
glutInitWindowPosition(100,100);
glutCreateWindow("Toko");
init();
glutDisplayFunc(display);
glutIdleFunc(display);
glutReshapeFunc(reshape);
glutKeyboardFunc (keyboard);
glutSpecialFunc(kibor);
glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
glLightfv(GL_LIGHT0, GL_POSITION, light_position);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glColorMaterial(GL_FRONT, GL_DIFFUSE);
glutMainLoop();
return 0;
}
