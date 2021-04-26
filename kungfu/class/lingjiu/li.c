// /NPC li.c 
// By Xuanyuan 12/7/2001

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int auto_perform();
int ask_youming();
int ask_guizhao();

void create()
{
	set_name("����ˮ", ({ "li qiushui", "li", "qiushui" }));
	set("long",
	    "�����Ű�ɫ����������������ȣ��������˿�׳��Ʋ��������ݡ�\n");
	set("title", "���Ĺ���̫��");
	set("gender", "Ů��");
	set("per", 13);
	set("age", 80);
	set("shen_type",-1);
	set("attitude", "peaceful");

	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 30);

	set("max_qi", 6000);
	set("max_jing", 3200);
	set("neili", 7500);
	set("max_neili", 7500);
	set("jiali", 100);

	set("combat_exp", 3500000);

	set_skill("force", 350);
	set_skill("dodge", 350);
	set_skill("parry", 350);
	set_skill("hand",350);
	set_skill("strike", 350);
	set_skill("sword",350);
	set_skill("blade",350);
	set_skill("literate",100);
	set_skill("music",350);
	set_skill("claw",350);

	set_skill("youming-guizhao",350);
	set_skill("zhemei-shou",350);
	set_skill("liuyang-zhang",350);
	set_skill("tianyu-qijian",350);
	set_skill("yueying-wubu",350);
	set_skill("bahuang-gong", 350);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "youming-guizhao");
	map_skill("sword", "tianyu-qijian");
	map_skill("claw", "youming-guizhao");

	prepare_skill("claw","youming-guizhao");

	set("inquiry", ([
		"��ڤ��צ" : (: ask_youming :),
		"�����צ" : (: ask_guizhao :),
	]));
	set("lingjiu/guizhao",1);

	create_family("���չ�",1,"����");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
	setup();
	carry_object("/d/zhongnan/obj/baipao")->wear();
}

void init()
{
	object ob = this_player();

	add_action("do_learn","learn");
	add_action("do_learn","xue");
	::init();
	if (ob->query_skill("beiming-shengong") && ob->query("id") != "wuya zi" || 
		ob->query_skill("lingbo-weibu") && ob->query("id") != "wuya zi" ) {
//	if (ob->query("got_beiming")) {
		message_vision(HIY "$NͻȻ��$n�ȵ�����Ȼ�ô���徸��أ�����������ɣ�\n"NOR, this_object(), ob );
		kill_ob(ob);
	   }
}

