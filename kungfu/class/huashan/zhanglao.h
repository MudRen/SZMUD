// Code of ShenZhou
void init()
{
	object ob, me = this_object();

	::init();

	set_heart_beat(1);

	if ( interactive(ob=this_player()) && ob->query("family/master_id")==me->query("id") 
	&& ob->query("shen") < 0 ) {
		command("say " + RANK_D->query_rude(ob) + "�������������������Ϊ��" );
		command( "expell " + ob->query("id"));
	}

	add_action("do_steal", "steal");
	add_action("do_throw", "throw");
}

void attempt_apprentice(object ob)
{
	if ( ob->query_skill("dugu-jiujian", 1) && !ob->query("family/family_name") ) {
		command("say �ðɣ��Ϸ���������ˡ����������£������Դ���Ϊ�ȣ����ƳͶ�");
		command("recruit " + ob->query("id"));
		return;
	}
	
	if ( (string)ob->query("family/family_name") != "��ɽ��" ) {
		command("say " + RANK_D->query_respect(ob) + "���һ�ɽ���ˣ�ˡ�Ҳ������㡣");
		return;
	}

	if ( (string)ob->query("gender") == "����" ) {
		command("say " + RANK_D->query_respect(ob) + "�Ƕ������ˣ�ˡ�Ҳ������㡣");
		return;
	}

	if ( (int)ob->query("shen") < 50000 ) {
		command("say �һ�ɽ�����������������ɣ��Ե���Ҫ���ϡ�");
		command("say "+RANK_D->query_respect(ob)+"��Ʒ�·��棬���û��������Ϸ������㡣");
		return;
	}

	if ( (int)ob->query_skill("strike", 1) < 50 ) {
		command("say "+RANK_D->query_respect(ob)+"�Ļ����Ʒ���Ϊ������ˡ�Ҳ������㡣");
		return;
	}

	if ( (int)ob->query_skill("cuff", 1) < 50 ) {
		command("say "+RANK_D->query_respect(ob)+"�Ļ���ȭ����Ϊ������ˡ�Ҳ������㡣");
		return;
	}

	if ( (int)ob->query_skill("dodge", 1) < 50 ) {
		command("say "+RANK_D->query_respect(ob)+"�Ļ����Ṧ��Ϊ������ˡ�Ҳ������㡣");
		return;
	}

	if ( (int)ob->query_skill("parry", 1) < 50 ) {
		command("say "+RANK_D->query_respect(ob)+"�Ļ����м���Ϊ������ˡ�Ҳ������㡣");
		return;
	}

	if ( (int)ob->query_skill("force", 1) < 50 ) {
		command("say "+RANK_D->query_respect(ob)+"�Ļ����ڹ���Ϊ������ˡ�Ҳ������㡣");
		return;
	}

	if ( (int)ob->query_skill("sword", 1) < 50 ) {
		command("say "+RANK_D->query_respect(ob)+"�Ļ���������Ϊ������ˡ�Ҳ������㡣");
		return;
	}

	if ( (int)ob->query_skill("hunyuan-zhang", 1) < 50 ) {
		command("say "+RANK_D->query_respect(ob)+"�Ļ�Ԫ����Ϊ������ˡ�Ҳ������㡣");
		return;
	}

	if ( (int)ob->query_skill("pishi-poyu", 1) < 50 ) {
		command("say "+RANK_D->query_respect(ob)+"����ʯ����ȭ��Ϊ������ˡ�Ҳ������㡣");
		return;
	}

	if ( (int)ob->query_skill("huashan-jianfa", 1) < 50 ) {
		command("say "+RANK_D->query_respect(ob)+"�Ļ�ɽ������Ϊ������ˡ�Ҳ������㡣");
		return;
	}

	if ( (int)ob->query_skill("huashan-shenfa", 1) < 50 ) {
		command("say "+RANK_D->query_respect(ob)+"�Ļ�ɽ����Ϊ������ˡ�Ҳ������㡣");
		return;
	}

	if ( (int)ob->query_skill("zixia-gong", 1) < 50 ) {
		command("say "+RANK_D->query_respect(ob)+"����ϼ����Ϊ�������ҵ�Ҫ��ˡ�Ҳ������㡣");
		return;
	}

	command("say �ðɣ��Ϸ���������ˡ����������£������Դ���Ϊ�ȣ����ƳͶ�");
	command("recruit " + ob->query("id"));
}

