// room /d/wulin/xiaolu4.c
//updated by Lara 2001/10/17
inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
С·�����ѵ���ͷ�����ƾӹ�����������ɽ�������ֲ������ࡣ�䲼
�ּ��ѣ�����Χ��ľ��Ȼһ�塣
LONG
        );

        set("exits", ([
         "east" : __DIR__"shangjue",
         "west" : __DIR__"shangjuw",
         "south" : __DIR__"xiaolu3",
 ]));

        set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

