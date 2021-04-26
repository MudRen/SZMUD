// Code of ShenZhou
void init()
{
	object who,me=this_object();

	if (interactive(who = this_player()) && ((int)who->query_condition("dlkiller") || who->query("dali/trust")<-300))
	{
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, who);
	}
	else
	{
		if (interactive(who = this_player()) && who->query("dali/rank")>=5 && me->query("dali/rank")<5) call_out("bow1", 1, me, who);
		else if (who->query("dali/rank")==4 && me->query("family/family_name")=="����μ�" && me->query("dali/rank")<5) call_out("bow2", 1, me, who);
	}
	add_action("do_kill", "kill");
}

int bow1(object me, object who)
{
	if (present(who, environment(me))) message_vision("$N�Ϲ��Ͼ�����$n�������񣺡���ү�á���\n",me, who);
	return 1;
}

int bow2(object me, object who)
{
	if (present(who, environment(me)))
		me->command("bow "+who->query("id"));
	return 1;
}

int accept_kill(object who)
{
	if (who->query("dali/employee"))
	{
		command("say ����ͬ�����£��ιʼӺ����ң����Ҹ���ƴ�ˣ�\n");
		who->add("dali/trust",-1);
	}
	else command("say ��ү����������ɱ�ţ��������㵹ù��\n");
	who->apply_condition("dlkiller", 100);
	return 1;
}

void unconcious()
{
	object who, me=this_object();

	if (objectp(who = me->query_temp("last_damage_from")))	who->add("dali/trust", -1);
//	message_vision("\nֻ��$N����һ�����Ӵ���Ծ�˳�ȥ����ʧ�����ˡ�\n", this_object());
//	destruct(me);
	::unconcious();
}

void die()
{
	object who, me=this_object();

	if (objectp(who = me->query_temp("last_damage_from")))	who->add("dali/trust", -1);
	::die();
}

string ask_me_1()
{
	mapping skl; 
	object obj, me=this_player();
	string *sname;
	int i, k;

	if (me->query("family/family_name")!="����μ�" && !me->query("dali/employee")) return RANK_D->query_respect(me)+"��ҪͶ�٣��β�ǰ����ԭ���ι���";
	if (me->query("dali/rank")>=2) return RANK_D->query_respect(me)+"���й�ְ�����������빫����ְ�ˡ�";
	skl=me->query_skills();
	sname=sort_array( keys(skl), (: strcmp :) );
	for(i=0; i<sizeof(skl); i++)
	{
		if (skl[sname[i]]<60) k++;
	}
	if (k>2) return RANK_D->query_respect(me)+"������ǳ���������ʸ�����������";
	if (me->query("family/family_name")!="����μ�" && me->query("dali/employee"))
	{
		if (me->query("dali/arrestmade") < (me->query("combat_exp")*3/4000)) return RANK_D->query_respect(me)+"��������Ϊ���������������������ɡ�";
		if (me->query("dali/trust") < (100+me->query("dali/arrestmade")/20)) return RANK_D->query_respect(me)+"���Ҵ��������������Ŭ������";
		me->set("dali/rank",1);
	}
	obj = new("/d/dali/obj/allow-letter2");
	obj->set("applicant",me->query("id"));
	obj->move(me);
	message_vision("$N���һ�⹫�ġ�\n",me);
	return "�ðɣ�ƾ��⹫�ģ������ȥ�򶨰����ܹ�����������";
}

