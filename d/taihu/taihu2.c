// Code of ShenZhou
//maco

inherit ROOM;

void check_trigger();
void on_board(object room);
//void arrive(object room);
//void close_passage(object room);


void create()
{
	set("short", "����");
	set("long", @LONG
������̫����������Ŀ��ȥ�������̲����죬Զˮ���졣����
�������ȼ����˼ң���������һ���洬��
LONG
	);
	 set("exits", ([
		"west" : __DIR__"taihu",
	]));
	set("cost", 2);
	set("outdoors", "guiyun");
	
	set("water_name", "��");
	set("boat", __DIR__"duchuan2");
	set("opposite", __DIR__"matou2");


	set("objects", ([
		"/d/city/obj/stone" : 1,
	]));

	setup();
}

void setup()
{
	object room;

	::setup();

	if( room = find_object(this_object()->query("boat")) )
	room->delete("yell_trigger");
}

#include "ferry.h"
