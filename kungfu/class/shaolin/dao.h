// Code of ShenZhou
// dao.h for fight and get letter from Dao

int accept_object(object ob, object obj)
{
	object me = this_object();

	mapping my_fam  = me->query("family");
	mapping ob_fam  = ob->query("family");

	if ( ob->query_temp("have_letter") && present("tuijian xin2", ob) ) 
	{
		command("say ��ô���������ҵ��Ƽ���ȥ��ʦ���� ?");
		return 0;
	}

	if((obj->query("id") == "damo ling")
	&& ob_fam["generation"] == my_fam["generation"] + 1
	&& !ob->query_temp("have_letter") ) 
	{
		ob->set_temp("fight_ok",1);
	        command("say �ã���Ȼ�ѵõ�������ɣ����Ǿ�����֤һ���书��");
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}
        
	if (obj->query("id") == "tuijian xin1" 
	&& ob->query_temp("have_letter") )
	{
		ob->set_temp("apprentice_ok",1);
	        command("say �ã�" + ob->query("name") + "����Ը�����Ϊʦ��");
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}

        command("smile");
        command("say �ⶫ�����ҿ�û��ʲô�á�");
        command("give " + obj->query("id") + " to " + me->query("id"));
	return 0;

}

void destroying(object me, object obj)
{
	destruct(obj);
	return;
}

int accept_fight(object ob)
{
	object me  = this_object();
	
	if ( !ob->query_temp("fight_ok") ) return 0;

	if ( me->is_fighting() ) 
		return notify_fail(me->name() + "ҡͷ����"
		+ RANK_D->query_respect(ob) + "�������ж�Ϊʤ��");

	me->set("qi", me->query("max_qi"));	
	me->set("eff_qi", me->query("max_qi"));	
	me->set("jing", me->query("max_jing"));	
	me->set("eff_jing", me->query("max_jing"));	
	me->set("jingli", me->query("max_jingli"));	

	me->set_temp("challenger", ob);

	add_action("do_kill", "kill");
	ob->delete_temp("fight_ok");
	
	return 1;
}

int chat()
{
	object me = this_object();
	object ob = me->query_temp("challenger");
	object obj;
	int my_max_qi, his_max_qi;

	if ( !objectp(ob) ) return ::chat();

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if ( me->is_fighting(ob) ) return ::chat();

	me->delete_temp("challenger");
	remove_action("do_kill", "kill");
	if ( me->is_fighting() ) return ::chat(); 

	if ( !present(ob, environment()) ) return ::chat(); 

	if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
	{
		command("say �������ʤ�����������������µļѵ��� ! ��ϲ���� !\n");
		message_vision("$N����$nһ���Ƽ��š�\n", me, ob);
		ob->set_temp("have_letter",1);
		obj=new("/d/shaolin/obj/tuijianxin-2");
		obj->move(ob);
		return ::chat();
	}

	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
	{
		command("say ����" + RANK_D->query_respect(ob) + 
			"���ö����ϰ�������������������г���ͷ�� !\n");
		return ::chat();
	}

	return ::chat();  
}

int do_kill()
{
	object me= this_object();
	say(me->name() + "�߸߾����Ħ��ȵ������������Ħ��ʦ�����˵����ڴ�ɱ�ˣ�");
	return 1;
}

void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping ob_fam;
	mapping my_fam  = me->query("family");

	string name, new_name;

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
	{
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}

//	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������") 
//	{
//		command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
//		return;
//	}

	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
		return;
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 1) )
	{
		command("say " + ob_fam["master_name"] + "��ͽ����ô�ܵ���������ˣ������� !");
		command("recruit " + ob->query("id"));
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		if ( ob->query_temp("apprentice_ok") )
		{
			ob->delete_temp("have_letter");
			ob->delete_temp("apprentice_ok");
	
			command("say ��" + ob_fam["master_name"] + "���������ҵİɣ������� !");
			command("say ƶɮ�ֵ�һ����֮�ţ����ǿ�ϲ�ɺ� !");

			if( me->query("class") == "bonze" )
			{ 
				new_name = "��" + name[2..3];
				ob->set("name", new_name);
				command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ���������ֱ����� !");
			}
			else 	command("say ��ϲ������Ϊ���������ֱ��׼ҵ��ӣ�");

			command("recruit " + ob->query("id"));
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + "����û���Ƽ��ţ�����Խ����ʦ��");
			return;
		}
	}

	return;
}

