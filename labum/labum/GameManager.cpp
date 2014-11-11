#include "GameManager.h"

//Alterar Velocidade do Sapo
#define FROG_SPEED 0.008f
/*
GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 0.2 };
GLfloat light_diffuse[] = { 0.08, 0.08, 0.08, 0.0 };
GLfloat light_specular[] = { 0.4, 0.1, 0.4, 0.4 };
 GLfloat light_position[] = { 0.0f, -0.96f, 0.4f, 3.0f };
 GLfloat spot_direction[] = { 0.0f, 0.0f, 2 };
 GLfloat emission[] = { 0.0, 0.8, 0.1, 1.0 };
 */
GameManager::GameManager()
{
	//glEnable(GL_DEPTH_TEST);
	//Graphics initialization

	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glShadeModel(GL_SMOOTH); //set the shader to smooth shader
	/*
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 35);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 0.0);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

	glEnable(GL_CULL_FACE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	*/
	for (int i = 0; i < OBJECT_COUNT; i++)
		_game_objects[i] = NULL;
	
	for (int i = 0; i < CAMERA_COUNT; i++)
		_camera[i] = NULL;


	_frog = NULL;

	for (int c = 0; c < 2; c++)
	{
		_cars[c] = NULL;
	}
}


GameManager::~GameManager(void)
{
	for (int i = 0; i < OBJECT_COUNT; i++)
		if (_game_objects[i]) 
			delete (_game_objects[i]);

	for (int i = 0; i < CAMERA_COUNT; i++)
		if (_camera[i]) 
			delete (_camera[i]);
}
	

