//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","��ˮ��");
	set("long",@LONG
��������ޱȣ��Ǿ��������ĵط�������������ͷ��Ӭ��������������
Щ�߲���������ؤ����������
LONG
	);
	set("exits",([
		"northeast" : __DIR__"wroad2",
	]));
	set("objects",([
                 "d/city/npc/qigai":1,
                 "d/city/npc/dog":1,
                 "d/city/npc/liumang":1,
        ]));
set("outdoors", "changan");
	setup();
}
