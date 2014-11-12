#pragma once
#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <vector>

#include "GameObject.h"
#include "Entity.h"
#include "Model.h"

#include "dyFrog.h"
#include "dyCar.h"
#include "dyLog.h"
#include "dyTurtle.h"
#include "dyRV.h"
#include "River.h"
#include "Road.h"
#include "River.h"
#include "Roadside.h"
#include "Riverside.h"
#include "RiverRoad.h"
#include "FinalFlower.h"
#include "LightSource.h"
#include "LightStreetLamp.h"
#include "LightSun.h"

#include "MyCamera.h"
#include "CamOrtho.h"
#include "CamPerspe.h"
#include "CamPerspeAll.h"

#include "math.h"
#include "Header.h"

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_Warnings
#define _CRTDBG_MAP_ALLOC
#define CAMERA_COUNT 3
#define LIGHT_COUNT 7
#define LIGHT_LAMP_COUNT 6
#define OBJECT_MOVING_CAR_COUNT 8
#define OBJECT_MOVING_RV_COUNT 4
#define OBJECT_MOVING_LOG_COUNT 12
#define OBJECT_MOVING_TURTLES_COUNT 3
#define OBJECT_COUNT OBJECT_MOVING_CAR_COUNT +OBJECT_MOVING_RV_COUNT + OBJECT_MOVING_LOG_COUNT + OBJECT_MOVING_TURTLES_COUNT + 8
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600
#define _DEBUG 1

//controls
#define P_UP		'w'
#define P_DOWN		's'
#define P_LEFT		'a'
#define P_RIGHT		'd'

#if _DEBUG
	#ifndef DBG_NEW
		#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
		#define new DBG_NEW
	#endif
#endif  // _DEBUG

enum { ORTHO, THIRD_PERSON, PERSP };

class GameManager
{
public:
	GameManager(void);
	~GameManager(void);

private:
	GameObject * _game_objects[OBJECT_COUNT];
	GameObject * _game_objects_moving_cars[OBJECT_MOVING_CAR_COUNT];
	
	//Camera * _cameras[CAMERA_COUNT];
	MyCamera * _camera[CAMERA_COUNT];
	LightSource * _light[LIGHT_COUNT];
	LightSun * _sun;
	LightStreetLamp * _lamp[LIGHT_LAMP_COUNT];
	MyCamera * _active_cam;
	int _time;
	int _spawntime;
	bool _disablelighting;
	int _spawntimeCar;
	int indiceLog;
	int indiceTurtle;
	int _spawntimeRVS;
	int _keypressed;
	bool mouse_left_down, mouse_right_down;
	float _screenWidth;
	float _screenHeight;
	Model _model;
	River * _river;
	Road * _road;
	dyFrog * _frog;

	dyCar * _cars[OBJECT_MOVING_CAR_COUNT];
	dyCar * _cars_line[2][OBJECT_MOVING_CAR_COUNT/2];

	dyRV * _rvs[OBJECT_MOVING_RV_COUNT];
	dyRV * _rvs_line[2][OBJECT_MOVING_RV_COUNT / 2];

	dyLog * _logs[OBJECT_MOVING_LOG_COUNT];
	dyLog * _logs_line[3][OBJECT_MOVING_LOG_COUNT / 3];

	dyTurtle * _turt[OBJECT_MOVING_TURTLES_COUNT];
	dyTurtle * _turt_line[1][OBJECT_MOVING_TURTLES_COUNT / 1];
	
	

public:
	void display(void);
	void reshape(GLsizei w, GLsizei h);
	void keypressed(unsigned char key, int x, int y);
	void keyUp(unsigned char key, int x, int y);
	void onTimer(void){};
	void idle(void){};
	void update(void);
	void init(void);
	void randomSpawn();
	bool loadOBJ(const char * path, std::vector<Vector3> & out_vertices, std::vector<Vector3> & out_uvs, std::vector<Vector3> & out_normals);
	void ReadMouse(int button, int state, int x, int y);
	void ReadMouseMotion(int x, int y);
	void ReadSpecialKeyboard(int key, int xx, int yy);
};

