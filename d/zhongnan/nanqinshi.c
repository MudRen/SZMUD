// Code of ShenZhou
// road: /zhongnan/nanqinshi.c
// by sdong July, 1998

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "���᷿");
        set("long", @LONG
��������᷿����ܣ�ļ��Ǹɾ�����Ȼ���ü򵥣�ȴҲ����һ����ů
�ĸо������м���ľ����һ�����ӣ���������������ͷ��˯������������
����
LONG
        );

        set("sleep_room", 1);
        set("no_fight", 1);

        set("exits",([
		 "west" : __DIR__"liangong1",
        ]));


        set("cost", 0);
        setup();
        //replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        object *inv;
        int i;


        inv = all_inventory(me);

        if ( dir == "west" || dir == "north" ) {
                for (i=0; i<sizeof(inv); i++) {
                        if (inv[i]->is_character())
                        return notify_fail("�㲻�ܴ�����������뿪��Ϣ�ҡ�\n");
                }
        }

        return ::valid_leave(me, dir);
}



