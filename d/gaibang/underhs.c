// Code of ShenZhou
// ���� to huashan
// qfy August 17, 1996

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��ɽ���������ѵ���ͷ�����ϱ��ǻ�ɽ�����ڡ�
LONG
	);

	set("exits", ([
		"up" : "/d/village/eexit",
		"west":__DIR__"hsandao2",	
	]));

	set("objects",([
		CLASS_D("gaibang") + "/mo-bushou" : 1,
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}
