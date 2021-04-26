// Code of ShenZhou
//lang.c ��

inherit NPC;

void create()
{
	set_name("��", ({ "lang", "wolf" }) );
	set("race", "Ұ��");
	set("age", 15);
	set("long", "����һͷ��ɫ���ǣ����ú�ɫ���۾������㣬��ʱ�������˵�ս��������\n");
	set("attitude", "aggressive");
	
	set("str", 40);	
	set("con", 40);
	set("dex", 40);	
	set("int", 10);

	set("combat_exp", 2000);

	set_temp("apply/attack", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor",  20);

	set("chat_chance", 10);
	set("chat_msg", ({
		"�Ƿ���һ���ƽУ�������ʱ��Ҫ��������\n",
		"�ǵ�˫Ŀ�ںڰ������ź�⣬������ע�������һ��һ����\n",
	}) );
	
	setup();
}


