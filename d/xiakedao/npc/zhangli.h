//Cracked by Roath
void init()
{
        object me = this_player();
		::init();
        if( interactive(me) )
        {	remove_call_out("greeting");
            call_out("greeting", 1, me);
        }
}

void greeting(object me)
{	if (query_temp("met") == 0)
	{	if(me->query_temp("greeted") <= 0)
		{	set_temp("met", 1);
			set_temp("xkd/guest", me->query("id"));
			me->set_temp("greeted", 1);
			command("bow " + me->query("id"));
			command("say ���͵�" + query("nickname")+"�����֮������ӭ" + me->query("name") + "�����������\n"+
			"    "+HBRED+HIW"(follow " + query("id") +")"NOR);
			remove_call_out("check_follow");
			call_out("check_follow", 5, me, 0);
		}
	}
	else
	{	if (me->query_temp("greeted") == 0)
		{	me->set_temp("greeted", -1);
			command("sorry " + me->query("id"));
			command("say ���ڱ���̫�࣬���һ�¡�");
		}
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}
	return;
}
int check_follow(object me, int count)
{	string curguest;
	curguest = query_temp("xkd/guest");
	command("say " + curguest);
	if (!(present(curguest, environment(this_object()))))
	{	command("say ok");
		move("/d/xiakedao/shatan1");
		set_temp("met", 0);
		return 1;
	}
	if ((me->query_leader() == this_object()) || (count > 0))
	{	command("tell " + me->query("id") + " �������");
		message_vision("$N����$n���֣�����һ���Ͳ�֪ȥ���ˡ�\n", this_object(), me);
		move("/d/xiakedao/register");
		me->move("/d/xiakedao/register");
		message_vision("$N����$n�������˽�����\n", this_object(), me);
		command("say " + RANK_D->query_respect(me) + "����Ҫ����Ǽ��¡�");
		command("bye " + me->query("id"));
		message_vision("$N˵��ת�����˳�ȥ��\n", this_object());
		me->set_leader("");
		move("/d/xiakedao/shatan1");
		set_temp("met", 0);
	}
	else
	{	command("tell " + me->query("id") + " ����������(�����"+HBRED+HIW"follow " + query("id") + NOR")");
		call_out("check_follow", 10, me, 1);
	}
	return 1;
}