//Created by Zyu on k1-08-20
// jiang.c ����

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("�ϻ���", ({ "hua jiang", "jiang" }));
	set("long", "����һλ��ͷ�������ϻ��������Ͽ��������µ�ӡ�ǡ�˫��ȴ������λ�ľ���������ˡ�\n");
	set("gender", "����");
	set("age", 67);

	set_temp("apply/attack", 1);
	set_temp("apply/defense", 1);
	set_temp("apply/damage", 1);

	set("combat_exp", 1);
	set("shen_type", 1);

	set("inquiry", ([
		"����" : (: ask_job :),
		"job" : (: ask_job :),
		"�����" : "�������˼ҵ����������������еġ�",
		"����" : "�ҵļ���ͽ���Ⱥ����Ǳ�ȥ�ˣ�Ҳ��֪��������ˡ�",
	]) );

	set("chat_chance", 10);
	set("chat_msg", (: random_chat :) );	
	setup();

	carry_object("/clone/weapon/gangdao")->wield();
}

void init()
{
	object me = this_player();
	int exp = me->query("combat_exp");

	remove_call_out("check_exp");
	call_out("check_exp", 0, me, exp);
}

void check_exp(object me,int exp)
{
	if ( exp <= 4000 )
		return RANK_D->query_respect(me) + "�����в�������";
	else if (exp >= 8000 )
		return RANK_D->query_respect(me) + "���������������ʲô�ջ��ˡ�";
}

int random_chat()
{
    switch ( random(86) ) {
    case 0:
        command("say �ܵ�����Ķ�����������ϵ������ˡ�");
        return 1;
    case 1:
        command("say �����������Щ����������(ask jiang about job)��");
        return 1;
    case 2:
        command("say ��Щ�¿��Ļ������Ͼ�Ҫ�������ˣ���Ϊʲô��û��Ը�����ء�");
        return 1;
    case 3:
        command(":)");
        return 1;
    case 4:
	command("ah");
	return 1;
    case 5;
	command("say ������ûʲô��ͷ��������л������");
	return 1;
    default:
        return 0;
    }
    return 1;
}

void ask_job()
{
	return;
}