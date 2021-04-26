// Code of ShenZhou
// jitan.c ��̳
// Ryu

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY"��̳"NOR, ({ "fa tan", "altar", "tan" }) );
	set_weight(300000);
	set_max_encumbrance(5000000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ�������Ӵ��ͭ�Ƽ�̳����Լ���ɣ���ԲԼ�����ɣ����ǵ����·�������\n"
			    "��ָ������ģ������֮����ʮ�귽�ɡ�\n");
		set("value", 1000);
		set("material", "wood");
		set("no_get",1);
	}
	setup();
}

int is_container() { return 1; }

void init()
{
	add_action("do_put", "put");
	add_action("do_light", "light");
	add_action("do_spray", "peng");
	add_action("do_dazuo", "dazuo");
	add_action("do_wave", "wave");
	add_action("do_spray", "spray");
}

int do_put(string arg)
{
	object me, obj;
	string item, target; 
	int amount;

	me = this_player();

	if( !arg || sscanf(arg, "%s in %s", item, target) != 2 )
                return notify_fail("��Ҫ��ʲô�����Ž����\n");
                
        if( item == "all" ) {
		write("����һ��һ�����ɡ�\n");
		return 1;
	}
                                                                
	sscanf(item, "%d %s", amount, item);
	
	if( !objectp(obj = present(item, me)) )
		return notify_fail("��Ҫ��˭ʲô������\n");

	if( obj->query("id") != "corpse"){
		write("�㲻����̳�������������\n");
		return 1;
	}
}
int do_light(string arg)
{
	object  me = this_player();

	if (!present("fire", me))
		return notify_fail("��Ҫ��ʲô���\n");
	if (!query("in_use"))
		return notify_fail("��Ҫ��ȼʲô��\n");
        if (!id(arg))
                return notify_fail("��Ҫ��ȼʲô��\n");
	message_vision(HIR"$N��ȼ�˼�̳�е�ľ�������ͣ������һ�������\n"NOR, me);
	set("burning", 1);
	set("pending", me->query("name"));
	set("long", query("long") + HIR"����ȼ�����ܵĻ��档\n"NOR);
	set("in_use", 0);
	remove_call_out("burning");
        call_out("burning",20+random(20), me);
	return 1;
}
void burning(object me)
{
	int point;
	point = me->query_temp("award_pending")*10/me->query("combat_exp");
	point = point * me->query_skill("lamaism")/12;
	if (me->query("combat_exp") < 150000) point = point/2;
	message_vision(BLU"һ˿����������̳��ȽȽ���𡣻�����$N�𷨸��٣��ǻ���ȥ��\n"NOR, me);
	if (me->query_temp("award_pending"))
	me->add("potential", point + random(point/2));
	if (me->query_temp("award_doubling"))
	me->set("potential", me->query("max_potential"));
	if (me->query("potential") > me->query("max_potential"))
	me->set("potential", me->query("max_potential"));
	set("wait_for_spray", 1);
}
int do_spray(string arg)
{
	object  ob, me = this_player();
	ob = (present("lubo", me));
	
	if (!present("lubo", me))
		return 0;
	if (me->query("name") != query("pending"))
		return notify_fail("��������ʲô���֣�\n");
	if (!query("wait_for_spray"))
		return notify_fail("ʱ��δ����\n");
	if (!id(arg))
                return notify_fail("�������Ķ��磿\n");
	if (ob->query("liquid/remaining") < 1)
		return notify_fail("­�������ˮ�Ѿ���ʣ�޼��ˡ�\n");

	message_vision(HIW"$N����­������һ��ˮ�����ۡ���һ���͵س������ܻ����罫��ȥ��\n"NOR, me);
	ob->add("liquid/remaining", -1);
	set("wait_for_spray", 0);
	set("time_to_dazuo", 1);
	return 1;
}
int do_dazuo()      
{
	object me = this_player();
	
	if (me->query("name") != query("pending"))
                return notify_fail("���ʲô���֣�\n");
	if (me->query("neili") < 600)
		return notify_fail("������������\n");
	if (!query("time_to_dazuo"))
                return notify_fail("�ⲻ���������ʱ��\n");

	message_vision(HIY"$N���ȴ�����������̣����������дǣ�������һ˿������$N��ǰ���۳��Ρ�\n"NOR, me);
	me->start_busy(20);
	remove_call_out("rise");
        call_out("rise",20+random(20), me);
	return 1;
}
void rise(object me)
{
       message_vision(BLU"����Խ��Խ�࣬��Ȼ�ʳ����Σ� $N��ָ���Σ��������ԣ�ָ������֮·��\n"NOR, me);
	me->add("neili", -600);
	if (me->query_temp("award_pending")*10/me->query("combat_exp") >= 16)
        me->add("max_neili", me->query_skill("lamaism", 1)/60);
        if (me->query_temp("award_doubling"))
        me->add("max_neili", me->query_skill("lamaism", 1)/10);
        set("time_to_dazuo", 0);
	set("time_to_wave", 1);
}
int do_wave(string arg)
{
	object weapon, me = this_player();

	if (!arg && arg != "ling" && arg != "fa ling")
		return notify_fail("��Ҫҡʲô��\n");
		
	if (!present("fa ling", me))
		return notify_fail("��Ҫҡʲô��\n");

	if (me->query("name") != query("pending"))
                return notify_fail("��������ʲô���֣�\n");

	if ( !objectp(weapon = me->query_temp("weapon"))
	|| (me->query_temp("weapon"))->query("name") != "����")
		return notify_fail("������û������������\n");
	
	if (!query("time_to_wave"))
		return notify_fail("ʱ��δ����\n");

	message_vision(CYN"$N�ֳַ��壬���߱�ҡ�������ж��ܴ����䡣ͻȻ���һ��������������\n"NOR, me);
	set("time_to_wave", 0);
	remove_call_out("close_up");
        call_out("close_up",20+random(20), me);
	me->start_busy(20);
	return 1;
}
void close_up(object me)
{
	object ob = this_object();
	int gaining;
	gaining = me->query_temp("award_pending")*10/me->query("combat_exp");
	gaining = 14 * gaining;
	if (gaining > 300) gaining = 300;	
	if (me->query("combat_exp") < 80000)
	gaining = gaining/3;
	if (me->query("combat_exp") > 80000 && me->query("combat_exp") < 100000)
	gaining = gaining/2;

	message_vision(HIW"��Ժ���ã����һ����������ָֻ���ƽ����������ϡ�\n"NOR, me);
	set("long", "����һ�������Ӵ��ͭ�Ƽ�̳����Լ���ɣ���ԲԼ�����ɣ����ǵ����·�������\n"
    		    "��ָ������ģ������֮����ʮ�귽�ɡ�\n");
	set("long", query("long") + RED"����ȼ�ŵĻ����Ϩ���ˡ�\n"NOR);
	me->improve_skill("lamaism", me->query("int"));
	me->add("jingli", -300, "���Լ�������");
	set("burning", 0);
	if (me->query_temp("award_pending"))
        me->add("combat_exp", gaining + random(gaining/2));
       // if (me->query_temp("award_doubling"))
        //me->add("combat_exp", (int)me->query_temp("award_pending")/50);	
	me->delete_temp("award_pending");
	me->delete_temp("award_doubling");
	me->delete_temp("marks/��");
	if (random(me->query("potential")) > me->query_con()*3)
	me->unconcious();
	remove_call_out("renewing");
        call_out("renewing", 50 + random(100), ob);
}
void renewing(object ob)
{
	ob->set("last_burner", ob->query("pending"));
	ob->set("pending", 0);
	ob->set("long", "����һ�������Ӵ��ͭ�Ƽ�̳����Լ���ɣ���ԲԼ�����ɣ����ǵ����·�������\n"
    			"��ָ������ģ������֮����ʮ�귽�ɡ�\n");
}				 
