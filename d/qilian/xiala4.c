// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
̧����ȥ����ããһƬɳĮ�����޾�ͷ��ֱ����ߡ����ﾡ��
��ɳʯ����û��һ���������ɹ����Ϊ������
LONG
        );
        set("exits", ([
                "east" : __DIR__"xiala1",
                "south" : __FILE__,
		"north" :__DIR__"xiala2",
		"west" :__DIR__"xiala3",
        ]));


	set("cost", 55555);
	set("outdoors","qilian-shan");
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
     if (me->query_temp("mark/steps") == -3)
            {
	ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++){
        if( ob[i]->query("rider") == me )
        ob[i]->move("/d/qilian/gebi7");
	}
	me->move("/d/qilian/gebi7");
           me->delete_temp("mark/steps");
         return notify_fail("�����˳�������\n");
}
 return ::valid_leave(me,dir);
}
