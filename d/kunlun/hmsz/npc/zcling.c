// zcling.c (kunlun)

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�쳤��", ({ "zhu changling", "zhu" }));
	set("title", "ׯ��");
	set("gender", "����");
	set("long", "�����Ǻ�÷ɽׯׯ��,��˵���������ĺ���.\n");
	set("age", 50);	
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 29);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	
	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 0);
	set("combat_exp", 600000);

	set_skill("force", 140);
	set_skill("dodge", 140);
	set_skill("parry", 140);
        set_skill("finger", 140);
        set_skill("yiyang-zhi",130);
	set_skill("kurong-changong", 160);

	map_skill("force", "kurong-changong");
	map_skill("finger", "yiyang-zhi");
	map_skill("parry", "yiyang-zhi");
          prepare_skill("finger", "yiyang-zhi");

	setup();
        carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 10);
}
