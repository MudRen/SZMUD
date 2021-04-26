// Code of ShenZhou
// Npc: 
// Date: 

#include <ansi.h>
#include <dbase.h>
inherit NPC;

string ask_me();
int do_repair(string arg);

void create()
{
	set_name("СƼ", ({
		"xiao ping",
		"ping",
	}));
	set("long",
		"����һ��������ʮ���������ɵ�СѾ������Ҷü�������ˮ������\n"
		"ʮ��һ���������ӣ�������Ͷ��֮���ƺ������书��\n"
		"��˵��������ɽ����һ����Ů������Ů����巽�漫����ݡ�\n"
	);


	set("gender", "Ů��");
	set("attitude", "friendly");

	set("age", 18);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 400);
	set("max_jing", 300);
	set("neili", 450);
	set("max_neili", 450);
	set("jiali", 40);
	set("combat_exp", 10000);
	set("score", 100);

	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("strike", 50);
	set_skill("parry", 50);
	set_skill("sword", 50);
	set_skill("literate", 50);


	set("inquiry", ([
		"����"     : (: ask_me :),
		"�첹"	   : (: ask_me :),
		"����"   : (: ask_me :)
	]));

	setup();

        carry_object("/d/taihu/obj/red_cloth")->wear();
}

void init()
{
	add_action("do_repair", "sew");
}

string ask_me()
{
        object me = this_player();
	
        if (query_temp("busy"))
                return "Ӵ����Ǹ�����������æ���ء��������Ժ�\n";
	
	if (!me->query_temp("allow_repair")) 
		return "��λ"+RANK_D->query_respect(me)+"�����ȸ�һ��������\n";

        me->set_temp("pending/sewing", 1);
        return "��֪����λ"+RANK_D->query_respect(me)+"��Ҫ�Ҳ�(sew)Щʲ�᣿\n";
}

int do_repair(string arg)
{
        object obj,me;
        string file;

        me = this_player();

	if (!arg) return notify_fail("��Ҫ��ʲô������\n");        

	if( !objectp(obj = present(arg, me)) )
                return notify_fail("��Ҫ�첹ʲô������\n");

        if (!obj->query("armor_prop/armor") || obj->query("armor_prop/armor")<1)
                return notify_fail("�ⶫ���ܷ첹��\n");

        if (obj->query("material")=="steel" || obj->query("material")=="iron")
                return notify_fail(CYN"СƼ˵�����������˫���㲹�ⶫ����\n"NOR);

        if (obj->query("shaolin"))
                return notify_fail(CYN"СƼ˵���������ⲻ�ǵ�����....... �������������Ҳ������һ������\n"NOR);

        set_temp("busy",1);
	start_busy(2);
        file = base_name(obj);

        remove_call_out("destroy_ob");
        call_out("destroy_ob", 1, obj);

	obj = new(file);
        write("СƼ����һ�ڳ�����˵�����������ˣ���ȥ�ɣ��´�С�ĵ�Ŷ��\n");
        if(obj) obj->move(me);
        me->delete_temp("allow_repair");
        
	remove_call_out("enough_rest");
	call_out("enough_rest", 2);
		
        return 1;
}

void enough_rest()
{
        delete_temp("busy");
}

int accept_object(object me, object ob)
{
	command("jump");
	command("say ���Ƕ�л" + RANK_D->query_respect(me) + "���� ��");

	if(ob->query("money_id") && ob->value() >= 100)
		me->set_temp("allow_repair", 1);
	
	remove_call_out("destroy_ob");
	call_out("destroy_ob", 1, ob);

	return 1;
}

void destroy_ob(object ob)
{
	if(ob) destruct(ob);
}
