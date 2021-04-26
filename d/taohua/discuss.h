// Code of ShenZhou
#include <ansi.h>

int in_ask, answer;
int bCheckingRobot;


void say_question(object me, object ob)
{
	//object ob = this_player();
	int a, b, c;
	string oper;

	//if( in_ask || random(20) > 10 ) return;
	if( !ob || !userp(ob) || !me || !userp(me) )
	{
		bCheckingRobot = 0;
		return;
	}

	delete_temp("wrong");
	a = random(19) + 2;
	b = random(19) + 2;
	switch(random(5)) {
		case 0:
			answer = a + b;
			oper = chinese_number(a) + "��" + chinese_number(b)+ "���ڶ��٣�";
			break;
		case 1:
			if (a < b) { c = b; b = a; a = c;}
			answer = a - b;
			oper = chinese_number(a) + "��ȥ" + chinese_number(b)+ "���ڶ��٣�";
			break;
		case 2:
			if( a * b < 200 ) {
				answer = a * b;
				oper = chinese_number(a) + "��" + chinese_number(b)+ "���ڶ��٣�";
			} else {
				answer = (a * b) % 10;
				oper = chinese_number(a) + "��" + chinese_number(b)+ "����λ����춶��٣�";
			}
			break;
		case 3:
			answer = a % b;
			oper = chinese_number(a) + "����" + chinese_number(b)+ "�������Ƕ��٣�";
			break;
		case 4:
			oper = chinese_number(a) + "��" + chinese_number(b)+ "����������Ƕ��٣�";
			if( b < a ) { c = b; b = a; a = c; }
			while( a > 1 && b%a > 1 ) {
				c = a;
				a = b%a;
				b = c;
			}
			answer = b%a == 1 ? 1 : a;
			break;
	}
	message_vision("$N��$n���ʵ���"+oper + "��������ʮ��������(da <number>))��\n",me,ob);
	in_ask = 1;
	remove_call_out("say_answer");
	call_out("say_answer", 30, me,ob);
}

void say_answer(object me, object ob)
{
	object env, *inv;
	int i;

	if( !ob || !userp(ob) || !me || !userp(me) )
	{
		bCheckingRobot = 0;
		return;
	}

	ob->add("robot_check_wrong", 1);
	call_out("ans_wrong", 1, me, ob);

	message_vision("$N˵������ô�򵥶����᣿�𰸵���" + chinese_number(answer) + "��\n",me);
	in_ask = 0;
	remove_call_out("say_question");
	call_out("say_question", 1, me, ob);
}


int do_answer(string arg)
{
	object ob = this_player();
	object partner;
	string s;
	int ans;

	if( !ob->query_temp("partner") || !ob->query_temp("partner_id") || ! (partner=present(ob->query_temp("partner_id"), environment(ob)) ) )
		return notify_fail("����û������Ҫ��֮���۵��ˡ�\n");


	if( !in_ask ) return notify_fail("��������һ�⡣\n");
	if( !arg ) return notify_fail("����ش�һ�����֡�\n");

	message_vision( CYN "$N�����" + arg + "\n" NOR, ob);

	if( sscanf(arg, "%d", ans)==1 ) {
		if( ans==answer ) {
			ob->add("robot_check", 1);
			message_vision("$N˵��������ˣ�\n",partner);
			partner->command("pat " + this_player()->query("id") );

			remove_call_out("say_answer");
			in_ask = 0;
			if( this_player()->query("robot_check") >= 3 ) {
				message_vision(HIG"$N˵�����ܺã����Ȼ���㷨�����о����������������Ǽ��������书�ɡ�\n\n"NOR,partner);
				ob->delete("robot_check");
				ob->delete("robot_check_wrong");
				ob->delete("robot_checking");
				partner->delete("robot_check");
				partner->delete("robot_check_wrong");
				partner->delete("robot_checking");
				bCheckingRobot = 0;
				return 1;
			}
			else
			{
				remove_call_out("say_question");
				call_out("say_question", 1, partner,ob);
			}

		} else {
			message_vision("$N˵������\n",partner);
			this_player()->add("robot_check_wrong", 1);
			add_temp("wrong/" + this_player()->query("id"), 1);
			call_out("ans_wrong", 0, partner,ob);
			if( query_temp("wrong/" + this_player()->query("id")) > 3 ) {
				message_vision(HIG"ֻ�����һ������ҩʦͻȻ������$N����ǰ��\n"NOR,ob);
				message_vision(HIY"��ҩʦ�������ض�$N�ȵ������ⲻФ֮ͽ������ô�����ⶼ�𲻳���ȥ���ɡ�\n"NOR,ob);
				message_vision(HIR"��ҩʦ��ָһ����һ���ھ��ƿն�������$nϮ����$Nֻ����͸�����������˵�һ�����ڵ��ϡ�\n"NOR,ob,ob);
				message_vision(HIC"��ҩʦ����һ�ӣ���$N��վ����ߵ����⣬�����ͺ����������ǰ��ⲻФ֮ͽ�ӵ��⵺ȥ��ԽԶԽ�ã���\n\n��ҩʦ���ߺߵ����ˡ�\n\n"NOR,ob);

				this_player()->receive_wound("qi", 100, this_object());
				this_player()->set("jingli",-1);
				this_player()->set("qi",-1);
				this_player()->move("/d/island/icefire_land");
				ob->delete("robot_checking");
				ob->delete("robot_check");
				ob->delete("robot_check_wrong");
				bCheckingRobot = 0;
				in_ask = 0;
				remove_call_out("say_question");
				remove_call_out("say_answer");
			}

			//remove_call_out("say_question");
			//call_out("say_question", 1, ob);
		}
	}
	return 1;
}

