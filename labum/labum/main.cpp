#include <stdlib.h>
#include <crtdbg.h>
#include "GameManager.h"
#include "Header.h"



GameManager* game_manager = NULL;


void myReshape(GLsizei w, GLsizei h) {
	if (game_manager) 
		game_manager->reshape(w, h);

}

void keyboard(unsigned char key, int x, int y)
{
	if (game_manager)
		game_manager->keypressed(key, x, y);
}

void keyboardUP(unsigned char key, int x, int y)
{
	if (game_manager)
		game_manager->keyUp(key, x, y);
}


void onIdle(){
	if (game_manager)
		game_manager->update();
}

void myDisplay(void) {
	if (game_manager)
		game_manager->display();
}

void update(int value){
	game_manager->update();
	glutPostRedisplay();
	glutTimerFunc(10, update, 0);
}
void mouse(int button, int state, int x, int y)
{
	game_manager->ReadMouse(button, state, x, y);
}
void mouseMotion(int x, int y)
{
	game_manager->ReadMouseMotion(x, y);
}

void AppSpecialKeys(int key, int x, int y)
{
	game_manager->ReadSpecialKeyboard(key, x, y);
}

void fnExit1(void)
{
	if (game_manager)
		delete(game_manager);
	if (_DEBUG){
		_CrtMemState s1;
		_CrtMemCheckpoint(&s1);
		_CrtMemDumpStatistics(&s1);
		_CrtDumpMemoryLeaks();
	}
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(-1, -1);

	glutCreateWindow("Teste");
	//glutFullScreen();
	//Make the default cursor disappear
	glutSetCursor(GLUT_CURSOR_NONE);
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardUP);
	glutSpecialFunc(AppSpecialKeys);
	
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutPassiveMotionFunc(mouseMotion);
	
	glutTimerFunc(50, update, 0);
	game_manager = new GameManager();
	game_manager->init();
	atexit(fnExit1);
	glutMainLoop();
	
	


	return 0;
}



