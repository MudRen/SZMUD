// Code of ShenZhou
// Room: fushou2.c ��������Ϣ��

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��������Ϣ��");
        set("long", @LONG
���Ǹ����ֽӴ�����Ů���ǵ���Ϣ�ң�����Ů���ӻ�ɽ֮ǰͨ���ڴ˽���
һ�ޣ��ñ���������ɽ�����ڰ���һ�ų�������ǽ���м���ľ����
LONG
        );

        set("sleep_room", 1);
        set("no_fight", 1);

	set("exits", ([
	    "southdown" : __DIR__"fushou3",
	]));

	create_door("southdown", "ľ��", "northup", DOOR_CLOSED);

	set("cost", 0);
        setup();
	//replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        object *inv;
        int i;

        inv = all_inventory(me);

        if ( dir == "southdown" ) {
                for (i=0; i<sizeof(inv); i++) {
                        if (inv[i]->is_character())
                        return notify_fail("�㲻�ܴ�����������뿪��Ϣ�ҡ�\n");
                }
        }

        return ::valid_leave(me, dir);
}
