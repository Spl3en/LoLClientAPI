// --- Author : Moreau Cyril - Spl3en
#pragma once

// ---------- Includes ------------
#include "Position/Position.h"
#include "LoLAPIRequest.h"


// ---------- Defines -------------


// ------ Structure declaration -------
#pragma pack(push, 1)
typedef struct _GamePositionPacket{
	Position pos;

}	GamePositionPacket;

typedef struct _ScreenPositionPacket
{
	int x, y;
}	ScreenPositionPacket;

typedef struct _AnglePacket{
	float y;
	float x;

}	AnglePacket;

typedef struct _FloatPacket{
	float value;

}	FloatPacket;

typedef struct _BytePacket{
	byte value;

}	BytePacket;

typedef struct _IntPacket
{
	int value;

}	IntPacket;

typedef struct _BufferPacket
{
	char buffer [16];

} 	BufferPacket;

typedef struct _ObjectPacket
{
	int size;

} 	ObjectPacket;

typedef struct _HpPacket
{
	float curHP;
	float maxHP;

}	HpPacket;

typedef struct _BooleanPacket{
	bool value;

}	BooleanPacket;

typedef struct _RectanglePacket
{
	int x, y;
	int w, h;
	byte r, g, b;

}	RectanglePacket;

typedef struct _TextPacket
{
	int x, y;
	byte r, g, b;
	float opacity;
	byte fontSize;
	int stringLen;
	byte fontFamilyLen;

}	TextPacket;

typedef struct _SpritePacket
{
	int x, y;
	float opacity;
	int filePathLen;
}	SpritePacket;
#pragma pack(pop)

typedef struct _LoLAPIPacket
{
	LoLAPIRequest request;
	int id;

	union {
		GamePositionPacket gamePositionPacket;
		ScreenPositionPacket screenPositionPacket;
		AnglePacket anglePacket;
		FloatPacket floatPacket;
		IntPacket intPacket;
		BytePacket bytePacket;
		BufferPacket bufferPacket;
		ObjectPacket objectPacket;
		HpPacket hpPacket;
		BooleanPacket booleanPacket;
		RectanglePacket rectPacket;
		TextPacket textPacket;
		SpritePacket spritePacket;
	};

}	LoLAPIPacket;
