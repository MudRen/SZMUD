// Code of ShenZhou
// Npc: /kungfu/class/emei/jingdao.c ����ʦ̫
// Date: xbc 96/09/22

inherit NPC;

string ask_for_join();
string ask_for_huansu();
int auto_perform();

void create()
{
        set_name("����ʦ̫", ({
                "jingdao shitai",
                "jingdao",
                "shitai",
	}));
	set("long",
		"�����ڻ��������е�ʦ̫��ƽʱ�ڲؾ�����������ɵĲ��顣\n"
	);

	set("gender", "Ů��");
	set("attitude", "friendly");
	set("class", "bonze");

        set("inquiry",([
                "����"  : (: ask_for_join :),
                "����" : (:ask_for_huansu:),
        ]));

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

        set_skill("force", 60);
        set_skill("linji-zhuang", 60);
        set_skill("strike", 70);
        set_skill("jinding-zhang", 70);
        set_skill("finger", 70);
        set_skill("tiangang-zhi", 70);
        set_skill("parry", 70);
        set_skill("dodge", 80);
        set_skill("zhutian-bu", 80);
        set_skill("persuading", 60);
        set_skill("mahayana", 80);
        set_skill("literate", 80);

        map_skill("force", "linji-zhuang");
        map_skill("strike", "jinding-zhang");
        map_skill("finger", "tiangang-zhi");
        map_skill("parry", "jinding-zhang");
        map_skill("dodge", "zhutian-bu");

	prepare_skill("strike", "jinding-zhang");
	prepare_skill("finger", "tiangang-zhi");

	create_family("������", 4, "����");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

	setup();

        carry_object("/d/emei/npc/obj/nun-cloth")->wear();
        carry_object("/d/emei/npc/obj/emei-shoes")->wear();
}
void init()
{
	::init();
        add_action("do_kneel", "kneel");

}

#include "/kungfu/class/emei/jing1.h"
#include "/kungfu/class/emei/nun.h"
#include "/kungfu/class/emei/auto_perform.h"
