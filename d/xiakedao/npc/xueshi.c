//Cracked by Roath
// copy from zhu.c ����
// CLEANSWORD 1996/2/2
// Jay 9/11/96, added degree

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("��ѧʿ", ({ "shi", "xue shi" }));
        set_color("$YEL$");
	set("long", "���Ǹ���ͨʫ���ѧ�ߣ�ԭ���Ǳ��ƶ��������͵�����ѧ���书����\n�����ص�����������\n");
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
	carry_object(__DIR__"obj/yellowrobe")->wear();

/*	set("chat_chance", 3);
	set("chat_msg", ({
	}) );
*/
}

int recognize_apprentice(object ob)
{	if (ob->query_skill("literate", 1) <= 20)
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
	{	command("say " + RANK_D->query_respect(me) + 
			"��˵����ȶ�����Ҫ������Ŀ��ʶ�������ȥ��
�����������书�ؼ��أ�");
		command("say ����Ը���ѧ�����(xue " + query("id") + " literate)");
	}
	else 
	{	if (me->query_skill("literate", 1) >= 20 )
		{	command("say ��ȥ����ɣ���������鿼״Ԫ�ģ�");
		}
	}
}

