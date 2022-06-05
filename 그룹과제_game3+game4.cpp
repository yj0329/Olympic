#define _CRT_SECURE_NO_WARNINGS
#include <bangtal.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ANIMATION_TIME      0.01f
#define GAME_TIME           70.0f 


//공통
int stage = 0, score_total;
SceneID opening, game1_title, game2_title, game3_title, game4_title, fail, ending;
ObjectID startbutton, restartbutton, endbutton;
TimerID timer_title;

//game1 변수
SceneID scene1_g1, scene2_g1, scene1_g2;
int speed_g1 = 0, x_g1 = 600, y_g1 = 0, speed2_g1 = 0, speed3_g1[3] = { 0, 0, 0 }, speed_g2[100] = { 0 };
int x2_g1[3] = { x_g1, x_g1, x_g1 }, y2_g1[3] = { 0,0,0 }, xt_g1[6], yt_g1 = 600;
TimerID timer1_g1, timer2_g1, timer1_g2;
ObjectID ship_g1, op_g1[120], NextGame_g1, life_g1[5], shot_g1[3], target_g1[6];
ObjectID up_g2[25], down_g2[25], left_g2[25], right_g2[25];
int mscale_g1[120], mx_g1[120], my_g1[120];
int lfx_g1 = 0, lfy_g1 = 600;
int score_g1 = 0, score2_g1 = 0, count_g1 = 3, rcount_g1[3] = { 3,3,3 };
int enemySpeed_g1 = score_g1 / 100 + 1;
const char* m_g1[120] = {
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png",
   "Images/M1.png","Images/M2.png","Images/M3.png","Images/M4.png"
};
const char* water_g1[3] = { "Images/life.png","Images/life.png" ,"Images/life.png" };
const char* bullet_g1[3] = { "Images/bullet.png","Images/bullet.png","Images/bullet.png" };
const char* tar_g1[6] = { "Images/target.png","Images/target.png" ,"Images/target.png" ,"Images/target.png" ,"Images/target.png" ,"Images/target.png" };


//game2 변수
SceneID game2;
ObjectID arrow_g2[25], arrow_g2_[4];
TimerID timer_arrow_g2, timer_main_g2;
int score_g2 = 0, arrow_dir_g2[25], arrow_num_g2 = 0, arrow_x_g2[25], arrow_y_g2[25], keystate_g2 = 4;


//game3 변수
SceneID game3;
ObjectID ball_g3, stick_g3, block_g3[10][5], ball_1_g3, ball_2_g3;
TimerID timer_ball_g3, timer_stick_g3, timer_delay_g3, timer_main_g3, fail_end;
int ball_x_g3 = 626, ball_y_g3 = 130, ball_dx_g3 = 5, ball_dy_g3 = 5, stick_x_g3 = 580, block_x_g3[10][5], block_y_g3[10][5], stick_dir_g3, life_g3 = 3, score_g3 = 0;
bool block_state_g3[10][5] = { false }, borken_g3 = false;


//game4 변수
SceneID game4;
TimerID timer_ball_g4, timer_hurdle_g4, timer_track_g4, timer_ani_g4;
ObjectID hurdle_g4[20], ball_g4, track_g4;
int hurdle_x_g4[20], ball_y_g4 = 250, ball_dy_g4 = 30, track_x_g4 = 1300;
int score_g4 = 5000;
bool animation_g4 = true;
time_t start_g4, end_g4;


//game1 함수


//game2 함수
void hide_arrow_g2(void);

//game3 함수
bool bounceBall_stick_g3(void);
void bounceBall_wall_g3(void);
void bounceBall_block_g3(void);
bool check_corner_g3(int i, int j);
bool check_clear_g3(void);


//공통 함수 
void game_fail(void);
void game_ending(void);
void setGame(void);


//Callback
void timerCallback(TimerID timer);
void keyboardCallback(KeyCode keycode, KeyState keystate);
void mouseCallback(ObjectID object, int x, int y, MouseAction action);



//game1
bool PointinR(int x, int y, int rx, int ry, int size) {
	return(x > rx) && (x < rx + size) && (y > ry) && (y < ry + size);
}

bool PointinB(int x, int y, int rx, int ry) {
	return (x > rx) && (x < rx + 120) && (y + 94 == ry);
}

