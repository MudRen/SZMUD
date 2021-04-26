// Code of ShenZhou
// dali bandit 2, middle level

#include <ansi.h>
#include <room.h>

inherit NPC;

void create()
{
	switch (random(5))
	{
		case 0 :
			set_name("ɽ��", ({"shan zei", "zei"}));
			break;
		case 1 :
			set_name("����", ({"tu fei", "fei"}));
			break;
		case 2 :
			set_name("�ݿ�", ({"cao kou", "kou"}));
			break;
		case 3 :
			set_name("��åͷ", ({"liumang tou", "tou"}));
			break;
		case 4 :
			set_name("ǿ��", ({"qiang dao", "dao"}));
			break;
	}
	switch (random(5))
	{
		case 0 :
			set("title", "�������ֶ�ɮ");
			set("long", "��һ������������ɴ��ˣ��������߽�����Ϊ��������\n������һ���������\n");
			break;
		case 1 :
			set("title", "��ɽ����ͽ");
			set("long", "��������������Ⱥ���µ��ӣ�ȴ�����ڻ�ɽ��Ϊ���������������ǽ���ܵ����������Ϊ�ܡ�\n��ѧ��һ��ɽ�������ֲ���\n");
			break;
		case 2 :
			set("title", "�䵱����ͽ");
			set("long", "���������䵱����֮һ����ͽ�������ѱ�ʦ�ų��ӣ��ڽ����ϸ�Щ��ҽ���Ĺ�����\n��������������ǳ��\n");
			break;
		case 3 :
			set("title", "ѩɽ������");
			set("long", "���Ǵ����µ������̰���ֺ�ɫ��������ɽ������һЩ�����������á�\n����������Щ�湦��\n");
			break;
		case 4 :
			set("title", "�嶾������");
			set("long", "��������������嶾��һ�����õ�������������Щ�����ڸ������ף�Ϊ�嶾�������ʲġ�\n����ǿ��׳�����Բ�������׶Ը���\n");
			break;
	}
	set("gender", "����");
	set("age", 25+random(10));
	set("attitude", "heroism");
	set("str", 20+random(10));
	set("int", 12+random(10));
	set("con", 17+random(10));
	set("dex", 22+random(10));
	set("dalibandit",1);
	set("dalibandit2",1);
	set("shen_type", -1);
	set("chat_chance", 15);
	set("chat_msg", ({(: random_move :),}));
	setup();
	carry_object("/d/city/obj/tiejia.c")->wear();
}

void init()
{
	object who=this_player(), me=this_object();

	if (interactive(who)) set_heart_beat(1);
	if (who->query("dalivictim") && !me->is_fighting() && random(3)==2)
	{
		remove_call_out("killvictim");
		call_out("killvictim", 1, me, who);
	}
}

