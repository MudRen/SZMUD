//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","�����·");
	set("long",@LONG
·�Ϸ���һ������ζ���ֵĶ������Ǹ����̣�����Ů���Ŵ������������
ͻȻ����ƥ������⼱����������Щ��������������������������ֶ������壬
������æ�ܿ���
LONG
	);
	set("exits",([
		"northwest" : __DIR__"center",
		"southeast" : __DIR__"roupu",
		"southwest" : __DIR__"wwroad4",
		"northeast" : __DIR__"wwroad6",
	]));
set("outdoors", "changan");
	setup();
}
