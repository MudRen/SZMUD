//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","���������");
	set("long",@LONG
������һ��������ʯ�����ϣ�����Ϳ쵽�������ˣ��������£����ַ�
������ʱ��������������������Ļ���տ��Ų��á����������������������
�������Ż�ȥ����Ͻ�����
LONG
	);
	set("exits",([
		"east" : __DIR__"wroad2",
		"west" : __DIR__"wroad4",
		"north" : __DIR__"huadian",
	]));
set("outdoors", "changan");
	setup();
}
