// Filename:   /d/jueqinggu/zhifang.c
// Program:    Jiuer
// Date:       Aug 15, 2001

#include <ansi.h>
inherit ROOM;
void create()
{
		  set("short","֥��");
		  set("long",@LONG
����֥����ƽʱ���Ž��������˲������ڣ���˵ׯ����֥�������
һ�������İٶ������֥��֥�������ϰ���һ������(pot)��
LONG);
		  set("exits",([ 
			  "south" : __DIR__"changlang3",
			  ]));

		  set("item_desc", (["pot" : HIW"һ�������裬����������һֻ��֥(ling zhi)��\n"NOR,
			  "ling zhi" : YEL"һ�����������İٶ������֥��\n"NOR,
			  ]));
		  set("lingzhi_count", 1);
		  set("cost",1);
		  setup();
	//	  replace_program(ROOM);
}

void init()
{
	add_action("do_zhe","zhe");
}
int do_zhe(string arg)
{
	object obj, me = this_player();

        if(arg == "ling zhi")
	{
		if (query("lingzhi_count") >= 1) 
		{
			message_vision("$Nһ����������֥���������۷Ź⣬���ְ���֥����������\n",me);
			obj = new("/clone/drug/lingzhi");
			obj->move(me);
			write("��˳�ְ���֥�������\n");
			add("lingzhi_count", -1);
			return 1;
		}
		return notify_fail("��֥�ѱ������ˡ�\n");
	}
}