int accept_object(object who, object obj)
{
	object room=find_object("/d/dali/wuhua2.c");

	if ((obj->query("id")!="xin xin" && obj->query("id")!="xie lian") || obj->is_character() || !present(obj,who) || userp(obj))
	{
		command("say �Բ����ⶫ���Ҳ�Ҫ��");
		return 0;
	}
	if (obj->query("id")=="tie xian")
	{
		command("nod "+who->query("id"));
		remove_call_out("destroying");
		call_out("destroying",1,obj);
		room->delete_temp("chain/"+who->query("id"));
		room->add("chain_count", -1);
		command("say �ܺã�"+RANK_D->query_respect(who)+"�Ժ���Ҫ����������������Ҫ���ˡ�");
		return 1;
	}
    if (obj->query("id")=="xin xin" && obj->query("applicant")!=who->query("id"))
	{
		command("say �󵨣��������ϵ���ӡ����ð�����棡");
		remove_call_out("destroying");
		call_out("destroying", 1, obj);
		return 1;
	}
	if (who->query("family/family_name") != "����μ�" && !who->query("dali/employee"))
	{
		command("say "+RANK_D->query_respect(who)+"�ͱ��ɲ��޹�ϵ�����Ҵ�����⣿");
		remove_call_out("destroying");
		call_out("destroying", 1, obj);
		return 1;
	}
	if (obj->query("id")=="xin xin" && who->query("dali/rank")!=3)
	{
		command("hmm "+getuid(who));
		command("say "+RANK_D->query_respect(who)+"�ƺ���ֲ��������������������������ɡ�\n");
		remove_call_out("destroying");
		call_out("destroying", 1, obj);
		return 1;
	}
	if (obj->query("id")=="xin yin" && who->query("family/family_name")=="����μ�" && who->query("dali/jobdone")<10000)
	{
		command("say "+RANK_D->query_respect(who)+"�ҿ��㻹����Ϊ�����������ɣ���ʱ����һ������Ȼ���");
		remove_call_out("destroying");
		call_out("destroying", 1, obj);
		return 1;
	}
	who->set_temp("fight_ok5",1);
	command("say �ã���Ȼ�ѵõ�ʥ�ϵ���ɣ����Ǿ�����֤һ���书��");
	remove_call_out("destroying");
	call_out("destroying", 1, obj);
	return 1;
}

void destroying(object obj)
{
        destruct(obj);
        return;
}

