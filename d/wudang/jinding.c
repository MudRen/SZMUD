// Code of ShenZhou
// jinding.c �� 
// by Fang 8/20/96

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"��"NOR);
	set("long", @LONG
	��е���������Ϯ����ԭ�����ѵ����䵱ɽ������������ľ�����ǰ��
�Ľ����ͭ���ɣ����Իƽ�ÿ�������ٿգ����������������������𶥡���
����߸߶�����Ⱥ��֮�ϣ�����������ɽ����������壬�б���һɽ����¯����
��¯�壬��ɽǧ�֣������·���
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northdown" : __DIR__"santian",
                "south" : __DIR__"zijin",
                "west" : __DIR__"liantai",
	]));
	set("cost", 2);
        set("fjing", 1);
	setup();
	replace_program(ROOM);
}

