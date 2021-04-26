// Code of ShenZhou
// Npc: /kungfu/class/shaolin/qing-xiao.c
// Date: YZC 96/01/19

inherit NPC;


void create()
{
	set_name("��������", ({
		"qingxiao biqiu",
		"qingxiao",
		"biqiu",
	}));
	set("long",
		"����һλ���ǿ����׳��ɮ�ˣ�����û���������ȫ���ƺ��̺�\n"
		"�������������һϮ�ײ��ڱ����ģ��ƺ������ա�\n"
	);

	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 30);
	set("shen_type", 1);
	set("str", 23);
	set("int", 21);
	set("con", 18);
	set("dex", 22);
	set("max_qi", 350);
	set("max_jing", 200);
	set("neili", 350);
	set("max_neili", 350);
	set("jiali", 30);
	set("combat_exp", 25000);
	set("score", 100);

	set_skill("force", 40);
	set_skill("hunyuan-yiqi", 30);
	set_skill("dodge", 40);
	set_skill("shaolin-shenfa", 40);
	set_skill("cuff", 40);
	set_skill("luohan-quan", 40);
	set_skill("club", 50);
	set_skill("weituo-gun", 50);
	set_skill("parry", 40);
	set_skill("buddhism", 30);
	set_skill("literate", 40);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("club", "weituo-gun");
	map_skill("parry", "weituo-gun");

	prepare_skill("cuff", "luohan-quan");

	create_family("������", 40, "����");

	setup();

        carry_object("/d/shaolin/obj/qing-cloth")->wear();
        carry_object("/clone/weapon/qimeigun")->wield();
}


#include "/kungfu/class/shaolin/qing.h"

