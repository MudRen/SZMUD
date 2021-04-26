//                标准描述长度示例                                   |
// 用来看的椅子，哈哈  ★/obj/yizi.c
// by naihe 奈何  2002-04-23
// 请勿更改本文件源码，谢谢！

#include <ansi.h>
inherit ITEM;


void create()
{
	set_name(WHT"石椅"NOR, ({"yizi", "shiyi", "yi zi"}));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "一张石料的长椅，两三人宽，有着舒服的靠背和扶手。左边的扶手刻着一行小字：\n“房间建成留念·机器人工厂荣誉出品”，右边的则刻着：“仙界2002年4月”。\n你可以坐（sit）上去休息。\n");
	set("unit", "张");
	set("value", 1);
	set("no_get","1");
	}

	setup();
}

void init()
{
	add_action("do_sit",  "sit");
//	add_action("do_sdup", "sdup");
}

int do_sit(string arg)
{
	object me , test;
	me = this_player();
//	test = present("start_busy()", me);

	if(!arg)
	{
//	me->start_busy(10);
	tell_object(me,"你正想坐下去，突然见到靠背边上刻着“坐者罚款”几个极小的字，吓得赶快跳了起来。\n");
	tell_room(environment(me),(string)me->query("name")+"正准备往石椅上坐下去，却不知怎的又跳了起来，还连连擦着冷汗。\n",me);
	return 1;
	}
	return 0;
}
/* 本来想真的做个可以休息的椅子的，突然觉得不太好，就罢了，纯粹搞搞气氛吧  ：） 。忙时以及“起来”的功能都不要了，只是看看而已  ：） */