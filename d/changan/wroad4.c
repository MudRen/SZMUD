//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","���������");
	set("long",@LONG
������һ��������ʯ�����ϣ�����Ϳ쵽�������ˡ����������������
֪��ͨ��δ���һЩ�ټ�С��Ҵ�ææ�����Ǳ���ȥ�����������Ǻ�«����
Ҳ����ǰȥ�������Щ��С��������һЩ������
LONG
	);
	set("exits",([
                "east" : __DIR__"wroad3",
		"west" : __DIR__"ximen",
		"north" : __DIR__"byxiang",
	]));
set("outdoors", "changan");
	setup();
}
