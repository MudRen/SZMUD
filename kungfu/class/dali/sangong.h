// Code of ShenZhou
void init()
{
	object ob,me=this_object();
        add_action("do_answer", "answer", 1);

	if (interactive(ob = this_player())
		&& ((int)ob->query_condition("dlkiller")
		|| ob->query("dali/trust")<-300)) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
	else {
		if (interactive(ob = this_player()) && ob->query("dali/rank")>=5 && me->query("dali/rank")<5)
			call_out("bow1", 1, me, ob);
		else 
			if (ob->query("dali/rank")==4 && me->query("family/family_name")=="����μ�" && me->query("dali/rank")<5)
				call_out("bow2", 1, me, ob);
	}

	if (interactive(ob = this_player())
		&& ob->query("dali/employee")
		&& ob->query("family/family_name")!="����μ�"
		&& ob->query("dali/trust")<0) {
		message_vision("$N����ؾ���$n����"+RANK_D->query_respect(me)+"Ͷ�Ҵ���Ϊ�ȴ��ô��Ϊ���졢�����ۣ����Ͼ�Ҫ���㿪���ˣ���\n",me,ob);
	}

	if (interactive(ob = this_player())
		&& ob->query("dali/employee")
		&& ob->query("family/family_name")!="����μ�"
		&& (ob->query("dali/trust")<=-100
		|| ob->query("family/family_name")=="ؤ��"
		|| ob->query("family/family_name")=="������"
		|| ob->query("family/family_name")=="ѩɽ��"
		|| ob->query("family/family_name")=="Ѫ����"
		|| ob->query("family/family_name")=="����ɽ"
		|| ob->query("sg/spy")
		|| (ob->query("class") && ob->query("class")!="officer")
		|| (ob->query("PKS")>20	&& ob->query("combat_exp")/ob->query("PKS") < 7500))) {
		command("sneer "+ob->query("id"));
                command("expell "+ob->query("id"));
                      ob->move("/d/taishan/jianyu"); 
		message_vision("$N��$n��Ц�ŵ�����"+RANK_D->query_rude(me)+"����Ϊ��ȴ�Ļ����죬�ӹ���Ϊ�����������������С����ң�ĵط�����\n",me,ob);
//                 ob->set("dali/betrayer",1);
//                 ob->delete("dali/employee");
//                 ob->delete("dali/rank");
//                 ob->delete("dali/jobdone");
//                 ob->delete("dali/arrestmade");
//                 ob->delete("dali/duty");
//                 ob->delete("dali/lastjob");
//                 ob->delete("class");
//                 if (ob->query_skill("buddhism",1)>40) ob->set_skill("buddhism", 40);
//                 ob->set("dali/trust",-100);
	}

/*
	if (interactive(ob = this_player())
		&& ob->query("dali/employee")
		&& ob->query("family/family_name")!="����μ�"
		&& (ob->query("shen")>(ob->query("combat_exp")/2)
		|| ob->query("shen")<(-ob->query("combat_exp")/2)
		|| ob->query("family/family_name")=="ȫ���"
		|| ob->query("family/family_name")=="�һ���")) {
		command("sigh "+ob->query("id"));
                command("expell "+ob->query("id"));
                      ob->move("/d/taishan/jianyu"); 
		message_vision("$N�����������$n���˵������"+RANK_D->query_respect(me)+"�����ڽ����������󳤣��ڴ�������Ϊ��ʵ��̫ί�����ˡ���\n",me,ob);
                 ob->set("dali/betrayer",1);
		ob->delete("dali/employee");
		ob->delete("dali/rank");
		ob->delete("dali/jobdone");
		ob->delete("dali/arrestmade");
		ob->delete("dali/duty");
		ob->delete("dali/lastjob");
		ob->delete("class");
		if (ob->query_skill("buddhism",1)>40) ob->set_skill("buddhism", 40);
                ob->set("dali/trust",0);
*/
	}

int bow1(object me, object ob)
{
	if (present(ob, environment(me)))
		message_vision("$N�Ϲ��Ͼ�����$n�������񣺡���ү�á���\n",me,ob);
	return 1;
}

int bow2(object me, object ob)
{
	if (present(ob, environment(me)))
		me->command("bow "+ob->query("id"));
	return 1;
}

int accept_fight(object me)
{
	if (me->query("family/family_name") != "����μ�"
		&& !me->query("dali/employee")) {
		command("say ��ү����������ɱ�ţ��������㵹ù��\n");
        me->apply_condition("dlkiller", 100);
        kill_ob(me);
        return 1;
	}
	else {
		command("say ����æ�Ź����أ���������ҡ�");
        return notify_fail("������������㽻�֡�\n");
	}
}

int accept_kill(object me)
{
	if (me->query("dali/employee")) {
		command("say ����ͬ�����£��ιʼӺ����ң����Ҹ���ƴ�ˣ�\n");
		me->add("dali/trust",-1);
	}
	else command("say ��ү����������ɱ�ţ��������㵹ù��\n");
	me->apply_condition("dlkiller", 100);
	return 1;
}

void unconcious()
{
	object ob, me=this_object();

	if (objectp(ob = me->query_temp("last_damage_from")))
                ob->add("dali/trust", 0);

	::unconcious();
}

void die()
{
	object ob, me=this_object();

	if (objectp(ob=me->query_temp("last_damage_from")))
		ob->add("dali/trust", -1);

	::die();
}