int accept_fight(object ob)
{
	object obj, me = this_object();
	int my_max_qi = me->query("max_qi");

	if ( me->query("qi")*100 / my_max_qi <= 80 ) {
		call_out("checking1", 1, me, ob);
		return 0;
	}

	remove_call_out("checking1");
	call_out("checking1", 1, me, ob);

	return 1;
}

int accept_kill(object ob)
{
	object obj, me = this_object();

	if ( me->query("id")== "ai lao" && obj = present("gao lao", environment(me)) ) {
		command("say �üһ����ı���Ϸ�ʦ�ܣ�׼��˫���ϱڣ�");
		obj->kill_ob(ob);
	}

	if ( me->query("id")== "gao lao" && obj = present("ai lao", environment(me)) ) {
		command("say ʦ�֣�׼��˫���ϱڳ�����һ");
		obj->kill_ob(ob);
	}

	remove_call_out("checking2");
	call_out("checking2", 1, me, obj, ob);

	return 1;
}

int checking1(object me, object ob)
{
	object obj;

	if ( me->is_fighting() && me->is_killing() && !me->query_temp("hebi") ) {
		if ( me->query("id") == "gao lao" && obj=present("ai lao", environment(me)) ) 
			obj->kill_ob(ob);
		if ( me->query("id") == "ai lao" && obj=present("ai lao", environment(me)) ) 
			obj->kill_ob(ob);
		call_out("checking2", 1, me, obj, ob); 
	}
	else if ( me->is_fighting() ) {
		call_out("checking1", 1, me, ob);
	}

	return 1;
}
	
int checking2(object me, object obj, object ob)
{
	if ( me->is_fighting() ) {
	   if ( objectp(obj) && !obj->is_fighting() ) {
		obj->kill_ob(ob);
	   }

	   if ( !me->query_temp("hebi") ) {
		if ( me->query("id") == "gao lao" ) command("perform hebi ai");
		if ( me->query("id") == "ai lao" ) command("perform hebi gao");
	   }
 
	   call_out("checking2", 1, me, obj, ob);
	}
	
	return 1;
}

int auto_perform()
{
	object me=this_object();
	object weapon=me->query_temp("weapon");
	object opp=me->select_opponent();

	if ( !me->is_fighting() ) {
                if ( me->query("eff_qi") < me->query("max_qi") )
                        exert_function("heal");
                me->set("jiali", 80);

                return 1;
        }

        if ( objectp(weapon) ) {
                if ( weapon->query("skill_type") == "blade" )
                        return perform_action("blade.sanshen");
        }
        else if ( !me->query_temp("leidong") ) {
			return perform_action("cuff.leidong");
	}
	else if ( !me->query_temp("wuji") && opp->query_condition("hyz_damage") <= 5 ) {
			return perform_action("strike.wuji");
	}
}

int accept_object(object me, object obj)
{
	object ob = this_player();

	if ( me->is_fighting() ) 
		return notify_fail("���ʣ���û������æ����\n");

	if ( obj->query("id") != "zixia paper" ) return 0;
	
	if ( ob->query("huashan/yin-jue") > 1 ) {
		remove_call_out("ask_why");
		call_out("ask_why", 1, obj, ob);
		return 1;
	}

	if ( (string)ob->query("family/family_name") != "��ɽ��" ) {
		remove_call_out("thank_other");
		call_out("thank_other", 1, me, obj, ob);
	}
	else {
		remove_call_out("thank_huashan");
		call_out("thank_huashan", 1, obj, ob);
	}

	return 1;
}

