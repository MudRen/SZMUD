// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "ɮ��");
        set("long", @LONG
������һ��ɮ�¾�ס�ĵط���һ��Ϊľ��ƽ��С����ɵ�СԺ��ɮ�´�
�༯����һ����СԺ�ڽྻ���أ��徲���š�СԺ֮����С����ͨ��ÿ��ɮ
��ͨ����������ɮ�¡�������ʱ��Ժ��
LONG
        );
	set("no_fight", "1");
        set("no_steal", "1");
	set("sleep_room",1);
        set("exits", ([
                "east" : __DIR__"zoulang",
                "north" : __DIR__"shilun",
		"south" : __DIR__"jingtang",
        ]));


	set("cost", 1);
        setup();
}
void init()
{
add_action("do_get", "get");
}
int do_get(string arg)  
{
        object obj;

        if( arg
        && objectp(obj = present(arg, environment(this_player())))
        && obj->is_character() ) {
                write("�㲻�ܰᶯ��ҵ����塣\n");
                return 1;
        }
        else
                return 0;
} 

