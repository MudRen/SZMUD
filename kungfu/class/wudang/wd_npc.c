// Code of ShenZhou
// modified from zhang.c 3/00

inherit NPC;
inherit F_MASTER;

#include <ansi.h>
#include "/kungfu/class/wudang/auto_perform.h"

int reset();
int auto_perform();
string ask_tjsg();
string ask_zhenwu();
#define CANPIAN "/kungfu/class/wudang/obj/canpian"

void create()
{

        set_name("������", ({ "zhang sanfeng", "zhang" }));
        set("nickname", "��������");
        set("long",
                "������䵱�ɿ�ɽ���桢�������ֵ�̩ɽ�������������ˡ�\n"
                "��������һϮ�ۻ�ĻҲ����ۣ����θߴ��쳣���뷢������\n"
		"���Ϻ���⻬��Ц���е����ǿ��ף�����Ҳ��������״��\n");
        set("gender", "����");
        set("age", 100);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        
        set("max_qi", 14123);
        set("max_jing", 4000);
	set("eff_jingli", 5000);
	set("max_jingli", 5000);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jiali", 300);
        set("combat_exp", 6400000);
        set("score", 640000);

        set_skill("force", 400);
        set_skill("taiji-shengong", 400);
        set_skill("dodge", 400);
        set_skill("tiyunzong", 400);
        set_skill("cuff", 400);
        set_skill("taiji-quan", 400);
        set_skill("parry", 400);
        set_skill("sword", 400);
        set_skill("taiji-jian", 400);
        set_skill("taoism", 400);
        set_skill("literate", 400);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        prepare_skill("cuff", "taiji-quan");

        create_family("�䵱��", 1, "��ɽ��ʦ");
        set("class", "taoist");
        set("chat_chance", 80);
        set("chat_msg", ({
                (: reset :),
        }) );

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

        set("inquiry", ([
		"���佣" : (: ask_zhenwu : ),
		"̫����" : (: ask_tjsg :),
		"������" : (: ask_tjsg :)
        ]));

	setup();
	if( clonep() )
	{
		carry_object("/clone/weapon/changjian")->wield();
		carry_object("/d/wudang/obj/greyrobe")->wear();
	}
}

string ask_zhenwu()
{
	object player = this_player();

	if( !player->query("wudang/zhenwu") )
		return "�����佣����ƶ������ʱ���õı��С�";
}

string ask_tjsg() {
    object *obs, obj, player=this_player();

    if (player->query("family/master_id") != "zhang sanfeng") {
        return "̫���������䵱������֮����\n";;
    }
    switch (random(10)) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        return "��ʦ��Զ��ʦ���ھ��ģ�����ѧ��ȫ��������չ����Σ�"+
                "������У���ֻ����ͨ�����ĳɡ�\n";
    case 5:
    case 6:
    case 7:
    case 8:
        return "��ʦ��Զ��ʦѧ�á������澭����Բ��֮ǰ���о��ģ�����Ů����"+
              "��������ɫ��ʦ�������˸��Լǵ�һ���֣�\n"+
                "����䵱�����ҡ����������书�������ʮ������ͥ�����������֡�\n";
    case 9:
        if (player->query_skill("taiji-shengong", 1) < 200) {
            return "��Ĺ�����ǳ���ú�ѧȫ���䵱̫������˵�ɡ�\n";
        }

        obj = 0;
        obs = filter_array(children(CANPIAN), (: clonep :));
        if (sizeof(obs) > 0) obj = obs[0];

        if (objectp(obj) && objectp(environment(obj)) &&
            userp(environment(obj))) {
            return "�����񹦲�ƪ����ʦ�ֵܽ����ˣ���ȥ�����ǰ�\n";
        }
        if (!objectp(obj)) obj = new(CANPIAN);
        obj->move(player);
        message_vision("$N��$nһ�������񹦲�ƪ��\n", this_object(), player);
	command ("rumor "+this_player()->query("name")+"Ū����һ��"NOR YEL"�����񹦲�ƪ"HIM"��"NOR);
        return "�ҽ����мǵõ�һЩ�����񹦱�¼�ڴˣ�\n"+
                "�����һλ�����ɸ�����֮��ͬ����(canwu)��Ҳ�����⹦������ʧ����\n";
    }
    return 0;
}

