// Code of ShenZhou
void init()
{
        object ob, me = this_object();
}

int accept_fight(object ob)
{
        object me = this_object();
	object ob1, ob2, ob3, ob4, ob5, ob6;
	string msg1, msg2, msg3, msg4, msg5, msg6;
	int my_max_qi = me->query("max_qi");

	if ( me->query("qi")*100 / my_max_qi <= 80 ) {
                return 0;
        }

	ob1 = present("tao genxian", environment(me));
	ob2 = present("tao ganxian", environment(me));
	ob3 = present("tao zhixian", environment(me));
	ob4 = present("tao yexian", environment(me));
	ob5 = present("tao huaxian", environment(me));
	ob6 = present("tao shixian", environment(me));

	msg1 = "�Ҹ���ͻȻ�ƽ�$N��һ����$N������׽ȥ��\n";
	msg2 = "�Ҹ���ͻȻ�ƽ�$N��һ����$N������׽ȥ��\n";
	msg3 = "��֦��ͻȻ�ƽ�$N��һ����$N�����׽ȥ��\n";
	msg4 = "��Ҷ��ͻȻ�ƽ�$N��һ����$N���ҽ�׽ȥ��\n";
	msg5 = "�һ���ͻȻ�ƽ�$N��һ����$N������׽ȥ��\n";
	msg6 = "��ʵ��ͻȻ�ƽ�$N��һ����$N���ҽ�׽ȥ��\n";

	command( "say ��ⷶ�׼����" );

	if ( ob1 != me ) call_out("tear_and_kill", random(5), ob1, ob, msg1);
	if ( ob2 != me ) call_out("tear_and_kill", random(5), ob2, ob, msg2);
	if ( ob3 != me ) call_out("tear_and_kill", random(5), ob3, ob, msg3);
        if ( ob4 != me ) call_out("tear_and_kill", random(5), ob4, ob, msg4);
        if ( ob5 != me ) call_out("tear_and_kill", random(5), ob5, ob, msg5);
        if ( ob6 != me ) call_out("tear_and_kill", random(5), ob6, ob, msg6);

	call_out("observe", 1, me, ob);
        return 1;
}

string ask_me()
{
	return "���ù��������ֵܣ�����Ȼ�����ȥ������";
}

int accept_kill(object ob)
{
	object me = this_object();
	object ob1, ob2, ob3, ob4, ob5, ob6;

	ob->delete_temp("win");
	command( "say ����ı�ĺ������ɣ��ǲ��Ƕʼ��������ֵ�����������\n");

	if ( objectp(ob1 = present("tao genxian", environment(me))) ) ob1->kill_ob(ob);
	if ( objectp(ob2 = present("tao ganxian", environment(me))) ) ob2->kill_ob(ob);
	if ( objectp(ob3 = present("tao zhixian", environment(me))) ) ob3->kill_ob(ob);
	if ( objectp(ob4 = present("tao yexian", environment(me))) ) ob4->kill_ob(ob);
	if ( objectp(ob5 = present("tao huaxian", environment(me))) ) ob5->kill_ob(ob);
	if ( objectp(ob6 = present("tao shixian", environment(me))) ) ob6->kill_ob(ob);

	return 1;
}

int tear_and_kill(object me, object ob, string msg)
{
	if ( !ob->is_fighting() && ob->query("qi")*2 <= ob->query("max_qi")) {
		ob->delete_temp("caught"); 
		return 1;
	}

	message_vision(msg,ob);

	if ( random(me->query("combat_exp")) > (int)ob->query("combat_exp")/2 ) {
		me->delete_temp("catch_pending");
		me->set_temp("catch", 1);
		ob->add_temp("caught", 1);
		message_vision("���$N��"+me->name()+"׽�����ţ�\n", ob);
		if ( ob->query_temp("caught") == 4 ) {
		   message_vision("\n�ҹ�����׽��$N��֫��Ȼһ����$Nֻ����һ���ʹ����ʧȥ֪���ˡ�\n", ob);
		   ob->unconcious();
		   ob->die();
		   CHANNEL_D->do_channel(me,"chat",sprintf("%s���ҹ�����˺���Ŀ��ˣ�",ob->name()));
//		   COMBAT_D->killer_reward(me, ob);
		}
	}
	else {
		message_vision("$N�ɹ��������ˡ�\n", ob);
	}

	return 1;
}     

int observe(object me, object ob)
{
        int my_max_qi = me->query("max_qi");
        string msg;

        if (me->is_fighting()) {
	   if ( (me->query("qi")*100 / my_max_qi) <= 80 ) {
                command("exert recover");
           }

	   call_out("observe", 1, me, ob);
           return 1;
        }

	if (me->query("qi")*2 <= me->query("max_qi")) {
 	   me->remove_enemy(ob);
           ob->remove_enemy(me);
           command( "say "+RANK_D->query_respect(ob)+"��Ȼ�м��֣��һ�������Ъ����ɣ��ɲ����Ҵ򲻹���ม�");
	   if ( me->name() == "�Ҹ���" ) ob->set_temp("win/tao1", 1);
	   if ( me->name() == "�Ҹ���" ) ob->set_temp("win/tao2", 1);
	   if ( me->name() == "��֦��" ) ob->set_temp("win/tao3", 1);
           if ( me->name() == "��Ҷ��" ) ob->set_temp("win/tao4", 1);
           if ( me->name() == "�һ���" ) ob->set_temp("win/tao5", 1);
           if ( me->name() == "��ʵ��" ) ob->set_temp("win/tao6", 1);
	   ob->delete_temp("caught");
	}

	if (ob->query("qi")*2 <= ob->query("max_qi")) {
           me->remove_enemy(ob);
           ob->remove_enemy(me);
	   ob->delete_temp("caught");
        }

	if ( !present(ob, environment()) ) return 1;

	return 1;
}
