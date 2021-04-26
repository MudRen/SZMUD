// Code of ShenZhou
// snbz.c

inherit NPC;

void create()
{
	int i;

	set_name("��ũ�����", ({ "shennong dizi","shennong","dizi" }) );
	set("gender", "����");
	i = random(8);
	set("age", 35+i);
	if (i>4) 
	set("long",
		"����һ����ũ��İ��ڣ������£�����ҩ�ң��ֳ�һ���̵���\n");
	else
        set("long",
                "����һ����ũ��İ��ڣ������£�����ҩ�ң��ֳ�һ��ҩ����\n");
	set("combat_exp", 5000+i*4000);
	set("shen_type", 0);
	set("attitude", "heroism");

	set_skill("blade", 30+i*5);
	set_skill("hammer",30+i*5);
	set_skill("unarmed", 30+i*5);
	set_skill("parry", 30+i*5);
	set_skill("dodge", 30+i*5);

	setup();

	if (i>4)
	carry_object("/d/dali/obj/duandao")->wield();
	else
	carry_object("clone/weapon/yaochu")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 5+2*i);
}
