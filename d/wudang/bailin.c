// Code of ShenZhou
// bailin.c �䵱����
// by Fang 8/19/96

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"�䵱����"NOR);
	set("long", @LONG
	�㴩����һƬï�ܵİ����У���ɭ���䣬��ʯ��ᾣ�����û�ˡ���ʱ��
�����Ӵ������߷��ܶ�����
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southup" : __DIR__"haohanpo",
		"northdown" : __DIR__"yuzhen",
	]));
        set("objects", ([
                __DIR__"npc/yetu" : 2]));
	set("cost", 3);
	setup();
	replace_program(ROOM);
}

