// Code of ShenZhou
// shu-sheng.c
// Jay 6/1/97

inherit NPC;

void create()
{
	set_name("�ų���", ({ "zhang chaotang", "zhang", "chaotang" }) );
	set("gender", "����" );
	set("age", 22);
	set("int", 28);
	set("long",
		"���Ǹ�����ʫ���������������һֱ���������Ļ��������Ͽ���\n");

        set("inquiry", ([
		"�����" : "�������ڵ�������\n",
	]));
	set("attitude", "peaceful");
        set("shen_type", 1);
	set("combat_exp", 40);
	set_skill("literate", 40);
	setup();
	carry_object("/clone/armor/cloth")->wear();
}

