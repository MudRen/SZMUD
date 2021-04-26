// Code of ShenZhou
// Npc: /kungfu/class/emei/jingfeng.c ����ʦ̫
// Date: xbc 96/09/22

inherit NPC;

string ask_me_1();
string ask_me_weapon(string);
string ask_for_join();
string ask_for_huansu();
int auto_perform();

void create()
{
        set_name("����ʦ̫", ({
                "jingfeng shitai",
                "jingfeng",
                "shitai",
	}));
	set("long",
		"�����ڻ��������е�ʦ̫��ƽʱ�ڴ���䷢�Ŷ����ɵ�����������ҩƷ��\n"
	);

	set("gender", "Ů��");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 40);
	set("shen_type", 1);

	set("str", 26);
	set("int", 20);
	set("con", 20);
	set("dex", 25);

	set("max_qi", 600);
	set("max_jing", 600);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 50);
	set("combat_exp", 100000);
	set("score", 1000);

        set_skill("force", 70);
        set_skill("linji-zhuang", 70);
        set_skill("finger", 70);
        set_skill("tiangang-zhi", 70);
        set_skill("strike", 70);
        set_skill("jinding-zhang", 60);
        set_skill("sword", 70);
        set_skill("emei-jian", 80);
        set_skill("parry", 70);
        set_skill("dodge", 70);
        set_skill("zhutian-bu", 70);
        set_skill("persuading", 60);
        set_skill("mahayana", 50);
        set_skill("literate", 70);

        map_skill("force", "linji-zhuang");
        map_skill("strike", "jinding-zhang");
        map_skill("finger", "tiangang-zhi");
        map_skill("sword", "emei-jian");
        map_skill("parry", "emei-jian");
        map_skill("dodge", "zhutian-bu");

	prepare_skill("strike", "jinding-zhang");
	prepare_skill("finger", "tiangang-zhi");
 
	create_family("������", 4, "����");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

	set_weight(1000000); 

        set("inquiry", ([
                "���������" :    (: ask_me_1 :),
                "��Ҷ��" :    (: ask_me_weapon, "liuyedao" :),
                "��" :    (: ask_me_weapon, "ruanjian" :),
                "Ƥ����" :    (: ask_me_weapon, "yaodai" :),
                "����"  : (: ask_for_join :),
                "����" : (:ask_for_huansu:),
        ]));

	set("gao_count", 10);
	set("liuyedao_count", 4);
	set("ruanjian_count", 4);
	set("yaodai_count", 8);

	setup();

	carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/emei/npc/obj/nun-cloth")->wear();
        carry_object("/d/emei/npc/obj/emei-shoes")->wear();
}

string ask_me_weapon(string name)
{
        mapping fam, log; 
        object ob, who = this_player();
	object room = load_object("/d/emei/chuwu");

        if (!(fam = who->query("family")) || fam["family_name"] != "������")
                return RANK_D->query_respect(who) + 
                "�뱾��������������֪�˻��Ӻ�̸��";

        if (  ob=present(name, who) )
                return RANK_D->query_respect(who) + 
                "���������ϲ�����" + ob->query("name") + "����������Ҫ�ˣ� ����̰�����У�";

	log = room->query_temp(name);
	if ( mapp(log) && log[who->query("id")] ) 
		return "�Ҳ��Ǹո���������������Ҫ�ˣ�����̰�����У�";

        if ( mapp(log) && sizeof(log) > query(name+"_count"))
                return "��Ǹ�������ò���ʱ���Ѿ������ˡ�";

        if (name=="yaodai")
	ob = new("/d/emei/obj/yaodai");
	else ob = new("/clone/weapon/" + name);
        ob->move(who);

	room->set_temp(name+"/"+who->query("id"),1);

        message_vision("����ʦ̫��$Nһ" + ob->query("unit") + ob->query("name") + "��\n", who);

        return "��ȥ�ɡ�����Ҫ��ס����������ֻ�ɷ������䣬����ƾ�˷������ˡ�";
}


string ask_me_1()
{
        mapping fam, log; 
        object ob, who = this_player();
	object room = load_object("/d/emei/chuwu");

        if (!(fam = who->query("family")) || fam["family_name"] != "������")
                return RANK_D->query_respect(who) + 
                "�뱾��������������֪�˻��Ӻ�̸��";

        if ( (int)who->query_condition("bonze_drug" ) > 0 )
                return RANK_D->query_respect(who) + 
                "���ǲ��Ǹշ��ҩ����������Ҫ�ˣ� ��ҩ����к����棬����ʱ�������ɡ�";

        if (  present("tian xiang", who) )
                return RANK_D->query_respect(who) + 
                "���������ϲ�����һ���������������������Ҫ�ˣ� ����̰�����У�";

	log = room->query_temp("tianxiang");

        if ( mapp(log) && log[who->query("id")])
                return "�Ҳ��Ǹո�����һ���������������������Ҫ�ˣ� ����̰�����У�";

        if ( mapp(log) && sizeof(log) > query("gao_count")) return "�Բ�������������Ѿ�������";

        ob = new(DRUG_D("tianxiang"));
        ob->move(who);

        room->set_temp("tianxiang/"+who->query("id"),1);

        message_vision("$N���һ����������ࡣ\n",this_player());
        return "�ðɣ���ס������Σ����ͷ��Ҫ����ʹ�ô�ҩ��";

}

void init()
{
	::init();
        add_action("do_kneel", "kneel");

}

#include "/kungfu/class/emei/nun.h"
#include "/kungfu/class/emei/jing1.h"
#include "/kungfu/class/emei/auto_perform.h"
