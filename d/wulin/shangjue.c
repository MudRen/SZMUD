// room /d/wulin/shangjue.c
//Lara 2001/10/19
inherit ROOM;
void create()
{
        set("short", "���ƾ�");
        set("long", @LONG
��������������ʹ�ߵľӴ�,Ŀǰ�����ǿյġ�
LONG
        );

        set("exits", ([
         "west" : __DIR__"xiaolu4",        
        ]));

        set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
