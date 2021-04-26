// Code of ShenZhou
// tao3.c ��ʵ��
// qfy July 21, 1996

inherit NPC;
string ask_me();

void create()
{
	set_name("��ʵ��", ({ "tao shixian", "tao", "shixian" }));
	set("nickname", "�ҹ���������");
	set("long", 
"��ʵ�����ҹ������������С��ͬʱ����Ҳ��С��\n");
	set("gender", "����");
	set("age", 55);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 27);
	set("int", 20);
	set("con", 27);
	set("dex", 30);
	set("shen", 0);
	
	set("max_qi", 1500);
	set("max_jing", 800);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 50);
	set("combat_exp", 300000);
	set("score", 5000);

	set_skill("force", 95);
	set_skill("dodge", 95);
	set_skill("parry", 95);
	set_skill("unarmed", 95);
	set_skill("ding-dodge", 90);
	set_skill("ding-force", 90);
	set_skill("ding-unarmed", 90);

	map_skill("dodge", "ding-dodge");
	map_skill("force", "ding-force");
	map_skill("unarmed", "ding-unarmed");

	set("chat_chance", 6);

	set("chat_msg", ({
		"��ʵ�ɹ��ǵص���������̫�����ɣ�\n",
		"��ʵ�ɶԴ��˵�����������ϣ��������\n",
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
