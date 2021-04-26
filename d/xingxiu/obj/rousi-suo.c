// Code of ShenZhou
// /d/xingxiu/obj/rss.c
// haowen mar 31st 1999
inherit ITEM;
//inherit F_AUTOLOAD;
#include <ansi.h>;
void create()
{
        set_name("��˿��", ({"rousi suo", "rope", "suo"}));
        set_weight(80);
        set_max_encumbrance(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "�������������֮һ����˿���������޺��Ե�ѩ��֮˿�Ƴɡ�
��ѩ��Ұ����ѩɣ֮�ϣ�����Զ�ϱ���ΪС��Ҳ�޶��ԣ��³����Ĳ�˿ȴ����������
Ѱ����һ����˿���Ѳ������ϡ��˱����������ץ(catch),��(release)���\n");
                set("unit", "��");
                set("value",0);
                set("no_sell", 1);
                set("no_beg", 1);
                set("no_get", 1);
                set("no_steal", 1);
        }
}
void init()
{
	mapping myfam;
	myfam=this_player()->query("family");
	if(myfam["family_name"] == "������"){
        	add_action("do_shou", "shou");
        	add_action("do_shou", "catch");
        	add_action("do_fang", "fang");
       		add_action("do_fang", "release");
        	add_action("do_look", "look");
        	add_action("do_look", "l");
//      	add_action("do_quit", "quit");
	}
}
/*int do_quit()
{
        if (!this_object()->query("catched"))
                {command("quit");
                return 1;}
        else    return notify_fail("�����ڲ����˳���Ϸ��\n");
}*/

int do_shou(string arg)
{
        object env,*inv, ob,target,victim,me=this_player();
        int i;
        env=environment(me);
        inv=all_inventory(env);
        for (i=0;i<sizeof(inv);i++){
                if (inv[i]==me) continue; 
                if (!me->visible(inv[i])) continue;
                if (inv[i]->query("id")==arg)
                        target=inv[i];
                }
        ob=this_object();
        if (!target) 
                return notify_fail("������˭��\n");
        
        if(target==me)
                return notify_fail("�㲻�����Լ���\n");

        if(!userp(target))
                return notify_fail("��ֻ������ң�\n");
                
        if( environment(me)->query("no_fight") ) 
        	return notify_fail("�㲻������������˿����\n");
        /*
        if(!me->is_fighting() || !target->is_fighting() || !living(target))
                return notify_fail("�������ս���в���ʹ����˿����\n");
        */
        
        if(ob->query_temp("catched"))
                {
                victim=find_player(ob->query_temp("catched"));
                if (victim && environment(victim)->query("short")=="��˿����")
                        return notify_fail("��˿���Ѿ������ˣ������ղ��±����ˣ�\n");

                else {ob->delete_temp("catched");
                        ob->delete("no_drop");}
                }
        if(me->is_busy())
                return notify_fail("��������æ���أ�\n");
                      
   
        message_vision( HIY "$N��Ц�����������ƺ���ʲô������$n��ȥ��\n" NOR,me,target);
        if(random(me->query_skill("feixing-shu",1)+me->query("neili")+me->query("combat_exp")/1000) > random(target->query_skill("dodge",1)+target->query("neili")+target->query("combat_exp")/1000))
                {

			tell_object(target,HIR"���Ȼ����ǧ����ϸ�߲�סȫ���ֽŶ��Ѿ����ܿ��ƣ�\n"NOR);

			tell_object(me,HIG"������һ�������а�ϲ�������Ѿ������ˣ�\n"NOR);
        		message_vision(HIY"$N���ܲ�������Ȼ�����εĶ�����סȫ���������á�\n" NOR, target);
                 	ob->set("no_drop",1);
                 	ob->set_temp("catched",target->query("id"));
                 	target->set_temp("current_catcher",me->query("id"));
                 	target->move("/d/xingxiu/rousiroom");
                }
        else {
                	message_vision(HIY "$n����һԾ���ܿ���$N���еĶ�����\n" NOR,me,target);
                	me->start_busy(random(5)+1);
        }          
        
        me->add("neili",-200);
        return 1;
}

int do_fang(string arg)
{
        object ob,target,victim,me=this_player();
        int i;
        string temp;
        ob=this_object();
if (!arg || arg == "") return notify_fail("�����˭��\n"); 
        if(!ob->query_temp("catched"))
                return notify_fail("��˿����û����ס�κ��ˣ�\n");

        victim=find_player(ob->query_temp("catched"));
        target=find_player(arg);
 
        if (!target) 
                return notify_fail("�����˭��\n");
        
        if(target==me)
                return notify_fail("�㲻�ܷ��Լ���\n");

        if(!userp(target))
                return notify_fail("��ֻ�ܷ���ң�\n");
                        
        
        if(!target->query_temp("current_catcher") || target->query_temp("current_catcher")!=me->query("id"))
                return notify_fail(target->query("name")+"û�б�����ס��\n");

        if(!victim || environment(victim)->query("short")!="��˿����" )
                {
                 ob->delete_temp("catched");
                 ob->delete("no_drop");
                 return notify_fail("��˿����û����ס�κ��ˣ�\n");
                }
        message_vision(HIR "$N����һ��ƺ���һ�����߻ص�$N�����С�\n" NOR,me);
        message_vision(HIY "$N��Ȼ������ȫ�ޣ����̻������\n"NOR,target);

        tell_object(target,HIR"�������ͻ����Ȼ����һ�ᣬ�Ѿ�������������\n" NOR);
        target->delete_temp("current_catcher");
        ob->delete_temp("catched");
        ob->delete("no_drop");
        target->move(environment(me));
        return 1;
}
int do_look(string arg)
{
        object ob,victim;

        ob=this_object();
 
        if( !arg || arg == "" ) return 0;

        if( present(arg, this_player()) != ob ) return 0;

        if( ob->query_temp("catched")) 
                {
                victim=find_player(ob->query_temp("catched"));
                if(environment(victim)->query("short")=="��˿����")
                {
                tell_object(
this_player(),"�������������֮һ����˿���������޺��Ե�ѩ��֮˿�Ƴɡ�
��ѩ��Ұ����ѩɣ֮�ϣ�����Զ�ϱ���ΪС��Ҳ�޶��ԣ��³����Ĳ�˿ȴ����������
Ѱ����һ����˿���Ѳ������ϡ��˱����������ץ(catch),��(release)���\n"+"����������������"+
victim->query("name") +"\n");
                return 1;}
                else {ob->delete_temp("catched");
                        ob->delete("no_drop");}
                }               
                tell_object(
this_player(),"�������������֮һ����˿���������޺��Ե�ѩ��֮˿�Ƴɡ�
��ѩ��Ұ����ѩɣ֮�ϣ�����Զ�ϱ���ΪС��Ҳ�޶��ԣ��³����Ĳ�˿ȴ����������
Ѱ����һ����˿���Ѳ������ϡ��˱����������ץ(catch),��(release)���\n");
       return 1;
}
