// Code of ShenZhou
// zhang.c ������

inherit NPC;
inherit F_MASTER;

int auto_perform();
string ask_tjsg();
#define CANPIAN "/kungfu/class/wudang/obj/canpian"

void create()
{
	object zhenwu;

	set_name("������", ({ "zhang sanfeng", "zhang" }));
	set("nickname", "��������");
	set("long", 
		"�������䵱�ɿ�ɽ���桢�������ֵ�̩ɽ�������������ˡ�\n"
		"��һ���ۻ�Ļ�ɫ���ۣ����ޱ߷���\n"
		"��ĸߴ��������꣬������⣬��ü�԰ס�\n");
	set("gender", "����");
	set("age", 100);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 5000);
	set("max_jing", 3000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 300);
	set("combat_exp", 2000000);
	set("score", 500000);

	set_skill("force", 200);
	set_skill("taiji-shengong", 200);
	set_skill("dodge", 200);
	set_skill("tiyunzong", 200);
	set_skill("cuff", 200);
	set_skill("taiji-quan", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("taiji-jian", 200);
	set_skill("taoism", 200);
	set_skill("literate", 200);

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
		(: auto_perform :),
	}) );

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	set("inquries", ([
	    "̫����" : (: ask_tjsg :),
	    "������" : (: ask_tjsg :)
	]));

	setup();
	zhenwu=carry_object("/clone/unique/zhenwu");
	if (objectp(zhenwu)) zhenwu->wield();
}

string ask_tjsg() {
    object obj, player=this_player();

    if (player->query("family/master_id") != "zhang sanfeng") {
	return 0;
    }
    switch (random(10)) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
	return "��ʦ��Զ��ʦ���ھ��ģ�����ѧ��ȫ��������չ����Σ�"+
		"������У���ֻ����ͨ�����ĳɡ�\n";
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
	obj = find_object(CANPIAN);
	if (objectp(obj) && userp(environment(obj))) {
	    return "�����񹦲�ƪ����ʦ�ֵܽ����ˣ���ȥ�����ǰ�\n";
	}
	if (objectp(obj)) {
	    obj->move(player);
	}else {
	    obj = new(CANPIAN);
   	}
	message_vision("$N��$nһ�������񹦲�ƪ��\n", this_object(), player);
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
	command("chat ������" + obj->name() + "����" );
       command("chat ƶ�������ǰ�������������ˣ���Ȼ����ɱ���ң������⸱�Ϲ�ͷ��Ҫ��ֻ����" + RANK_D->query_respect(obj) + "�������ˡ�");
	return 1;
}


#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>

void die()
{
	object corpse, killer;
	int i;
	string str, mykiller;

	if( !living(this_object()) ) revive(1);
        command("chat ƶ���ݺὭ�������꣬����ʼ���������죬�������ˣ�");
	// Clear all the conditions by death.
	this_object()->clear_condition();

	if( objectp(killer = query_temp("last_damage_from")) ) {
		set_temp("my_killer", killer->query("id"));
		COMBAT_D->killer_reward(killer, this_object());
                command("chat " + killer->name() + "������أ��������Ž��ޱ�");
        	command("chat* " + "������ָ��" + killer->name()
	 + "��̾������" +  killer->name() + "�ǹ����������ֵ�һ����ʦ����\n");
	} else 
		killer = this_object();
	corpse = new("/clone/misc/corpse");
	corpse->set("my_killer", killer->query("id"));
	corpse->set("victim_name", "������");
	corpse->set("combat_exp", 2000000);
	corpse->set("name", "�������ʬ��");
	corpse->set("gender", "����");
	corpse->set("long",
                "�������䵱�ɿ�ɽ���桢�������ֵ�̩ɽ�������������ˡ�\n"
                "��һ���ۻ�Ļ�ɫ���ۣ����ޱ߷���\n"
                "��ĸߴ��������꣬������⣬��ü�԰ס�\n\n"
		"Ȼ�������Ѿ����ˣ�ֻʣ��һ��ʬ�徲�����������\n" );

	corpse->move(environment(this_object()));

//	COMBAT_D->announce(this_object(), "dead");

//	if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
//		corpse->move(environment());

//	this_object()->remove_all_killer();
//	all_inventory(environment())->remove_killer(this_object());

//	this_object()->dismiss_team();
	destruct(this_object());
}

#include "/kungfu/class/wudang/auto_perform.h"
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
