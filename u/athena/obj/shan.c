
// 苏梦馨(Athena)
// OBJ：/u/athena/obj/shan.c

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void init()
{
        add_action("do_shan","hui");
}

void create()
{
	set_name(YEL "檀香扇" NOR, ({ "tanxiang shan", "shan"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
                set("fen", 5);
		set("long", "这是把用上等香木制成香扇，散发着一丝轻香。\n");
		set("value", 10000);
		set("material", "wood");
                set("no_get",1);
		set("wield_msg", HIY "$N展开扇子，轻轻的扇了扇风。\n" NOR);
		set("unwield_msg", HIY "$N刷的一声合上扇子，放回袖中。\n" NOR);
	}
	init_sword(100);
	setup();
}

int do_shan(string arg)
{
       object me, ob;
       string name1, name2;

       if (!arg) return notify_fail("你要毒谁？\n");
       me = this_player();
       ob = present(arg, environment(me));
       if (!ob) return notify_fail("找不到这个生物.\n");
       if( this_object()->query("fen") <=0)
               return notify_fail("毒粉已经用光了。\n");
       name1 = (string)me->query("name");
       name2 = (string)ob->query("name");       
       tell_room(environment(me),
      HIY + name1+"用扇子对"+name2+"轻轻挥了挥。\n\n", NOR,
       ({me, ob}));
       
       tell_object(ob, HIW "你感觉好象有什么粉末飘到了身上。。。\n" NOR);
       tell_object(me, HIW "你用扇子对"+name2+"轻轻一挥。\n" NOR);
       this_object()->add("fen", -1);
       ob->delete("env/immortal");
       ob->unconcious();
       return 1;
}

