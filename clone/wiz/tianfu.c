// Code of ShenZhou
// jiuzhuan-huanhundan.c ��ת���굤�Ĵ���Ʒ

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
	log_file("OBJECTS", sprintf("%s(%s)�õ�һ���츣��(%O)\n", 
			this_player()->query("name"), getuid(this_player()), this_object()));
}

void create()
{
	set_name("�츣��", ({"tianfu dan", "tianfu", "dan"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һö��˸�Ű׹���츣������˵ֻ�д�����������ܵõ���\n");
		set("value", 1);
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
	return notify_fail("��Ҫ��ʲô��\n");
	
        if (id(arg) && me->query("JzHhD") == "3")
	return notify_fail("�Զ���Ҫ���µģ����ǲ�Ҫ���ˣ�\n");

	message_vision(HIW "$N������һö�츣��������������һ��һ����������һ��һ�������������\n" NOR, me);
        me->set("JzHhD","3");
	log_file("OBJECTS", sprintf("%s(%s)����һ���츣��(%O) %s\n",
			me->query("name"), getuid(me), this_object(), 
			ctime(time())));
	log_file("OBJECTS", sprintf("%s(%s)��%s����(%s)���Ƶ�һ�ž�ת���굤(%O)��\n",
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