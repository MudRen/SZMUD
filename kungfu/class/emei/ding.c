// Code of ShenZhou
// /emei/ding.c ������
// xQin: 99/08/14

inherit NPC;
inherit F_MASTER;

int auto_perform();
void create()
{
        set_name("������", ({ "ding minjun", "ding", "minjun" }));
        set("long", 
                "�������ʦ̫�İ˴��׼ҵ���֮һ��\n"
                "��������ģ���ò��������ϧȧ��΢�ߣ����ӣ��С�ڣ�\n"
                "ƤɫҲ������𪡣\n");
        set("gender", "Ů��");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("str", 25);
        set("int", 20);
        set("con", 20);
        set("dex", 25);
        
        set("max_qi", 1100);
        set("max_jing", 1100);
        set("neili", 1800);
        set("jiali", 60);
        set("max_neili", 1800);

        set("combat_exp", 300000);
        
	set_skill("force", 125);
  	set_skill("linji-zhuang", 125);
  	set_skill("throwing", 125);
  	set_skill("strike", 125);
  	set_skill("jinding-zhang", 125);
  	set_skill("hand", 125);
  	set_skill("jiushou-jiushi", 125);
  	set_skill("sword", 125);
  	set_skill("emei-jian", 125);
  	set_skill("blade", 125);
  	set_skill("yanxing-dao", 125);
  	set_skill("parry", 125);
  	set_skill("dodge", 125);
  	set_skill("zhutian-bu", 125);
//	set_skill("literate", 80);
  	set_skill("persuading", 100);
  	set_skill("mahayana", 100);

  	map_skill("force", "linji-zhuang");
  	map_skill("strike", "jinding-zhang");
  	map_skill("hand", "jieshou-jiushi");
  	map_skill("sword", "emei-jian");
  	map_skill("blade", "yanxing-dao");
  	map_skill("parry", "emei-jian");
  	map_skill("dodge", "zhutian-bu");
	
  	prepare_skill("strike", "jinding-zhang");
  	prepare_skill("hand", "jieshou-jiushi");

        create_family("������", 4, "����");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

        set("inquiry", ([
                "����" : "��ȥ��ɽ�����������Ҿ��ֱ�ʦ��ɡ������ڸ����֡�ǧ���֡�\n�����֡������ֺ����������С�\n",
            "���ʦ̫" : "���Ǳ��������ˣ��ڻ��������С�\n",
        ]));

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/emei/npc/obj/hui-cloth")->wear();
        carry_object("/d/emei/npc/obj/emei-shoes")->wear();

}

#include "/kungfu/class/emei/sujia.h"
#include "/kungfu/class/emei/auto_perform.h"
