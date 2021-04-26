// Filename:   /d/jueqinggu/qinghuaao6.c
// Program:    Jiuer
// Date:       Aug 15, 2001

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short",HIM"�黨԰"NOR);

		  set("long",@LONG
����һƬ�������ɵ�԰�βݵأ�������ܲ���Χ�����黨��
���۴��ĸ���λ���������а˾��ɵ��������黨��
LONG);

	  set("exits",([ 
		"north" : __DIR__"caodi",	
		"northeast" : __DIR__"qinghuaao1",
	    "northwest" : __DIR__"qinghuaao5",
		]));
	  set("objects", ([ 
		  "/d/jueqing/npc/jiading" : 1,
		  ]));
	  set("cost",1);
	  setup();	
}

int valid_leave(object me, string dir)
{
	if ((dir == "northwest") && !wizardp(me)) {
		if ( !me->is_fighting() )
			if (objectp(present("jiading", environment(me))))
				return notify_fail("�����˵�ס�����ȥ·��������������˵�һ�ɲ������ڡ�\n");
			else return ::valid_leave(me, dir);
		else {
			message_vision(HIR"�鼱֮�У�$N���ֲ��������봩�����ԣ���ָȴ�����䱳������С�̴����ˡ�\n\n"NOR,me);
			me->apply_condition("qh_poison",10);
			return ::valid_leave(me, dir);
		}
	}
	else return ::valid_leave(me, dir);
}