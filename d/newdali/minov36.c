// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov36.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"��ϼɽ"NOR);
	set("long","
��ϼɽ�������ƺ���ɽ�����㣬��������������ͺ���ɽɫ���޲�Ϊ֮�㵹��

������������ʫԻ��
������"HIC"��ϼ������������
���������ƺ�ˮ�����⣬
���������캬�����ϴ䣬
������Զɽ�ͱ�Ħ��ԣ�
������ˮ��ɽɫ���ӳ��
�������������Ʊ��쾻��\n"NOR
);
	set("objects", ([
		__DIR__"npc/youke1.c" : 1,
		]));
	set("exits", ([
		"westdown" : __DIR__"minov35",
		]));
	set("area", "���۲�");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
