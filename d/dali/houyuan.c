// Code of ShenZhou
inherit ROOM;

void create()
{
        set("short", "后院");
        set("long", @LONG
一个小小的庭院，当中一棵公孙树上一片黄叶缓缓飞落，
你脚下落叶沙沙作响。
LONG
        );
        set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}




























