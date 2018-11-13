#include "api_robot.h"

int _start() {
	set_motor_speed(0, 60);
	set_motor_speed(1, 60);
	int actualTime = get_time();
	int timeBase = actualTime;
	int i = 1;
	int sonar = 0;

	while (1) {
		if (i==50){
			i=1;
		} 

		/*vira*/
		actualTime = get_time();
		set_motor_speed(0, 0);
		while (actualTime < timeBase + 180){
			actualTime = get_time();
		}
		timeBase = actualTime;	
		set_motor_speed(0, 60);

		//sonar = read_sonar(4);
		//if (i*1000 > sonar && sonar > 1200) {
		/*reto*/
		actualTime = get_time();
		while (actualTime < timeBase + i*100){
			actualTime = get_time();
		}
		timeBase = actualTime;
		i++;
		// } else {
		// 	/*sonar*/
		// 	actualTime = get_time();
		// 	set_motor_speed(0, 0);
		// 	while (actualTime < timeBase + 370){
		// 		actualTime = get_time();
		// 	}
		// 	set_motor_speed(0, 60);
		// }
	}

	return 0;
}