int ask_youming()
{
        object ob = this_player();
        
        if (ob->query("family/family_name") != "���չ�") {
                command("sneer");
                command("say ʦ��ȴ��֪����������ڤ��צ�������չػ�֮ͯʱҪ�����ܵ��ͷ��");
                return 1;
        }
		if (ob->query("family/master_name") == "��ɽͯ��") {
                command("say ʦ��������͵ѧ�ҵ���ڤ��צ���Ǿ������ʶ��ʶ��");
				kill_ob(ob);
				return 1;
		}     
        if (ob->query("lingjiu/li")) {
                command("say �Ҳ����Ѿ���ʼ������ô��");
                return 1;
        }
        if (ob->query_skill("claw",1) < 99) {
                command("say Ҫʹ�������ľ�����Ҫ�����צ�����㻹�Ƕ���ϰ��ϰ��˵�ɡ�");
                return 1;
        }
		command("say �ã��Ҿͽ������ס���ڤ��צ�����������ҶԸ��Ǹ����ˣ�\n");
        ob->set("lingjiu/li", 1);
        return 1;
}
int ask_guizhao()
{
        object ob = this_player();
        
        if (ob->query("family/family_name") != "���չ�") {
                command("sneer");
                command("say ʦ��ȴ��֪����������ڤ��צ�������չػ�֮ͯʱҪ�����ܵ��ͷ��");
                return 1;
        }
		if (ob->query("family/master_name") == "��ɽͯ��") {
                command("say ʦ��������͵ѧ�ҵ���ڤ��צ���Ǿ������ʶ��ʶ��");
				kill_ob(ob);
				return 1;
		}     
        if (!ob->query("lingjiu/li")) {
                command("say ˭������͵ѧ���书�ģ�");
                return 1;
        }
        if (ob->query_skill("claw",1) < 180) {
                command("say Ҫʹ�������ľ�����Ҫ�����צ�����㻹�Ƕ���ϰ��ϰ��˵�ɡ�");
                return 1;
        }
        if (ob->query_skill("youming-guizhao",1) < 180) {
                command("say Ҫʹ�������ľ�����Ҫ�����צ�����㻹�Ƕ���ϰ��ϰ����ڤ��צ����˵�ɡ�");
                return 1;
        }

		command("say �ã��Ҿͽ���һʽ�������צ�����������ҶԸ��Ǹ����ˣ�\n");
        ob->set("lingjiu/guizhao", 1);
        return 1;
}
int do_learn(string arg)
{
	object me=this_player();
	string skill, teacher, skill_name;
	object ob;
	int master_skill, my_skill, gin_cost, rand;

        if (me->is_busy())
                return 0;

	if(!arg || (sscanf(arg, "%s %s", teacher, skill)!=2 ))
		return 0;
	if (teacher != "li" && teacher != "qiushui" && teacher != "li qiushui")
		return 0;
	if( me->is_fighting() )
		return 0;
	if( !(ob = present(teacher, environment(me))) || !ob->is_character()) {
		write("��Ҫ��˭��̣�\n");
		return 1;
	}
	if( !living(ob) ) {
		write("��....����Ȱ�" + ob->name() + "Ū����˵��\n");
		return 1;
	}
	if( !me->query("lingjiu/li")) {
		write("����ˮ������ȵ���˭������͵ѧ���书�ģ�\n");
		return	1;
	}
	if (me->query("family/master_name") == "��ɽͯ��") {
		command("say ����Ѱ�����ʦ�����£�����ѧ������ڤ��צ��ʲô��");
		me->delete("lingjiu/li");
		kill_ob(me);
		return 1;
		}     
	if (skill != "youming-guizhao" && skill != "��ڤ��צ") {
		write("���������±����ұ���ѧ�ˡ�\n");
		return 1;
	}
	my_skill = me->query_skill(skill, 1);
	master_skill = ob->query_skill(skill, 1);
	if( my_skill >= master_skill ) {
		write("������ڤ��צ�ϵ������Ѿ���������ˮ�ˣ�\n");
		return 1;
	}
	if( !SKILL_D(skill)->valid_learn(me) ) {
		write("������ǿ��ֲ������㹻���ڹ��������ſ���ѧϰ��ڤ��צ��\n");
		return 1;
	}
	gin_cost = 150 / (int)me->query("int");

	if( !my_skill ) {
		gin_cost *= 2;
		me->set_skill(skill,0);
	}
	rand = random(20);
	if (rand == 4)
		gin_cost *= 2;
	else if (rand == 15)
		gin_cost += 4;
	if( (int)me->query("potential") < 1 ){
		write("���Ǳ���Ѿ����ӵ������ˣ�û�а취��ѧ�ˡ�\n");
		return 1;
	}
	message_vision("$N��$n����йء���ڤ��צ�������⡣\n", me, ob);
	if( (int)me->query("jing") > gin_cost ) {
		if( (string)SKILL_D(skill)->type()=="martial"
		&&	my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) {
			write("Ҳ����ȱ��ʵս���飬�������ˮ�Ľ��������޷���ᡣ\n");
		} 
		else {
			if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
				write("����������ˮ��ָ�����ԡ�" + skill_name + "����һ���ƺ���Щ�ĵá�\n");
			else
				write("����������ˮ��ָ�����ƺ���Щ�ĵá�\n");
			me->add("potential", -1);
			me->improve_skill(skill, random(me->query_int()));
		}
	} 
	else {
		gin_cost = me->query("jing");
		write("�����̫���ˣ����ʲôҲû��ѧ����\n");
	}

	me->receive_damage("jing", gin_cost );

	return 1;
}

int auto_perform()
{
	object me=this_object();
	object weapon=me->query_temp("weapon");
	object opp=me->select_opponent();

	if( me->query("qi",1) < 0 || me->query("jing",1) < 0 || me->query("jingli",1) < 0) return 1;

	if ( !me->is_fighting() ) {
					 if ( me->query("eff_qi") < me->query("max_qi") )
								me->exert_function("heal");
					 me->set("jiali", 50);

					 return 1;
		  }

	if ( !me->query_temp("lingjiu/youming") ) {
			return perform_action("claw.youming");
			}
			else return perform_action("claw.guizhao");
}
