// Code of ShenZhou
// Npc: /kungfu/class/emei/jinghe.c ����ʦ̫
// Date: xbc 96/09/22
// Modified by xQin 8/00

inherit NPC;

string ask_for_join();
string ask_for_huansu();
int auto_perform();

void my_move();

void create()
{
        set_name("����ʦ̫", ({
                "jinghe shitai",
                "jinghe",
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
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 40);
	set("combat_exp", 88000);
	set("score", 1000);

        set_skill("force", 50);
        set_skill("linji-zhuang", 50);
        set_skill("strike", 65);
        set_skill("jinding-zhang", 65);
        set_skill("finger", 65);
        set_skill("tiangang-zhi", 65);
        set_skill("parry", 65);
        set_skill("dodge", 60);
        set_skill("zhutian-bu", 60);
        set_skill("persuading", 60);
        set_skill("literate", 60);
        set_skill("mahayana", 50);

        map_skill("force", "linji-zhuang");
        map_skill("finger", "tiangang-zhi");
        map_skill("strike", "jinding-zhang");
        map_skill("parry", "jinding-zhang");
        map_skill("dodge", "zhutian-bu");

	prepare_skill("finger", "tiangang-zhi");

	create_family("������", 4, "����");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

//        set("chat_chance", 2);
        set("chat_msg", ({
                "����ʦ̫����������������Ը�У����������ҵ���Ա�һ�д�����һ���ƣ������ڵ¡�\n",
        	(: this_object(), "my_move" :),
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

void my_move()
{
        int value;

        value = random(10);

        if (value > 6)
        {
		command("say ���������ߣ����Ǳ�һ�д��������������塣\n");
                command("west");
        }
        else if (value < 4)
        {
                command("say ����ʦ̫��������֮ѧ�����У���֮������Ī���󣬹ʺ���\n");
                command("east");
        }
}

#include "/kungfu/class/emei/nun.h"
#include "/kungfu/class/emei/jing1.h"
#include "/kungfu/class/emei/auto_perform.h"
