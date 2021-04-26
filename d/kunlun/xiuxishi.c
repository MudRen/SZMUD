//xiuxishi.c (kunlun)

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
���Ǽ�������᷿�����Ŵ������ţ����ߺܻ谵��������ż�����ʰ��
���������ľ�������ž�������˯����
LONG
        );

        set("sleep_room", 1);
        set("no_fight", 1);

        set("exits",([
                 "south" : __DIR__"liangong",
                  "southeast" : __DIR__"chufang",
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

        if ( dir == "southeast" || dir == "south" ) {
                for (i=0; i<sizeof(inv); i++) {
                        if (inv[i]->is_character())
                        return notify_fail("�㲻�ܴ�����������뿪��Ϣ�ҡ�\n");
                }
        }

        return ::valid_leave(me, dir);
}
