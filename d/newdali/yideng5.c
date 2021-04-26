// Code of ShenZhou
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����ɽ��Ķ��ϣ�һ���ƽ�أ����ѳɶ�ʮ��Ķɽ����ź̵���һ����ͷ
������ߣ�������б��һ����ʯ(rock)��һͷ��ţ�������ϣ������ҵţ�ȴ����
������������һ�˰����ֲ���˫�����ε���ס����ʯ��
LONG);
	set("objects", ([
		"/kungfu/class/dali/farmer" : 1,
        ]));
	set("item_desc", ([
		"rock" : "������ͷţ��˵Ҳ�����ٽ����£���ʯ�ķ�������Ҳ������ţ֮�£�����һ\n�뿿��ɽ�£�������������ס��Ҳ������������ˡ�\n",
        ]));
	set("exits", ([
		"down" : __DIR__"yideng4",
        ]));
	set("cost", 2);
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("outdoor","dali");
    set("no_sleep_room",1);
	set("invalid_startroom", 1);
	setup();
	replace_program(ROOM);
}
