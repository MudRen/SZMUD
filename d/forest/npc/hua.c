// Code of ShenZhou
// Jay 7/11/96

inherit NPC;

void create()
{
	set_name("����Ӱ", ({ "hua jianying","hua" }) );
	set("gender", "����");
	set("age", 30);
	set("long",
		"���е���ģ��׾���Ƥ��������һ����������ͻ��һ�磬һ����ͷ�����˰�磬������һλ��òӢ�������\n");
	set("nickname","���Ǹ���");
	set("title","̫������");
	set("combat_exp", 14000);
        set("shen_type", -1);
	set("attitude", "aggressive");

	set("apply/attack",  23);
	set("apply/defense", 23);

	set_skill("hammer", 35);
	set_skill("unarmed", 40);
	set_skill("parry", 30);
	set_skill("dodge", 40);

	setup();
        carry_object("/d/xingxiu/npc/obj/liuxing")->wield();
        carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 1);
}
