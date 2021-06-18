// Code of ShenZhou
// /d/taohua/obj/bagua.c
// Lara 2001/11/28
// snowyu 2002/1
#include <ansi.h>
inherit ITEM;

#include "/d/REGIONS.h";

#define ROUTER "/clone/obj/traverser"
/******************* ���ﶨ��ռ��busy***********************/;
#define zhanbu_busy 10
/*********************************************************/

nosave object route_finder;
nosave object target_room;
// 0: idle, 1: searching
nosave int status;

int do_route(string, object);
int do_printroute(object);
void init();

void create()
{
	set_name("������", ({ "tie bagua", "bagua" }) );
	set_weight(10000);
	set_color(GRN);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "�������Ǵ����������������أ����а���ͼ����\n"
			"����ָ�chuzhen <����>\n");
		set("unit", "ö");
		set("wield_msg", GRN "$N�ɿڴ����ó�$n��\n" NOR );
		set("unwield_msg", GRN "$N��$n�Żؿڴ��С�\n" NOR );
		set("value", 1600);
		set("tanzhi",200);
	}
	setup();
}

void init()
{
	add_action("do_divine", "divine");
	add_action("do_divine", "zhanbu");
	add_action("do_chuzhen", "chuzhen");
	add_action("do_printroute", "printroute");
	add_action("do_taohua", "taohua");
	add_action("do_convert", "convert");
	add_action("do_convert", "huan");
}

int do_divine(string arg)
{
	object ob, where, env, me = this_player();
	mapping myfam;
	string region;
	int i, lvl, diff, busy_time ,rate, exp, pot;
        if( me->query_temp("quitting") )
        return notify_fail("��Ҫ�˳���Ϸ�˻�ռ����������ô����ɣ�\n");//����quitʱzhanbu��bug
	if (me->is_busy() || me->query_temp("pending/exercising") || me->query_temp("exit_blocked")) return notify_fail("��������æ���ء�\n");
	myfam = (mapping)me->query("family");
	if( !myfam || myfam["family_name"] != "�һ���" ) return notify_fail("����һ����ӣ����ܽ����Ŷݼ�����ռ����\n");
	if( (lvl = (int)me->query_skill("qimen-dunjia", 1)) < 60 ) return notify_fail("�����Ŷݼ׵ȼ�������\n");
	if( me->query("jingli") < 100 ) return notify_fail("��ľ���������������ռ����\n");
	if( me->query("jing") < 100 ) return notify_fail("��ľ�������������ռ����\n");
	if (!arg) return notify_fail("��Ҫռ��˭��λ�ã�\n");
        if (arg=="a zi") return notify_fail("�������ռ�������ϵ�λ�ã��������ץס���ˣ�\n");

	if( !(ob = find_player(arg)) ) if( !(ob = find_living(arg)) ) return notify_fail("����û�����.\n");
/*************************** �������zhanbu busy**************************/
if( time() - me->query_temp("taohua/last_zhanbu") < zhanbu_busy  )
            return notify_fail("��ո�ռ���������ܾۼ�����!\n");
me->set_temp("taohua/last_zhanbu", time());
//zhanbu_busy��������exp ���ٶȣ����ļ���ͷ����ģ���ע��
/*************************************************************************/
	message_vision(CYN"$N����һֻ����������������Ĵָ�����������������ӡ�������î�������ȡ��硢δ���ꡢ�ϡ��硢��\n������λ��ϸ��������������\n\n\n"NOR, me);
        rate = 21 - lvl/20; //������
        if(rate < 1) rate = 1;
	busy_time = rate-random(me->query("int")-20);
        //����busy time���㹫ʽ����������Խ��busy timeԽ��
        if(busy_time < 5) busy_time = 5;
/************************************************************/
// ����ȡ��ԭ����busy time
//me->start_busy(busy_time);
/************************************************************/
	me->add("jing", -50);
	me->add("jingli", -50);
	if( arg == me->query("zangbu_yapu")) return notify_fail("����˲�֪��������Ү...\n");
	if( !(where = environment(ob))) return notify_fail("����˲�֪��������Ү...\n");
	if( !wizardp(me) && wizardp(ob) ) return notify_fail("�󵨣�����ı����ʦ��\n");
	if( strsrch(file_name(where), "/d/") != 0 ||  undefinedp(region = region_names[explode(file_name(where), "/")[1]]) ) return notify_fail("����˲�֪��������Ү...\n");
	env = environment(me);
	diff = (int)(me->query("combat_exp")/ob->query("combat_exp"));
	if( lvl > 120 && !ob->query_temp("apply/name") && random(lvl / 10 + me->query_int() + diff) > ob->query_kar()/2 )
	{
		me->add("jing", -random(200-lvl));
		printf("%s(%s)������%s%s��\n", (string)ob->name(), (string)ob->query("id"), region, (string)where->query("short"));
//              if( me->query("combat_exp") < (me->query("int")*3+me->query_int()) * 5000 )
		{
//                      exp = rate/2+random(me->query("int")+me->query_int()-40)/2;
                       exp = 3+ random(2);
			if (me->query("potential")<me->query("max_potential"))
				pot = rate/2+random(me->query("int")+me->query_int()-40)/4;//����������㹫ʽ���Ⱥ��������й�
			else pot = 0;
		}
		me->add_temp("apply/karma",random(3));
		if( lvl > 140 && !ob->query("yapu_target") )
		{
			do_route(file_name(where), me);
		}
		if( (random(lvl/2)+diff) < ob->query("kar") ) tell_object(ob, HIB"��о����񲻶����ƺ������ڰ��п�������......\n"NOR);
	}
	else if( me->query_int() > random(ob->query_kar()) )
	{
		me->add("jing", -random(200-lvl));
		printf("%s(%s)������%sһ����\n", (string)ob->name(), (string)ob->query("id"), region);
//              if( me->query("combat_exp") < (me->query("int")*3+me->query_int()) * 5000 )
		{
// exp = rate/3+random(me->query("int")+me->query_int()-40)/3;
                       exp = 3+ random(2);
			if (me->query("potential")<me->query("max_potential"))
                                pot = rate/4+random(me->query("int")+me->query_int()-40)/4;
			else pot = 0;
		}//����������㹫ʽ���Ⱥ��������й�
		me->add_temp("apply/karma",random(2));
	 	if( (random(lvl/2)+diff) < ob->query("kar")/2 ) tell_object(ob, HIB"��о����񲻶����ƺ������ڰ��п�������......\n"NOR);
	}
	else
	{
		write("���龫���������˰��Σ�ȴ����һ�����á��� \n");
		me->set("jing", 1);
		me->improve_skill("qimen-dunjia",random((int)me->query_int()));
	}
        me->add("combat_exp", exp);
	me->add("potential", pot);
log_file("/job/th-zhanbu",sprintf("[%s] %s(%s) ռ���õ� %d �㾭��� %d ��Ǳ�ܡ�\n", ctime(time()),me->name(), me->query("id"), exp, pot));
	me->improve_skill("qimen-dunjia",2+lvl/100+random((me->query("int")*4+me->query_int())/20));
//���Ӽ�qmdj���ٶ�
	return 1;
}

