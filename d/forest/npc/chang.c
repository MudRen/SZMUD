// Code of ShenZhou
// Jay 7/11/96

inherit NPC;

void create()
{
	set_name("������", ({ "chang changfeng","chang" }) );
	set("gender", "����");
	set("age", 35);
	set("long",
		"���ָ��ַʣ�������һ���������ڵ��¡�\n");
	set("nickname","˫�ƿ���");
	set("title","̫������");
	set("combat_exp", 15000);
        set("shen_type", -1);
	set("attitude", "aggressive");

	set("apply/attack",  28);
	set("apply/defense", 28);

	set_skill("hammer", 44);
	set_skill("unarmed", 44);
	set_skill("parry", 30);
	set_skill("dodge", 30);

	setup();
        carry_object(__DIR__"obj/mubei")->wield();
        carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 1);
}
