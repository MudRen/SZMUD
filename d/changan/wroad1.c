//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","���������");
	set("long",@LONG
������һ��������ʯ�����ϣ�����Ϳ쵽�������ˣ����Կ�����¥����
��ǰ��
LONG
	);
	set("exits",([

		"west" : __DIR__"wroad2",
		"northeast" : __DIR__"xfroad1",
		"southeast" : __DIR__"wwroad1",
	]));
set("outdoors", "changan");
	setup();
}
