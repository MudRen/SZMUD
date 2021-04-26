// Code of ShenZhou
// Room: /d/dali/southgate.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"����"NOR);
	set("long", @LONG
�˼��Ǵ����������ǵ����ţ������ʵ��������ǣ���گ�ڳ�����������
����������Ķ��ϵġ�������������Դ˳�Ϊ������ǽ��ʯ������ݳɣ��߶���
�壬�����ɡ��������������������ľ�ʿ�ɴ����۾��۲����������������ˣ�
ż�����ʼ����μ����ɷ��ӡ�
LONG);
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/dalishibing" : 3,
		]));
	set("exits", ([
		"eastup" : __DIR__"minov12",
		"north" : __DIR__"dalicheng12",
		"south" : __DIR__"shqiao",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
