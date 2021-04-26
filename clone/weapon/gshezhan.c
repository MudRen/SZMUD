// Code of ShenZhou
// guaishezhang.c
// sdong, 11/20/98

#include <weapon.h>
#include <ansi.h>

inherit STAFF;

string long_desc();

void create()
{
	set_name(HIB"������"NOR, ({ "guai shezhang", "staff", "shezhang" }));
	set_weight(4000);
	set("unit", "��");
	set("long", (: long_desc :));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", (: long_desc :));
	}
		set("value", 450);
		set("material", "steel");
		set("snake_type","����");
//***** ADDED BY SCATTER *****
                       set("wposition", "/clone/weapon/gshezhan.c");
//***** END OF ADDING *****
		set("wield_msg", HIW"$N���һ��$n"+HIW"�������У��ȶ˵���ͷ�������죬���˲���������\n"NOR);
		set("unwield_msg", "$N�����е�$n����������\n");
		init_staff(35);
		setup();
}
string long_desc()
{
		  string desc ;
		  object staff = this_object();

		  desc = HIB"һ�����������ĺ�ɫ���ȣ����Ǹ������ƣ���ͷ���Ÿ��ѿڶ�Ц����ͷ����ͷ����¶������ѩ�׵����ݣ�\nģ�������������죬\n"NOR;

		  if( staff->query("snake")==1 ) desc += HIW"��������һ������������С�ߣ���ס���������¡�\n"NOR;
		  else if ( staff->query("snake")==2 ) desc += HIW"����������������������С�ߣ���ס���������¡�\n"NOR;
		  
		  return desc;
}

void init()
{
		  add_action("convert","convert");
}

int convert(string arg)
{
		  object me = this_player();
		  object ob;

		  if (arg!="shezhang" && arg!="staff" && arg!="zhang") return 0;
		  if (me->query("family/family_name") != "����ɽ")
					 return notify_fail("�㲻�ܻ���Ϊ�ߡ�\n");
		  if ((int)me->query("jing") < 100)
					 return notify_fail("��ľ���������\n");

	if (!present("guai shezhang", me))
		return notify_fail("������û�й����ȡ�\n");

		  if (random(me->query_skill("training",1)) <20) {
			  message_vision("$N�������������㵸�����񷢷�һ�㡣\n"
					 ,me);
			  me->receive_damage("jing", 95);
			  return 1;
		  }

		 if(query("snake") <1)return notify_fail("������û���ߡ�\n");

		  message_vision("$N�������������㵸���͵�һˤ�������ϵĶ����Ƽ�һ����˳�����\n",
					 me,);

		  //seteuid(ROOT_UID);
		  set_default_object(__FILE__);
                  ob = new("/d/baituo/npc/guaishe.c");
		  ob->move(environment(me));
		  ob->set_owner(me);
        ob->set("food",250);

		  add("snake",-1);

		  return 1;
}



