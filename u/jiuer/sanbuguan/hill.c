//Cracked by shenzhou
// Room: /d/sanbuguan/hill.c
//Modified by jiuer 5/27/2002

inherit ROOM;

void create()
{
        set("short", "��ʤɽ");
        set("long", @LONG
���������ݳ�����ʮ�������ĵ�ʤɽ������������䣬����������
�˴����ƽ�������ɽ������ʤ������ʵ��ɽֻ���߰��ɸߣ������Ǹ�С��
���ѡ�ɽ�Ϲ����㳤�ſúܴ�׳����������
LONG
        );
        set("exits", ([
			"east" : __DIR__"road2",
			"west" : __DIR__"yichang",
			]));
		
		set("objects", ([ 
			"/d/sanbuguan/npc/mao" : 1,
			]));
		
		set("outdoors", "sanbuguan");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