void attempt_apprentice(object ob)
{
        mapping fam;

        if( mapp(fam = ob->query("family")) && fam["family_name"] != "�䵱��" )
        {
                command ("say " + RANK_D->query_respect(this_player())
                        + "�����������ˣ�ϰ�仹���ȴӸ�λ������ɣ�");
                return;
        }

        if ((string)ob->query("family/family_name") == "ؤ��" && ob->query("rank") > 1 ) {
                command("say " + RANK_D->query_respect(ob) + "��ؤ����֣�ˡ�Ҳ������㡣");
                return;
        }

        if ((int)ob->query_skill("taiji-shengong", 1) < 100) {
                command("say ���䵱�����ڼ��书���������ڹ��ķ���"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "�Ƿ�Ӧ����̫�����϶��µ㹦��");
                return;
        }
        if ((int)ob->query("shen") < 100000) {
                command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }
        if (ob->query_int() < 30) {
                command("say ���䵱���书ȫ�ӵ��������");
                command("say Ҫ�ܴﵽ¯����֮��������ʲô�ĵ����޹ؽ�Ҫ������ȴ�ǰ��Ҳ�����á�");
                command("say " + RANK_D->query_respect(ob) + "�����Ի�����Ǳ�����ڣ�������ذɡ�");
                return;
        }
        command("chat ����������������");
        command("chat �벻���ϵ��ڴ���֮�꣬���ٵ�" + ob->name() + "��ôһ������֮�ţ����ǿ�ϲ�ɺء�");
        command("recruit " + ob->query("id"));
}

int accept_kill(object obj)
{
	object me = this_object();
	mapping skill_status;
	string *sname;
	int i, max = 200;

	command("chat ������" + obj->name() + "����" );
	command("chat ƶ�������ǰ�������������ˣ���Ȼ����ɱ���ң������⸱�Ϲ�ͷ��Ҫ��ֻ����"
	 + RANK_D->query_respect(obj) + "�������ˡ�");

	if( !objectp(obj->query_temp("weapon")) || !objectp(me->query_temp("weapon")) )
	{
		command("unwield sword");
		command("enable parry taiji-quan");
	}
	else if( objectp(obj->query_temp("weapon")) )
	{
		command("wield sword");
		command("enable parry taiji-jian");
	}
	command("exert taiji");
/*
	if( obj->query("combat_exp") > 2000000 )
	{
		me->set("combat_exp", obj->query("combat_exp"));

		if( mapp(skill_status = obj->query_skills()) )
		{
			skill_status = obj->query_skills();
			sname = keys(skill_status);

			for( i=0; i < sizeof(skill_status); i++ )
				if( skill_status[sname[i]] > max )
					max = skill_status[sname[i]];
		}
		if( mapp(skill_status = me->query_skills()) )
		{
			skill_status = me->query_skills();
			sname = keys(skill_status);
			for( i=0; i < sizeof(skill_status); i++ )
				me->set_skill(sname[i],max);
		}
		me->set_skill("taoism", 200);
		me->set_skill("literate", 200);
	}
*/
	return 1;
}

void die()
{
	object ob, me;
	me = this_object();

	if( !living(this_object()) ) revive(1);
	command("chat ƶ���ݺὭ�������꣬����ʼ���������죬�������ˣ�");
	if( objectp(ob = me->query_temp("last_damage_from")) )
	{
		command("chat " + ob->name() + "������أ��������Ž��ޱȡ�");
		command("chat* " + "ָ��" + ob->name()
		 + "��̾������" + ob->name() + "�ǹ����������ֵ�һ����ʦ����\n");
	}
	::die();
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob=this_player())) {
        if (ob->query("family/master_id") == "zhang sanfeng"
        && (ob->query("shen") < -100
          || time() < (int)ob->query("incharge") + 864000)) {
                command("say " + RANK_D->query_rude(ob) + "�������������������Ϊ��");
                command("expell " + ob->query("id"));
        }
        }
}

int reset()
{
        object me = this_object();
/*
	if( me->query("combat_exp") > 4000000 )
	{
		me->set_skill("force", 400);
		me->set_skill("taiji-shengong", 400);
		me->set_skill("dodge", 400);
		me->set_skill("tiyunzong", 400);
		me->set_skill("cuff", 400);
		me->set_skill("taiji-quan", 400);
		me->set_skill("parry", 400);
		me->set_skill("sword", 400);
		me->set_skill("taiji-jian", 400);
		me->set("combat_exp", 4000000);
	}
*/
	if( me->query("eff_qi") < me->query("max_qi") )
		exert_function("heal");
	me->set("jiali", 300);
	command("wield sword");

	return 1;
}
