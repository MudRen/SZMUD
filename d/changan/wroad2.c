//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","���������");
	set("long",@LONG
������һ��������ʯ�����ϣ�����Ϳ쵽�������ˣ����Կ�����¥������
ǰ�������Ǹ�ֻ������ס�ĵط�,�����Ϳ�Ҫ�����ˡ�
LONG
	);
	set("exits",([
                "southwest" : __DIR__"chougou",
                "east" : __DIR__"wroad1",
                "west" : __DIR__"wroad3",
		"north" : __DIR__"dadao",
	]));
set("outdoors", "changan");
	setup();
}
