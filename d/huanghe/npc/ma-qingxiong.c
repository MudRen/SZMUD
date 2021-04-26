// Code of ShenZhou
// ma.c ������

inherit NPC;

void create()
{
	set_name("������", ({ "ma qingxiong", "ma" }));
	set("nickname", "���Ǳ�");
	set("long", 
"�������ǻƺ��Ĺ���������ǹ�������ɳͨ��������ӣ����ڱ޷���\n");
	set("title", "�ƺ��Ĺ�����");
	set("gender", "����");
	set("age", 32);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 21);
	set("int", 20);
	set("con", 21);
	set("dex", 19);
	
	set("max_qi", 400);
	set("max_jing", 300);
	set("neili", 200);
	set("max_neili", 200);
	set("jiali", 20);
	set("combat_exp", 9800);

        set_temp("apply/attack",  30);
        set_temp("apply/defense", 30);

	set_skill("force", 35);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("whip", 45);
	set_skill("unarmed", 35);

	setup();
	carry_object("/clone/weapon/changbian")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}
