// Code of ShenZhou
// Room: /d/murong/huayuan3
//arthurgu /1999.9

#include "room.h"
inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
   �����и�С��������ʱ�������۵����С�����һ������
���Ӳ����󣬵�ζ�����������Ծ������˲�׽����԰���϶�
����С�š�
LONG
	);
	set("cost", 1);
	set("outdoors", "murong");
	set("exits", ([ 
        "out" : __DIR__"lianwu1",
        "west" : __DIR__"huayuan1",
                      ]));
	set("no_clean_up", 0);
        create_door("out","ľ��","enter", DOOR_CLOSED);
	setup();

	replace_program(ROOM);
}