bool collided(int i) {
	int size = 120;
	return PointinR(x_g1 + 25, y_g1 + 60, mx_g1[i], my_g1[i], size) ||
		PointinR(x_g1, y_g1 + 30, mx_g1[i], my_g1[i], size) ||
		PointinR(x_g1 + 60, y_g1 + 30, mx_g1[i], my_g1[i], size);
}

bool colbul(int i) {
	return PointinB(x2_g1[i], y2_g1[i], xt_g1[2 * (i - 1)], yt_g1) ||
		PointinB(x2_g1[i], y2_g1[i], xt_g1[2 * (i - 1) + 1], yt_g1);
}

bool Rangeover(int i) {
	if (i > 1280 || i < 0) {
		return true;
	}
	else {
		return false;
	}
}

int shooting(int i) {
	if (i > 100 && i < 800)
		return 1;
	else if (i > 810 && i < 1200)
		return 2;
	else if (i > 1210 && i < 10000)
		return 3;
}


//game2
void  hide_arrow_g2(void) {

	for (int i = 0; i < 25; i++) {
		switch (arrow_dir_g2[i]) {
		case 0: //위
			if (arrow_y_g2[i] == 460) {
				if (keystate_g2 == 0) {
					score_g2 += 400;
					//showMessage("점수 획득");
				}
				hideObject(arrow_g2[i]);

		    }
			break;
		case 1: //오른쪽
			if (arrow_x_g2[i] == 740) {
				if (keystate_g2 == 1) {
					score_g2 += 400;
					//showMessage("점수 획득");
				}
				hideObject(arrow_g2[i]);

			}
			break;
		case 2: //아래
			if (arrow_y_g2[i] == 140) {
				if (keystate_g2 == 2) {
					score_g2 += 400;
					//showMessage("점수 획득");
				}
				hideObject(arrow_g2[i]);

			}
			break;
		case 3:  //왼쪽
			if (arrow_x_g2[i] == 420) {
				if (keystate_g2 == 3) {
					score_g2 += 400;
					//showMessage("점수 획득");
				}
				hideObject(arrow_g2[i]);

			}
			break;
		}

	}

}



//game3
bool check_clear_g3(void) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 5; j++) {
			if (!block_state_g3[i][j]) return false;
		}
	}
	return true;
}

bool check_corner_g3(int i, int j) {

	if ((block_x_g3[i][j] - ball_x_g3 - 15) * (block_x_g3[i][j] - ball_x_g3 - 15) + (block_y_g3[i][j] + 30 - ball_y_g3 - 15) * (block_y_g3[i][j] + 30 - ball_y_g3 - 15) <= 255) {//왼쪽 위
		ball_dx_g3 = -5; ball_dy_g3 = 5; return true; 
	} else if ((block_x_g3[i][j] + 60 - ball_x_g3 - 15) * (block_x_g3[i][j] + 60 - ball_x_g3 - 15) + (block_y_g3[i][j] + 30 - ball_y_g3 - 15) * (block_y_g3[i][j] + 30 - ball_y_g3 - 15) <= 255) {  //오른쪽 위
		ball_dx_g3 = 5; ball_dy_g3 = 5; return true; 
	} else if ((block_x_g3[i][j] + 60 - ball_x_g3 - 15) * (block_x_g3[i][j] + 60 - ball_x_g3 - 15) + (block_y_g3[i][j] - ball_y_g3 - 15) * (block_y_g3[i][j] - ball_y_g3 - 15) <= 255) { // 오른쪽 아래
		ball_dx_g3 = 5; ball_dy_g3 = -5; return true; 
	} else if ((block_x_g3[i][j] - ball_x_g3 - 15) * (block_x_g3[i][j] - ball_x_g3 - 15) + (block_y_g3[i][j] - ball_y_g3 - 15) * (block_y_g3[i][j] - ball_y_g3 - 15) <= 255) { // 왼쪽 아래
		ball_dx_g3 = -5; ball_dy_g3 = -5; return true; 
	} else return false;
}