void killvictim(object me, object who)
{
	if (present(who, environment(me)))
	{
		if (who->query("race")=="����" && who->query("age")<15)
		{
			command("grin "+who->query("id"));
			message_vision("$N��ݺݵض�$n�е�����ү���첻���ˣ��������С��������������  $N������ɱ��$n��\n", me, who);
			kill_ob(who);
			return;
		}
		if (who->query("gender")=="Ů��" && who->query("age")<30  && random(3)==2)
		{
			command("flirt "+who->query("id"));
			message_vision("$N��ǰ��Ϸ$n��$nȴ�����������ӡ�$N��Ȼ��ŭ��������ɱ��$n��\n", me, who);
			me->set_temp("rapping",1);
			kill_ob(who);
			return;
		}
		else if (who->query("gender")=="Ů��" && who->query("age")<30 )
		{
			switch (random(4))
			{
				case 0 :
					command("flirt "+who->query("id"));
					break;
				case 1 :
					command("flirt2 "+who->query("id"));
					break;
				case 2 :
					command("miss4 "+who->query("id"));
					break;
				case 3 :
					command("miss2 "+who->query("id"));
					break;
			}
			switch (random(4))
			{
				case 0 :
					message_vision("$N��ǰ��Ϸ$n��$nȴ��$N������\n", me, who);
					break;
				case 1 :
					message_vision("$N�����ֺ�$n��$nȴ��$N�Ӷ�������\n", me, who);
					break;
				case 2 :
					message_vision("$N��$n�ٰ����ڣ�$nȴ��$N�޶����ԡ�\n", me, who);
					break;
				case 3 :
					message_vision("$N��$n�������$nȴ��$NŭĿ���ӡ�\n", me, who);
					break;
			}
			me->start_busy(20);
			remove_call_out("action_start");
			call_out("action_start", 5, me, who);
			return;
		}
		else if (who->query("race")!="����")
		{
			command("grin "+who->query("id"));
			message_vision("$N�ֵ��������ӵĶ������������أ���Ұζ������������  $N���$nɱ�˳Ե���\n", me, who);
			kill_ob(who);
			return;
		}
		else if (random(3)==2)
		{
			message_vision("$N��Ц�ŵض�$n˵�������������Գ���"+RANK_D->query_rude(who)+"�����ԹԵظϿ�����鱦��������\n", me, who);
			message_vision("$n���ɲ�����$N����Ц�ź������"+RANK_D->query_rude(who)+"��������������Ҫɱ����Ȯ��������  ����$N��ɱ��$n��\n", me, who);
			kill_ob(who);
			return;
		}
		else
		{
			switch (random(4))
			{
				case 0 :
					message_vision(CYN"$NЦ����������$n˵����"+RANK_D->query_self_rude(me)+"�ҽ�����磬ȱ��Щ�̲�"+RANK_D->query_close(who)+"����������������ɣ�\n"NOR, me, who);
					break;
				case 1 :
					command("poor "+who->query("id"));
					break;
				case 2 :
					message_vision(CYN"$N�ᵶ��������$nһ���󺰣�����ɽ���ҿ������������ԣ���Ҫ�Ӵ˹���������·�� !\n"NOR, me, who);
					break;
				case 3 :
					command("interest "+who->query("id"));
					break;
			}
			switch (random(4))
			{
				case 0 :
					message_vision(CYN"$nץ��һ�ѹ��ӵݸ�$N�������İɣ�������������ӣ�ע�ⲻҪ���¿Ƕ�����\n"NOR, me, who);
					break;
				case 1 :
					message_vision(CYN"$n��ü������߳�������ٴ��ҵ�������,��������͸�����Ҳ����Ӧ��,��������İɣ���\n"NOR, me, who);
					break;
				case 2 :
					message_vision("$nȡ��һ���廨�ɰ�����������һ����ֻ����વ�һ�����죬��Ȼ�ɰ���ûʲô������\n", me, who);
					break;
				case 3 :
					message_vision(CYN"$n��$N˵�����Ҳ���ʶ�㣬ƾʲôҪ���㣡\n"NOR, me, who);
					break;
			}
			me->start_busy(20);
			remove_call_out("action_start");
			call_out("action_start", 5, me, who);
			return;
		}
	}
	return;
}

