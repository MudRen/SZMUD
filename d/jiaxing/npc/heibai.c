// Code of ShenZhou
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("�ڰ���",({ "heibai zi","zi","heibai" }) );
        set("gender", "����");
        set("age", 55);
	set("long",
		"��üĿ���㣬ͷ�����ڶ�Ƥ�����ף�"
		"�ƺ�һ�߽�ʬģ����\n");
       // set("nickname","");
        set("title","÷ׯ��ׯ��");
        set("combat_exp", 85000);
        set("shen_type", 0);
        set("attitude", "friendly");
        set_skill("unarmed", 85);
	set_skill("force",85);
        set_skill("parry", 85);
        set_skill("dodge", 85);
	set_skill("hammer",85);

	set("max_neili",450);
	set("neili",450);
	set("jiali",45);


	set("mz/toy","����");
	set("mz/set","heibai");
	set("mz/need","tubiweng");
	set("mz/needname","��ׯ��");
        setup();
        carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/qiping")->wield();
}

void fightwin(object who)
{
}
#include "mzfight.h"



