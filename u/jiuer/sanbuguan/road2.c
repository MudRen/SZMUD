//Cracked by shenzhou
// Room: /d/sanbuguan/road2.c
// jiuer 05/23/2002

inherit ROOM;

void create()
{
        set("short", "���");

        set("long", @LONG
��ʯ��������������졣���Բ�û��ʲô�ر�ľ��¿���������פ�㡣
��������ԼԼ�Ŀ��Կ������ݳǵ����Ƕ�ڡ�������һС��ͤ�������Ϻ�
����С��Ů��æ���Ÿ���������Ϸ���
LONG
    );
        set("exits", ([
			"east" : __DIR__"road1",
			"northwest" : __DIR__"road3",
			"west" : __DIR__"hill",
			]));
	
		set("objects", ([ 
			"/d/sanbuguan/npc/seller" : 1,
			"/d/sanbuguan/npc/girl" : 1,
			]));

		set("outdoors", "sanbuguan");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
