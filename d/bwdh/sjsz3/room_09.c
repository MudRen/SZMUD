// Code of ShenZhou
// group bwdh/room 09
// 

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create() {
	 set("short", HIW"ɽ��"NOR);
	 set("long", @LONG
������һ�����͵�ɽ����ͨ���վ���ɽ�塣���������Ҫ������һ�ذѵ������Ī�С�
����ͨ��Х�ƻ�̳�����ڱ����صĻ�Ҫ֮�ء�
LONG
    );
    set("exits", ([
        "west"      : __DIR__"room_07",
        "east"      : __DIR__"etang",
	 ]));
    create_room();
	 setup();
    message("vision","�����ص�һ�����Զ������ˣ�",this_object());
}

void init() {
	 init_room();
}
