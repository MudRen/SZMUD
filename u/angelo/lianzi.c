// lianzi. c 
// angelo's only =)
#include <ansi.h>

inherit ITEM;

void setup()
{}

int cure_ob(string);
void create()
  {
           set_name(HIR"莲子"NOR, ({"lianzi", "zi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
                  set("long", "一颗绿绿的莲子散发的淡淡的芳香,看起来好像好好吃.\n");
		set("value", 10000);
                 set("medicine", 1);
	}
	setup();
}
	
int cure_ob(object me)
{
	int force_limit, neili_limit, force_skill, add_skill, improve;


	force_limit = me->query_skill("force")*(me->query("con")*2/3);
	neili_limit = me->query("max_neili");
	force_skill = me->query_skill("force", 1);
	
        if ( neili_limit <= force_limit  )
	{
		me->add("max_neili", 20+random(20));
		me->add("neili", 100);

       message_vision(HIY "$N吃下一颗莲子，觉得甜甜的...\n" NOR);
 }

	me->unconcious();
	destruct(this_object());
	return 1;
}

