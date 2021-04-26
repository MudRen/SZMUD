// Code of ShenZhou
//yapu.c

#include <ansi.h>

inherit NPC;

void create()
{
	int skill;
	skill = random(60);
	set_name("����", ({ "ya pu","pu", "servant"}) );
	set("gender", "����");
	set("age", 30);
	set("long",
"���Ǹ��һ����ϵ�Ӷ�ͣ��Ǹ��������壬�����֮ͽ��
����ҩʦ��ס�󣬸�ȥ��ͷ���������䣬�䵱����.
���������ƣ�����ľȻ��\n");
	set("combat_exp", 10000);
        set("shen_type", -1);
	set("attitude", "peaceful");
	set("max_qi", 500);
	set("max_jing", 500);
	set("max_neili", 500);
	set("neili", 500);
	set_temp("apply/armor", 50);	

	set("str", 28);
	set("con", 28);
	set("dex", 28);

	set_skill("cuff", 30+skill);
	set_skill("parry", 30+skill);
	set_skill("force", 30+skill);
	set_skill("dodge", 30+skill);

	setup();

        carry_object("/clone/misc/cloth")->wear();

}

