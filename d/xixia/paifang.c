// Code of ShenZhou
// RYU 1/5/97
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��Ů�Ʒ�");
        set("long", @LONG
�������ǰ��һ���ߴ��ʯ��������д�š���Ů�Ʒ����ĸ��ֽ�
���֣����������Զ���þ���ɹ���ܣ��Ѿ��Ե���Щ�����ˡ�
LONG
        );
        set("exits", ([
        ]));


        setup();
        set("outdoors","xixia");
        replace_program(ROOM);
}
