// Code of ShenZhou
// Npc: /kungfu/class/shaolin/cheng-xin2.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;
int auto_perform();

void create()
{
	set_name("����", ({
		"chengxin luohan",
		"chengxin",
		"zhuangyan",
		"luohan",
	}));
	set("long",
		"����һλ�뷢���׵���ɮ����һϮ��ߺڲ����ġ�������ݸߣ�\n"
		"̫��Ѩ�߸߹����ƺ��������书��\n"
	);

	set("nickname", "ׯ���޺�");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 60);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	set("combat_exp", 500000);
	set("score", 5000);

	set_skill("force", 100);
	set_skill("hunyuan-yiqi", 100);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);
        set_skill("cuff", 80);
        set_skill("luohan-quan", 80);
        set_skill("club", 80);
        set_skill("weituo-gun", 80);
        set_skill("strike", 110);
        set_skill("sanhua-zhang", 110);
        set_skill("hand", 100);
        set_skill("qianye-shou", 100);
	set_skill("blade", 120);
	set_skill("xiuluo-dao", 120);
	set_skill("parry", 100);
	set_skill("buddhism", 100);
	set_skill("literate", 100);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "luohan-quan");
        map_skill("club", "weituo-gun");
        map_skill("strike", "sanhua-zhang");
        map_skill("hand", "qianye-shou");
	map_skill("blade", "xiuluo-dao");
	map_skill("parry", "xiuluo-dao");

	prepare_skill("strike", "sanhua-zhang");

	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

	create_family("������", 37, "����");

	setup();

        carry_object("/d/shaolin/obj/jiedao")->wield();
        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}
int auto_perform()
{
        object me = this_object();
        object weapon;

        if (!present("jie dao", me)){
        weapon = new("/d/shaolin/obj/jiedao");
        weapon->move(me);
        message_vision("$NͻȻת�������ó�һ�ѽ䵶��\n", me);
        command("wield jie dao");
        return 1;
        }
}

#include "/kungfu/class/shaolin/cheng.h"

