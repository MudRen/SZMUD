// Code of ShenZhou
// Room: /d/xingxiu/gcmaze1.c
// Date: June 30, 96   Jay

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�߲��Թ�");
	set("long", @LONG
�������ֺ���խ����������ͻȻ����������ֻ��������һ����ã�
�ıڹ��Ķ�������ľ��ķ���żȻ�ڱ��ϼ����������ģ�д���ǡ���
����������������̩�������������ʮ���꡹�ȵ�������ǽ����һ����
(bian)����һ�����˵������Ϸ���
LONG
	);

	set("item_desc", ([
		"bian" : "����д���ǡ������ʥ��ʦ����λ����\n",
	]));

	set("exits", ([
		"out" : __DIR__"gcdoor",
                "enter" : __DIR__"gcmaze2",
	]));
	create_door("out","������","enter",DOOR_CLOSED);

	set("cost", 6);
	setup();
}

