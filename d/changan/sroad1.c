//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","�����ϴ��");
	set("long",@LONG
������һ����ʯ����ϣ��������ɨ���˴������Ƶ�Ҷ�ӵ�������������
�ĵ������ͷң������ϡ������������һЩС�������ʶ������ˡ�
LONG
	);
	set("exits",([
		"northeast" : __DIR__"wwroad4",
		"northwest" : __DIR__"wwroad3",
		"south" : __DIR__"sroad2",
	]));
set("outdoors", "changan");
	setup();
}
