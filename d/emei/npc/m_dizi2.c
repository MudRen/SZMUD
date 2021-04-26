// Code of ShenZhou
// /d/emei/npc/m_dizi2.c �е��� 
// Shan: 96/07/09

#include <ansi.h>

inherit NPC;

string ask_me(string);

void create()
{
	set_name("�е���", ({ "dizi", "nan dizi" }));
	set("long", 
        "���Ƕ���ɽ�ĵ�������ӣ����ڻ��������ֵ�С���ӡ�\n");
	set("gender", "����");
	set("age", 14+random(5));
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 20+random(2));
	set("int", 20+random(2));
	set("con", 21+random(2));
	set("dex", 24+random(2));
	
	set("max_qi", 100+random(60));
	set("max_jing", 100+random(50));
	set("neili", 140+random(30));
	set("max_neili", 140+random(30));

	set("combat_exp", 2000+random(200));
	set("score", 1000+random(200));

	set_skill("force", 25+random(5));
        set_skill("dodge", 20+random(4));
        set_skill("unarmed", 20+random(2));
        set_skill("parry", 20+random(3));
        set_temp("apply/attack", 15+random(4));
        set_temp("apply/defense", 15+random(3));
        set_temp("apply/damage", 5+random(2));

	create_family("������", 5, "����");

	setup();
	
	carry_object(__DIR__"obj/hui-cloth")->wear();
        set("chat_chance", 3);
        set("chat_msg", ({
		"����С���ӵ�������ǹ��ĺ��н�é�ҵĵط���\n",
        }) );

        set("inquiry", ([
                "��Ů��" : (: ask_me, "yunufeng" :),
        ]));

}

string ask_me(string name)
{

       if ( name == "yunufeng" )
        say(CYN "\nС���ӵ�����Ů�嶥�и�С���ӣ��ļ����ݣ���˵��ǰ����Ů��������ԡ�أ� \n\n" NOR);

}

