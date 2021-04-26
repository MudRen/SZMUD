// Code of ShenZhou
// dayou.c 

inherit NPC;

void create()
{
	set_name("½����", ({ "lu dayou", "lu", "dayou" }));
	set("nickname", "�����");
	set("long", 
"½������ĺ��ݣ��ֳ��ļ�������ģ���������ò�������\n"
"ͬ�������е������ǻ�ɽ������һ���еĺ��֡�\n");
	set("gender", "����");
	set("age", 26);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 23);
	set("int", 23);
	set("con", 24);
	set("dex", 28);
	
	set("max_qi", 800);
	set("max_jing", 600);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 20);
	set("combat_exp", 50000);
	set("score", 5000);

	set_skill("force", 50);
	set_skill("zixia-gong", 50);
	set_skill("dodge", 60);
	set_skill("parry", 50);
	set_skill("sword", 60);
	set_skill("huashan-jianfa", 60);
	set_skill("strike", 55);
	set_skill("hunyuan-zhang", 55);
	set_skill("huashan-shenfa", 60);

	map_skill("force", "zixia-gong");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("strike", "huashan-zhangfa");
	map_skill("dodge", "huashan-shenfa");

	prepare_skill("strike", "huashan-zhangfa");

	create_family("��ɽ��", 14, "����");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
}
