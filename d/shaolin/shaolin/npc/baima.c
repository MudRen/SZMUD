// Code of ShenZhou
// baima.c ����

inherit NPC_TRAINEE;

int return_home(object home);

void create()
{
	set_name("����", ({ "bai ma", "ma", "horse" }) );
	set("race", "����");
	set("age", 10);
	set("long", "����һƥ��ɫ�Ĵ�������������ʨ�ף�������࣬ȷ��ƥ������ǧ����\n");
	set("msg_fail", "$n����$Nŭ˻һ��������������");
	set("msg_succ", "$nҡ��ͷ��ת�����ӻ����ŵ��棬�ƺ��򲻶�����");
	set("msg_trained","$n��˻һ�����ߵ�$N��߰����������Ե�ʮ�ָ��ˣ�");
	set("auto_follow",1);
	set("attitude", "peaceful");

	set("wildness", 5);
	
	set("str", 30);	
	set("con", 40);
	set("dex", 40);	
	set("int", 20);

	set("max_tili", 1000);
	set("combat_exp", 10000);
	set_weight(100000);

	setup();
}

int return_home(object home) 
{
	return 1;
}