bool bounceBall_stick_g3(void) {
	if (ball_y_g3 < 130) {

		if (ball_x_g3 + 15 >= stick_x_g3 - 10 && ball_x_g3 + 15 <= stick_x_g3 + 20) {
			ball_dx_g3 = -5;
			ball_dy_g3 = 5;
			return true;
		}
		else if (ball_x_g3 + 15 >= stick_x_g3 + 20 && ball_x_g3 + 15 <= stick_x_g3 + 100) {
			ball_dy_g3 = 5;
			return true;
		}
		else if (ball_x_g3 + 15 >= stick_x_g3 + 100 && ball_x_g3 + 15 <= stick_x_g3 + 130) {
			ball_dx_g3 = 5;
			ball_dy_g3 = 5;
			return true;
		}
		else return false;
	}
	else return true;
}

void bounceBall_wall_g3(void) {
	if (ball_x_g3 <= 295) ball_dx_g3 *= -1;
	if (ball_x_g3 >= 920) ball_dx_g3 *= -1;
	if (ball_y_g3 >= 675) ball_dy_g3 *= -1;
}

void bounceBall_block_g3(void) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 5; j++) {
			if (block_state_g3[i][j]) continue;
			if (borken_g3) continue;

			if (check_corner_g3(i, j)) {
				hideObject(block_g3[i][j]);
				block_state_g3[i][j] = true;
				score_g3 += 200;
				borken_g3 = true;
			}
			else if (((block_y_g3[i][j] + 30 == ball_y_g3) && (block_x_g3[i][j] <= ball_x_g3 + 15)) && (block_x_g3[i][j] + 60 >= ball_x_g3 + 15)) {  //top
				hideObject(block_g3[i][j]);
				ball_dy_g3 = 5;
				block_state_g3[i][j] = true;
				score_g3 += 200;
				borken_g3 = true;

			}
			else if (((block_y_g3[i][j] == ball_y_g3 + 30) && (block_x_g3[i][j] <= ball_x_g3 + 15)) && (block_x_g3[i][j] + 60 >= ball_x_g3 + 15)) { //bottom
				hideObject(block_g3[i][j]);
				ball_dy_g3 = -5;
				block_state_g3[i][j] = true;
				score_g3 += 200;
				borken_g3 = true;

			}
			else if (((block_x_g3[i][j] + 60 == ball_x_g3) && (block_y_g3[i][j] <= ball_y_g3 + 15)) && (block_y_g3[i][j] + 30 >= ball_y_g3 + 15)) { //right
				ball_dx_g3 = 5;
				hideObject(block_g3[i][j]);
				block_state_g3[i][j] = true;
				score_g3 += 200;
				borken_g3 = true;

			}
			else if (((block_x_g3[i][j] == ball_x_g3 + 30) && (block_y_g3[i][j] <= ball_y_g3 + 15)) && (block_y_g3[i][j] + 30 >= ball_y_g3 + 15)) { //left
				ball_dx_g3 = -5;
				hideObject(block_g3[i][j]);
				block_state_g3[i][j] = true;
				score_g3 += 200;
				borken_g3 = true;

			}
		}
	}
}


//공통
void game_ending(void) {

	locateObject(restartbutton, ending, 295, 250);
	showObject(restartbutton);

	locateObject(endbutton, ending, 800, 250);
	showObject(endbutton);

	enterScene(ending);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, true);

	stage = 50;

	score_g4 += 5000;
	score_g4 -= 100 * difftime(start_g4, end_g4);

	score_total = score_g1 + score2_g1+score_g3 + score_g4;
	char buff[30];
	sprintf(buff, "score: %d", score_total);

	showMessage(buff);

}

void game_fail(void) {
	locateObject(restartbutton, fail, 295, 250);
	//showObject(restartbutton);

	locateObject(endbutton, fail, 800, 250);
	//showObject(endbutton);

	enterScene(fail);

	stage = 60;
	
	startTimer(fail_end);

}

void setGame(void) {

	srand((unsigned int)time(NULL));

	//game3
	ball_x_g3 = 626, ball_y_g3 = 130, ball_dx_g3 = 5, ball_dy_g3 = 5, stick_x_g3 = 580;
	borken_g3 = false;
	block_state_g3[10][5] = { false }; 
	life_g3 = 3, score_g3 = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 5; j++) {
			showObject(block_g3[i][j]);
		}
	}

	locateObject(stick_g3, game3, stick_x_g3, 100);
	showObject(stick_g3);

	showObject(ball_2_g3);
	showObject(ball_1_g3);

	locateObject(ball_g3, game3, ball_x_g3, ball_y_g3);


	//game4

	locateObject(track_g4, game4, 1300, 150);

	hurdle_x_g4[0] = 1400;
	for (int i = 0; i < 19; i++) {
		int d = rand() % 5;
		d = (d + 3) * 100;
		hurdle_x_g4[i + 1] = hurdle_x_g4[i] + d;
	}

	for (int i = 0; i < 20; i++) {
		locateObject(hurdle_g4[i], game4, hurdle_x_g4[i], 200);
		showObject(hurdle_g4[i]);
	}

}

ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown = true) {
	ObjectID object = createObject(image);
	if (shown == true) {
		locateObject(object, scene, x, y);
		showObject(object);
	}
	return object;
}

