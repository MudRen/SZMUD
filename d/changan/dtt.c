//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
        set("short","��ͷ̨");
	set("long",@LONG
������ǹ��������̵ĵط���һ���ߴ��̨���Ϲ�������ѩ���Ĵ󿳵���
���˸о���һ����ɭɭ�Ŀֲ�������һ�������ų�������š�
LONG
	);
	set("exits",([
        "northdown":__DIR__"xiaolu",
        "eastdown":__DIR__"luanfd",
	]));
set("outdoors", "changan");
	setup();
}
