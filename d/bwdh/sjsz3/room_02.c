// Code of ShenZhou
// group bwdh/room 02
// Apache 09/27/98

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create() {
    set("short", HIG"��ƫ��"NOR);
    set("long", @LONG
�����Ǳ��䳡����ƫ�����տ��Ĵ�����һ���ܺõ������ط���
LONG
    );
    set("exits", ([
		  "west" : __DIR__"wzoulan",
		  "south" : __DIR__"room_03",
		  "east"  : __DIR__"room_11",
			 ]));
    create_room();
    setup();
}

void init() {
    init_room();
}