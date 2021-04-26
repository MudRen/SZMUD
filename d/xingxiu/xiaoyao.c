// Code of ShenZhou
// Xiaoyao.c:  the sleeping room for Xingxiu
// Jay May 13, 96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��ң��");
        set("long", @LONG
����һ���ֲڵ�ʯ�����������˼��ų����Ĳݵ��ӡ������Ա�
��һЩ�ƾƹ��ӡ�����(wall)����Щ�ּ���
LONG
        );

//        set_light(0);
        set("sleep_room", "1");
        set("no_fight", "1");

        set("exits", ([
                "out" : __DIR__"xxh6",
        ]));

        set("item_desc", ([
                "wall" : "�����������˵ö���֮��\n",
        ]) );
	set("cost", 1);
        setup();
}
int valid_leave(object me, string dir)
{
        object *inv;
        int i;
        inv = all_inventory(me);
        if ( dir == "out" || dir == "enter" ) {
                for (i=0; i<sizeof(inv); i++) {
                        if (inv[i]->is_character())
                        return notify_fail("�㲻�ܴ�����������뿪��Ϣ�ҡ�\n");
                }
        }
        return ::valid_leave(me, dir);
}