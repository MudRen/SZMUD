// Code of ShenZhou
// Room: /d/village/sroad3.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ��������С���ӣ�ϡϡ����ķֲ��ż�ʮ�������෿�����������˼�
���࣬���Ҵ�����ܼ���������һ���ϱ������ʯ·��������һ���ںڰ�����
С���ӡ�
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"sroad4",
  "south" : __DIR__"sroad2",
  "west"  : __DIR__"alley1",
]));
        set("no_clean_up", 0);
        set("outdoors", "xxx");

	set("cost", 1);
        setup();
        replace_program(ROOM);
}


