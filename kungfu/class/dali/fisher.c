// Code of ShenZhou
inherit NPC;

void create()
{
	set_name("�������", ({ "diancang yuyin", "yuyin", "fisher"}));
	set("long", 
		"����ʮ������ͣ�һ�ź�����Ĺ��������������������������\n");
	set("gender", "����");
	set("age", 45);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1000);
	set("max_jing",1000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 50);
//	set("combat_exp", 700000);

	set_temp("apply/armor", 50);
	set_skill("force", 140);
	set_skill("dodge", 180);
	set_skill("ding-dodge", 180);
	set_skill("ding-force", 140);
	set_skill("ding-unarmed", 140);
	set_skill("parry", 140);
	set_skill("unarmed", 140);
	set_skill("staff", 140);
	set_skill("duanjia-jian", 100);
	map_skill("dodge", "ding-dodge");
	map_skill("force", "ding-force");
	map_skill("unarmed", "ding-unarmed");
	map_skill("staff", "duanjia-jian");

	setup();
	carry_object("/clone/weapon/tiejiang")->wield();
    carry_object("/d/city/obj/cloth")->wear(); 
}

int accept_object(object who, object ob)
{
	object thisroom;
	thisroom=find_object("/d/dali/yideng1.c");

	if((string)ob->query("name")=="������" && ob->query("race") == "Ұ��") {
		remove_call_out("destroying");
		call_out("destroying", 1, ob);

	write("��������ӹ������ޣ��������´������㼸�ۣ����Ľ���������\n");
	write("��ˮ�У������˵���������Դ���ȥ����ʦ����ƴ�Ÿ�ʦ��һ��\n");
	write("��� \n");
	write("��ת���׽����ޣ�����˵�ÿ�ĭ��ɣ���С�İ�С����������˳�����\n");
	thisroom->set("exits/enter", "/d/dali/smallboat.c");
	remove_call_out("closing");
	call_out("closing", 5, thisroom);
    return 1;
	}
}

void closing(object thisroom)
{
	say("����������˼��䣬�ص�����ԭ�����ĵط���\n");
	thisroom->delete("exits/enter");
}

void destroying(object ob)
{
	destruct(ob);
	return;
}
