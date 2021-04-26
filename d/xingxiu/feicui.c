// Code of ShenZhou
// feicui.c ����
// maco
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIG"����"NOR);
	set("long", @LONG
ǰ���Ȼ���ʣ���һ��Ƭƽ�ء�����ȺɽΧ�ƣ�����һֻ��
��һ�㣬�������ı�ˮӨȻ��������䣬�Ǹ�Բ�εĳ���(pool)
����׵����ӳ�ڱ��̵ĳ��У����з��̣����з��ף����޽ྻ
���ľ������
LONG
	);

	set("exits", ([
		"east" : __DIR__"houshan",
	]));
	set("resource/water", 1);

	set("item_desc", ([
	"pool" : "��ˮ�ξ��峺�������˺�̦�࣬ԭ��Բ�����ܶ�����䣬��ˮ��ӳ����ɫ��\n"
		"��˵����������������ϴ����������������ϴ�˾͸��ӳ�\n",
	"����" : "��ˮ�ξ��峺�������˺�̦�࣬ԭ��Բ�����ܶ�����䣬��ˮ��ӳ����ɫ��\n"
		"��˵����������������ϴ����������������ϴ�˾͸��ӳ�\n",
	]));

	set("outdoors","xingxiu");
	set("cost", 1);
	setup();
}

void init()
{
	object *inv = all_inventory(find_object("/d/xingxiu/feicui"));
	object comer = this_player();
	int i;
	add_action("do_drink", "drink");
	add_action("do_swim", "swim");
	add_action("do_swim", "dive");
	if ( (string)comer->query("race") == "����" )
		for ( i=0 ; i < sizeof(inv); i++)
			if ( inv[i]->query_temp("feicui_swimming") ) {
				if ( inv[i]->is_spouse_of(comer) ) {
					tell_object(inv[i], HIB"�㷢�������ߵ��رߣ���ϸһ����ԭ�������" + inv[i]->query("spouse/title") + "���龪һ����\n"NOR);
					message("vision",CYN + comer->name() + "��������ĵ�һЦ��\n"NOR, inv[i]);
					message("vision",CYN"�����" + inv[i]->name() + "���ĵ�һЦ��\n"NOR, comer);
				}
				else if ( (string)inv[i]->query("gender") != "Ů��"
					|| (string)comer->query("gender") == "Ů��" ) {
					tell_object(inv[i], HIW"��ͻȻ����������·�����ŵøϽ��������أ��޲����Ҹ��ط����ȥ��\n"NOR);
					tell_object(comer, "�����һ���˻Ż����ŵش�����������������\n");
					inv[i]->delete_temp("feicui_swimming");
					inv[i]->set("jing", 0);
					inv[i]->start_busy(1);
				}
				else {
					tell_object(inv[i], HIW"���������߳����أ�ͻȻ����" + comer->name() + "������������ŵþ���һ�����ֵ�����ˮ�\n"NOR);
					tell_object(comer, HIG"����������΢΢����һ��������һֻ�ֱ۴Ӻ�����������������һ��ʪ���ܵ�ͷ��ˮ�������һתͷ���������㣬һ�����У�������ˮ�С�\n"NOR);
					inv[i]->delete_temp("feicui_swimming");
					inv[i]->set("jing", 0);
					inv[i]->start_busy(1);
					if ( random(inv[i]->query_per()/6) ) inv[i]->unconcious();
				}	
			}
}