int ask_why(object obj, object ob)
{
	object me = this_object();

	message_vision("$N����üͷ��$n˵�����ף��㲻���ѱչؾ��޹�����\n", me, ob);
	command("say ��ϼ��ҳ�����ұ���Ҳ�ã��㻹����������");

	destruct(obj);
	return 1;
}

int thank_other(object me, object obj, object ob)
{
	message_vision("$Nʧ���е��������⾹�Ǳ�����ʧ�������ϼ��ҳ���⡣����������������Ϊ����\n", me);
	command("say �����������ɽһ����"+RANK_D->query_respect(ob)+"���⡣");
	command("bow");
	message_vision("$N˵��������ȥ��\n", me);

	destruct(obj);
	destruct(me);
	return 1;
}

int thank_huashan(object obj, object ob)
{
	object ob1, me=this_object();
	
	message_vision("$Nʧ���е��������⾹�Ǳ�����ʧ�������ϼ��ҳ��\n", me);
	
	if ( me->query("id") == "gao lao" && ob1=present("ai lao", environment(me)) ) { 
		command("say ���Һ�ʦ����������������ڴ˵��Űɡ�");
		message_vision("$N������������һ��ϸ˵��һ����ֻ����������ɫ���˼��䣬���˵�ͷ��˼�š�\n", me);
		me = ob1;
	}	
	else if ( me->query("id") == "ai lao" && present("gao lao", environment(me)) ) { 
		command("say ���Һ�ʦ����������������ڴ˵��Űɡ�");
		message_vision("$N������������һ��ϸ˵��һ����������������ɫ���˼��䣬���˵�ͷ��˼�š�\n", me);
	}	
	else {
		command("say ������ϸ�о��˼㣬����ڴ˵��Űɡ�");
		message_vision("$N˵���������ߵ�һ�����£�ȫ���ע���ж�������ϼ��ҳ����\n", me);
	}

	remove_call_out("open_room");
	call_out("open_room", 5, me, ob, obj);

	return 1;
}

int open_room(object me, object ob, object obj)
{
	message_vision("$N���˹�������$n������һ��\n", me, ob);
	command("say ������һ���ϼ��ҳ��ʵ����Ϊ�������˸��󹦡���ɽ�����ˣ� ");

	if ( file_name(environment(me)) != "/d/huashan/xiaozhu" ) {
		command("say ���ػ�ɽȥ�ɣ���ϲѶ���ߴ�ⷶ���");
		message_vision("$N˵��������ȥ��\n", me);
		destruct(obj);
		if (objectp(me) ) destruct(me);
	}
	else {
		command("say �ã��ұ�Ϊ�㻤�����㰲����������չ����������ɡ�");
		message_vision("$N����ϼ��ҳ������$n��\n", me, ob);
		message_vision("����$Nת����ǽ��һ��һ��һ�ƣ�ǽ�����к�¡¡����һ��¶��һ��������\n", me);
		command("say ������ʮ������ʼ�����в�͸��������ô���ԭ������������ܡ�");
		command("say �ú�����������Ķ�����С�ı�������Ĳ������ˣ�");
		obj->move(ob);
		message_vision("$N���������ڣ�ʯ�ű㻺���ر�������\n", ob);
		ob->move("/d/huashan/stair");
	}

	return 1;
}

int do_steal()
{
	object obj, ob=this_object(), me=this_player();

	if ( ob->query("id")=="ai lao" ) {
		obj = present("gao lao", environment(me));
	}
	else if ( ob->query("id")=="gao lao" ) {
		obj = present("ai lao", environment(me));
	}

	call_out("checking2", 5, ob, obj, me);

	return 0;
}

int do_throw()
{
	object obj, ob=this_object(), me=this_player();

	if ( ob->query("id")=="ai lao" ) {
		obj = present("gao lao", environment(me));
	}
	else if ( ob->query("id")=="gao lao" ) {
		obj = present("ai lao", environment(me));
	}

	call_out("checking2", 5, ob, obj, me);

	return 0;
}
