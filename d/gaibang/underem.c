// Code of ShenZhou
// /d/gaibang/underem.c
// Xbc: 96/10/01

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�����ܶ�");
        set("long", @LONG
���Ƕ���ɽ���²����ľ����ܶ��������������õģ������˸������
����ؤ������ռ�����ͭ�����ȡ�������ͨ��ؤ�������ͨ����
LONG
        );

	set("exits", ([
		"up" : "d/emei/shack",
		"east":__DIR__"emandao2",
	]));

	set("objects",([
                CLASS_D("gaibang") + "/mo-bushou" : 1,
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}



