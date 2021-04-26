// Code of ShenZhou
// Room: /d/dali/northgate.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"����"NOR);
	set("long", @LONG
������ǣ���������ǣ��Ǵ�����Ķ��ǡ�����گ�ڳ������������ϡ���
��͹��������ϡ������˹��������ϡ����������������������Ķ��ϵġ�����
���������Դ˳�Ϊ�����˴����Ǳ����ţ���÷ϪΪ���ӣ���ǽ����Ϫ�ϣ���ʯ��
�����ݳɣ��߶����壬�����ɣ���������¥��פ�����ڡ���ʯ�ٵ��ӳ���ֱ��
�����죬����һ��������·����ͨȥ��
LONG);
	set("objects", ([
		__DIR__"npc/dalishibing" : 3,
		__DIR__"npc/wujiang" : 1,
		]));
	set("exits", ([
		"northeast" : __DIR__"chhill",
		"westup" : __DIR__"shanlu",
		"north" : __DIR__"gaten1",
		"south" : __DIR__"dalicheng1",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
