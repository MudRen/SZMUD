// Code of ShenZhou
// Room: /d/village/bighouse1.c

inherit ROOM;

void create()
{
        set("short", "ǰ��");
        set("long", @LONG
����һ�����ͨ����ש�߷����������С��������������һָ�ġ���լ���ˡ�
������ǰ��������İ���ܼ򵥣��������������ܲ��ԣ������м���Ǯ����Ҳ����
���û��������Ǹ�С��ͨ�����ҡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" :__DIR__"sroad4",
  "east" :__DIR__"bighouse2",
]));
        set("no_clean_up", 0);

        set("cost", 1);
        setup();
        replace_program(ROOM);
}
