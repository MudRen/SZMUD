// Code of ShenZhou
// Room: /d/gaibang/undertree.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;




void create()
{
	set("short", "�����ѱ�");
	set("long", @LONG
�����䵱ɽ�������ѱ��ϵ�Сɽ���������������õģ������˸���
�������ؤ������ռ�����ͭ�����ȡ�������ͨ��ؤ�������ͨ����
LONG
	);

	set("exits", ([
		"out" : "/d/wudang/tufeiwo1",
		"northeast":__DIR__"wdandao2",
	]));

	set("objects",([
		CLASS_D("gaibang") + "/li-sheng" : 1,
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}



