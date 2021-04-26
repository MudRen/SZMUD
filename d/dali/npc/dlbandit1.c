// Code of ShenZhou
// dali bandit 1, low level

#include <ansi.h>
#include <room.h>

inherit NPC;
string ask_me();

void create()
{
	int i;
	i=random(5)+1;
	switch (random(5)) {
	case 0 :
		set_name("С��", ({"xiao zei", "zei"}));
		break;
	case 1 :
		set_name("��Ʀ", ({"di pi", "pi"}));
		break;
	case 2 :
		set_name("���", ({"e ba", "ba"}));
		break;
	case 3 :
		set_name("��å", ({"liu mang", "liu"}));
		break;
	case 4 :
		set_name("����", ({"wu lai", "lai"}));
		break;
	}
	switch (i) {
	case 1 :
		set("title", "������������");
		set("long", "��һ���������������������������¶���Ҳ����ѧ��Щ���򣬻ص������Ϊ��������\n�������������΢��\n");
		break;
//	case 2 :
//		set("title", "��ɽ����ͽ");
//		set("long", "�����������ڻ�ɽ����ѧ�գ���Ϊ��Ϊ���챻�����ǽ���ڵط������չ�죬��ܶ�Ź��\n����������Ȼ����������������ȴ����ô����\n");
//		break;
	case 2 :
		set("title", "�䵱����ͽ");
		set("long", "���������䵱�ɵĵͱ����ӣ�ĳ����ʦ����ɽ������У���ʦ�������˺���Ҳ���һ��䵱��ƾ��һ�㹦���ڽ������˻졣\n�������������Ĳ��\n");
		break;
	case 3 :
		set("title", "ѩɽ��С����");
		set("long", "�����½���������µ�С���������ѩɽ��������������߾���ɽ��͵��������\n����û��ѧ�����ٹ���\n");
		break;
	case 4 :
		set("title", "ؤ�����");
		set("long", "����һ����ؤ��磬��ʵ������Ϊ�񼣱�ؤ�￪�����ڱ����첻��ȥ�ˣ��ܵ��ϱ�������\n�������˴��׺ݣ�û�ж������ʵѧ��\n");
		break;
	case 5 :
		set("title", "�嶾�̴���");
		set("long", "�嶾���ܲ��ڴ�����ȻҪ����צ�����������������ǵط��������Ķ�������������֡�\n����Ȼûѧ�����ٹ������ֵ������ý��ġ�\n");
		break;
	}

	set("gender", "����");
	set("age", 20+random(10));
	set("attitude", "heroism");
	set("str", 20+random(10));
	set("int", 10+random(10));
	set("con", 15+random(10));
	set("dex", 20+random(10));
	set("dalibandit",1);
	set("shen_type", -1);
	set("inquiry", ([
            "�����" : (: ask_me :),
        ]));
    set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :),
	}));

	setup();
	
	carry_object("/d/city/obj/beixin")->wear();
}

void init()
{
	object who=this_player(), me=this_object();

	if (interactive(who)) set_heart_beat(1);

	if (who->query("dalivictim") && !me->is_fighting() && random(3)==2) {
		remove_call_out("killvictim");
		call_out("killvictim", 1, me, who);
	}
}
string ask_me()
{
                object me, who;

                who = this_object();
                me = this_player();
                if (who->query("owner") == me->query("id"))
                {
                   command ("heihei");
                                
                                return "������Ǵ�������Ǹ��õط���";
                }

                command ("en");

                return "������Ǵ������";    
}


void killvictim(object me, object who)
{
	if (present(who, environment(me))) {
		if (who->query("race")=="����" && who->query("age")<15) {
			command("grin "+who->query("id"));
			message_vision("$N��ݺݵض�$n�е�����ү���첻���ˣ��������С��������������  $N������ɱ��$n��\n", me, who);
			kill_ob(who);
			return;
		}
		if (who->query("gender")=="Ů��" && who->query("age")<30) {
			command("flirt "+who->query("id"));
			message_vision("$N��ǰ��Ϸ$n��$nȴ�����������ӡ�$N��Ȼ��ŭ��������ɱ��$n��\n", me, who);
			kill_ob(who);
			return;
		}
		else {
			if (who->query("race")!="����") {
				command("grin "+who->query("id"));
				message_vision("$N�ֵ��������ӵĶ������������أ���Ұζ������������  $N���$nɱ�˳Ե���\n", me, who);
				kill_ob(who);
				return;
			}
			else {
				message_vision("$N��ݺݵض�$n�µ�����"+RANK_D->query_rude(who)+"��ʲôֵǮ�Ķ������Ͽ��ó���Т�����ӡ���\n", me, who);
				message_vision("$n��΢���ɲ�����$N�㲪Ȼ��ŭ��������"+RANK_D->query_rude(who)+"�Ҳ�������  ����$N��ɱ��$n��\n", me, who);
				kill_ob(who);
				return;
			}
		}
	}
	return;
}

int random_move()
{
	mapping exits, doors;
	string *dirs, dir;
	object me=this_object();

	if (is_fighting() || is_busy() || !living(me))
		return 0;

	if (!me->query("steps")) {
		remove_call_out("destroying");
		call_out("destroying",1200,me);
	}

	if (me->query("steps")>=30) {
		remove_call_out("destroying");
		call_out("destroying",1,me);
		return 0;
	}

	me->add("steps",1);

	if (!objectp(environment()) 
		|| !mapp(exits = environment()->query("exits")) 
        || query("jingli") < query("max_jingli") / 2 )
		return 0;

	dirs = keys(exits);

	if (this_object()->query("race") == "����"
		&& mapp(doors = environment()->query_doors()))
		dirs += keys(doors);

	if (sizeof(dirs) == 0) return 0;
	dir = dirs[random(sizeof(dirs))];

	if (strsrch(environment(me)->query("exits/"+dir), "/d/dali/minov") == -1)
		return 0;

	if (mapp(doors) && !undefinedp(doors[dir])
		&& (doors[dir]["status"] & DOOR_CLOSED) )
		command("open " + dir);

	command("go " + dir);
	return 1;
}

void destroying(object me)
{
	message_vision("$N�㬵�������������������浹ù������һ��ȦʲôҲûŪ������  ˵�վͼ��Ҵҵ����ˡ�\n",me);
	destruct(me);
	return;
}

void unconcious()
{
	object ob, me=this_object();

	if (objectp(ob = me->query_temp("last_damage_from"))
		&& ob->query_temp("marks/arrestee") != me->query("name"))
		me->set("wrong_fainted", 1);

	::unconcious();
}

void die()
{
	object ob, me=this_object();

	if (objectp(ob=me->query_temp("last_damage_from"))
		&& me->query("combat_exp")>ob->query("combat_exp")*2)
		ob->add("dali/trust", 1);

	::die();
}
