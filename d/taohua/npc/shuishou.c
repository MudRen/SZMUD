// Code of ShenZhou
// shuishou.c 
inherit NPC;

void create()
{
	set_name("�ư�ˮ��", ({ "shui shou","shou" }) );
	set("gender", "����");
	set("age", 35);
        set("long",
		"���������ƣ������ӹ���Ϊ��ʵ�����ϱ����紵���ֺ��ֺڡ���\n");
	set("combat_exp", 10000);
	set("shen_type", 0);
	set("attitude", "friendly");

	set("apply/attack",  30);
	set("apply/defense", 30);

	set("jingli",100);

	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);

        setup();
	carry_object("/d/shenlong/obj/cloth")->wear();
	add_money("coin", 50);
}
