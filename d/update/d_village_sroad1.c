// Code of ShenZhou
// Room: /d/village/sroad1.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ��������С���ӣ�ϡϡ����ķֲ��ż�ʮ�������෿�����������˼�
���࣬���Ҵ�����ܼ�����һ����ʯ·��������С��������ˣ������ͨ�����
�����ģ����Ͼ��ǳ����·�ˣ���������ңң�����ĳ����ǡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sroad2",
  "west" : "/d/changan/dongmen",
  "south" : __DIR__"sexit",
]));
        set("no_clean_up", 0);
        set("outdoors", "xxx");
        set("objects", ([
		__DIR__"npc/girl": 1,
		__DIR__"npc/boy": 1 ]),
 );

	set("cost", 1);
        setup();
        replace_program(ROOM);
}


