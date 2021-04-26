// Code of ShenZhou
// Room: /d/heimuya/jiudian.c
// Date: fear 1999/12/08

inherit ROOM;




void create()
{
        set("short", "ƽ���Ƶ�");
        set("long", @LONG
������ƽ����Ψһ�ľƵ꣬��̨��һ����������
�ϴ���ƺ����ƿͲ��ֻ࣬��һ�������������ƿ���
�ڶ����ӡ��Ƶ�Ķ��ߴ��ſ���ƽ���ݵı����֡�
LONG
        );

        set("exits", ([
                "east" : __DIR__"northstreet1",
        ]));

        set("objects", ([
                __DIR__"npc/dianban" : 1,
                __DIR__"npc/jiuke" : 1,
        ]));

        set("cost", 1);
        setup();
        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if( present("xiao er", me) && dir="east" )
                return notify_fail("�ö˶˵��������С��������ȥ����\n");

        return ::valid_leave(me, dir);
}