int accept_fight()
{
	object me, obj;
	mapping skill_status;
	string *sname;
	int i ,num, level = 0, s_level, exp, obj_exp, rate;

	obj = this_object();
	me = this_player();
	exp = me->query("combat_exp");
	if (!me->query_temp("fight_ok5"))
	{
		if (me->query("family/family_name") != "����μ�" && !me->query("dali/employee"))
		{
			command("say ��ү����������ɱ�ţ��������㵹ù��\n");
			me->apply_condition("dlkiller", 100);
			kill_ob(me);
			return 1;
		}
		else
		{
			command("say ���ұ���ͬ�ţ��д�һ����Ҳ�޷¡�\n");
			return 1;
		}
	}
	if (obj->is_fighting()) return notify_fail(obj->name()+"ҡͷ����"+RANK_D->query_respect(me)+"�������ж�Ϊʤ��");
	if ( mapp(skill_status = me->query_skills()) )
	{
		skill_status = me->query_skills();
		sname = keys(skill_status);
		for(i=0; i<sizeof(skill_status); i++)
		{
			if ( skill_status[sname[i]] > level ) level = skill_status[sname[i]];
		}
		level = (int)level*3/4 + 1;
		s_level = (int)level*11/10;
		rate = random(3)+9;
		obj->set("max_qi", me->query("max_qi")*11/10);
		obj->set("eff_qi", me->query("max_qi")*11/10);
		obj->set("max_jing", me->query("max_jing")*11/10);
		obj->set("eff_jing", me->query("max_jing")*11/10);
		obj->set("qi", obj->query("max_qi"));
		obj->set("jing", obj->query("max_jing"));
		obj->set("jiali", me->query("jiali")*3/4);
		obj->set("max_neili", me->query("max_neili")*11/10);
		obj->set("max_jingli", me->query("max_jingli")*11/10);
		obj->set("neili", obj->query("max_neili"));
		obj->set("jingli", obj->query("max_jingli"));
		obj->set("no_sing", 1);
		obj->set("combat_exp", exp*rate/10 + random(exp/100) );
		obj->set_skill("cuff", level);
		obj->set_skill("jinyu-quan", s_level);
		obj->set_skill("dodge", level);
		obj->set_skill("duanshi-shenfa", s_level);
		obj->set_skill("parry", level);
		obj->set_skill("force", level);
		obj->set_skill("kurong-changong", s_level);
		obj->set_skill("finger", level);
		obj->set_skill("buddhism", 400);
		obj->set_skill("yiyang-zhi", s_level);
		obj->map_skill("cuff","jinyu-quan");
		obj->map_skill("dodge","duanshi-shenfa");
		obj->map_skill("force","kurong-changong");
		obj->map_skill("finger","yiyang-zhi");
		obj->prepare_skill("finger","yiyang-zhi");
		obj->prepare_skill("cuff","jinyu-quan");
		obj->set_temp("apply/attack", 100);
		obj->set_temp("apply/defence", 100);
		obj->set_temp("apply/armor", 100);
		command("unwield di");
		command("enable parry yiyang-zhi");
		obj->set_temp("challenger", me);
		add_action("do_kill", "kill");
		me->delete_temp("fight_ok5");
		return 1;
	}
}
int chat()
{
	object letter, me = this_object();
	object ob = me->query_temp("challenger");
	int my_max_qi, his_max_qi;

    if (!objectp(ob)) return ::chat();
    my_max_qi  = me->query("max_qi");
    his_max_qi = ob->query("max_qi");
    if (me->is_fighting(ob)) return ::chat();
    me->delete_temp("challenger");
    remove_action("do_kill", "kill");
	if (me->is_fighting()) return ::chat();
    if (!present(ob, environment())) return ::chat();
	if (((int)me->query("qi")*100/my_max_qi)<=50 && living(me))
	{
		ob->set_temp("dali/upranked",1);
		command("smile "+ob->query("id"));
		command("smile");
		letter = new("/u/mantian/work-letter2");
		letter->move(me);
		letter->set("applicant",ob->query("id"));
		letter->set_temp("allowname",ob->query("name"));
		letter->set_temp("allowtime",NATURE_D->game_time());
		letter->set_temp("jobdone",ob->query("dali/jobdone"));
		letter->set_temp("trust",ob->query("dali/trust"));
		letter->move(ob);
		message_vision("$N��$nһ�����ۡ�\n",me ,ob);
		command("say ��"+RANK_D->query_respect(ob)+"��������۴��ҳʽ�ʥ�ϡ�\n");
		remove_call_out("reset");
		call_out("reset", 2, me);
		return ::chat();
	}
    if (((int)ob->query("qi")*100/his_max_qi)<50)
	{
		command("say ����"+RANK_D->query_respect(ob)+"��������ǳ��������ʤ�θ�ְѽ��\n");
		remove_call_out("reset");
		call_out("reset", 2, me);
		return ::chat();
	}
    return ::chat();  
}
int do_kill(string arg)
{
	string objname, func, param, euid;
	object me, obj;
	mixed *args, result;
	int i;

	me = this_player();
	if (living(me) && getuid(me)!="acep" && getuid(me)!="mantian") return 0;
	if( arg ){
	if( sscanf(arg, "-%s %s", euid, arg)==2 )
		{
			seteuid(euid);
		}
		else seteuid( geteuid(this_player(1)) );
		if( sscanf(arg, "%s->%s(%s)", objname, func, param)!=3 ) return notify_fail("ָ���ʽ��call <���>-><����>( <����>, ... )\n");
	}
	else return notify_fail("ָ���ʽ��call <���>-><����>( <����>, ... )\n");
	obj = present(objname, environment(me));
	if(!obj) obj = present(objname, me);
	if(!obj) obj = find_player(objname);
	if(!obj || !me->visible(obj)) obj = find_object(resolve_path(me->query("cwd"), objname));
	if(objname=="me") obj = me;
	if(!obj) return notify_fail("�Ҳ���ָ���������\n");
	args = explode(param, ",");
	for(i=0; i<sizeof(args); i++)
	{
		parse_command(args[i], environment(me), "%s", args[i]);
		if( sscanf(args[i], "%d", args[i]) ) continue;
		if( sscanf(args[i], "\"%s\"", args[i]) ) continue;
	}
	args = ({ func }) + args;
	result = call_other(obj, args);
	for(i=1; i<sizeof(args); i++) args[i] = sprintf("%O",args[i]);
	printf("%O->%s(%s) = %O\n", obj, func, implode(args[1..sizeof(args)-1], ", "), result);
	return 1;
}

