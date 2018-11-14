#include "api_robot.h"

int _start() {
	set_motor_speed(0, 10);
	set_motor_speed(1, 10);
	int actualTime = get_time();
	int timeBase = actualTime;
	int timeBaseAux;
	int aux;
	int i = 1;
	int sonar3 = 2000;
	int sonar4 = 2000;
	int wall = 0;

	while (1) {
		if (i==50){
			i=1;
		}
		set_time(0);

		/*vira*/
		if (!wall) {
			actualTime = get_time();
			timeBase = actualTime;
			set_motor_speed(0, 0);
			while (actualTime < timeBase + 1950) {
				actualTime = get_time();
			}
			set_motor_speed(0, 10);
		}
		/*reto*/
		actualTime = get_time();
		timeBase = actualTime;	
		aux = actualTime;
		while (actualTime < timeBase + i) {
			if (actualTime != aux) {
				aux = actualTime;
				sonar3 = read_sonar(3);
				sonar4 = read_sonar(4);
			}
			if (sonar3 < 1500 || sonar4 < 1500) {
				/*sonar*/
				wall = 1;
				actualTime = get_time();
				timeBaseAux = actualTime;
				set_motor_speed(0, 0);
				while (actualTime < timeBaseAux + 1950){
					actualTime = get_time();
				}
				set_motor_speed(0, 10);
				sonar3 = read_sonar(3);
				sonar4 = read_sonar(4);
				break;
			} else {
				wall = 0;
			}
			actualTime = get_time();
		}
		i++;
	}

	return 0;
}
