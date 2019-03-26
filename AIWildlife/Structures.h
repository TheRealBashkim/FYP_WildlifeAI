#ifndef STRUCTURES_H
#define STRUCTURES_H
struct Gene
{
	int mID;
	std::string mName;
	float health;
	float maxAge;
	float mCurrentStamina = 0;
	float mCurrentAge = 0;
	float maxStamina;
	float maxSpeed;
	std::string mGender;
	
};


#endif
