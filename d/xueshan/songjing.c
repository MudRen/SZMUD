// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "�о���");
        set("long", @LONG
������ɮ���Ƕ��о���ĵط������ص����š���ǰ���Ǽ��ܡ���η��ʤ��
�����յĵ��񣬵�����ɢ����һЩ���顣
LONG
        );
        set("exits", ([
                "west" : __DIR__"yanwu",
        ]));

	set("objects",([
	"d/qilian/obj/fojing1" : 1,
	]));
	set("cost", 1);
        setup();
        replace_program(ROOM);
}
