// Code of ShenZhou
// laoshu.c ����

inherit NPC;

void create()
{
	set_name("����", ({ "lao shu", "shu", "mouse" }) );
	set("race", "Ұ��");
	set("age", 2);
	set("long", "һֻ�������С����\n");
	set("attitude", "peaceful");
	
//	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
//	set("verbs", ({ "bite", "claw" }) );

	set_weight(300);

	set("combat_exp", 100);
	//set("shen_type", -1);
	set("env/wimpy", 70);

	set_temp("apply/attack", 5);
//	set_temp("apply/damage", 20);
	set_temp("apply/dodge", 20);
	set_temp("apply/armor", 1);

	setup();
}

void die()
{
        object ob;
        message_vision("$N��ҵĺ��˼��������ˡ�\n", this_object());
        ob = new("/d/quanzhou/obj/shurou");
        ob->move(environment(this_object()));
        destruct(this_object());
}

