// room /d/wulin/fajuw.c
//Lara 2001/10/19
inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
���������ķ���ʹ�ߵľӴ���Ŀǰ�����ǿյġ�
LONG
        );

        set("exits", ([
         "east" : __DIR__"xiaolu8",        
        ]));

        set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
