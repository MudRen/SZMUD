// Code of ShenZhou
// tao5.c �һ���
// qfy July 21, 1996

inherit NPC;
string ask_me();

void create()
{
	set_name("�һ���", ({ "tao huaxian", "tao", "huaxian" }));
	set("nickname", "�ҹ���������");
	set("long", 
"�һ������е��壬����ڼ����Ϊ���ֵ���������ġ�\n");
	set("gender", "����");
	set("age", 58);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 29);
	set("int", 22);
	set("con", 28);
	set("dex", 27);
	set("shen", 0);
	
	set("max_qi", 1500);
	set("max_jing", 800);
	set("neili", 1300);
	set("max_neili", 1300);
	set("jiali", 50);
	set("combat_exp", 300000);
	set("score", 5000);

	set_skill("force", 95);
	set_skill("dodge", 95);
	set_skill("parry", 95);
	set_skill("unarmed", 95);
	set_skill("ding-dodge", 95);
	set_skill("ding-force", 90);
	set_skill("ding-unarmed", 90);

	map_skill("dodge", "ding-dodge");
	map_skill("force", "ding-force");
	map_skill("unarmed", "ding-unarmed");

	set("chat_chance", 5);

	set("chat_msg", ({
		"�һ����˸߲��ҵ�˵�����ҵ������������ҹ�������������ġ�\n",
		"�һ���˵�������ǳ�������嶷�ƣ��ȸ�ʮ���ҹ��Ҳ����ʲô��\n",
	}) );

	set("inquiry", ([
		"�����" : "��������ҵĺ����ѣ���˵�������ֵ��ǽ����е�Ӣ�ۺú���\n",
		"������" : (: ask_me :),
		"��ǰ��" : (: ask_me :),
		"������ǰ��" : (: ask_me :),
	]));

	setup();
	carry_object("/d/city/obj/cloth")->wear();
}

#include "/d/huashan/npc/tao.h"