void action_start(object me, object who)
{
	if (me->query_temp("arrestee"))
	{
		remove_call_out("action_start");
		remove_call_out("action_end");
		remove_call_out("action_stop");
		return;
	}
	if (who->query("gender")=="Ů��" && who->query("age")<30)
	{
		switch (random(4))
		{
			case 0 :
				message_vision(CYN"$N����$n���ŵ�˵����"+RANK_D->query_close(who)+"���������������һ����\n"NOR, me, who);
				break;
			case 1 :
				message_vision(CYN"$N��ʼ��$n���ֶ��ŵ�˵����"+RANK_D->query_close(who)+"����"+RANK_D->query_self_rude(me)+"��ȥ�ɡ�\n"NOR, me, who);
				break;
			case 2 :
				message_vision(CYN"$N���������Ķ�$n˵����"+RANK_D->query_close(who)+"����"+RANK_D->query_self_rude(me)+"��֤����һ���ӡ�\n"NOR, me, who);
				break;
			case 3 :
				message_vision(CYN"$N��ʼ��$n��������˵����"+RANK_D->query_close(who)+"��������£��������������ꡣ\n"NOR, me, who);
				break;
		}
		switch (random(4))
		{
			case 0 :
				message_vision(CYN"$n����һ������$Nŭ��������������󡣬��֪�һ��˶����澵���ˣ�Ҳ�������һ�����֣���\n"NOR, me, who);
				me->set_temp("rapping",1);
				break;
			case 1 :
				message_vision(CYN"$n����$N�µ������㵱����˭ѽ������Ϊ����С��Ůѽ����\n"NOR, me, who);
				me->set_temp("rapping",1);
				break;
			case 2 :
				message_vision("$n����һ�������ҿ����������ļǶ��⡣žžžž���������$N�������յ�ʱ���ס�\n", me, who);
				me->set_temp("rapping",1);
				break;
			case 3 :
				message_vision(CYN"$n��$N˵���������������ô��Ƥ�ȳ�ǽ��������񣡡�\n"NOR, me, who);
				me->set_temp("rapping",1);
				break;
		}
	}
	else
	{
		switch (random(4))
		{
			case 0 :
				command("stare "+who->query("id"));
				break;
			case 1 :
				message_vision(CYN"$N����$nŭ������"+RANK_D->query_rude(who)+"��"+RANK_D->query_self_rude(me)+"����������ɫ��Ϳ���Ⱦ�����ˡ�\n"NOR, me, who);
				break;
			case 2 :
				message_vision(CYN"$N��$n�ȵ�����"+RANK_D->query_rude(who)+"���㻹Ҫ��Ҫ����������������ϵĽ����鱦����������\n"NOR, me, who);
				break;
			case 3 :
				message_vision(CYN"$N��ŭ������ָ��$n����������"+RANK_D->query_rude(who)+"�������ò��ͷ��ˣ���\n"NOR, me, who);
				break;
		}
		switch (random(4))
		{
			case 0 :
				message_vision(CYN"$n���쳤̾�������ѵ����������Ȼû��������������ڰ����� ��\n"NOR, me, who);
				me->set_temp("robbing",1);
				break;
			case 1 :
				message_vision(CYN"$n��$N�ȵ�����"+RANK_D->query_rude(me)+"���㾹�ҵ�����������Ҫȥ�ٸ����㣡���� ��\n"NOR, me, who);
				me->set_temp("robbing",1);
				break;
			case 2 :
				message_vision(CYN"$n����$N��У���$N�����������å����\n"NOR, me, who);
				me->set_temp("robbing",1);
				break;
			case 3 :
				message_vision("$n��$N�Ŀ�����ȫ��֮����\n", me, who);
				me->set_temp("robbing",1);
				break;
		}
	}
	me->start_busy(30);
	kill_ob(who);
	remove_call_out("action_end");
	call_out("action_end", 5, me, who);
	return;
}
void action_end(object me, object who)
{
	if (me->query_temp("arrestee"))
	{
		remove_call_out("action_start");
		remove_call_out("action_end");
		remove_call_out("action_stop");
		return;
	}
	if (who->query("gender")=="Ů��" && who->query("age")<30)
	{
		switch (random(6))
		{
			case 0 :
				command("stare "+who->query("id"));
				break;
			case 1 :
				command("loveshoe "+who->query("id"));
				break;
			case 2 :
				command("smell2 "+who->query("id"));
				break;
			case 3 :
				command("smell "+who->query("id"));
				break;
			case 4 :
				command("mo97 "+who->query("id"));
				break;
			case 5 :
				command("doufu "+who->query("id"));
				break;
		}
		switch (random(4))
		{
			case 0 :
				message_vision(CYN"$n����$N�������Ҫ�����޳���������Ϸ��Ů����\n"NOR, me, who);
				remove_call_out("action_stop");
				call_out("action_stop", 1, me, who);

				break;
			case 1 :
				message_vision("$n��$N�Ӷ�������\n", me, who);
				remove_call_out("action_start");
				call_out("action_start", 5, me, who);
				break;
			case 2 :
				message_vision(CYN"$n����$N˵�˾䣺���ģ�\n"NOR, me, who);
				remove_call_out("action_stop");
				call_out("action_stop", 1, me, who);
				break;
			case 3 :
				message_vision(CYN"$n��������޲����İ���\n"NOR, me, who);
				remove_call_out("action_stop");
				call_out("action_stop", 1, me, who);
				break;
		}
	}
	else
	{
		switch (random(8))
		{
			case 0 :
				message_vision("$N��ݺݵض���$n��"+RANK_D->query_rude(who)+"���ҿ���������Ķ��ܡ�\n", me, who);
				break;
			case 1 :
				message_vision("$N��ݺݵض���$n��"+RANK_D->query_rude(who)+"���ҿ���������Ķ��ܡ�\n", me, who);
				break;
			case 2 :
				message_vision(CYN"$N��$n�ȵ������������ˣ�����ɱ������"+RANK_D->query_rude(who)+"��˵����\n"NOR, me, who);
				break;
			case 4 :
				message_vision(CYN"$N��ŭ������ָ��$n����������"+RANK_D->query_rude(who)+"�������ò��ͷ��ˣ���\n"NOR, me, who);
				break;
			case 5 :
				message_vision("$N���ĵؿ���$n���޲��ð�����ж�˿����̻����\n", me, who);
				break;
			case 6 :
				message_vision(CYN"$Nһ�����ӣ�����$n�����Ľе�������ˣ��������Ѱ�������ˣ������\n"NOR, me, who);
				break;
			case 7 :
				message_vision(CYN"$N����$n�������"+RANK_D->query_rude(who)+"���Ҳ��ݺ�����һ�٣�������ͷ֮�ޡ���\n"NOR, me, who);
				break;
		}
		switch (random(4))
		{
			case 0 :
				message_vision(CYN"$n��У�����������ɱ�˰������˰�����\n"NOR, me, who);
				remove_call_out("action_stop");
				call_out("action_stop", 1, me, who);
				break;
			case 1 :
				message_vision("$n��$N������ġ�\n", me, who);
				remove_call_out("action_stop");
				call_out("action_stop", 1, me, who);
				break;
			case 2 :
				message_vision(CYN"$n��$N˵��������������п�ȸ����\n"NOR, me, who);
				remove_call_out("action_stop");
				call_out("action_stop", 1, me, who);
				break;
			case 3 :
				message_vision("$n��δ����$N�Ļ���\n", me, who);
				remove_call_out("action_start");
				call_out("action_start", 5, me, who);
				break;
		}
	}
	return;
}
void action_stop(object me, object who)
{
	object room, room1;
	int room_no;

	if (me->query_temp("arrestee"))
	{
		remove_call_out("action_start");
		remove_call_out("action_end");
		remove_call_out("action_stop");
		return;
	}
	switch (random(3))
	{
		case 0 :
			message_vision("$N����ûȤ������������ˡ�\n", me, who);
			break;
		case 1 :
			message_vision("$N��$n���޷�Ӧ���Թ����ˡ�\n", me, who);
			break;
		case 2 :
			message_vision("$N��$n̬��ǿӲ��ֻ�����ա�\n", me, who);
			break;
	}
	me->delete_temp("robbing");
	me->delete_temp("rapping");
	me->remove_all_killer();
	who->remove_all_killer();
	me->start_busy(1);
	return;
}

