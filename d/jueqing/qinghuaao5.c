// Filename:   /d/jueqinggu/qinghuaao5.c
// Program:    Jiuer
// Date:       Aug 15, 2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
		  set("short",HIM"�黨԰"NOR);

		  set("long",@LONG
����һƬ�������ɵ�԰�βݵأ�������ܲ���Χ�����黨������
���ĸ���λ���������а˾��ɵ��������黨��
LONG);

	  set("exits",([ 
		"northeast" : __DIR__"qinghuaao4",
		"southeast" : __DIR__"qinghuaao6",
		"westup" : __DIR__"shiliang",
		]));
	  
	  set("objects", ([ 
		  "/d/jueqing/npc/jiading" : 1,
		  ]));

	  set("cost",1);
	  setup();	
}

int valid_leave(object me, string dir)
{
	if ((dir == "westup")&& !wizardp(me)) 
	{   
		if (objectp(present("jiading", environment(me))))
			return notify_fail("�����˵�ס�����ȥ·��������������˵�һ�ɲ������ڡ�\n");
	}	
//	message_vision(HIR"�鼱֮�У������ֲ��������봩�����ԣ���ָȴ�����䱳������С�̴����ˡ�\n\n"NOR,me);
//	me->apply_condition("qh_poison",10);

	return ::valid_leave(me, dir);
}
