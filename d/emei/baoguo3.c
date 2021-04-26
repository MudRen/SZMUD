// Code of ShenZhou
// Room: baoguo3.c ����������

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "����������");
        set("long", @LONG
���Ǳ����µ������������е��ӻ�ɽ֮ǰͨ���ڴ˽���һ�ޣ��ñ���
������ɽ�����ڰ���һ�ų�������ǽ���м���ľ����
LONG
        );

        set("sleep_room", 1);
        set("no_fight", 1);

	set("exits", ([
	    "east" : __DIR__"baoguo1",
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

        if ( dir == "west" ) {
                for (i=0; i<sizeof(inv); i++) {
                        if (inv[i]->is_character())
                        return notify_fail("�㲻�ܴ�����������뿪��Ϣ�ҡ�\n");
                }
        }

        return ::valid_leave(me, dir);
}
