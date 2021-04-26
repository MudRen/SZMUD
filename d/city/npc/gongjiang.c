// Code of ShenZhou
// ����
// ssy

#include <ansi.h>
#include <dbase.h>
inherit NPC;

string ask_me();
int do_repair(string arg);

void create()
{
        set_name("����", ({ "gong jiang", "jiang", "worker"}));
     
        set("long",
"һλר�ſ���������ɫ(setcolor)����(setname)Ϊ���Ĺ�����\n");
        set("gender", "����");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 22);
        set("int", 20);
        set("con", 20);
        set("dex", 18);

        set("max_qi", 500);
        set("max_jing", 500);
        set("neili", 0);
        set("max_neili", 0);
        set("jiali", 0);
        set("combat_exp", 1000);
        set("score", 1000);

        set_skill("force", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);

        set("inquiry", ([
                "setname"     : (: ask_me :),
                "setcolor"     : (: ask_me :),
        ]));

        setup();
        carry_object("/d/city/obj/cloth")->wear();

}

void init()
{
        add_action("do_setname", "setname");
        add_action("do_setcolor", "setcolor");

}

string ask_me()
{
        object me = this_player();

        if (query_temp("busy"))
                return "Ӵ����Ǹ�����������æ���ء��������Ժ�\n";
        if (!me->query_temp("allow_set"))
                return "��λ"+RANK_D->query_respect(me)+"�����ȸ�ʮ��������\n";

        me->set_temp("pending/sewing", 1);
        return "��֪����λ"+RANK_D->query_respect(me)+"��Ҫ����Щʲ�᣿
(setcolor weapon_name color) (setname weapon_name)\n";
}

int do_setcolor(string arg)
{
        object obj,me;
        string file;
	string target,thecolor; 

        me = this_player();

        if (!me->query_temp("allow_set"))
	  return notify_fail("��λ"+RANK_D->query_respect(me)+"�����ȸ�ʮ��������\n");
          
	if(!arg)
	  return notify_fail("ʲô��\n");
	else if (sscanf(arg, "%s %s", target, thecolor)!=2)
          return notify_fail("ʲô��\n");
        if( !objectp(obj = present(target, me)) )
                return notify_fail("��Ҫ��ʲô�����Ͽ����֣�\n");

        if (!obj->query("weapon_prop/damage") || obj->query("weapon_prop/damage")<1)
                return notify_fail("�ⶫ���Ǳ�����\n");

        if (query_temp("busy"))
	  return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

	if (thecolor=="HIY")
	  obj->set("name",HIY+obj->query("name")+NOR);
        else if (thecolor=="HIG")
          obj->set("name",HIG+obj->query("name")+NOR);
        else if (thecolor=="HIR")
          obj->set("name",HIR+obj->query("name")+NOR);
        else if (thecolor=="HIB")
          obj->set("name",HIB+obj->query("name")+NOR);
        else if (thecolor=="HIM")
          obj->set("name",HIM+obj->query("name")+NOR);
        else if (thecolor=="HIC")
          obj->set("name",HIC+obj->query("name")+NOR);
        else if (thecolor=="HIW")
          obj->set("name",HIW+obj->query("name")+NOR);
        else if (thecolor=="RED")
          obj->set("name",RED+obj->query("name")+NOR);
        else if (thecolor=="GRN")
          obj->set("name",GRN+obj->query("name")+NOR);
        else if (thecolor=="YEL")
          obj->set("name",YEL+obj->query("name")+NOR);
        else if (thecolor=="BLU")
          obj->set("name",BLU+obj->query("name")+NOR);
        else if (thecolor=="MAG")
          obj->set("name",MAG+obj->query("name")+NOR);
        else if (thecolor=="CYN")
          obj->set("name",CYN+obj->query("name")+NOR);
        else if (thecolor=="WHT")
          obj->set("name",WHT+obj->query("name")+NOR);
	else return notify_fail("��ɫ������ help color �е�һ��\n");

        write("����Ĩ��һ�Ѻ���˵�������ƺ��ˣ���ȥ�ɡ���\n");
        me->delete_temp("allow_set");

        remove_call_out("enough_rest");
        call_out("enough_rest", 2);

        return 1;
       
}
 
int do_setname(string arg)
{
        object obj,me;

        me = this_player();

	if (!me->query_temp("allow_set"))
	  return notify_fail("��λ"+RANK_D->query_respect(me)+"�����ȸ�ʮ��������\n");
	  
	if (!arg) return notify_fail("��Ҫ��ʲô�����Ͽ����֣�\n");        

	if( !objectp(obj = present(arg, me)) )
                return notify_fail("��Ҫ��ʲô�����Ͽ����֣�\n");

        if (!obj->query("weapon_prop/damage") || obj->query("weapon_prop/damage")<1)
                return notify_fail("�ⶫ���Ǳ�����\n");
//	if (obj->query("value")>=1000000)
	//        return notify_fail("��������̫�����ˣ����ܱ����֡�\n");
        if (query_temp("busy"))
                return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

        if (obj->query("owner"))
                return notify_fail(obj->query("name")+"�ϲ����Ѿ���������\n");


        set_temp("busy",1);
        start_busy(2);

	obj->set("long",obj->query("long")+"\n"+obj->query("name")+"�Ͽ��У�"+me->query("name")+"֮������\n");
        obj->set("short",obj->query("short"));
        obj->set("owner",me->query("id"));

        write("����Ĩ��һ�Ѻ���˵�������̺��ˣ���ȥ�ɡ���\n");

	me->delete_temp("allow_set");

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
        command("smile");
	command("say ���Ƕ�л" + RANK_D->query_respect(me) + "���� ��");

        if(ob->query("money_id") && ob->value() >= 1000)
                me->set_temp("allow_set", 1);

        remove_call_out("destroy_ob");
        call_out("destroy_ob", 1, ob);

        return 1;
}

void destroy_ob(object ob)
{
        if (ob) destruct(ob);
}