int do_swim(string arg)
{
	object me = this_player();
	object *inv;
	int i;
	
	if ( !arg || (arg != "pool" && arg != "����") ) 
		return 0;

	if ( me->query_temp("feicui_swimming") )
		return notify_fail("�����ڳ���Ϸˮ��\n");

	if ( me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("��������æ���ء�\n");

	inv = all_inventory(me);	
	for (i=0; i<sizeof(inv); i++) {
		if ( (string)inv[i]->query("equipped")=="worn" ) 
			switch(inv[i]->query("armor_type")) {
				case "cloth":
				case "armor":
				case "suncoats":
					if ( inv[i]->query_weight() > 8000)
						return notify_fail("���ų��صļ�θ��ˮ�����������㰡����\n");
					else 
						me->receive_damage("jing", 10, me);
						return notify_fail(BLU"�����������У�Ū�û����·�ʪ�����ģ��Ͻ����س��⡣���һ�����㲻�ɵô���һ�����硣\n"NOR);
				case "boots":
					return notify_fail("����Ь��ˮ����\n");
				case "bandage":
					return notify_fail("�㻹�������أ�������ˮ���˿ڸ�Ⱦ����\n");
				default:
					break;
			}
	}
	inv = all_inventory(environment(me));
	for (i=0; i<sizeof(inv); i++) 
		if ( (string)inv[i]->query("race") == "����" && inv[i] != me && !me->is_spouse_of(inv[i]) )
			return notify_fail("��Ŀ��֮���ѹ�������ˮ���㲻�Ӻ����𣿣�\n");

	message_vision(HIG"$N��ȥ���£������������У��ڱ̲���������ȥ��\n"NOR, me);
	me->set_temp("feicui_swimming", 1);

	me->start_busy(21);
	call_out("out_of_pool", 20, me);

	return 1;
}

void out_of_pool(object me)
{
	if ( !me->query_temp("feicui_swimming") ) return;
	me->delete_temp("feicui_swimming");
//	me->improve_skill("force", random(me->query_con()/5));

		if(me->query("per") > 25) {
//		me->improve_skill("beauty", 5*me->query_per());
		tell_object(me, "����һС����������������⣬ֻ��ƣ�;�ȥ�������ӡ�\n");
		message("vision", me->name()+"�ݹ�����ش��������������������Ϸ��϶���ˮ�顣\n", environment(me), ({ me }) );
		
			if(!me->query("feicui_per") && me->query("gender") == "Ů��") {
			tell_object(me, HIM"���뵽�й����صĹ��ϴ�˵�������������ڳ���ϴ����������������ϴ�˾͸��ӳ󡱣����ɵ���Ȼ�Ķ��������κ죬��֪���Լ��ǲ�����ĸ���������Щ��\n"NOR);
			me->add("per",1);
			me->set("feicui_per",1);
			log_file("test/add_per", sprintf("%s(%s) add 1 per from ���� on %s\n", me->name(), me->query("id"), ctime(time())));
			}
		}

		else {
		tell_object(me, "����һС�����������ε���Щ���ˣ����������⡣\n");
		message("vision", me->name()+"���������������������Ϸ��϶���ˮ�顣\n", environment(me), ({ me }) );
		
			if(!me->query("feicui_per") && me->query("per") < 20 && me->query("gender") == "Ů��") {
			tell_object(me, "��ͻȻ�뵽�й����صĹ��ϴ�˵�������������ڳ���ϴ����������������ϴ�˾͸��ӳ󡱣����ɵ��亹�乶��£���̫�ҵ�ͷ����ˮ�������޷�������ʵ��\n");
			me->add("per",-1);
			me->set("feicui_per",1);
			log_file("test/add_per", sprintf("%s(%s) lost 1 per from ���� on %s\n", me->name(), me->query("id"), ctime(time())));
			}

		}
	me->start_busy(1);
}

int do_drink(string arg)
{
	int current_water;
	int max_water;
	object me;

	me = this_player();
	current_water = me->query("water");
	max_water = me->query("str")*10 + 100;
	if( arg == "pool") {
	if (current_water<max_water) {
	    me->set("water", current_water+30);
	    if(me->query("jing") < me->query("eff_jing"))me->add("jing", 30);
	    message_vision("$N�߽��رߣ�������ȥ��ֻ��������ǣ�˫������ˮ�����Ϳڶ�����һ�����������Ƣ��\n", me);
	}
	else write("���Ѿ����˸�������Ҳ�Ȳ���һ��ˮ�ˡ�\n");

	return 1;
	}
	else return 0;
}
