//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","Ǯׯ");
	set("long",@LONG
����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ�����ض��зֵꡣ����
�е���Ʊ�����ǳ��ã�ͨ��ȫ����
LONG
	);
	set("exits",([
		"east" : __DIR__"nroad3",
	]));
        set("objects", ([ 
                __DIR__"npc/bankhuoji" : 1,
]));

	setup();
}
