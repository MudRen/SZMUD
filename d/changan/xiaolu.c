//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","С·");
	set("long",@LONG
���߰�ʯ��㣬�����֣��������ޣ��ݺ����������̦޺�ɰߣ�
������ӳ������΢¶��С�������������߾͵�С�����ˣ��������Ǹ�
�������ĵط��������˸�ȥ���������������̵ķ�����ƽ�����Ž�
��û�˸ҽ�ȥ��
LONG
	);
	set("exits",([
        "northeast":__DIR__"xiaoyanta",
		"southeast":__DIR__"luansg",
                "west" : __DIR__"nroad2",
	]));
set("outdoors", "changan");
	setup();
}
