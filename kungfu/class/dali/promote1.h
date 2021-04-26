// Code of ShenZhou
int accept_object(object ob, object obj)
{
	mapping ob_fam;
	ob_fam=ob->query("family");

	if (obj->query("id")!= "shou yu") {
		command("say �Բ����ⶫ���Ҳ�Ҫ��");
		return 0;
	}

	if (!(ob_fam = ob->query("family"))
		|| ob_fam["family_name"] != "����μ�") {
		command("say "+RANK_D->query_respect(ob)+"�ͱ��ɲ��޹�ϵ�����Ҵ�����⣿");
		remove_call_out("destroying");
		call_out("destroying", 1, ob, obj);
		return 1;
	}

	if (ob->query("dali/rank")) {
		command("hmm "+getuid(ob));
		command("say "+RANK_D->query_respect(ob)+"�ƺ���ֲ��������������������������ɡ�\n");
		remove_call_out("destroying");
		call_out("destroying", 1, ob, obj);
		return 1;
	}

	if (ob->query("dali/jobdone")<150) {
		command("say "+RANK_D->query_respect(ob)+"�ҿ��㻹����Ϊ�����������ɣ���ʱ����һ������Ȼ���");
		remove_call_out("destroying");
		call_out("destroying", 1, ob, obj);
		return 1;
	}

	ob->set_temp("fight_ok1",1);
	command("say �ã���Ȼ�ѵõ���������ɣ����Ǿ�����֤һ���书��");
	remove_call_out("destroying");
	call_out("destroying", 1, ob, obj);
	return 1;
}

void destroying(object ob, object obj)
{
	destruct(obj);
	return;
}

int accept_fight(object ob)
{
	object me;
	me=this_object();

	if (!ob->query_temp("fight_ok1")) return 0;

	if (me->is_fighting())
		return notify_fail(me->name()+"ҡͷ����"+RANK_D->query_respect(ob)+"�������ж�Ϊʤ��");

	me->set("qi", me->query("max_qi"));     
    me->set("eff_qi", me->query("max_qi")); 
    me->set("jing", me->query("max_jing")); 
    me->set("eff_jing", me->query("max_jing"));     
    me->set("jingli", me->query("max_jingli"));     
	me->set_temp("challenger", ob);
    add_action("do_kill", "kill");
    ob->delete_temp("fight_ok1");
    return 1;
}

int chat()
{
	object me = this_object();
	object ob = me->query_temp("challenger");
	object obj;

	int my_max_qi, his_max_qi;
	if (!objectp(ob)) return ::chat();

	my_max_qi  = me->query("max_qi");
    his_max_qi = ob->query("max_qi");
	if (me->is_fighting(ob)) return ::chat();

	me->delete_temp("challenger");
    remove_action("do_kill", "kill");

    if (me->is_fighting()) return ::chat();
    if (!present(ob, environment())) return ::chat(); 
    if (((int)me->query("qi")*100/my_max_qi)<=50) {
		command("say �ã���Ȼ���������ǵ����� ��ϲ���� !\n");
		command("say �ã��Ҿʹ�����������������Ժ�� !\n");
		ob->set("title","�����ƽ��������Ժ");
		ob->set("dali/rank",1);
        return ::chat();
	}

    if (((int)ob->query("qi")*100/his_max_qi)<50) {
		command("say ����"+RANK_D->query_respect(ob)+"���ö��Ŭ���������ڴ����������г���ͷ�ء�\n");
		return ::chat();
	}
    return ::chat();  
}

int do_kill()
{
	object me= this_object();
    say(me->name()+"�߸߾������ͣ��ȵ����������±��䣬����ɱ��!\n");
	return 1;
}