int do_chuzhen(string arg)
{
	object obj, env, me;
	string dest;
	mapping exit;

	if(!arg) return notify_fail("��Ҫ���ĸ��������\n");
	me = this_player();
	if (me->is_busy() || me->query_temp("pending/exercising") || me->query_temp("exit_blocked")) return notify_fail("��������æ���ء�\n");
	env = environment(me);
	if( !env->query("th_buzhen") ) return notify_fail("���ﲢ�޲��������󷨡�\n");
	if( me->query_skill("qimen-dunjia", 1) < 60 ) return notify_fail("������Ŷݼ���Ϊ�������޷��������ذ¡�\n");
	if( me->query_skill("qimen-dunjia",1) < env->query("th_pozhen")/3)
	{
		message_vision(CYN"$N���ڵ���ڤ˼���룬ͻȻ��ɫ��䣬������Ѫ��\n"NOR,me);
		me->unconcious();
		return notify_fail("");
	}
	exit = env->query("org_exits");
	dest = exit[arg];
	if(undefinedp(exit[arg])) return notify_fail("�������û�г�·��\n");
	if( !(obj = find_object(dest)) ) call_other(dest, "???");
	if( !(obj = find_object(dest)) ) return notify_fail("�������û�г�·��\n");
	message_vision(CYN"$N��˼Ƭ�̣�������һת����һ������Ȼ��ʧ����Ӱ���١�\n"NOR,me);
	if( me->move(obj) )
	{
		message( "vision", me->name()+"�첽���˹�����\n"NOR,
		environment(me), ({me}) );
		return 1;
	}
	return 0;
}

int visit_room(string room_path, mapping traverse_info, mapping room_info, string target)
{
	string room_short, tmp;

	if (! room_info) return 0;
	// taking care of the colors in names
	room_short=explode(room_info["short"], ESC)[0];
	if (sscanf(room_short, "[%*dm%s", tmp) == 2) room_short = tmp;
	if (sscanf(room_short, "[%*d;%*dm%s", tmp) == 3) room_short = tmp;
	if (room_short == target)
	{
		target_room = find_object(room_path);
		if (! target_room)  target_room = load_object(room_path);
		// something wrong with the room, return 1 to prune the search branch
		if (! target_room)
		return 1;
		return -1;   // found room, done
	}
	return 0;      // otherwise, keep going
}