int random_move()
{
	mapping exits, doors;
	string *dirs, dir;
	object me=this_object();

	if (is_fighting() || is_busy() || !living(me)) return 0;

	if (!me->query("steps"))
	{
		remove_call_out("destroying");
		call_out("destroying",1200,me);
	}
	if (me->query("steps")>=50)
	{
		remove_call_out("destroying");
		call_out("destroying",1,me);
		return 0;
	}
	me->add("steps",1);
	if (!objectp(environment()) || !mapp(exits = environment()->query("exits")) || query("jingli") < query("max_jingli") / 2 ) return 0;
	dirs = keys(exits);
	if (this_object()->query("race") == "����" && mapp(doors = environment()->query_doors())) dirs += keys(doors);
	if (sizeof(dirs) == 0) return 0;
	dir = dirs[random(sizeof(dirs))];
	if (strsrch(environment(me)->query("exits/"+dir), "/d/dali/minov") == -1) return 0;
	if (mapp(doors) && !undefinedp(doors[dir]) && (doors[dir]["status"] & DOOR_CLOSED)) command("open " + dir);
	command("go " + dir);
	return 1;
}
void destroying(object me)
{
	switch (random(3))
	{
		case 0 :
			message_vision("$N�㬵�������������������浹ù������һ��ȦʲôҲûŪ������  ˵�վͼ��Ҵҵ����ˡ�\n",me);
			break;
		case 1 :
			message_vision("$N������ص����µ���������ģ������治���ˣ���ôһ���˾�ȻʲôҲûŪ������  ˵�վͼ��Ҵҵ����ˡ�\n",me);
			break;
		case 2 :
			message_vision("$N������ص���������������ôʲôҲû���ҵ� ... ... �����Щ���������ɡ���  ˵�վͼ��Ҵҵ����ˡ�\n",me);
			break;
	}
	destruct(me);
	return;
}

void unconcious()
{
	object ob, me=this_object();

	if (objectp(ob = me->query_temp("last_damage_from")) && ob->query_temp("marks/arrestee") != me->query("name")) me->set("wrong_fainted", 1);
	::unconcious();
}

void die()
{
	object ob, me=this_object();

	if (objectp(ob=me->query_temp("last_damage_from")) && me->query("combat_exp")>ob->query("combat_exp")*2) ob->add("dali/trust", 1);
	::die();
}
