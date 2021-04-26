// Code of ShenZhou
// copy from zhu.c ����
// lisser

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("��ѧʿ", ({ "shi", "xue shi" }));
        set_color("$YEL$");
	set("long", "���Ǹ���ͨʫ���ѧ�ߡ�\n");
	set("gender", "����");
	set("age", 65);
        set("max_jing", 200);
        set("max_qi", 200);
	set_skill("literate", 200);

	set_temp("apply/attack", 14);
	set_temp("apply/defense", 14);
	set_temp("apply/damage", 30);

	set("combat_exp", 400);
	set("shen_type", 1);

	set("inquiry", ([
		"ѧλ" : "������������ȵ���ѧ������ǿ��\n",
		"�ƾ�" : "������������ȵ���ѧ������ǿ��\n",
	]));

	setup();
//	carry_object("/d/city/cloth")->wear();
}

int recognize_apprentice(object ob)
{	if (ob->query_skill("literate", 1) <20)
	{	ob->set_temp("mark/��", 1);
		return 1;
	}
	else
	{	ob->delete_temp("mark/��", 1);
		return 1;
	}
}

void init()
{
        object me = this_player();        

        ::init();

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object me)
{
	if (me->query_skill("literate", 1) == 0 )
	{	command("say " + RANK_D->query_respect(me) + "�����ɣ������кô���");
		command("say ����Ը���ѧ�����(xue " + query("id") + " literate)����Ϥxue�����ʹ�á�");
	}
	else 
	{	if (me->query_skill("literate", 1) >= 10 )
		{	command("say ��ȥ�����ط��ɣ�����ֻ����õ����硣");
		}
	}
}

