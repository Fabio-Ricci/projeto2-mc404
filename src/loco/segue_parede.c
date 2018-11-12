#include "api_robot.h"

int _start() {
	//motor_cfg_t m;
	//m.id = 0;
	//m.speed = 60;
	set_motor_speed(0, 20);
	int i =0;
	/*while(i<99999)
	{
		int j =0;
		while(j<5)
		{
			j++;
		}
		i++;
		
	}*/
	set_motor_speed(1, 20);
	
	int s1;
	int s2;
	int s3;
	int s4;
	while(1)
	{
		s1 = read_sonar(3);
		s2 = read_sonar(4);
		s3 = read_sonar(5);
		s4 = read_sonar(2);
		if(s1<=1200||s2<=1200||s3<=1200||s4<=1200)
		{
			set_motor_speed(1, 0);
			set_motor_speed(0, 2);

		}
		s1 = read_sonar(7);
		s2 = read_sonar(8);
		if(s1<=1350  && abs(s1-s2)<=20)
		{

			set_motor_speed(1, 0);
			set_motor_speed(0, 0);
			break;

		}
	}
	
	set_motor_speed(1, 20);
	set_motor_speed(0, 20);

	while(1)
	{
		
		s1 = read_sonar(7);
		s2 = read_sonar(4);

		if(s2<1000)
		{
			set_motor_speed(1, 0);
			set_motor_speed(0, 8);
			while(1)
			{
				s2 = read_sonar(4);
				if(s2>1200)
				{
					set_motor_speed(1, 20);
					set_motor_speed(0, 20);
					break;	
				}
			}
		}
		if(s1>400)
		{
			set_motor_speed(0, 7);
			set_motor_speed(1, 10);
		}else
		if(s1<350)
		{
			set_motor_speed(1, 7);
			set_motor_speed(0, 10);
		}else
		{
			set_motor_speed(1, 20);
			set_motor_speed(0, 20);
		}

		


		
	}

		

	return 0;
}


int abs(int a){
	if (a < 0){
		return -a;
	}
	return a;
}