int ans_wrong(object partner,object ob)
{
	if(ob->query("robot_check_wrong") > 5) {
		message_vision(HIG"ֻ�����һ������ҩʦͻȻ������$N����ǰ��\n"NOR,ob);
		message_vision(HIY"��ҩʦ�������ض�$N�ȵ������ⲻФ֮ͽ������ô�����ⶼ�𲻳���ȥ���ɡ�\n"NOR,ob);
		message_vision(HIR"��ҩʦ��ָһ����һ���ھ��ƿն�������$nϮ����$Nֻ����͸�����������˵�һ�����ڵ��ϡ�\n"NOR,ob,ob);
		message_vision(HIC"��ҩʦ����һ�ӣ���$N��վ����ߵ����⣬�����ͺ����������ǰ��ⲻФ֮ͽ�ӵ��⵺ȥ��ԽԶԽ�ã���\n\n��ҩʦ���ߺߵ����ˡ�\n\n"NOR,ob);

		ob->move("/d/island/icefire_land");
		ob->delete("robot_check_wrong");
		ob->delete("robot_check");
		ob->delete("robot_checking");
		partner->delete("robot_check_wrong");
		partner->delete("robot_check");
		partner->delete("robot_checking");
		bCheckingRobot = 0;
		in_ask = 0;
		remove_call_out("say_question");
		remove_call_out("say_answer");
	}
	return 1;
}


