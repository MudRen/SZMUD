// Code of ShenZhou

int accept_fight()
{
        object me, ob;

        me = this_object();
        ob = this_player();

        if( ob->query_temp(me->query("mz/set"))) {
		command("say �����书���ڣ����º�����������Ҳ����ٶ����ˡ�");
		return 0;
	}
	if (!ob->query_temp(me->query("id")+"toy")) {
		command("say ����Ұ�Ӷ��꣬��ɢ���ˣ�������˶��֡�");
		return 0;
	}
	if (!ob->query_temp(me->query("mz/need"))) {
		command("say �������ͬ"+me->query("mz/needname")+"����֮��"
			"�������ֳ�");	
		return 0;
	}
	command("say �ðɣ����ҾͱȻ��Ȼ����㵽Ϊֹ��");
	me->set_temp("challenger", ob);
	return 1;
}

int chat()
{
	object me = this_object();
	object ob = me->query_temp("challenger");
        int my_max_qi, his_max_qi;

	if( !objectp(ob) ) return ::chat();
	if (me->is_fighting(ob)) return ::chat();

	me->delete_temp("challenger");
        if (me->is_fighting()) return ::chat();

        my_max_qi  = (int)me->query("max_qi");
        his_max_qi = (int)ob->query("max_qi");

        if ( !present(ob, environment()) ) return ::chat();

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 )
        {
		command("say ���¹�Ȼ�������������ˡ�");
		ob->set_temp(me->query("mz/set"),1);
		ob->set_temp(me->query("id")+"toy",0);
		call_out("fightwin",1,ob);
		return ::chat();
	}

	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 )
        {
                command("say ������"+me->query("mz/toy")+"Ҫ�����ˡ�");
		command("jump");
		return ::chat();
	}
}

int accept_object(object me, object obj)
{
	if ((string)obj->query("name")!=this_object()->query("mz/toy")){
		command("say ���Ӳ�����֮����������ջء�");
		return 0;
	}
	command("bow "+me->query("id"));
	command("say �����������������ԸΪ�˱�ƾ΢ĩ֮���͸��¶���һ�ġ�");
	me->set_temp(this_object()->query("id")+"toy",1);
	return 1;
}


