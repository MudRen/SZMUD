// lianzi. c 
// angelo's only =)
#include <ansi.h>

inherit ITEM;

void setup()
{}

int cure_ob(string);
void create()
  {
           set_name(HIR"����"NOR, ({"lianzi", "zi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                  set("long", "һ�����̵�����ɢ���ĵ����ķ���,����������úó�.\n");
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

       message_vision(HIY "$N����һ�����ӣ����������...\n" NOR);
 }

	me->unconcious();
	destruct(this_object());
	return 1;
}