int do_route(string arg, object me)
{
	int ready;

	if (status == 1) return notify_fail("��������·;. �� printroute ����ʾ�����\n");
	if (objectp(route_finder)) destruct(route_finder);
	route_finder = new (ROUTER);
	if (! objectp(route_finder))
	{
		target_room = 0;
		return notify_fail("���,������� "+ROUTER+"?\n");
	}
	status = 1;
	target_room = find_object(arg);
	if (! target_room)  target_room = load_object(arg);
	if (! objectp(target_room))
	{
	    // return notify_fail("Ŀ�귿�� "+arg+" ������.\n");
	    // assume arg is a short name, not file path
	    ready = route_finder->traverse(base_name(environment(me)), (: visit_room :), arg);
	}
	else
	{
		ready = route_finder->find_route(base_name(environment(me)), base_name(target_room));
	}
	if (ready)  return do_printroute(me);
	return notify_fail("�Ѿ���ʼ����·;���� printroute ����ʾ���.\n");
}

int do_printroute(object me)
{
	mapping info;
	mixed   route;
	int     i, n, wizp, lvl;
	object  room;
	string  room_file, room_short;

	lvl = me->query_skill("qimen-dunjia",1);
	if (status == 0) return notify_fail("������ route ����·;.\n");
	if (! objectp(route_finder))
	{
		status = 0;
		target_room = 0;
		route_finder = 0;
		return notify_fail("��֣�object maproute ������.\n");
	}
	if (! route_finder->traverse_finish())
	{
		return notify_fail("��û�ҵ�����ȵ�������.\n");
	}
	status = 0;
	if (target_room)
	{
		route = route_finder->thread_route(base_name(target_room));
	}
	else
	{
		status = 2;
	}
	target_room = 0;
	destruct(route_finder);
	route_finder = 0;

	if (status == 2)
	{
		return notify_fail("û���������.\n");
		status = 0;
	}
	if ((int)route == 1)
	{
		return notify_fail("û��ȥ�˷���ĵ�·.\n");
	}
	if (sizeof(route) <= 1)
	{
		return notify_fail("�㲻���������\n");
	}
	printf("�ҵ��˵�·�������￪ʼ��\n");
	n = sizeof(route);
	if(n > lvl/20) n = lvl/20;
	wizp = wizardp(me);
	for (i=1; i<n; i++)
	{
		room_file = keys(route[i])[0];
		room = find_object(room_file);
		if (! objectp(room) ) room = load_object(room_file);
		if (objectp(room))
		{
			room_short=room->query("short");
		}
		else
		{
			room_short="��֪���Ķ�";
	    }
	    info = route[i][room_file];
	    if (info["dir"] == "cross_river")
		{
			printf("�ڶɹ�"+room->query("name"));
		}
		else if (strsrch(info["dir"], "out_sea")==0)
		{
			printf("�����ɺ�");
		}
		else
		{
			printf("�� %s ", info["dir"]);
		}
		printf("�� %s %s, ���� %s��\n", room_short, wizp?"("+room_file+")":"", chinese_number(info["dist"]));
	}
	if(n < sizeof(route)) printf("......��֪���Ķ�.\n");
	return 1;
}

int do_taohua(string arg)
{
	object me, obj;
	me = this_player();
	if (me->query("family/family_name") != "�һ���") return 0;

	if(arg) return 0;
	write("��Ŀǰ���һ�����"+me->query("th_exp")+"�㣬�һ�Ǳ��"+me->query("th_pot")+"�㡣\n");
	return 1;
}

int do_convert(string arg)
{
	object me, obj;
	int th_exp, th_pot, exp, pot, max_pot, use_pot;

	me = this_player();
	exp = me->query("combat_exp");
	pot = me->query("potential");
	max_pot = me->query("max_potential");
	th_exp = me->query("th_exp");
	th_pot = me->query("th_pot");
	use_pot = max_pot-pot;
	if(use_pot > th_pot) use_pot = th_pot;
	if (me->query("family/family_name") != "�һ���") return 0;
	if(!arg) return notify_fail("ָ���ʽ��convert || huan [ exp || pot ] \n");
	if(arg == "exp")
	{
		if(th_exp == 0)
		return notify_fail("������û���һ����顣\n");
		write("�㽫"+th_exp+"���һ�����ȫ��ת��Ϊʵ�ʾ��顣\n");
		me->add("combat_exp",th_exp);
		me->delete("th_exp");
		log_file("/job/th-huan",sprintf("[%s] %s(%s) �һ� %d ���һ�����\n",ctime(time()),me->name(), me->query("id"), th_exp));
	}
	else if(arg == "pot")
	{
		if(th_pot == 0)
		return notify_fail("������û���һ�Ǳ�ܡ�\n");
		if(pot >= max_pot)
		return notify_fail("���Ǳ���Ѿ����ˣ��޷�ת���һ�Ǳ�ܡ�\n");
		write("�㽫"+use_pot+"���һ�Ǳ��ת��Ϊʵ��Ǳ�ܣ���ʣ��"+(th_pot-use_pot)+"�㡣\n");
		me->add("potential",use_pot);
		me->add("th_pot", -use_pot);
		log_file("/job/th-huan",sprintf("[%s] %s(%s) �һ� %d ���һ�Ǳ��\n",ctime(time()),me->name(), me->query("id"), use_pot));
	}
	else return notify_fail("ָ���ʽ��convert || huan [ exp || pot ] \n");
	return 1;
}
