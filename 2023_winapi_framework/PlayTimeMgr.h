#pragma once
class PlayTimeMgr
{
	SINGLE(PlayTimeMgr);
public:
	void Init();
	void SetPlayTime(float time)
	{
		playtime = time;
	}
	const float& GetPlayTime() const
	{
		return playtime;
	}
private:
	float playtime;
};

