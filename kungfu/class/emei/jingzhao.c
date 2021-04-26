// Code of ShenZhou
// Npc: /kungfu/class/emei/jingzhao.c ����ʦ̫
// Date: xbc 99/06/22
// Modified by xQin 8/00
inherit NPC;
inherit F_MASTER;

string ask_for_join();
string ask_for_huansu();
int auto_perform();

void create()
{
        set_name("����ʦ̫", ({
                "jingzhao shitai",
                "jingzhao",
                "shitai",
	}));
	set("long",
		"����һλ���������ʦ̫���ڸ��������С�\n"
		"�������ʦ̫�İ˴��ֱ�����֮�壬���ó�������ָ����\n"
	);

	set("gender", "Ů��");
	set("attitude", "friendly");
	set("class", "bonze");

        set("inquiry",([
                "����"  : (: ask_for_join :),
                "����" : (:ask_for_huansu:),
        ]));

	set("age", 34);
	set("shen_type", 1);

	set("str", 26);
	set("int", 20);
	set("con", 20);
	set("dex", 25);

	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1100);
	set("max_neili", 1100);
	set("jiali", 50);
	set("combat_exp", 500000);
	set("score", 1000);

        set_skill("force", 80);
        set_skill("linji-zhuang", 80);
        set_skill("strike", 90);
        set_skill("jinding-zhang", 90);
        set_skill("finger", 90);
        set_skill("tiangang-zhi", 90);
        set_skill("sword", 90);
        set_skill("emei-jian", 90);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("zhutian-bu", 80);
        set_skill("persuading", 80);
        set_skill("mahayana", 80);
        set_skill("literate", 90);

        map_skill("force", "linji-zhuang");
        map_skill("finger", "tiangang-zhi");
        map_skill("strike", "jinding-zhang");
        map_skill("sword", "emei-jian");
        map_skill("parry", "jinding-zhang");
        map_skill("dodge", "zhutian-bu");

        prepare_skill("finger", "tiangang-zhi");
        prepare_skill("strike", "jinding-zhang");

	create_family("������", 4, "����");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

	setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/emei/npc/obj/nun-cloth")->wear();
        carry_object("/d/emei/npc/obj/emei-shoes")->wear();
}

void init()
{
        object ob;

	::init();
        add_action("do_kneel", "kneel");

        if (interactive(ob=this_player()) 
	&& ob->query("family/master_id") == "jingzhao shitai"
	&& ob->query("shen") < -100) 
	{
       	 	message_vision(
                "$n����$N˵��������ô����������£�\n",
                ob, this_object() );
		command("say �Ҷ��������������������ɣ�" +
                        "�Ե���Ҫ���ϡ��Ҳ����������㣬��ȥ�ɡ�\n");
                command("expell " + ob->query("id"));
                return;
        }

        if (interactive(ob=this_player()) 
	&& ob->query("family/master_id") == "jingzhao shitai"
        && ob->query("class") !=  "bonze" )                 
	{
		message_vision(
                        "$n����$N˵�������Ȼ�����ף�����ȥ�����׼�ʦ��ѧ�հɡ�\n", ob, this_object());
                ob->delete("family/master_name");
                ob->delete("family/master_id");
                return;
        }
}

#include "/kungfu/class/emei/jing2.h"
#include "/kungfu/class/emei/auto_perform.h"
#include "/kungfu/class/emei/nun.h"

