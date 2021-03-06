// Code of ShenZhou
// jiuzhuan-huanhundan.c 九转还魂丹的代替品

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
	log_file("OBJECTS", sprintf("%s(%s)得到一颗天福丹(%O)\n", 
			this_player()->query("name"), getuid(this_player()), this_object()));
}

void create()
{
	set_name("天福丹", ({"tianfu dan", "tianfu", "dan"}));
	set_weight(10);
                set("medicine", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一枚闪烁着白光的天福丹，据说只有从神仙那里才能得到。\n");
		set("value", 1);
                set("no_sell", 1);
	}
	set_color(HIW);

	setup();
}

int do_eat(string arg)
{
	mapping skill_status;
        string *sname;
        int i, point, count, new_shen, new_exp, new_pot;
	object me = this_player();
	object ob = this_object();

	if (!id(arg))
	return notify_fail("你要吃什么？\n");
	

	message_vision(HIW "$N服下了一枚天福丹，但觉外日月一往一来，内日月一颠一倒，功力大进！\n" NOR, me);
	log_file("OBJECTS", sprintf("%s(%s)吃下一颗天福丹(%O) %s\n",
			me->query("name"), getuid(me), this_object(), 
			ctime(time())));
	log_file("OBJECTS", sprintf("%s(%s)于%s吃下(%s)复制的一颗九转还魂丹(%O)。\n",
			me->query("name"), getuid(me), ctime(time()),
			this_object()->query("cloner"), this_object()));
			

/*        if ( me->query("death_count") > 0 ) {
                me->add("death_count", -1);
                if ((int)me->query("death_times") > (int)me->query("death_count"))
			me->set("death_times", (int)me->query("death_count"));
        } else {
		COMBAT_D->death_penalty(me);
		me->set("death_count", 0);
		me->set("death_times", 0);
		destruct(ob);
		return 1;
	}
*/
	if ( mapp(skill_status = me->query_skills()) ) {
                skill_status = me->query_skills();
                sname = keys(skill_status);
                count = sizeof(skill_status);

                for(i=0; i<sizeof(skill_status); i++) {
			point = (skill_status[sname[i]]+1)*(skill_status[sname[i]]+1)/2+1;
			while ( (point /= 2) > 0 )
                        	me->improve_skill(sname[i], point+1); 
                }
        }

	new_shen = (int)me->query("shen") / 0.9;
        new_exp = (int)me->query("combat_exp") / 99;
        if (new_exp > 5000) new_exp = 5000;

//        new_pot = (int)me->query("potential") - (int)me->query("learned_points");

	me->set("shen", new_shen);
        me->add("combat_exp", new_exp);
//        me->add("potential", new_pot);
//      me->add("balance", me->query("balance"));
	destruct(ob);
	return 1;
}
