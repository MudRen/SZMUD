// Code of ShenZhou
// Room: /d/quanzhou/zahuopu.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
������һ��ר��Ů���õĶ�����С���ӡ�
LONG
	);

	set("exits", ([
                "south" : __DIR__"citong_w1",
	]));

	set("objects", ([
                 __DIR__"npc/chen" : 1,
    	]) );

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

