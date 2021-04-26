// Code of ShenZhou
// Npc: /kungfu/class/emei/jingxin.c ����ʦ̫
// Date: xbc 96/09/22
// Modified by xQin 8/00
inherit NPC;

string ask_for_join();
string ask_for_huansu();
int auto_perform();

void create()
{
        set_name("����ʦ̫", ({
                "jingxin shitai",
                "jingxin",
                "shitai",
	}));
	set("long",
		"�����ڻ��������е�ʦ̫�������ڲ������������ҵ����������⡣\n"
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

        set("startroom","/d/emei/hz_east");

	set("str", 26);
	set("int", 20);
	set("con", 20);
	set("dex", 25);

	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 20);
	set("combat_exp", 90000);
	set("score", 1000);

        set_skill("force", 50);
        set_skill("linji-zhuang", 50);
        set_skill("finger", 70);
        set_skill("tiangang-zhi", 70);
        set_skill("strike", 70);
        set_skill("jinding-zhang", 70);
        set_skill("literate", 70);
        set_skill("parry", 60);
        set_skill("dodge", 60);
        set_skill("zhutian-bu", 60);
        set_skill("persuading", 60);
        set_skill("mahayana", 50);

        map_skill("force", "linji-zhuang");
        map_skill("strike", "jinding-zhang");
        map_skill("finger", "tiangang-zhi");
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

        set("chat_chance", 1);
        set("chat_msg", ({
                "����ʦ̫�������������ߣ����Ǳ�һ�д��������������塣\n",
                "����ʦ̫����������������Ը�У����������ҵ���Ա�һ�д�����һ���ƣ������ڵ¡�\n",
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
#include "/kungfu/class/emei/auto_perform.h"
#include "/kungfu/class/emei/nun.h"

