//Cracked by Roath
//
inherit ROOM;

void create()
{
        set("short", "Ӫ��");
        set("long", @LONG
��������������ʳ��ӵĵط����е�������˯������
��˯�͸Ͻ��ɡ�
LONG
        );
        set("sleep_room",1);

        set("exits", ([
                "east" : __DIR__"jiaochang",
        ]));

        set("cost", 1);
        setup();
        replace_program(ROOM);
}

