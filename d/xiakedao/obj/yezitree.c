//Cracked by Roath
// yezitree.c
// By ssy

#include <ansi.h>

inherit ITEM;
void reset_count();
int t0;

void create()
{
	set_name("Ҭ����",({"yezi tree", "tree"}));
	set_weight(900000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ�ø߸ߵ�Ҭ���������������м�ֻҬ�ӡ�\n");
		set("unit", "��");
		set("value", 8);
		set("no_get", 1);
    	}
	t0 = uptime();
        set("yezicount",1);
}


void init()
{
        int t;
        t = uptime();
	if ((t-t0)>900)  // every 15 mins re-grow a yezi
	  {
	    t0=t;
	    set("yezicount",1);
	  }
	add_action("do_pa", "pa");
	add_action("do_pa", "climb");
}

int do_pa(string arg)
{
	object ye, me = this_player();
	int check;

	if( !arg || arg!="tree" && arg != "��" )
		return notify_fail("��Ҫ����ô��\n");
	
	if ((int)me->query("jingli") < 50)
                return notify_fail("���۵���վ��վ�������ˣ�����������\n");
        me->receive_damage("jingli", 20);
	message_vision(HIW"$N˫�ֱ�ס���ɣ�������������������\n"NOR,
		       me);
        if ((int)me->query_skill("dodge", 1) >= 10)
	  {
	    if (!(present("yezi", me)))
	      {
		if (query("yezicount")>0)
		  {
		    message_vision("$N������������ժ��һֻҬ�ӡ�\n", me);
		    ye = new(__DIR__+ "yezi");
		    ye->move(me);
		    add("yezicount", -1);
		  }
		else
		  {
                    message_vision("$N����������������Ҭ���Ѿ�����ժ���ˡ�\n", me);
		  }
	      }
	    else
	      {
                message_vision("$N��������������ժһֻҬ�ӣ�û�뵽�����Ѿ�������һֻ��һ�������񣬴���������������\n", me);
		if ((int)me->query("qi") > 30)
		  me->receive_damage("qi", 20);
		else me->receive_damage("jingli",40);
	      }
	    return 1;
	  }
        check = (int)me->query_skill("dodge",1)*
	  (int)me->query_skill("dodge",1)*
	  (int)me->query_skill("dodge",1);
        if (check > (int)me->query("combat_exp") * 10)
	  {       
	    write ("��ʵս���鲻�㣬���˰���ȫ�޳�����\n");
	    return 1;
	  }

	me->improve_skill("dodge", me->query("int"));
        return 1;
}

