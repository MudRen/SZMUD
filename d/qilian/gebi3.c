// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
̧����ȥ����ããһƬɳĮ�����޾�ͷ, ֱ����ߣ�����ɳ���ʳ���
�������в�ˮ�������Կɼ�Щ��ݻ�ɳ�ݡ�������פ��ʱ�����˴��ɳ
�á�ɳ��ʲô�ġ�
LONG
        );
        set("exits", ([
                "north" : __DIR__"gebi4",
                "south" : __FILE__,
		"east" :__DIR__"gebi2",
		"west" :__DIR__"gebi1",
        ]));


	set("cost", 4);
        set("tjjob", 6);
	set("outdoors", "qilian-shan");
        setup();
}

int valid_leave(object me, string dir)
{
	object *ob;
	int i;

        if ( dir == "south")
            me->add_temp("mark/steps",-1);
	if (me->query("ridable"))
            me->delete_temp("mark/steps");
	if( !me->query("rided") && me->query("id") != "camel"){
            me->add("jingli", -50);
            me->add("water", -50);
        if(me->query("water") < 0)
            me->set("water", 0);
        }
     if (me->query_temp("mark/steps") == -6)
            {
	ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++){
        if( ob[i]->query("rider") == me )
        ob[i]->move("/d/qilian/gebi");
	ob[i]->delete_temp("mark/steps");
	}
	me->move("/d/qilian/gebi");
           me->delete_temp("mark/steps");
	 return notify_fail("���ߵ����̲�ı�Ե�ˡ�\n");
}

        return ::valid_leave(me,dir);
}
