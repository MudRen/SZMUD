//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","����¥");
	set("long",@LONG
����ǳ������������Ľ���¥�ˣ���˵�����е����ˣ���[��������]����
��¥Ҳ����Ϊ����˲Ÿĳ��ֽ��������еĽ���¥������������¡������һ
Щ���𡢹ٸ����ŵ������������ͣ�Ҳ���û���˸Ҵ���Ҿ�¥�����⡣��¥
��ҵ���񣬶���ƽ�����¡�
LONG
	);
	set("exits",([

		"southeast" : __DIR__"eroad3",
	]));
set("objects", ([
     __DIR__"npc/jin.c" : 1,
]));
	
	setup();
}
