// Code of ShenZhou

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"�߾�"NOR, ({ "she jing", "shejing", "jing" }) );
	set_weight(500);
//	if( clonep() )
//		set_default_object(__FILE__);
//	else {
		set("unit", "��");
		set("long", "����ѵ���ܼ���ŷ�����Ա��߹ȣ�����������������֮������������ĥ��\n"
			);
		set("value", 3000);
		set("material", "skin");
	/*	set("skill", ([
			"name": "poison",      // name of the skill
            "exp_required": 0,     // minimum combat experience req
            "jing_cost":    20,    // jing cost every time study th
            "difficulty":   15,    // the base int to learn this sk
            "max_skill":    60,    // the maximum level you can lea
			]) );
	*/
//	}
		setup();
}
void init()
{  
	add_action("do_du", "du");
}

int do_du(string arg)
{
	object me = this_player();
	int level, check;
	object where;

	seteuid(getuid());
	where = environment(me);

	if(!present("she jing", me)) return 0;

	if(where->query("pigging"))
		return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

	if (where->query("sleep_room")) {
		write("������˯������������Ӱ�����ˡ�\n");
		return 1;
	}
	if (where->query("no_fight")) {
		write("����������ǣ��޷�ר��������\n");
		return 1;
	}
	if (where->query("name") == "����") {
		write("����̫����, �޷��ж��߾��� \n");
		return 1;
	}
	if (me->is_busy() || me->query_temp("pending/exercising")) {
		write("��������æ���ء�\n");
		return 1;
	}
	if( me->is_fighting() ) {
		write("ս���л���ĥ�߾�������ѽ��\n");
		return 1;
	}
	if( me->query("rided")) {
		write("����������ĥ�߾���С����·��\n");
		return 1;
	}
	if(!arg || arg != "she jing") 
	{   
		write("��Ҫ����ʲô��\n");
        return 1;
	}
	 level = (int)me->query_skill("poison",1);
   check = level*level*level;

    if ( level < 61) {
        write("�������Զ�����ڸ�����޷�����\n");
        return 1;
   }
   if ( level > 100) {
        write("�������Զ���̫ǳ��û���κΰ�����\n");
        return 1;
   }
   if (check > (int)me->query("combat_exp")*10 ) {
        write("��ʵս���鲻�㣬�޷�����\n");
        return 1;
   }
   if ( (int)me->query("jing") < 30 ) 
   { 
	   write("�㾫���޷����С�\n");
	   return 1;
   }

   me->receive_damage("jing", 20);
   me->improve_skill("poison", me->query("int"));
   write("�㰴���߾���ע�͵�Ҫ�죬��ϸ��ĥ������\n");
   return 1;
}
