/*-------------------------------------------------------------
** 文件名: qianceng-xue.c
** Copyright (c) 2000-2001
** 创建人: 叶枫
** 日  期: 2001/08/13
** 描  述: 巧克力
**-----------------------------------------------------------*/
#include <ansi.h>
inherit ITEM;

string *paizi = ({HIW"吉百利"NOR,HIY+"德芙"+NOR,HIY+"金帝"+NOR,HIC+"Kisses"+NOR,HIC+"M&M"+NOR});
void create()
{
	string pz = paizi[random(sizeof(paizi))];
        set_name(pz+YEL"巧克力"NOR, ({"qiaoke li"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("s_name","巧克力");
                set("long", "这是一块"+pz+"出品的纯巧克力。\n");
		set("unit", "块");
                set("value", 100);
                set("remaining", 16);
        }

        setup();
}

void init()
{
        add_action("do_drink", "eat");
}

int do_drink(string arg)
{
	int mjl = 5 + random(10);
	
        if (arg!="qiaoke li") return 0;
        if (this_player()->is_busy())
                return notify_fail("你上一个动作还没有完成。\n");

        set("value", 0);
	if ((int)this_player()->query("food") 
                >= (int)this_player()->max_food_capacity() ) 
		return notify_fail("你已经吃得太多了，再也撑不下任何东西了。\n"); 

        this_player()->add("food", random(2));

        if( this_player()->is_fighting() ) this_player()->start_busy(2);

        add("remaining", -4);
        if (query("remaining")) {
		message_vision("$N瓣了一块"+this_object()->name()+"，放在嘴里，只觉得丝一般的滑顺。\n",this_player());
        } else {
		message_vision("$N将最后一块"+this_object()->name()+"也放在嘴里，只觉得丝一般的滑顺。\n",this_player());
			if (this_player()->query("add_jingli") != "Added"){
	                this_player()->add("max_jingli",mjl);
	                this_player()->add("eff_jingli",mjl);
	                this_player()->set("add_jingli","Added");
                }
                destruct(this_object());
        }
        return 1;
}

