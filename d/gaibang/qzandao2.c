// Code of ShenZhou
// ���� to quanzhou
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
			"northwest" : __DIR__"qzandao1",
			"south" : __DIR__"underqz",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}
