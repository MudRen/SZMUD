// Code of ShenZhou
// Jay 7/11/96

inherit NPC;

void create()
{
	set_name("��ң��", ({ "xiaoyao zi","xiaoyao","zi" }) );
	set("gender", "����");
	set("age", 45);
	set("long",
		"���Ǹ�����ģ���������ˣ��������ڣ�ҧ��һ�����̹ܣ�˫Ŀ�����Ʊգ����������������\n");
	set("nickname","��ϼ����");
	set("title","̫������");
	set("combat_exp", 20000);
        set("shen_type", -1);
	set("attitude", "aggressive");

	set("apply/attack",  30);
	set("apply/defense", 30);

	set("chat_chance", 5);
	set("chat_msg", ({
		"��ң�����ְ��أ�����������\n",
	}) );

	set_skill("club", 50);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);

	setup();
        carry_object(__DIR__"obj/yanguan")->wield();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/village/npc/obj/shoes")->wear();
	carry_object(__DIR__"obj/jinchai");
	add_money("silver", 3);
}