//Callback
void keyboardCallback(KeyCode keycode, KeyState keystate) {
	
	//game1
	if (stage == 10) {
		if (keycode == KeyCode::KEY_RIGHT_ARROW) {
			speed_g1 += 1;
		}
		else if (keycode == KeyCode::KEY_LEFT_ARROW) {
			speed_g1 -= 1;
		}
		else if (keycode == KeyCode::KEY_UP_ARROW) {
			speed2_g1 += 20;
		}

	}

	//game2
	else if (stage == 20){
		if (keycode == KeyCode::KEY_UP_ARROW && keystate == KeyState::KEY_PRESSED) { //위
			keystate_g2 = 0;
		}
		else if (keycode == KeyCode::KEY_RIGHT_ARROW && keystate == KeyState::KEY_PRESSED) { //오른쪽
			keystate_g2 = 1;
		}
		else if (keycode == KeyCode::KEY_DOWN_ARROW && keystate == KeyState::KEY_PRESSED) { //아래
			keystate_g2 = 2;
		}
		else if (keycode == KeyCode::KEY_LEFT_ARROW && keystate == KeyState::KEY_PRESSED) { //왼쪽
			keystate_g2 = 3;
		}
		else if (keystate == KeyState::KEY_RELEASED && (((keycode == KeyCode::KEY_UP_ARROW || keycode == KeyCode::KEY_RIGHT_ARROW) || keycode == KeyCode::KEY_DOWN_ARROW) || keycode == KeyCode::KEY_LEFT_ARROW))
			keystate_g2 = 4;
	}

	
	//game3
	else if (stage == 30) {
		if (keycode == KeyCode::KEY_RIGHT_ARROW && keystate == KeyState::KEY_PRESSED) stick_dir_g3 = 1;
		else if (keycode == KeyCode::KEY_LEFT_ARROW && keystate == KeyState::KEY_PRESSED) stick_dir_g3 = -1;
		else if ((keycode == KeyCode::KEY_RIGHT_ARROW || keycode == KeyCode::KEY_LEFT_ARROW) && keystate == KeyState::KEY_RELEASED) stick_dir_g3 = 0;
	}


	//game4
	else if (stage == 41) {
		if ((keycode == KeyCode::KEY_SPACE && keystate == KeyState::KEY_PRESSED) && ball_y_g4 == 250) {
			startTimer(timer_ball_g4);
		}
	}
	else if (stage == 42) {
		if (keycode == KeyCode::KEY_SPACE && keystate == KeyState::KEY_PRESSED) {
			if (track_x_g4 <= -2940) {
				end_g4 = time(NULL);
				game_ending();
			}
			track_x_g4 -= 30;
			locateObject(track_g4, game4, track_x_g4, 150);
			showObject(track_g4);

			if (animation_g4) setObjectImage(ball_g4, "Images/running/오_큰거.png");
			else setObjectImage(ball_g4, "Images/running/왼_큰거.png");
			animation_g4 = !animation_g4;


		}
	}

}

void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	if (stage == 50 || stage == 60) {
		if (object == restartbutton) {
			setGame();
			enterScene(opening);
			stage = 30;
			setTimer(timer_title, 2.f);
			startTimer(timer_title);
		}
		else if (object == endbutton) endGame();
	}
	else if (stage == 0) {
		if (object == startbutton) {
			enterScene(game1_title);
			setTimer(timer_title, 2.f);
			startTimer(timer_title);
		}
	}
}

