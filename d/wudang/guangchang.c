// Code of ShenZhou
// guangchang.c �㳡
// by Xiang
// xQin 04/01

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"�䵱�㳡"NOR);
	set("long", @LONG
����һ���ɴ�ʯ���̳ɵĹ㳡�����䵱����ѧϰ�书�ͻ����д�ĵص�
����Χ��������ͩ����һ������������ص���Ҷ��һ���������ĵ�ͯ����
��ɨ�����洫���������㣬�����ǵ�ˮ�ܡ�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northdown" : __DIR__"zixiao",
		"south" : __DIR__"dishuiyan",
                "east": __DIR__"shanlu1",
                "eastdown" : __DIR__"tyroad1",
	]));
	set("objects", ([
		CLASS_D("wudang") + "/daotong" : 2]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

