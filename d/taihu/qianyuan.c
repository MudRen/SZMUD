// Code of ShenZhou
//Kane

#include "/d/taihu/guiyun.h"
inherit ROOM;

void create()
{
	set("short", "ǰԺ");
	set("long", @LONG
�����ǹ���ׯ��ǰԺ���൱�������ҿ�ǽ�����м���Ͱ���ƽ����
���Ǽ��˵�ס������ǰ��������ľ��������紵������Ҷ�������¡���ľ
��������һ�������
LONG
	);
	set("valid_startroom", 1);
	 set("exits", ([
		"north" : __DIR__"dating",
		"out" : __DIR__"damen",
	]));
	set("cost", 1);
	set("outdoors", "taihu");
	set("objects", ([
		"/d/taihu/npc/jiading" : 2,
	]));

	setup();
	"/clone/board/guiyun_b"->foo();
}