void timerCallback(TimerID timer) {

	//공통
	if (timer == timer_title) {
		switch (stage) {
		case 0:
			enterScene(game1_title);
			stage = 10;
			setTimer(timer_title, 2.f);
			startTimer(timer_title);
			break;
		case 10:
			enterScene(scene1_g1);
			startTimer(timer2_g1);  
			startTimer(timer1_g1);
			break;

		case 20:
			enterScene(game2);
			startTimer(timer_main_g2);
			setTimer(timer_arrow_g2, 0.01f);
			startTimer(timer_arrow_g2);
			break;
		case 30:
			enterScene(game3);
			startTimer(timer_delay_g3);
			break;
		case 41:
			enterScene(game4);
			startTimer(timer_hurdle_g4);
			startTimer(timer_ani_g4);
			break;
		}
	}


	//game1
	else if (stage == 10) {
		if (count_g1 > 0) {
			if (timer == timer1_g1) {
				x_g1 += speed_g1;
				const int savex = x_g1;

				if (Rangeover(x_g1) == true) {
					x_g1 = 600;
				}
				if (score_g1 == 100) {
					speed3_g1[0] += 1;
				}
				else if (score_g1 == 800) {
					speed3_g1[1] += 1;
					speed2_g1 = 0;
				}
				else if (score_g1 == 1200) {
					speed3_g1[2] += 1;
					speed2_g1 = 0;
				}
				for (int i = 1; i < 4; i++) {
					if (shooting(score_g1) == i) {
						xt_g1[2 * (i - 1)] += speed3_g1[i - 1];
						xt_g1[2 * (i - 1) + 1] -= speed3_g1[i - 1];
						if (xt_g1[2 * (i - 1)] > 1280 && xt_g1[2 * (i - 1) + 1] < 0) {
							if (rcount_g1[i] == 0) {
								hideObject(target_g1[2 * (i - 1)]);
								hideObject(target_g1[2 * (i - 1)] + 1);
							}
							else {
								rcount_g1[i] -= 1;
								xt_g1[2 * (i - 1)] = 600;
								xt_g1[2 * (i - 1) + 1] = 600;
								speed3_g1[i - 1] += 1;
							}
						}
						y2_g1[i - 1] += speed2_g1;
						x2_g1[i - 1] = savex;
						showObject(target_g1[2 * (i - 1)]);
						showObject(target_g1[2 * (i - 1) + 1]);
						showObject(shot_g1[i - 1]);
						locateObject(target_g1[2 * (i - 1)], scene1_g1, xt_g1[2 * (i - 1)], yt_g1);
						locateObject(target_g1[2 * (i - 1) + 1], scene1_g1, xt_g1[2 * (i - 1) + 1], yt_g1);
						locateObject(shot_g1[i - 1], scene1_g1, x2_g1[i - 1], y2_g1[i - 1]);
					}
				}

				for (int i = 0; i < 3; i++) {
					if (colbul(i)) {
						score2_g1 += (1000 + 500 * i);
						hideObject(target_g1[2 * i]);
						hideObject(target_g1[2 * i + 1]);
						hideObject(shot_g1[i]);
						showMessage("추가점수!");
					}
				}

				locateObject(ship_g1, scene1_g1, x_g1, y_g1);
				for (int i = 0; i < 120; i++) {
					if (my_g1[i] < -mscale_g1[i]) {
						score_g1 += 10;
						mx_g1[i] = rand() % 1280;
						my_g1[i] = (rand() % 1000) + 720;
						locateObject(op_g1[i], scene1_g1, mx_g1[i], my_g1[i]);
					}
					my_g1[i] -= enemySpeed_g1;
					locateObject(op_g1[i], scene1_g1, mx_g1[i], my_g1[i]);
					if (collided(i) == true) {
						if (count_g1 == 3) {
							count_g1--;
							hideObject(life_g1[0]);
							x_g1 = 600;
						}
						else if (count_g1 == 2) {
							count_g1--;
							hideObject(life_g1[1]);
							x_g1 = 600;
						}
						else if (count_g1 == 1) {
							count_g1--;
							enemySpeed_g1 = 0;
							enterScene(game2_title);
							stage = 20;
							setTimer(timer_title, 2.f);
							startTimer(timer_title);
							stopTimer(timer2_g1);
						}
					}
				}
				setTimer(timer1_g1, ANIMATION_TIME);
				startTimer(timer1_g1);
			}
		}
		else if (count_g1 == 0) {
			stopTimer(timer1_g1);
		}


		if (timer == timer2_g1 && count_g1 > 0) {
			enemySpeed_g1 = 0;
			stopTimer(timer1_g1);
			enterScene(game2_title);
			stage = 20;
			setTimer(timer_title, 2.f);
			startTimer(timer_title);

		}


	}

	//game2
	else if (stage == 20) {
		if (timer == timer_arrow_g2) {
			hide_arrow_g2();
			for (int i = 0; i < 25; i++) {
				switch (arrow_dir_g2[i]) {
				case 0: arrow_y_g2[i] -= 5; break;//위
				case 1: arrow_x_g2[i] -= 5; break;//오른쪽
				case 2: arrow_y_g2[i] += 5; break;//아래
				case 3: arrow_x_g2[i] += 5; break;//왼쪽
				}

				locateObject(arrow_g2[i], game2, arrow_x_g2[i], arrow_y_g2[i]);
			}
			//bool temp = check_arrow_g2();

			setTimer(timer_arrow_g2, 0.01f);
			startTimer(timer_arrow_g2);
		}
		else if (timer == timer_main_g2) {
			enterScene(game3_title);
			stage = 30;
			setTimer(timer_title, 2.f);
			startTimer(timer_title);
		}
	}
	
	

	//game3
	else if (stage == 30) {
		 if (timer == timer_ball_g3) {

			if (check_clear_g3()) {
				enterScene(game4_title);

				stage = 41;
				setTimer(timer_title, 2.f);
				startTimer(timer_title);
			}

			borken_g3 = false;

			bool temp = bounceBall_stick_g3();
			bounceBall_wall_g3();
			bounceBall_block_g3();

			ball_x_g3 += ball_dx_g3;
			ball_y_g3 += ball_dy_g3;

			locateObject(ball_g3, game3, ball_x_g3, ball_y_g3);
			
			if (temp) {
				setTimer(timer_ball_g3, 0.01f);
				startTimer(timer_ball_g3);
			}
			else {
				life_g3--;

				switch (life_g3) {
				case 2: hideObject(ball_1_g3);
					ball_x_g3 = 625, ball_y_g3 = 130, ball_dx_g3 = 5, ball_dy_g3 = 5;
					locateObject(ball_g3, game3, ball_x_g3, ball_y_g3);
					setTimer(timer_delay_g3, 3.f);
					startTimer(timer_delay_g3);
					break;

				case 1: hideObject(ball_2_g3);
					ball_x_g3 = 625, ball_y_g3 = 130, ball_dx_g3 = 5, ball_dy_g3 = 5;
					locateObject(ball_g3, game3, ball_x_g3, ball_y_g3);
					setTimer(timer_delay_g3, 3.f);
					startTimer(timer_delay_g3);
					break;

				case 0: game_fail();
					break;
				}
			}

		 }
		else if (timer == timer_stick_g3) {

			if (stick_dir_g3 == -1) stick_x_g3 -= 10;
			else if (stick_dir_g3 == 1) stick_x_g3 += 10;

			if (stick_x_g3 < 295) stick_x_g3 = 295;
			if (stick_x_g3 > 830) stick_x_g3 = 830;

			locateObject(stick_g3, game3, stick_x_g3, 100);

			setTimer(timer_stick_g3, 0.01f);
			startTimer(timer_stick_g3);

		}
		else if (timer == timer_delay_g3) { 
			 setTimer(timer_main_g3, 60.f);
			 startTimer(timer_ball_g3); 
			 startTimer(timer_main_g3); 
			 startTimer(timer_stick_g3);

		}
		else if (timer == timer_main_g3) {
			 enterScene(game4_title);

			 stage = 41;
			 setTimer(timer_title, 2.f);
			 startTimer(timer_title);
		 }

	}

	else if (timer == fail_end) {
		endGame();
	}
	

	
	//game4
	else if (stage == 41 || stage == 42) {
		if (timer == timer_hurdle_g4) {

			for (int i = 0; i < 20; i++) {
				if (hurdle_x_g4[i] == 600) {
					if (ball_y_g4 <= 370) {
						setObjectImage(hurdle_g4[i], "Images/hurdle_.png");
						score_g4 -= 250;
					}
				}

				hurdle_x_g4[i] -= 10;
				locateObject(hurdle_g4[i], game4, hurdle_x_g4[i], 200);
				showObject(hurdle_g4[i]);

			}

			if (hurdle_x_g4[19] <= -200) {
				stage = 42;
				startTimer(timer_track_g4);
			}
			setTimer(timer_hurdle_g4, 0.01f);
			startTimer(timer_hurdle_g4);
	    }
		else if (timer == timer_track_g4) {

			if (track_x_g4 >= 630) {
				track_x_g4 -= 10;
				locateObject(track_g4, game4, track_x_g4, 150);
				
				if (animation_g4) setObjectImage(ball_g4, "Images/running/오_큰거.png");
				else setObjectImage(ball_g4, "Images/running/왼_큰거.png");
				animation_g4 = !animation_g4;
				
				setTimer(timer_track_g4, 0.01f);
				startTimer(timer_track_g4);
			}
			else start_g4 = time(NULL);
		}
		else if (timer == timer_ball_g4) {
			if (ball_y_g4 + ball_dy_g4 > 250) {
				ball_y_g4 += ball_dy_g4;
				locateObject(ball_g4, game4, 640, ball_y_g4);
				showObject(ball_g4);
				ball_dy_g4 -= 3;

				setTimer(timer_ball_g4, 0.01f);
				startTimer(timer_ball_g4);
			}
			else {
				ball_y_g4 = 250;
				locateObject(ball_g4, game4, 640, ball_y_g4);
				showObject(ball_g4);
				ball_dy_g4 = 30;
			}
		}
		else if (stage == 41 && timer == timer_ani_g4) {
			if (animation_g4) setObjectImage(ball_g4, "Images/running/오_큰거.png");
			else setObjectImage(ball_g4, "Images/running/왼_큰거.png");
			animation_g4 = !animation_g4;

			if (stage == 41) {
				setTimer(timer_ani_g4, 0.05f);
				startTimer(timer_ani_g4);
			}
		}
	
	}
	
}


