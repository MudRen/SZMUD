// Code of ShenZhou
// haohanpo.c �䵱�ú���
// by Fang 8/19/96

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"�ú���"NOR);
	set("long", @LONG
	�˴�����ʮ����ɽ�ƶ��ͣ���Ϊ�ú��£�ɽ·����������ϸ�񣬴�ɫ���
�������ˣ���֪�����������������µ�ƣ�͡��¶���һ�������ۣ���չ����������
��ȥ�����������������ϲ��죬������ǰ������ȥʵ���ϻ�����ʮ�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southdown" : __DIR__"shanlu",
		"northdown" : __DIR__"bailin",
	]));

	set("cost", 3);
        set("fjing", 1);
	setup();
	replace_program(ROOM);
}

