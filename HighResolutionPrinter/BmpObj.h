#pragma once
#include "classmessage.h"

class CBmpObj :	public OBJ_Control
{
public:
	CBmpObj(void);
	CBmpObj(OBJ_Control obj,CBmpObj bmpObj);
	~CBmpObj(void);

public:
	void ReadBmp(char* strFileName);
};

