// Code of ShenZhou
// dayou.c 

inherit NPC;
string ask_biao();

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

	set("inquiry", ([
		"����" : (: ask_biao:),
	]) );

	setup();
	carry_object("/d/city/obj/cloth")->wear();
}

#include "/d/city/npc/biao_assign.h"
