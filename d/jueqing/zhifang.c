// Filename:   /d/jueqinggu/zhifang.c
// Program:    Jiuer
// Date:       Aug 15, 2001

#include <ansi.h>
inherit ROOM;
void create()
{
		  set("short","芝房");
		  set("long",@LONG
这是芝房，平时房门紧琐，闲人不得入内，听说庄主在芝房存放了
一株生长四百多年的灵芝。芝房北窗上摆着一白玉盆(pot)。
LONG);
		  set("exits",([ 
			  "south" : __DIR__"changlang3",
			  ]));

		  set("item_desc", (["pot" : HIW"一个白玉花盆，盆里种养着一只灵芝(ling zhi)。\n"NOR,
			  "ling zhi" : YEL"一株已生长了四百多年的灵芝。\n"NOR,
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
			message_vision("$N一见这百年的灵芝，不禁两眼放光，伸手把灵芝折了下来。\n",me);
			obj = new("/clone/drug/lingzhi");
			obj->move(me);
			write("你顺手把灵芝揣进怀里。\n");
			add("lingzhi_count", -1);
			return 1;
		}
		return notify_fail("灵芝已被折走了。\n");
	}
}
