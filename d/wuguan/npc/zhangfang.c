/*-------------------------------------------------------------
** �ļ���: zhangfang.c
** Copyright (c) 2000-2001
** ������: ��ݹ�����
** ��  ��: 2001/08/13
** ��  ��: ����ʷ�����
**-----------------------------------------------------------*/

#include <ansi.h>
inherit NPC;

string ask_end();
 
void create()
{
	set_name("�ŷ�", ({ "zhang feng","zhang","zhangfang"}));
	set("title", "��������˷�����");
	set("gender", "����");
	set("age", 50);
	set("str", 27);
        set("int", 23);
        set("con", 19);
	set("dex", 26);
	set("long", "һ����ʮ��������ˣ����һ�ֺ����̣��������ר�ܽ��͵��ˡ�\n");
	set("combat_exp", 5000);
	set("shen_type", 1);

	set_skill("literate", 70);
	set_skill("unarmed", 35);
	set_skill("dodge", 30);
	set_skill("parry", 30);

        set("qi", 500);
	set("max_qi", 500);
	set("neili", 100); 
	set("max_neili", 100);

	set("inquiry", 
           ([
             "���" : (: ask_end :),
             "finish" : (: ask_end :),
             ]));

	setup();
}

string ask_end()
{
        object me;
        object ob, wage;
        ob=this_player();
        me=this_object();

	if ( ob->query("wuguan/end") == 1 )
	   return("��û�������Ҫ���ͣ���ȥ������\n");

	if ( ob->query("wuguan/end") ==0 )
	   return("�㻹ûҪ��������Ҫ�ȹ������ܵõ����͡�\n");
	   
	if ( ob->query("wuguan/end") > 1 )
	   {
		ob->set("wuguan/end", 0);
		ob->add("combat_exp", 50+random(50));
		ob->add("potential", 30+random(20));
		ob->delete("wuguan/job_pending");
		ob->delete_temp("wuguan_job");
		wage = new("/clone/money/silver");
		wage->set_amount(ob->query("wuguan/job_times"));
		wage->move(ob);
		command("nod "+ob->query("id"));
		return ob->name()+"�ɵĲ���������Ľ��͡�";
	  }
}