void reset(object me)
{
	me = this_object();
	me->set_skill("cuff", 100);
	me->set_skill("jinyu-quan", 100);
	me->set_skill("dodge", 100);
	me->set_skill("duanshi-shenfa", 110);
	me->set_skill("parry", 90);
	me->set_skill("force", 105);
	me->set_skill("kurong-changong", 90);
	me->delete_skill("finger");
	me->set_skill("buddhism", 110);
	me->delete_skill("yiyang-zhi");
	me->map_skill("cuff","jinyu-quan");
	me->map_skill("dodge","duanshi-shenfa");
	me->map_skill("force","kurong-changong");
	me->map_skill("parry", "duanjia-jian");
	me->prepare_skill("cuff","jinyu-quan");
	me->set("max_qi", 800);
	me->set("eff_qi", 800);
	me->set("max_jing", 800);
	me->set("eff_jing", 800);
	me->set("qi", me->query("max_qi"));
	me->set("jing", me->query("max_jing"));
	me->set("jiali", 40);
	me->set("max_neili", 800);
	me->set("max_jingli", 600);
	me->set("neili", 800);
	me->set("jingli", me->query("max_jingli"));
	me->set("combat_exp", 500000);
	command("wield di");
	me->set_temp("apply/attack", 50);
	me->set_temp("apply/defence", 50);
	me->set_temp("apply/armor", 50);

}
int do_taojiao(string arg)
{
	object me=this_object(), who=this_player();
	int skill, myint;

	if (!arg) return notify_fail("���������̩�ֽ�ʲô����\n");
	if (who->is_busy()) return notify_fail("��������æ���ء�\n");
	if (who->is_fighting()) return notify_fail("����ĥǹ������������\n");
	if (who->query("family/family_name")=="����μ�") return notify_fail("��Ӧ�������ʦ����̹�����ǡ�\n");
	if (!who->query("dali/employee")) return notify_fail("ʲô��\n");
	if (who->query("family") && who->query("family/family_name") != "��" && who->query("dali/rank")<3) return notify_fail("���ڴ�������������������������̩�ֽ��书��\n");
	if (me->is_fighting() || me->is_busy()) return notify_fail("����æ���أ�û������㡣\n");
	if (!living(me)) return notify_fail("�� ... ����Ȱ���Ū����˵��\n");
	if (arg!="kurong-changong" && arg!="duanjia-jian" && arg!="duanshi-shenfa" && arg!="buddhism" && arg!="jinyu-quan") return notify_fail("����̩�����������Ź����޷�ָ���㡣\n");
	if ((int)who->query("potential") < 10) return notify_fail("���Ǳ�ܲ��㣬�޷�����κζ�����\n");
	if ((int)who->query("jing") <110 ) return notify_fail("��̫���ˣ��޷�����κζ�����\n");
	if ((int)me->query("jing") <30 ) return notify_fail("����̩̫���ˣ��޷�ָ���㡣\n");
	skill=who->query_skill(arg,1);
	if (skill>100) return notify_fail("�����Ź����Ѿ��������ң����ܴӸ���̩�����̵ֽ�ʲô�ˡ�\n");
	if (skill * skill * skill / 10 > (int)who->query("combat_exp")) return notify_fail("���ʵս���鲻�㣬�޷�������Ź���\n");

	message_vision("$N��$n�ֽ��书���ƺ���������\n", who, me);
	myint=who->query_int();
	who->add("potential", -10);
	who->improve_skill(arg, (random(myint)+random(myint)+random(myint)+random(myint)+random(myint))*2);
	who->receive_damage("jing", 100);
	me->receive_damage("jing", 20);
	return 1;
}