int do_discuss(string arg)
{
	object me,partner;
	int exp1, exp2, pot1, pot2, times, i;
	string name1, name2, name3, name4, target;

	me = this_player();
		  if (me->is_busy()
		  || me->query_temp("pending/exercising")
		  || me->query_temp("exit_blocked"))
					 return notify_fail("��������æ���ء�\n");

	if( !arg || arg == getuid(me))
		return notify_fail("û������Ҫ��֮���۵��ˡ�\n");

/*
        if (sscanf(arg, "%s %d", target ,times)!=2 ) {
		times = 1;
	if( !arg || arg == getuid(me))
		return notify_fail("û������Ҫ��֮���۵��ˡ�\n");
        }
*/
        if (sscanf(arg, "%s %d", target ,times)!=2 ) {
		times = 1;
            if (sscanf(arg, "%s", target )!=1 )
		return notify_fail("����û������Ҫ��֮���۵��ˡ�\n");
	}
        
        if (times < 1) 
                return notify_fail("��Ҫ���۶��ٴΣ�\n");
        if( !(partner = present(target, environment(me))) || !partner->is_character() || me == partner)
                return notify_fail("����û������Ҫ��֮���۵��ˡ�\n");


        exp1 = (int)me->query("exp_gain");
        pot1 = (int)me->query("pot_gain"); 
	name1 = me->name();
	name3 = me->query_temp("partner");
        exp2 = (int)partner->query("exp_gain");
        pot2 = (int)partner->query("pot_gain");
	name2 = partner->name();
	name4 = partner->query_temp("partner");

	partner->set_temp("partner_id",me->query("id"));
	me->set_temp("partner_id",partner->query("id"));
        if (me->query("th_discuss") > 2000000 )
                return notify_fail("������������࣬Ӧ��ʵ��һ�±����书�ļ����ˡ�\n");
        if (partner->query("th_discuss") > 2000000 )
                return notify_fail(name2+"�Ѿ����۹��ܶ౾����ѧ��Ӧ��ʵ��һ���ˡ�\n");

/*
	if (me->query("huang_called") )
                return notify_fail("��ҩʦҪ��ȥ��������Ϊ���ӣ��õ�������ʦ�����ǣ��ɲ����д蹦���ʱ��\n");
	if (partner->query("huang_called") )
                return notify_fail("��ҩʦҪ"+name2+"ȥ��������Ϊ���ӣ��õ�������ʦ�����ǣ��ɲ����д蹦���ʱ��\n");

	if (me->query("th_ask") )
                return notify_fail("�㻹ûȥ��"+me->query("th_ask")+"�ء�\n");
	if (partner->query("th_ask") )
                return notify_fail("�Է���û������ʦ���������¡�\n");
	if (me->query("th_teach") )
                return notify_fail("���"+me->query("th_teach")+"�����򣬲Űﵽһ���ġ�\n");
	if (partner->query("th_teach") )
                return notify_fail("�Է���û������ʦ���������¡�\n");
*/
        if( (exp1 < times || exp2 < times ) && times > 1)
                return notify_fail("�����������۲�����ô��Χ��\n");

	if (me->query("jing") < 20 || me->query("jingli") < 20)
		return notify_fail("��̫���ˣ��޷�����������ȥ��\n");
		  if (partner->query("jing") < 20 || partner->query("jingli") < 20)
					 return notify_fail("���ͬ��һ�������˯�����ӣ������޷�����������ȥ��\n");

if(me->query("serverbonus")&&partner->query("serverbonus")) times=times/2;
	if (me->query("jing") < 10+10*times || me->query("jingli") < 10+10*times)
		return notify_fail("����Ŀǰ�ľ���״��������һ�����۲�������ණ����\n");
		  if (partner->query("jing") < 10+10*times || partner->query("jingli") < 10+10*times)
					 return notify_fail("�ԶԷ�Ŀǰ�ľ���״��������һ�����۲�������ණ����\n");

	me->add("jing", -10*times);
	partner->add("jing", -10*times);
	me->add("jingli", -10*times);
	partner->add("jingli", -10*times);
if(me->query("serverbonus")&&partner->query("serverbonus")) times=times*4;

	if( exp1 < 1 && exp2 < 1) {
		tell_object(me,CYN"���"+name2+"������һ�󣬸о��Դ��յ����ģ�һ�����á�\n"NOR);
		tell_object(partner,CYN"���"+name1+"������һ�󣬸о��Դ��յ����ģ�һ�����á�\n"NOR);
		message_vision(CYN"$N��$n����һ�ûһ��İڿ�������\n"NOR,me,partner);
		me->start_busy(random(3));
		partner->start_busy(random(3));
		return 1;
	}

	if( exp1 < 1 ) {
		tell_object(me,CYN"����Ҫ��"+name2+"̽��һ���书�ĵã���ȴ����ûɶ��˵��...\n"NOR);
		tell_object(partner,CYN""+name1+"�ƺ���������۵�ʲ�������...\n"NOR);
		message_vision(CYN"$N��$nһ��������ֹ������ģ����\n"NOR,me,partner);
		return 1;
	}

		  if( exp2 < 1 ) {
					 tell_object(me,CYN"����Ҫ��"+name2+"̽��һ���书�ĵã���"+name2+"ȴһ���Ĳ����ɵ�����...\n"NOR);
					 tell_object(partner,CYN""+name1+"�ƺ���������۵�ʲ������ӣ�����ȴ����ûɶ��˵��...\n"NOR);
					 message_vision(CYN"$n��$Nһ��������ֹ������ģ����\n"NOR,me,partner);
					 return 1;
		  }

  if( me->query("robot_checking") )
  {
	if(bCheckingRobot == 0)
	{
		bCheckingRobot = 1;
		call_out("say_question",1,partner,me);
	}
	return notify_fail("�㻹���Ȱ�������������İ�! \n");
  }

  if( partner->query("robot_checking") )
  {
	if(bCheckingRobot == 0)
	{
		bCheckingRobot = 1;
		call_out("say_question",1,me,partner);
	}
	return notify_fail("���ǵ��˼��Ȱ����������˵��! \n");
  }

//discuss���discuss xxx <����>�ᣬ��ָ�������٣�check robot�������̫�࣬��ʱȡ��

/*
  if( random( 150 ) == 1 && bCheckingRobot == 0)
  {
	message_vision(HIG"$N˵�������һ����ɲ������书�������£�����ʦ�������Ű��ԡ����Ӱټ�����������������ͨ��\n",me);
	message_vision("$N˵�����ҵȵ�������ѧ��ʦ��һ������ѧ�ʣ��ʹ����޺��ˡ�\n",me);
	message_vision("$N˵��������������ô�ã�������Ϣ��Ϣ����������̽��̽��һЩ�㷨���⡣\n"NOR,me);
	partner->set("robot_checking",1);
	bCheckingRobot = 1;
	call_out("say_question",1,me,partner);
	return 1;
  }

        if(me->query("th_discuss") > 2000000){
	message_vision("$N����������ѧ��Ҫ��һ���������˹�������$N����ѽѽ�����˸����ƣ��ǻ�ҩʦ����Ҫ��$N����֪�кηԸ���\n",me,partner);
	message_vision("$N��$n����һ�ۣ�ͣ��������$N�����ͻӻ��֣�ʾ��֪�������ͱ㼴��ȥ��\n",me,partner);
	me->set("huang_called",1);
	me->delete("th_discuss");
	return 1;
	}
*/

	message_vision(CYN"$N��$n���ҵ�̽���Ÿ����书�ĵ�ʧ���������ѧ����⡣\n"NOR,me,partner);
	tell_object(me,HIY"��һ�ߺ�"+name2+"ӡ֤��ѧ��һ�߻�������"+name3+"�ı��侭��������ѧ����ʶ������һ�㣡\n"NOR);
		  tell_object(partner,HIY"��һ�ߺ�"+name1+"ӡ֤��ѧ��һ�߻�������"+name4+"�ı��侭��������ѧ����ʶ������һ�㣡\n"NOR);
	//me->start_busy(1+random(2));
	//partner->start_busy(1+random(2));

	exp1 = exp1-times; pot1 = pot1-times;
	exp2 = exp2-times; pot2 = pot2-times;

        me->set("exp_gain", exp1); 
        partner->set("exp_gain", exp2);

                    for (i=0; i<times; i++) {
	me->add("combat_exp",(int)(me->query_int()/30+1));
	me->add("th_discuss",1);
	partner->add("combat_exp",(int)(partner->query_int()/30+1));
	partner->add("th_discuss",1);
	}

	if (pot1>0) {
                me->set("pot_gain", pot1);
		for (i=0; i<times; i++) {
		if ( me->query( "serverbonus" ) || partner->query( "serverbonus" ) || me->query( "potential" ) < me->query( "max_potential" ) )
		me->add("potential",(int)(me->query_int()/20+1));
		}
	} else me->delete_temp("pot_gain");

	if (pot2>0) {
                partner->set("pot_gain", pot2);
                for (i=0; i<times; i++) {
		if(me->query("serverbonus")||partner->query("serverbonus")||partner->query("potential")<partner->query("max_potential") )
		partner->add("potential",(int)(partner->query_int()/20+1));
		}
        } else partner->delete_temp("pot_gain");
		if( wizardp(me) )
	message_vision("exp1:"+exp1+" exp2:"+exp2+" pot1:"+pot1+" pot2:"+pot2+"\n",me,partner);

        return 1;
}
