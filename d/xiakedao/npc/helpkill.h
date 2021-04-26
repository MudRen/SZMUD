//Cracked by Roath
int do_kill()
{
	object me, dest;
	int i;
	string killer;
	helpee = this_player();
	me = this_object();
	if (helpee->query_temp("xkd/give2")==0)
	{	return 0;
	}
	if ((int)helpee->query("xkd/find") == 1 ) 
	{	command("say ���Ѿ�������ˣ������ٰ����ˡ�");
		destruct(ling);
		return 1;
	}

	if (query_temp("xkd/busy"))
	{	command("say ����æ���أ�����ɡ�");
		return 1;
	}
	killer = helpee->query_temp("my_killer");
	if (! killer )
	{	command("say ����û�£���ʲ���");
		call_out("do_return", 0, ling, helpee);
		helpee->delete_temp("xkd/give2");
		return 1;
	}
	dest = find_player(helpee->query_temp("my_killer"));
	if( !dest )
	{	command("say �����ڲ�����Ϸ�У����������ɡ�");
		call_out("do_return", 0, ling, helpee);
		helpee->delete_temp("xkd/give2");
		return 1;
	}
	if (dest->is_ghost())
	{	command("say �������ۣ����Ѿ��ܵ���Ӧ���ˡ�");
		call_out("do_return", 0, ling, helpee);
		helpee->delete_temp("xkd/give2");
		return 1;
	}

	helpee->set("xkd/kill", 1);
	helpee->delete_temp("xkd/give2");
	me->set("xkd/killer", dest->query("id"));
	me->set("target_name", dest->query("name"));
	log_file("Playing", sprintf("%s(%s) attempted to let xiakedao dizi to kill %s(%s)\n",
                        this_player()->query("name"), getuid(this_player()),
                        dest->query("name"), dest->query("id")) );
	home = environment(me);
	command("say ����������ȵȣ���ȥȥ������");

	message_vision("$N���˳�ȥ��\n", me);

	call_out("do_chase", 1, me);

	return 1;
}
int do_chase(object me)
{

        object dest;
        dest = find_player(me->query("xkd/killer"));

        if( !objectp(dest) || !environment(dest) )
        {
                call_out("waiting", 0, me);
                return 1;
        }

        me->move(environment(dest));
        message_vision("$N���˹�����\n", me);
        me->set_leader(dest);
        command("look " + dest->query("id"));

        if ( !environment(me)->query("no_fight"))
        {
                call_out("do_killing", 0, me, dest);
                return 1;
        }
        else
        {
                call_out("waiting", 0, me);
                return 1;
        }

        return 1;
}
int do_killing(object me, object dest)
{

        if( objectp(dest) && present(dest, environment(me))
                 && !environment(me)->query("no_fight"))
        {
                message_vision(HIR "$N��$n˵�����󵨿�ͽ��������ɱ�޹���\n" NOR, me, dest);
                me->set_leader(dest);
                me->kill_ob(dest);
                dest->fight_ob(me);

                call_out("checking", 0,  me); 
        }
        else  
                call_out("waiting", 1, me); 

        return 1;
}

int waiting(object me)
{
        object dest;
        dest = find_player(me->query("xkd/killer"));

        if ( objectp(dest) )
        {
                if (dest->is_ghost())
                {
                        me->delete("xkd/killer");
                        call_out("do_back", 1, me);
                        return 1;
                }else if (me->is_fighting() && present(dest, environment(me)))
                {
                        call_out("checking", 0, me);
                        return 1;
                }else if (present(dest, environment(me)))
		    {		call_out("do_killing", 0, me, dest);
				return 1; 
		    }else if (living(me) && !environment(dest)->query("no_fight"))
                {
                        call_out("do_chase", 0, me);
                        return 1;
                }
		    else
		    {		call_out("checking", 0, me);
				return 1;
		    }
		
        }

        remove_call_out("waiting");
        call_out("waiting", 60, me);
    return 1;
}

int checking(object me)
{
        object ob;

        if (me->is_fighting()) 
        {
                call_out("checking", 1, me);
		    return 1;
        }

        if( objectp(ob = present("corpse", environment(me)))
                 && ob->query("victim_name") == me->query("target_name") )
        {
                me->delete("xkd/killer");
                call_out("do_back", 1, me);
	          return 1;
        }

        call_out("waiting", 0, me);
        return 1;
}

int do_back(object me)
{

	me->move(home);
	message("vision", me->query("name") + "���˽��������˲����ϵ�Ѫ��˵������ĳ������㱨�ˡ�\n", 
                environment(), me );
	me->set_leader(0);

	return 1;
}
