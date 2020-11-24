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
enum AgentNetworkENUM
{
	WANDER = 0,
	FEED ,
	EVOLVE,
	HIDE
};
struct AgentNetworkOptions
{
	AgentNetworkENUM Option;
	float val;
};

static AgentNetworkENUM GetValue(int val)
{
	switch (val)
	{
	case 0:
		return WANDER;
		break;
	case 1:
		return FEED;
		break;
	case 2:
		return EVOLVE;
		break;
	case 3:
		return HIDE;
		break;
	default:
		return WANDER;
		break;
	}
}
#endif
