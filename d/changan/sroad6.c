//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","�����ϴ��");
	set("long",@LONG
�����ǳ����ϴ�֣��������ɨ���˴����ߵ������ʱ��������������
�������������ϵĴ�������Զ���������ܶ�������ʿ�������������ֵı�����
LONG
	);
	set("exits",([
		"east" : __DIR__"datiepu",
		"south" : __DIR__"nanmen",
                "north" : __DIR__"sroad3",
	]));
set("outdoors", "changan");
	setup();
}