int main() {

	srand((unsigned int)time(NULL));

	setTimerCallback(timerCallback);
	setKeyboardCallback(keyboardCallback);
	setMouseCallback(mouseCallback);

	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);


	// 공통
	opening = createScene("opening", "Images/opening.png");

	game1_title = createScene("game1_title", "Images/title_game1.png");
	game2_title = createScene("game2_title", "Images/title_game2.png");
	game3_title = createScene("game3_title", "Images/title_game3.png");
	game4_title = createScene("game4_title", "Images/title_game4.png");
	fail = createScene("fail", "Images/fail.png");
	ending = createScene("ending", "Images/ending.png");

	timer_title = createTimer(2.f);
    startTimer(timer_title);

	//startbutton = createObject("Images/startbutton.png", opening, 540,100);

	restartbutton = createObject("Images/restartbutton.png");

	endbutton = createObject("Images/endbutton.png");

	
	//game1
	scene1_g1 = createScene("갤러그");
	timer1_g1 = createTimer(ANIMATION_TIME);
	startTimer(timer1_g1);
	timer2_g1 = createTimer(GAME_TIME);
	scene2_g1 = createScene("갤러그점수");
	ship_g1 = createObject("Images/ship.png", scene1_g1, x_g1, y_g1);
	for (int i = 0; i < 3; i++) {
		life_g1[i] = createObject(water_g1[i], scene1_g1, lfx_g1, lfy_g1);
		lfx_g1 += 60;
	}
	for (int i = 0; i < 3; i++) {
		shot_g1[i] = createObject(bullet_g1[i], scene1_g1, x2_g1[i], y2_g1[i], false);
	}

	srand((unsigned int)time(NULL));
	for (int i = 0; i < 120; i++) {
		mx_g1[i] = rand() % 1280;
		my_g1[i] = (rand() % 100) * i + 720;
		op_g1[i] = createObject(m_g1[i], scene1_g1, mx_g1[i], my_g1[i], true);
	}

	for (int i = 0; i < 6; i++) {
		if (i % 2 == 0)
			xt_g1[i] = 10;
		else
			xt_g1[i] = 1270;
		target_g1[i] = createObject(tar_g1[i], scene1_g1, xt_g1[i], yt_g1, false);
	}
	NextGame_g1 = createObject("Images/next.png", scene2_g1, 400, 100);


	//game2
	game2 = createScene("game2", "Images/background.png");

	arrow_g2_[0] = createObject("Images/arrow_up.png", game2, 580, 460, true);
	//상
	arrow_g2_[1] = createObject("Images/arrow_left.png", game2, 420, 300, true);
	//좌
	arrow_g2_[2] = createObject("Images/arrow_down.png", game2, 580, 140, true);
	//하
	arrow_g2_[3] = createObject("Images/arrow_right.png", game2, 740, 300, true);
	//우
	
	for (int i = 0; i < 25; i++) {
		arrow_dir_g2[i] = (int) (rand() % 4);

		switch (arrow_dir_g2[i]) {
		case 0: arrow_x_g2[i] = 580; arrow_y_g2[i] = i * 200 + 720; arrow_g2[i] = createObject("Images/arrow_up.png"); break;//위
		case 1: arrow_x_g2[i] = i * 200 + 1280; arrow_y_g2[i] = 300; arrow_g2[i] = createObject("Images/arrow_right.png"); break;//오른쪽
		case 2: arrow_x_g2[i] = 580; arrow_y_g2[i] = i * (-200) - 120; arrow_g2[i] = createObject("Images/arrow_down.png"); break;//아래
		case 3: arrow_x_g2[i] = i * (-200) - 120; arrow_y_g2[i] = 300; arrow_g2[i] = createObject("Images/arrow_left.png"); break;//왼쪽
		}

		locateObject(arrow_g2[i], game2, arrow_x_g2[i], arrow_y_g2[i]);
		showObject(arrow_g2[i]);
		
 	}

	timer_arrow_g2 = createTimer(0.01f);
	//startTimer(timer_arrow_g2);

	timer_main_g2 = createTimer(60.f);
	


	//game3
	game3 = createScene("game3", "Images/background_game3.png");

	ball_g3 = createObject("Images/ball.png");
	locateObject(ball_g3, game3, ball_x_g3, ball_y_g3);
	showObject(ball_g3);

	ball_1_g3 = createObject("Images/ball.png");
	locateObject(ball_1_g3, game3, 380, 45);
	showObject(ball_1_g3);

	ball_2_g3 = createObject("Images/ball.png");
	locateObject(ball_2_g3, game3, 330, 45);
	showObject(ball_2_g3);

	stick_g3 = createObject("Images/stick.png");
	locateObject(stick_g3, game3, stick_x_g3, 100);
	showObject(stick_g3);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 5; j++) {
			block_x_g3[i][j] = 65 * i + 300;
			block_y_g3[i][j] = 35 * j + 435;
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 5; j++) {
			block_g3[i][j] = createObject("Images/block.png");
			locateObject(block_g3[i][j], game3, block_x_g3[i][j], block_y_g3[i][j]);
			showObject(block_g3[i][j]);
		}
	}

	timer_ball_g3 = createTimer(0.01f);

	timer_stick_g3 = createTimer(0.01f);
	//startTimer(timer_stick_g3);

	timer_delay_g3 = createTimer(3.f);
	//startTimer(timer_delay_g3);

	timer_main_g3 = createTimer(60.f);

	fail_end = createTimer(2.f);


	//game4
	game4 = createScene("game4", "Images/background_game4.png");
	

	track_g4 = createObject("Images/track.png");
	locateObject(track_g4, game4, 1300, 150);
	showObject(track_g4);

	for (int i = 1; i < 11; i++) hurdle_x_g4[i] = 400 * i + 1000;

	hurdle_x_g4[0] = 1400;
	for (int i = 0; i < 19; i++) {
		int d = rand() % 5;
		d = (d + 3) * 100;
		hurdle_x_g4[i + 1] = hurdle_x_g4[i] + d;
	}

	for (int i = 0; i < 20; i++) {
		hurdle_g4[i] = createObject("Images/hurdle.png");
		locateObject(hurdle_g4[i], game4, hurdle_x_g4[i], 200);
		showObject(hurdle_g4[i]);
	}

	ball_g4 = createObject("Images/running/왼_큰거.png");
	scaleObject(ball_g4, 0.2f);
	locateObject(ball_g4, game4, 640, ball_y_g4);
	showObject(ball_g4);

	timer_ball_g4 = createTimer(0.01f);
	timer_hurdle_g4 = createTimer(0.01f);
    timer_track_g4 = createTimer(0.01f);
	timer_ani_g4 = createTimer(0.05f);

	

	//게임 시작
	startGame(opening);
}