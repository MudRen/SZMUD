//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","�����·");
	set("long",@LONG
����������·�ϣ����������뵽����Ķķ�����һ���������ĿͿ�����Ϊ
����Ǯ�����������δ󺺸����˳����������������������ţ�������ȴ������
�ģ�����û��ʲô�·���һ����
LONG
	);
	set("exits",([
		"northeast" : __DIR__"center",
		"southeast" : __DIR__"wwroad3",
		"west" : __DIR__"dufang",
		"northwest" : __DIR__"wwroad1",
	]));
set("outdoors", "changan");
set("fanhua", 2);
	setup();
}
