// Code of ShenZhou
// Room: /d/emei/house1.c С����
// Shan: 96/07/09

inherit ROOM;

void create()
{
        set("short", "С����");
	set("long", @LONG
����һ��С���ݣ���������һ��ũ�ҵķ��ӡ�����򵥵ذ���Щ�Ҿߣ�ǽ
�������Щũ�ߡ���������һ�������ź�һ��С���������˳����������ɫ��
�ŵ������㡣
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	  "north" :__DIR__"emroad6",
]));
        set("objects", ([
                __DIR__"npc/oldwoman": 1,
		"/d/village/npc/kid": 1,
]) );
        set("no_clean_up", 0);

	set("cost", 0);
        setup();
        replace_program(ROOM);
}
 
