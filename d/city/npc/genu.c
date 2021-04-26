// Code of ShenZhou
// genu.c
// xQin 7/00
#include <ansi.h>
inherit NPC;
string ask_me();
int accept_object(object who, object ob);

void create()
{
        set_name("С��",({ "xiao lian", "genu","girl"}) );
        set("title", CYN"��Ů"NOR);
        set("gender", "Ů��" );
        set("age", 17);
        set("long", "����һ��������Ϊ����������Ů�������ḧ���ã������ת�����˲���������Ϊ֮�Ķ���\n"
                    "ֻ���������������ͻ�Ϊ�����һ����\n");
        set_temp("apply/defense", 5);
        set("combat_exp", 700);
        set("shen_type", 1);
        set("per", 23);
        set("str", 14);
        set("dex", 15);
        set("con", 16);
        set("int", 20);
        set("attitude", "friendly");
        set("inquiry", ([
        "����" : (: ask_me :),
        "play" : (:ask_me:),
        "����" : (:ask_me:),
        "pipa" : "����������ǵ���С��Ů������������������ƷҲֻӦ�����С�\n",
        "����" : "����������ǵ���С��Ů������������������ƷҲֻӦ�����С�\n",
        "����" : "СŮ��������Ϊ������λ"+RANK_D->query_respect(this_player())+"����������\n",
        
        ]));

        setup();
        carry_object("/d/city/npc/obj/pipa")->wield();
	carry_object("d/quanzhou/npc/obj/red_cloth")->wear();
        carry_object("/d/city/npc/obj/qupu2");
}
int accept_object(object who, object ob)
{
        
        if (ob->query("money_id") && ob->value() >= 500) 
        {
        who->set("fee_paid",1);
	}
	tell_object(who, "С���������˸�Ҿ��\n");
	return 1;
	
}
string ask_me()
{ 
        object me, ob, *obs;
        me = this_player();

	                
        if (me->query("fee_paid", 1)) 
	{
	switch( random(7) ) {
	case 0:
		command ("chang dongxian_ge");
		me->delete("fee_paid", 1);
		break;
	case 1: 
		command ("chang caisang_zi");
		me->delete("fee_paid", 1);
		break;
	case 2: 
		command ("chang dielian_hua");
		me->delete("fee_paid", 1);
		break;
	case 3: 
		command ("chang shuidiao_getou");
		me->delete("fee_paid",1);
		break;
	case 4: 
		command ("chang zuichui_bian");
		me->delete("fee_paid", 1);
		break;
	case 5: 
		command ("chang yujie_xing");
		me->delete("fee_paid", 1);
		break;
	case 6:
		command ("chang san_tai");
		me->delete("fee_paid", 1);
		break;


}
	return "СŮ���׳��ˡ�";
	}
}
