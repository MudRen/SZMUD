// Code of ShenZhou
// tao3.c ��֦��
// qfy July 21, 1996

inherit NPC;
string ask_me();

void create()
{
	set_name("��֦��", ({ "tao zhixian", "tao", "zhixian" }));
	set("nickname", "�ҹ����ɲ�֪��������������");
	set("long", 
"��֦������Ҷ�ɲ�֪˭��������˭�����ġ�������˵�Լ�������\n"
"������Ҷ�ɳ���Ϊ�����ۡ�\n");
	set("gender", "����");
	set("age", 60);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 21);
	set("con", 29);
	set("dex", 29);
	set("shen", 0);
	
	set("max_qi", 1500);
	set("max_jing", 800);
	set("neili", 1400);
	set("max_neili", 1400);
	set("jiali", 50);
	set("combat_exp", 300000);
	set("score", 5000);

	set_skill("force", 95);
	set_skill("dodge", 100);
	set_skill("parry", 95);
	set_skill("unarmed", 100);
	set_skill("ding-dodge", 95);
	set_skill("ding-force", 95);
	set_skill("ding-unarmed", 95);

	map_skill("dodge", "ding-dodge");
	map_skill("force", "ding-force");
	map_skill("unarmed", "ding-unarmed");

	set("chat_chance", 5);

	set("chat_msg", ({
		"��֦��ָ����Ҷ��˵���������������������ġ�\n",
		"��֦��˵�������Ǹ�ĸ�����ǵ�˭������˭������������ȴ���ˡ�\n",
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
