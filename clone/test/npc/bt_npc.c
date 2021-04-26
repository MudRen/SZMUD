// Code of ShenZhou
// npc: /d/xingxiu/npc/ke.c
// Jay 3/27/96
// sdong 3/10/2000

#include "ansi.h"
inherit NPC;
int unarmed();
int staff();

int auto_perform();

void create()
{
	set_name("ŷ����", ({ "ouyang feng", "ouyang", "feng" }));
	set("long", "�����θߴ󣬸߱���Ŀ������ѩ�׶��룬����������\n"
		"������ʹ�����ųơ���������\n");
	set("nickname","����");
	set("title", "����ɽׯ��");
	set("gender", "����");
	set("age", 65);

	set("lingshe_count",3);
	set_skill("hand", 400);
	set_skill("cuff", 400);
	set_skill("lingshe-quan", 400);
	set_skill("shentuo-zhang", 400);
	set_skill("strike", 400);
	set_skill("dodge", 400);
	set_skill("chanchubu", 400);
	set_skill("parry", 400);
	set_skill("force", 400);
	set_skill("hamagong", 400);
	set_skill("lingshe-zhang",400);
	set_skill("staff",400);
	set_skill("poison",400);
	set_skill("training",400);
	map_skill("cuff","lingshe-quan");
	map_skill("strike","hamagong");
	map_skill("staff","lingshe-zhang");
	map_skill("dodge","chanchubu");
	map_skill("parry", "lingshe-zhang");
	map_skill("staff","lingshe-zhang");
	map_skill("force","hamagong");
//	prepare_skill("cuff","lingshe-quan");
	prepare_skill("strike","hamagong");

	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);

	set("neili", 8000);
	set("max_neili", 8000);
    set("eff_jingli", 5000);
    set("max_jingli", 5000);
	set("jiali", 200);
	set("combat_exp", 6400000);

		  set("attitude", "peaceful");
		  set("shen_type", -1);

		  create_family("����ɽ", 1 , "ׯ��");
		  set("chat_chance_combat", 50);
		  set("chat_msg_combat", ({
			 (: auto_perform :),
		  }) );

	set("inquiry", ([
		"ŷ����" : "������ֶ��",
        "unarmed"   : (: unarmed :),
        "staff"    : (: staff :),
	]));

	setup();
	carry_object("/clone/weapon/shezhang");
	carry_object("/d/city/obj/cloth")->wear();
}


void init()
{
	object ob;
}

int unarmed()
{
	command("halt");
	command("unwield shezhang");
	map_skill("parry", "hamagong");
	command("yun powerup");
	command("yun reverse");
	set("jiajin", 150);
	set("jiali", 200);
	return 1;
}

int staff()
{
	command("halt");
	command("wield shezhang");
	command("yun powerup");
	command("yun reverse");
	set("jiajin", 0);
	set("jiali", 0);
	map_skill("parry", "lingshe-zhang");
	return 1;
}


#include "/kungfu/class/baituo/auto_perform.h"

