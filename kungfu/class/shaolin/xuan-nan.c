// Code of ShenZhou
// Npc: /kungfu/class/shaolin/xuan-nan.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;
int auto_perform();
string ask_me();

void create()
{
	set_name("���Ѵ�ʦ", ({
		"xuannan dashi",
		"xuannan",
		"dashi",
	}));
	set("long",
		"����һλ�����ü����ɮ����һϮ��˿�ػ����ġ�����ļ��ݣ�\n"
		"���ָ���צһ������˫Ŀ΢�գ�һ��û����ɵ�ģ����\n"
	);

	set("nickname", "����������");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 150);
	set("combat_exp", 1000000);
	set("score", 500000);

	set_skill("force", 150);
	set_skill("hunyuan-yiqi", 150);
	set_skill("dodge", 150);
	set_skill("shaolin-shenfa", 150);
        set_skill("cuff", 120);
        set_skill("luohan-quan", 120);
        set_skill("staff", 150);
        set_skill("pudu-zhang", 120);
        set_skill("wuchang-zhang", 150);
        set_skill("strike", 120);
        set_skill("sanhua-zhang", 120);
        set_skill("hand", 120);
        set_skill("qianye-shou", 120);
	set_skill("parry", 150);
	set_skill("buddhism", 150);
	set_skill("literate", 101);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
        map_skill("strike", "sanhua-zhang");
        map_skill("hand", "qianye-shou");
	map_skill("staff", "wuchang-zhang");
	map_skill("parry", "wuchang-zhang");

	create_family("������", 36, "����");

	set("inquiry", ([
		"ʮ���޺���"       : (: ask_me :),
		"�޺�����"	   : (: ask_me :),
                "zhen" : (: ask_me :),
	]));

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        (: auto_perform :), }));

	setup();

        carry_object("/d/shaolin/obj/chanzhang")->wield();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}


#include "/kungfu/class/shaolin/xuan-nan.h"
#include "/kungfu/class/shaolin/auto_perform.h"
