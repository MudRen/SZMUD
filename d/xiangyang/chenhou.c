// Code of ShenZhou
// Room: /d/xiangyang/chenhou.c

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "�º���");
	set("long", @LONG
����С�ﾲ���ĵģ�ûʲ�������������ߴ���һ�����ʿ�������ź�����
ֱ����ȥ�Ϳ�����Ӫ������·�ľ�ͷ�ƺ�����ľ�������š�
LONG
	);
        set("coordinates", ([ "x" : 1, "y" : -7 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"nanjie2",
  "east" : __DIR__"xiaolu",
]));
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	create_door("east", "С��", "west", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
