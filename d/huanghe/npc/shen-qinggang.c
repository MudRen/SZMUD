// Code of ShenZhou
// shen.c �����

inherit NPC;

void create()
{
	set_name("�����", ({ "shen qinggang", "shen" }));
	set("nickname", "�ϻ굶");
	set("long", 
"������ǻƺ��Ĺ���ϴ��ǹ�������ɳͨ��Ĵ���ӣ���ʹ������\n");
	set("title", "�ƺ��Ĺ��ϴ�");
	set("gender", "����");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_qi", 400);
	set("max_jing", 300);
	set("neili", 200);
	set("max_neili", 200);
	set("jiali", 20);
	set("combat_exp", 10000);

	set_skill("force", 30);
	set_skill("wuhu-duanmen", 45);
	set_skill("wuxingbu", 35);
	set_skill("dodge", 35);
	set_skill("parry", 40);
	set_skill("blade", 45);
	set_skill("unarmed", 35);

	map_skill("blade", "wuhu-duanmen");
	map_skill("parry", "wuhu-duanmen");
	map_skill("dodge", "wuxingbu");

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}
