// Code of ShenZhou
// /kungfu/class/emei/zhou.c ������
// xbc: 97/02/01
// 18th-Aug-2000: modified by yasuko
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_jiuyin();
string ask_whip();
string ask_whip2();

void create()
{
	set_name("������", ({ "zhou zhiruo", "zhou"}));
	set("long", 
		"����һ��������������Ů�ӣ���������һ���̽���\n"
		"ֻ�����������ţ���ɫ������\n");
	set("gender", "Ů��");
	set("age", 26);
	set("attitude", "peaceful");

	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	set("kar", 15);
	set("per", 28);
	
	set("max_qi", 4000);
	set("max_jing", 4000);
	set("neili", 4000);
	set("jiali", 100);
	set("max_neili", 4000);

	set("combat_exp", 3600000);
	set("score", 10000);

	set_skill("literate", 101);
	set_skill("mahayana", 300);
	set_skill("force", 300);
	set_skill("linji-zhuang", 300);
	set_skill("claw", 380);
	set_skill("jiuyin-zhao", 380);
	set_skill("strike", 380);
	set_skill("cuixin-zhang", 380);
	set_skill("jinding-zhang", 380);
	set_skill("finger", 380);
	set_skill("tiangang-zhi", 380);
	set_skill("whip", 380);
	set_skill("feiyu-bian", 380);
	set_skill("sword", 380);
	set_skill("emei-jian", 380);
	set_skill("parry", 380);
	set_skill("dodge", 380);
	set_skill("zhutian-bu", 380);
	set_skill("throwing", 380);
	set_skill("persuading", 320);

	map_skill("claw", "jiuyin-zhao");
	map_skill("force", "linji-zhuang");
	map_skill("whip", "feiyu-bian");
	map_skill("sword", "emei-jian");
	map_skill("blade", "yanxing-dao");
	map_skill("parry", "emei-jian");
	map_skill("dodge", "zhutian-bu");
	map_skill("finger", "tiangang-zhi");
	map_skill("strike", "cuixin-zhang");

	prepare_skill("claw", "jiuyin-zhao");
	prepare_skill("strike", "cuixin-zhang");

	create_family("������", 4, "����");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function("longhe") :),
		(: exert_function("recover") :),
		(: perform_action("sword.mie") :),
		(: perform_action("whip.heji") :),
		(: perform_action("whip.chanrao") :),
		(: exert_function("fengyun") :),

	}) );

	set("special_master", 1);
	set("inquiry", ([
	    "���ʦ̫" : "���Ǳ��������ˣ��ڻ��������С�\n",
          "�����澭" : (: ask_whip :),
            "�����澭�ܳ���" : (: ask_jiuyin :),
            "����" : (: ask_whip2 :),
	]));
	setup();
	carry_object("/d/emei/npc/obj/hui-cloth")->wear();
	carry_object("/d/emei/npc/obj/emei-shoes")->wear();
	carry_object("/clone/weapon/changbian")->wield();
	carry_object("/clone/weapon/duanjian");

}

#include "/kungfu/class/emei/zhou.h"
