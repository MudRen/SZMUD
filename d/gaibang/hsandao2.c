// Code of ShenZhou
// ���� to huashan
// qfy August 17, 1996

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ؤ�Ｋ�����ܵĵ���ͨ��������ؤ�Ｘ����֮��Ѫ��ɡ� 
LONG
	);

	set("exits", ([
			"east" : __DIR__"underhs",
			"southeast" : __DIR__"hsandao1",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}
