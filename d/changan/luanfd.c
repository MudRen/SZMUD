//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","�ҷض�");
	set("long",@LONG
���ﶼ��һЩ��֪�������߱��ٸ�ն�׵�����ʬ�ĵط���һ�������ż��
����������������ݡ�
LONG
	);
	set("exits",([
		"northwest" : __DIR__"luansg",
          "westup" : __DIR__"dtt",
	]));
set("outdoors", "changan");
	setup();
}