// Code of ShenZhou
void init()
{
	object ob,me=this_object();

	if (interactive(ob = this_player())
		&& ((int)ob->query_condition("dlkiller")
                || ob->query("dali/trust")<-500)) {
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
       // kill_ob(me);
        return 1;
	}
	else {
		command("say ���ұ���ͬ�ţ��д�һ����Ҳ�޷¡�\n");
        return 1;
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