void GameManager::init(void)
{
	
	int obj = 0;
	_keypressed = 0;
	_spawntimeCar = 0;
	_time = glutGet(GLUT_ELAPSED_TIME);
	_screenWidth = SCREEN_HEIGHT;
	_screenHeight = SCREEN_WIDTH;
	_model.load();
	srand(time(NULL));
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	_game_objects[obj++] =  new Road(Vector3(0.0f, -.5f, 0.0f));
	_game_objects[obj++] = _river =  new River(Vector3(0.0f, .55f, -0.05f));
	_game_objects[obj++] = new Roadside(Vector3(0.0f, -0.95f, 0.0f));
	//_game_objects[3] = new Roadside(Vector3(0.0f, 0.1f, 0.0f));
	_game_objects[obj++] = new RiverRoad(Vector3(0.0f, 0.0f, 0.0f));
	_game_objects[obj++] = new Riverside(Vector3(0.0f, 0.9f, -0.03f));
	_game_objects[obj++] = new FinalFlower(Vector3(0.0f, 0.9f, -0.03f));

	//turtle
	_game_objects[obj++] = _turt[0] = _turt_line[0][0] = new dyTurtle(Vector3(-0.73f, 0.25f, -0.045f));
	_game_objects[obj++] = _turt[1] = _turt_line[0][1] = new dyTurtle(Vector3(-0.73f, 0.45f, -0.045f));
	_game_objects[obj++] = _turt[2] = _turt_line[0][2] = new dyTurtle(Vector3(-0.73f, 0.65f, -0.045f));
	
	//Logs
	_game_objects[obj++] = _logs[0] = _logs_line[0][0] = new dyLog(Vector3(0.9f, 0.15f, -0.045f));
	_game_objects[obj++] = _logs[1] = _logs_line[0][1] = new dyLog(Vector3(0.9f, 0.35f, -0.045f));
	_game_objects[obj++] = _logs[2] = _logs_line[0][2] = new dyLog(Vector3(0.9f, 0.55f, -0.045f));
	_game_objects[obj++] = _logs[3] = _logs_line[0][3] = new dyLog(Vector3(0.9f, 0.75f, -0.045f));

	_game_objects[obj++] = _logs[4] = _logs_line[1][0] = new dyLog(Vector3(0.9f, 0.15f, -0.045f));
	_game_objects[obj++] = _logs[5] = _logs_line[1][1] = new dyLog(Vector3(0.9f, 0.35f, -0.045f));
	_game_objects[obj++] = _logs[6] = _logs_line[1][2] = new dyLog(Vector3(0.9f, 0.55f, -0.045f));
	_game_objects[obj++] = _logs[7] = _logs_line[1][3] = new dyLog(Vector3(0.9f, 0.75f, -0.045f));

	_game_objects[obj++] = _logs[8] = _logs_line[2][0] = new dyLog(Vector3(0.9f, 0.15f, -0.045f));
	_game_objects[obj++] = _logs[9] = _logs_line[2][1] = new dyLog(Vector3(0.9f, 0.35f, -0.045f));
	_game_objects[obj++] = _logs[10] = _logs_line[2][2] = new dyLog(Vector3(0.9f, 0.55f, -0.045f));
	_game_objects[obj++] = _logs[11] = _logs_line[2][3] = new dyLog(Vector3(0.9f, 0.75f, -0.045f));

	_game_objects[obj++] = _frog = new dyFrog(Vector3(0.0f, -0.96f, 0.03f));

	//Upline car
	_game_objects[obj++] = _cars[0] = _cars_line[0][0] = new dyCar(Vector3(0.92f, -0.2f, 0.04f));
	_game_objects[obj++] = _cars[1] = _cars_line[0][1] = new dyCar(Vector3(0.92f, -0.6f, 0.04f));
	_game_objects[obj++] = _cars[2] = _cars_line[0][2] = new dyCar(Vector3(0.92f, -0.2f, 0.04f));
	_game_objects[obj++] = _cars[3] = _cars_line[0][3] = new dyCar(Vector3(0.92f, -0.6f, 0.04f));
	//Downline car
	_game_objects[obj++] = _cars[4] = _cars_line[1][0] = new dyCar(Vector3(0.92f, -0.2f, 0.04f));
	_game_objects[obj++] = _cars[5] = _cars_line[1][1] = new dyCar(Vector3(0.92f, -0.6f, 0.04f));
	_game_objects[obj++] = _cars[6] = _cars_line[1][2] = new dyCar(Vector3(0.92f, -0.2f, 0.04f));
	_game_objects[obj++] = _cars[7] = _cars_line[1][3] = new dyCar(Vector3(0.92f, -0.6f, 0.04f));
	
	//upline truck
	_game_objects[obj++] = _rvs[0] = _rvs_line[0][0] = new dyRV(Vector3(-0.8f, -0.4f, 0.17f));
	_game_objects[obj++] = _rvs[1] = _rvs_line[0][1] = new dyRV(Vector3(-0.8f, -0.8f, 0.17f));
	//down line truck
	_game_objects[obj++] = _rvs[2] = _rvs_line[1][0] = new dyRV(Vector3(-0.8f, -0.4f, 0.17f));
	_game_objects[obj++] = _rvs[3] = _rvs_line[1][1] = new dyRV(Vector3(-0.8f, -0.8f, 0.17f));

	_spawntime = 0;
	_spawntimeRVS = 0;
	for (int i = 0; i < OBJECT_MOVING_LOG_COUNT; i++){
		_logs[i]->isdefined = 'U';
		_logs[i]->setIsColided(false);

	}
	for (int i = 0; i < OBJECT_MOVING_CAR_COUNT; i++){
		_cars[i]->isdefined = 'U';
	}
	for (int i = 0; i < OBJECT_MOVING_RV_COUNT; i++){
		_rvs[i]->isdefined = 'U';
	}
	indiceLog = 0;

	for (int i = 0; i < OBJECT_MOVING_TURTLES_COUNT; i++){
		_turt[i]->setIsColided(false);
		_turt[i]->isdefined = 'U';
	}
	indiceTurtle = 0;
		
	/*
	_frog->flag_colisionl = 1;
	_frog->flag_colisiont = 0;
*/
	/*for (int i = 0, j = 7; i < OBJECT_MOVING_CAR_COUNT; i++, j++){
		_game_objects_moving_cars[i] = _game_objects[j];	
	}*/

	for (int i = 0; i < CAMERA_COUNT; i++)
	{
		
		
		switch (i)
		{
			//Camera Orthogonal
		case 0:
			_camera[i] = new CamOrtho(SCREEN_WIDTH, SCREEN_HEIGHT, 0);
			break;

			//Camera Perspectiva
		case 1:{
			float x = (float)_frog->getPosition()->getX();
			float y = (float)_frog->getPosition()->getY();
			float z = (float)_frog->getPosition()->getZ();
			_camera[i] = _active_cam = new CamPerspe(SCREEN_WIDTH, SCREEN_HEIGHT, x, y, z, x, y, z);
			break;
		}
			//camera Perspectiva all
		case 2:
			_camera[i] = new  CamPerspeAll(SCREEN_WIDTH, SCREEN_HEIGHT, 0);
			break;
		}
	}
	for (int i = 0; i < LIGHT_COUNT; i++)
	{
		switch (i)
		{
			case 0:
				_light[i] = _sun = new LightSun(GL_LIGHT0);
				break;
			case 1:
				_light[i] = _lamp[0] = new LightStreetLamp(GL_LIGHT1, -0.9f, 0.9f, 0.9f, 1.0f);
				break;
			case 2:
				_light[i] = _lamp[1] = new LightStreetLamp(GL_LIGHT2, -0.9f, 0.0f, 0.9f, 1.0f);
				break;
			case 3:
				_light[i] = _lamp[2] = new LightStreetLamp(GL_LIGHT3, -0.9f, -0.95f, 0.9f, 1.0f);
				break;
			case 4:
				_light[i] = _lamp[3] = new LightStreetLamp(GL_LIGHT4, 0.9f, 0.9f, 0.9f, 1.0f);
				break;
			case 5:
				_light[i] = _lamp[4] = new LightStreetLamp(GL_LIGHT5, 0.9f, 0.0f, 0.9f, 1.0f);
				break;
			case 6:
				_light[i] = _lamp[5] = new LightStreetLamp(GL_LIGHT6, 0.9f, -0.95f, 0.9f, 1.0f);
				break;
		}
	}
	
	_active_cam->Reshape2(_screenWidth, _screenHeight, _frog->getPosition()->getX(), _frog->getPosition()->getY(), _frog->getPosition()->getZ());
	_sun->refresh();
	for (int i = 0; i < LIGHT_LAMP_COUNT; i++)
		_lamp[i]->refresh();
	//bool res = loadOBJ("frog.obj", vertices, uvs, normals);
	//glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vector3), &vertices[0], GL_STATIC_DRAW);

}
void GameManager::display(void){
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	_active_cam->Reshape2(_screenWidth, _screenHeight, _frog->getPosition()->getX(), _frog->getPosition()->getY(), _frog->getPosition()->getZ());
	_sun->refresh();
	//_light[0]->draw();
	for (int i = 0; i < OBJECT_MOVING_TURTLES_COUNT; i++){
		if (_turt[i] && _turt[i]->isdefined == 'D')
			_turt[i]->draw();
	}
	for (int i = 0; i < 6; i++){
		if (_game_objects[i])
			_game_objects[i]->draw();
	}
	for (int i = 0; i < OBJECT_MOVING_CAR_COUNT; i++){
		if (_cars[i] && _cars[i]->isdefined == 'D')
			_cars[i]->draw();
	}
	for (int i = 0; i < OBJECT_MOVING_RV_COUNT; i++){
		if (_rvs[i] && _rvs[i]->isdefined == 'D')
			_rvs[i]->draw();
	}
	for (int i = 0; i < OBJECT_MOVING_LOG_COUNT; i++){
		if (_logs[i] && _logs[i]->isdefined == 'D')
			_logs[i]->draw();
	}
	
	_frog->draw();
	//_sun->draw();
	for (int i = 0; i < LIGHT_LAMP_COUNT; i++)
		_lamp[i]->draw();
	glFlush();
}


