// Code of ShenZhou
// room: /d/baituo/base2
// ���ոİ�
// maco 2/17/2000

inherit ROOM;

void create()
{
        set("short", "�ܽ�");
        set("long", @LONG
�������ֲ�����ָ��ֻ�������������������䶯��������
LONG
        );
        set("exits", ([ 
	    "south" : __DIR__"base1",
        ]));
        set("objects", ([ 
	    __DIR__"npc/snake" : 2,
		"/d/foshan/npc/zsnake" : 1,
         ]) );
        replace_program(ROOM);
	set("cost", 0);
        setup();
}

