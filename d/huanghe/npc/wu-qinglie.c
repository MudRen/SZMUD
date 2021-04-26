// Code of ShenZhou
// wu.c ������

inherit NPC;

void create()
{
	set_name("������", ({ "wu qinglie", "wu" }));
	set("nickname", "׷��ǹ");
	set("long", 
"�������ǻƺ��Ĺ���϶����ǹ�������ɳͨ��Ķ����ӣ���ʹ��ǹ��\n");
	set("title", "�ƺ��Ĺ��϶�");
	set("gender", "����");
	set("age", 33);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 21);
	set("int", 19);
	set("con", 21);
	set("dex", 19);
	
	set("max_qi", 400);
	set("max_jing", 300);
	set("neili", 200);
	set("max_neili", 200);
	set("jiali", 20);
	set("combat_exp", 10000);

	set_skill("liuhe-qiang", 45);
	set_skill("wuxingbu", 35);
	set_skill("force", 30);
	set_skill("dodge", 35);
	set_skill("parry", 40);
	set_skill("pike", 45);
	set_skill("unarmed", 35);

	map_skill("pike", "liuhe-qiang");
	map_skill("dodge", "wuxingbu");
	map_skill("parry", "liuhe-qiang");

	setup();
	carry_object("/clone/weapon/qiang")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}