void GameManager::reshape(int w, int h){
	_screenWidth = w;
	_screenHeight = h;
	_active_cam->Reshape(w, h);
}
void GameManager::ReadMouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN) {
		if (button == GLUT_LEFT_BUTTON) {
			mouse_left_down = true;
		}
		else if (button == GLUT_RIGHT_BUTTON) {
			mouse_right_down = true;
		}
	}
	else if (state == GLUT_UP) {
		if (button == GLUT_LEFT_BUTTON) {
			mouse_left_down = false;
		}
		else if (button == GLUT_RIGHT_BUTTON) {
			mouse_right_down = false;
		}
	}
}

void GameManager::ReadMouseMotion(int x, int y)
{
	// This variable is hack to stop glutWarpPointer from triggering an event callback to Mouse(...)
	// This avoids it being called recursively and hanging up the event loop
	static bool just_warped = false;

	if (just_warped) {
		just_warped = false;
		return;
	}

	//la cantidad desplazada en pixeles
	int dx = x - SCREEN_WIDTH / 2;
	int dy = y - SCREEN_HEIGHT / 2;

	if (dx) {
		
		_active_cam->RotateYaw(CAMERA_SPEED * dx);
		_active_cam->SetLastYaw(_active_cam->GetYaw());
	}

	if (dy) {
		_active_cam->RotatePitch(CAMERA_SPEED * dy);
	}

	glutWarpPointer(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

	just_warped = true;
}

void GameManager::keypressed(unsigned char key, int x, int y){
	if (key >= 'A' && key <= 'Z') 
		key += 32;
	switch (key)
	{
		//andar para cima
	case P_UP:
		_frog->setSpeed(0.0f, FROG_SPEED, 0.0f);
		break;

		//andar para baixo
	case P_DOWN:
		_frog->setSpeed(0.0f, -FROG_SPEED, 0.0f);
		break;

		//andar para a direita
	case P_RIGHT:
		_frog->setSpeed(FROG_SPEED, 0.0f, 0.0f);
		_keypressed = 1;
		break;

		//andar para a esquerda
	case P_LEFT: 
		_frog->setSpeed(-FROG_SPEED, 0.0f, 0.0f);
		_keypressed = 1;
		break;
	case 49:
		_active_cam = _camera[ORTHO];
		_active_cam->Reshape(_screenWidth, _screenHeight);
		_sun->refresh();
		for (int i = 0; i < LIGHT_LAMP_COUNT; i++)
			_lamp[i]->refresh();
		break;
	case 50:
		_active_cam = _camera[PERSP];
		_active_cam->Reshape(_screenWidth, _screenHeight);
		_sun->refresh();
		for (int i = 0; i < LIGHT_LAMP_COUNT; i++)
			_lamp[i]->refresh();
		break;
	case 51:
		_active_cam = _camera[THIRD_PERSON];
		_active_cam->Reshape(_screenWidth, _screenHeight);
		_sun->refresh();
		for (int i = 0; i < LIGHT_LAMP_COUNT; i++)
			_lamp[i]->refresh();
		break;
	case 'n':
		if (_light[0]->getState()){
			_sun->darkness();
			_sun->refresh();
			_light[0]->setState(false);
		}
		else{
			_sun->daylight();
			_sun->refresh();
			_light[0]->setState(true);
		}
		break;
	case 'c':
		for (int i = 0; i < LIGHT_LAMP_COUNT; i++){
			if (_lamp[i]->getState()){
				_lamp[i]->darkness();
				_lamp[i]->refresh();
				_lamp[i]->setState(false);
			}
			else{
				_lamp[i]->daylight();
				_lamp[i]->refresh();
				_lamp[i]->setState(true);
			}
		}
		break;
		
	}
	
	
		

}
void GameManager::ReadSpecialKeyboard(int key, int xx, int yy){

}

void GameManager::keyUp(unsigned char key, int x, int y){
	if (key >= 'A' && key <= 'Z')
		key += 32;
	switch (key)
	{
		//andar para cima
	case P_UP:
		if (_frog)
			_frog->setSpeed(0.0f, 0.0f, 0.0f);
		break;

		//andar para baixo
	case P_DOWN:
		if (_frog)
			_frog->setSpeed(0.0f, 0.0f, 0.0f);
		break;


		//andar para a direita
	case P_RIGHT:
		if (_frog)
			_frog->setSpeed(0.0f, 0.0f, 0.0f);
		_keypressed = 0;
		break;

		//andar para a esquerda
	case P_LEFT:
		if (_frog)
			_frog->setSpeed(0.0f, 0.0f, 0.0f);
		_keypressed = 0;
		break;

	}

}


void GameManager::update(){


	int time = glutGet(GLUT_ELAPSED_TIME);
	int delta_time = (time - _time)/11;
	/*
	light_position[1] = _frog->getPosition()->getX() + 9;
	light_position[2] = _frog->getPosition()->getY();
	light_position[3] = _frog->getPosition()->getZ()+2.0;
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 35);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 0.0);
	*/
	for (int i = 0; i < LIGHT_LAMP_COUNT; i++)
		_lamp[i]->refresh();
	_time = time;
		if (_frog )
				_frog->update(delta_time);


	for (int i = 0; i < OBJECT_MOVING_LOG_COUNT; i++){

		float speed_increase = 0;
		speed_increase = 0.000002 * round((float)(_time / 20000));
		
		if (_logs[i]->getSpeed().getX() < 0)
			_logs[i]->setSpeed(_logs[i]->getSpeed().getX() - speed_increase, _logs[i]->getSpeed().getY(), _logs[i]->getSpeed().getZ());
		else
			_logs[i]->setSpeed(_logs[i]->getSpeed().getX() + speed_increase, _logs[i]->getSpeed().getY(), _logs[i]->getSpeed().getZ());
		if (_logs[i]->isdefined == 'U'){
			continue;
		}
		_logs[i]->update(delta_time);


		if (_logs[i]->getPosition()->getX() < -1.15){

			double x = _logs[i]->getPosition()->getOriX() + 0.45;
			double y = _logs[i]->getPosition()->getOriY();
			double z = _logs[i]->getPosition()->getOriZ();
			_logs[i]->setPosition(x, y, z);
			_logs[i]->isdefined = 'U';
		}

		if (_frog->checkColision((_logs[i]->getPosition()->getX()) - 0.12, _logs[i]->getPosition()->getY(), 0.23, 0.08)){
			if (_frog->getSpeed().getX() == 0){
				_frog->setSpeed(_logs[i]->getSpeed().getX(), _frog->getSpeed().getY(), _frog->getSpeed().getZ());
			}
			else if(!_keypressed){
				_frog->setSpeed(_logs[i]->getSpeed().getX(), _frog->getSpeed().getY(), _frog->getSpeed().getZ());
			}
			indiceLog = i;
			_logs[i]->setIsColided(true);

		}
		else
		{
			_logs[i]->setIsColided(false);
		}
		


	}

	

	for (int i = 0; i < OBJECT_MOVING_TURTLES_COUNT; i++){
		float speed_increase = 0;
		
		speed_increase = 0.000002 * round((float)(_time / 20000));
		if (_turt[i]->getSpeed().getX() < 0)
			_turt[i]->setSpeed(_turt[i]->getSpeed().getX() - speed_increase, _turt[i]->getSpeed().getY(), _turt[i]->getSpeed().getZ());
		else
			_turt[i]->setSpeed(_turt[i]->getSpeed().getX() + speed_increase, _turt[i]->getSpeed().getY(), _turt[i]->getSpeed().getZ());
		if (_turt[i]->isdefined == 'U')
			continue;
		_turt[i]->update(delta_time);
		
		
		if (_frog->checkColision((_turt[i]->getPosition()->getX()) - 0.15, _turt[i]->getPosition()->getY(), 0.14, 0.08)){
			if (_frog->getSpeed().getX() == 0){
				_frog->setSpeed(_turt[i]->getSpeed().getX(), _frog->getSpeed().getY(), _frog->getSpeed().getZ());
			}
			else if (!_keypressed){
				_frog->setSpeed(_turt[i]->getSpeed().getX(), _frog->getSpeed().getY(), _frog->getSpeed().getZ());
			}
			indiceTurtle = i;
			_turt[i]->setIsColided(true);

		}
		else
		{
			_turt[i]->setIsColided(false);
		}
		if (_turt[i]->getPosition()->getX() > 1.3){
			double x = _turt[i]->getPosition()->getOriX() - 0.25;
			double y = _turt[i]->getPosition()->getOriY();
			double z = _turt[i]->getPosition()->getOriZ();
			_turt[i]->setPosition(x, y, z);
			_turt[i]->isdefined = 'U';
		}
	 
	}

	if ((_frog->checkColision((_river->getPosition()->getX()), _river->getPosition()->getY(), 1.0, 0.45)) && !(_logs[indiceLog]->getIsColided()) && !(_turt[indiceTurtle]->getIsColided())){

		double x = _frog->getPosition()->getOriX();
		double y = _frog->getPosition()->getOriY();
		double z = _frog->getPosition()->getOriZ();
		_frog->setPosition(x, y, z);
	}


	for (int i = 0; i < OBJECT_MOVING_RV_COUNT; i++){
		float speed_increase = 0;
		speed_increase = 0.000002 * round((float)(_time / 20000));
		if (_rvs[i]->getSpeed().getX() < 0)
			_rvs[i]->setSpeed(_rvs[i]->getSpeed().getX() - speed_increase, _rvs[i]->getSpeed().getY(), _rvs[i]->getSpeed().getZ());
		else
			_rvs[i]->setSpeed(_rvs[i]->getSpeed().getX() + speed_increase, _rvs[i]->getSpeed().getY(), _rvs[i]->getSpeed().getZ());
		if (_rvs[i]->isdefined == 'U')
			continue;
		_rvs[i]->update(delta_time);
		
		if (_rvs[i]->getPosition()->getX() > 1.4){

			double x = _rvs[i]->getPosition()->getOriX() - 0.30;
			double y = _rvs[i]->getPosition()->getOriY();
			double z = _rvs[i]->getPosition()->getOriZ();
			_rvs[i]->setPosition(x, y, z);
			_rvs[i]->isdefined = 'U';
		}

		if (_frog->checkColision((_rvs[i]->getPosition()->getX())-0.15, _rvs[i]->getPosition()->getY(), 0.24, 0.13)){
			double x = _frog->getPosition()->getOriX();
			double y = _frog->getPosition()->getOriY();
			double z = _frog->getPosition()->getOriZ();
			_frog->setPosition(x, y, z);
			

		}
	}



	for (int i = 0; i < OBJECT_MOVING_CAR_COUNT; i++){		
		float speed_increase = 0;
		speed_increase = 0.000002 * round((float)(_time / 20000));
		if (_cars[i]->getSpeed().getX() < 0)
			_cars[i]->setSpeed(_cars[i]->getSpeed().getX() - speed_increase, _cars[i]->getSpeed().getY() , _cars[i]->getSpeed().getZ());
		else
			_cars[i]->setSpeed(_cars[i]->getSpeed().getX() + speed_increase, _cars[i]->getSpeed().getY(), _cars[i]->getSpeed().getZ());
		if (_cars[i]->isdefined == 'U')
			continue;
		_cars[i]->update(delta_time);

		if (_cars[i]->getPosition()->getX() < -1.15){

			double x = _cars[i]->getPosition()->getOriX() + 0.25;
			double y = _cars[i]->getPosition()->getOriY();
			double z = _cars[i]->getPosition()->getOriZ();
			
			_cars[i]->setPosition(x, y, z);
			_cars[i]->isdefined = 'U';
		}
		
		if (_frog->checkColision(_cars[i]->getPosition()->getX(), _cars[i]->getPosition()->getY(), 0.12, 0.1)){
			double x = _frog->getPosition()->getOriX();
			double y = _frog->getPosition()->getOriY();
			double z = _frog->getPosition()->getOriZ();
			_frog->setPosition(x, y, z);
		}
		
	}

	randomSpawn();
	glutPostRedisplay();
	
	
}

void GameManager::randomSpawn(){
	if (_time > _spawntime){
		int i = 0;
		
		for (int w = 0; w < 3; w++){
			i = 0;
			while (1){
				int j = rand() % OBJECT_MOVING_LOG_COUNT/2;
				if (_logs_line[w][j]->isdefined == 'U'){
					_logs_line[w][j]->isdefined = 'D';
					break;
				}
				i++;
				if (i >= OBJECT_MOVING_LOG_COUNT / 2)
					break;
			}
		}
		for (int w = 0; w < 1; w++){
			i = 0;
			while (1){
				int j = rand() % OBJECT_MOVING_TURTLES_COUNT;
				if (_turt_line[w][j]->isdefined == 'U'){
					_turt_line[w][j]->isdefined = 'D';

					break;
				}
				i++;
				if (i >= OBJECT_MOVING_TURTLES_COUNT)
					break;
			}
		}

		
		_spawntime = _time + (rand() % (1000) + (500));
		/*
		for (int i = 0; i < OBJECT_MOVING_LOG_COUNT; i++){
			if (_logs[i]->isdefined == 'U'){
				_logs[i]->isdefined = 'D';
				_spawntime = _time + 5000;
				break;
			}
		}
		_spawntime = _time + 5000;
		*/
	}
	if (_time > _spawntimeCar){
		for (int w = 0; w < 2; w++){
			int i = 0;
			while (1){
				int j = rand() % OBJECT_MOVING_CAR_COUNT / 2;
				if (_cars_line[w][j]->isdefined == 'U'){
					_cars_line[w][j]->isdefined = 'D';
					break;
				}
				i++;
				if (i >= OBJECT_MOVING_LOG_COUNT / 2)
					break;
			}
		}
		_spawntimeCar = _time + (rand() % (1000) + (500));
	}
	if (_time > _spawntimeRVS){
		for (int w = 0; w < 2; w++){
			int i = 0;
			while (1){
				int j = rand() % OBJECT_MOVING_RV_COUNT / 2;
				if (_rvs_line[w][j]->isdefined == 'U'){
					_rvs_line[w][j]->isdefined = 'D';

					break;
				}
				i++;
				if (i >= OBJECT_MOVING_RV_COUNT / 2)
					break;
			}
		}

		_spawntimeRVS = _time + (rand() % (1900) + (1000));
	}

}

bool GameManager::loadOBJ(const char * path, std::vector<Vector3> & out_vertices, std::vector<Vector3> & out_uvs, std::vector<Vector3> & out_normals){
	std::vector<int> vertexIndices, uvIndices, normalIndices;
	std::vector<Vector3> temp_vertices;
	std::vector<Vector3> temp_uvs;
	std::vector<Vector3> temp_normals;
	FILE * file = fopen(path, "r");
	if (file == NULL){
		printf("Impossible to open the file !\n");
		return false;
	}
	
	while (1){
		
		char lineHeader[128];
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break; 

		if (strcmp(lineHeader, "v") == 0){
			Vector3 vertex = Vector3(0.0f, 0.0f, 0.0f);
			fscanf(file, "%lf %lf %lf\n", &vertex._x, &vertex._y, &vertex._z);
			temp_vertices.push_back(vertex);
		}
		else if (strcmp(lineHeader, "vt") == 0){
			Vector3 uv = Vector3(0.0f, 0.0f, 0.0f);
			fscanf(file, "%lf %lf\n", &uv._x, &uv._y);
			temp_uvs.push_back(uv);
		}
		else if (strcmp(lineHeader, "vn") == 0){
			Vector3 normal = Vector3(0.0f, 0.0f, 0.0f);
			fscanf(file, "%lf %lf %lf\n", &normal._x, &normal._y, &normal._z);
			temp_normals.push_back(normal);
		}
		else if (strcmp(lineHeader, "f") == 0){
			std::string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
			if (matches != 9){
				printf("File can't be read by our simple parser : ( Try exporting with other options\n");
				return false;
			}
			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);
			uvIndices.push_back(uvIndex[0]);
			uvIndices.push_back(uvIndex[1]);
			uvIndices.push_back(uvIndex[2]);
			normalIndices.push_back(normalIndex[0]);
			normalIndices.push_back(normalIndex[1]);
			normalIndices.push_back(normalIndex[2]);
		}
	}
	
	for (unsigned int i = 0; i < vertexIndices.size(); i++){
		unsigned int vertexIndex = vertexIndices[i];
		Vector3 vertex = temp_vertices[vertexIndex - 1];
		out_vertices.push_back(vertex);
	}
	
		
		/* std::cout << someVector[i]; ... */
	

	
	for (unsigned int i = 0; i < uvIndices.size(); i++){
		unsigned int uvIndex = uvIndices[i];
		Vector3 vertex = temp_uvs[uvIndex - 1];
		out_uvs.push_back(vertex);
	}
	for (unsigned int i = 0; i < normalIndices.size(); i++){
		unsigned int normalIndex = normalIndices[i];
		Vector3 vertex = temp_normals[normalIndex - 1];
		out_normals.push_back(vertex);
	}
	


	return true;
}