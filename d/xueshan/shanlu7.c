// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����ǿ��������ĳ�ɽ���룬��ʯ��ᾡ�������ȥ���Ǵ�����Ե�ˡ�
������һ��ѩɽ�������ơ�·������һ����ѩ��(hollow)��
LONG
        );
        set("exits", ([
                "northdown" : __DIR__"shanlu6",
		"westup" : __DIR__"shankou",
		"eastdown" : "/d/emei/chuanxi2",
		"down" : "/d/chengdu/chuanxi2",
        ]));
	set("item_desc", ([
	"hollow" : "һ��ѩ�ӣ��ƺ�������(jump)��ȥ��\n",
	]));
	set("objects", ([
                __DIR__"npc/liu" : 1,
        ]));

	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
}
void init()
{
        add_action("do_jump", "jump");
}
int do_jump(string arg)
{
	int i;
	object me, *ob;
        me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="hollow"){
    message_vision("$N����������������ѩ����һ������ߴһ��ˤ���ӵס�\n", me);
                        message("vision",
        me->name() + "����һ������ߴһ��ˤ�����ˡ�\n",
                                environment(me), ({me}) );
		ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++){
        if( ob[i]->query("rider") == me )
        ob[i]->delete("rider");
	me->delete("rided");
	}
                        me->move("/d/qilian/underxs");
                        message("vision",
    me->name() + "ͻȻ��ߴһ��������ˤ�����\n",environment(me), ({me}) );
	return 1;
	}
}
