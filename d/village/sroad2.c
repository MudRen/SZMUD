// Code of ShenZhou
// Room: /d/village/sroad2.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ��������С���ӣ�ϡϡ����ķֲ��ż�ʮ�������෿�����������˼�
���࣬���Ҵ�����ܼ���������һ���ϱ������ʯ·��������һ��С��������
����һ��˽�ӣ�����ѧͯ�����ʶ�������
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"sroad3",
  "south" : __DIR__"sroad1",
  "east"  : __DIR__"shouse",
  "west"  : __DIR__"sishu",
]));
        set("no_clean_up", 0);
        set("outdoors", "xxx");

	set("cost", 1);
        setup();
        replace_program(ROOM);
}


