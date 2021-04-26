// Code of ShenZhou
// xiaojian May 25, 2000
//getting tools for shaolin tiaoshui job
// mantian add name control on piao May/17/2001
string ask_piao()
{
	object me,ob,obj;
	me = this_player();
	ob = this_object();
	obj = present("shui piao", me);
	if(obj && obj->query("onwer") == me->query("id"))
		return "�����ϲ�����ˮư��, Ҫ��ô�����? ";
	if (!me->query("shaolin/job_asked") && !me->query_condition("tiaoshui"))
		return "��Ҫư����ʲô? ";
	if (me->query_temp("piao_asked"))
		return "�㲻�Ǹո�Ҫ��ư����ô����Ҫ��? ";

	command("say �ֶ���ˮư? �´�С�ĵ�! ");
	obj = new("/d/shaolin/obj/piao");
	obj->set("owner/id",me->query("id"));
	obj->set("owner/name",me->query("name"));
	obj->move(me);
	message_vision("$n��$Nһ��ˮư��\n",me, ob);
	me->set_temp("piao_asked",1);
	return "�ǵ�����󻹻�������";
	
	
}

string ask_tong()
{
	object me,ob,obj;
	me = this_player();
	ob = this_object();
	obj = present("shui tong", me);
	if (obj) 
		return "�����ϲ�����ˮͰ��? ";
	obj = present("shui tong", environment(me));
	if (obj && obj->query("onwer") == me->query("id"))
		return "���ϵ�ˮͰ��������𣿻�����ȥ�ɻ�? ";
	if (me->query("shaolin/tool_assigned"))
		return "�㲻���Ѿ��쵽����������ô����Ҫ��? ";
	if (!me->query("shaolin/job_asked"))
		return "������û��������Ҫʲô����? ";
	command("nod");
	command("say �ѵ���Ը��Ϊ���½�����ѣ���̫����! ");
	command("say ������ˮ�õ�ˮͰ������ȥ�ðɡ�");
	obj = new("/d/shaolin/obj/tong");
	obj->set("owner", me->query("id"));
	obj->move(me);
	message_vision("$N����$nһ��ˮͰ��\n", ob, me);
	me->set("shaolin/tool_assigned", 1);
	return "��ȥ��أ��һ�����ˮ���ء�";
}

int accept_object(object ob, object obj)
{
	object me;
	me = this_player();
	if(obj->query("id") == "shui piao"){
	        call_out("destroy_dest", 0, me, obj);
		return 1;
	}
	if(obj->query("id") =="shui tong"){
		if(obj->query("full")){
			if(me->query("shaolin/job_asked")&& me->query_condition("tiaoshui")){
				if (obj->query("owner") != me->query("id"))
					return notify_fail("�ⲻ�����ˮͰѽ��\n");
				else {
				call_out("reward_dest",1,me,obj);
				return 1;
				}
			}
			else{
			command("faint "+me->query("id"));
			command("say ����ô���ڲŻ���? �Ѿ��б�������������ˮ��\n");
			me->delete("shaolin/job_asked");
			me->delete("shaolin/tool_assigned");
			if (me->query_condition("tiaoshui"))
				me->clear_one_condition("tiaoshui");
			me->apply_condition("ts_pending",20+ random(5));
			call_out("dest_tool",1,me,obj);
			return 1;
		}
		}
		else{
				command("hmm "+me->query("id"));
				command("say Ͱ��û���أ���ô���������ң�\n");
				return 0;
				}
		}

        command( "hmm" );
        command( "say ������ⶫ����ʲ�᣿\n" );
        return 0;
}
void destroy_dest(object me, object obj)
{
	command("nod");
	command("say ������! \n");
	me->delete_temp("piao_asked");
	destruct(obj);
	return;
}
void dest_tool(object me, object obj)
{
	destruct(obj);
	return;
}
void reward_dest(object me, object obj)
{
	int pot, exp;
	command("thank "+me->query("id"));
	command("say �������ˣ���ȥ��Ϣһ�°ɡ�\n");
	destruct(obj);
	me->delete("shaolin/job_asked");
	me->delete("shaolin/tool_assigned");
	if (me->query_condition("tiaoshui"))
		me->clear_one_condition("tiaoshui");
	me->apply_condition("ts_pending",10+random(6));
	//me->add("combat_exp", 200+ random(50));
	pot = 100+ random(20);
	if(me->query("combat_exp") < 100000)
		exp = 220 + random(20);
	else if (me->query("combat_exp") < 300000)
                exp = 180 + random(30);
        else if (me->query("combat_exp") < 500000)
                exp = 150 + random(30);
        else exp = 90 + random(30);
        me->add("combat_exp", exp);
        me->add("potential", pot);
	if(me->query("potential") > me->query("max_potential"))
		me->set("potential", me->query("max_potential"));
       	log_file("/job/sl-tiaoshui",sprintf("[%s] %s(%s) ����ˮ�����õ� %d �㾭��� %d ��Ǳ�ܡ�\n", ctime(time()), me->name(), getuid(me), exp, pot)); //add log file. 
	return;
}
