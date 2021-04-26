// Code of ShenZhou
// tongbo.c
// updated by wsky

#include <ansi.h>

inherit F_CLEAN_UP;
inherit ITEM;

void create()
{
        set_name("ͭ��", ({ "tongbo" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Խ��������ͭ�ࡣ\n");
                set("value", 10);
                set("material", "iron");
        }
        setup();
}


void init()
{
        add_action("do_flatter","paima");
}

int do_flatter(string arg)
{

        string* flatter = ({
                "$N����ͭ�࣬����ߺ���ţ���$n���ɣ�������أ��������Ž��ޱȣ���",
                "$N���µ�����$n���ɽ���������ԭ�������������ɵ���������",
                "$N������ɫ�Ŀ���$n������˵������������Щ��ԭ��򣬻�����$n���ɵ�һ��Сָ����",
                "$N����ĺ�������$n������һ��ɽ�����ѣ���һң�����޹⡣��",
                "$N�����Աߵ��ˣ�����˵������˭�ҵ���$n���ɣ��ҵ�һ������ƴ������˵�꿴�˿���·��",
                "$N˵������˭��$n���ɱ��䣬��ֱ���۵������Բ������𡣡�",
        });

        int skill,int1,int2;
        object me,obj;
        string msg;
        mapping myfam, vtfam;
        
        me=this_player();

        skill = me->query("flattering");

        if(skill<300) skill==30;
                else if(skill>300 && skill < 600) skill==60;
                else if(skill>600) skill==100;

        if( !arg ) return notify_fail("������˭����ƨ��\n");

        if(arg==me->query("id")) return notify_fail("���Լ���ƨ����\n");

        if( !objectp(obj = present(arg, environment(me)) ))
                return notify_fail("�����Ѿ��뿪����ط��ˡ�\n");

        if (me->is_fighting()) return notify_fail("����л�������ƨ�������ǲ�Ҫ�������ˡ�\n");

	if( me->is_busy() ) return notify_fail("( ����һ��������û����ɣ�����ʩ���⹦��)\n");

	if( environment(me)->query("no_fight") ) return notify_fail("�����ﻹ������ƨ��\n");

        if ( (!( myfam= me->query("family")) || myfam["family_name"] != "������") && me->query("id")!="wsky")
          return notify_fail("ֻ�����޵��Ӳ������������Ƥ��\n");

        if( me->query_temp("flattering") )
                return notify_fail("���Ѿ��ڹ��ž�������ƨ�ˡ�\n");
    
        if ( (vtfam = obj->query("family")) && vtfam["family_name"] != "������" && me->query("id")!="wsky")
                return notify_fail("��ֻ�������޵�����ƨ��\n");
        
        if (!userp(obj) && me->query("id")!="wsky") return notify_fail("��ֻ���������ƨ��\n");
        
        if (obj->query("combat_exp")<(me->query("combat_exp"))/3*2 && me->query("id")!="wsky") return notify_fail("���˹���̫�ֵ������\n");
	
        if (obj->query_temp("flattered")) return notify_fail("��"+RANK_D->query_rude(obj)+"����������ѬѬȻ���ء�\n");

        if (obj->query_temp("angry")) {
                message_vision(HIR"$n����ŭ�����֣�ȫ����$N������$N����һ���������ƨ�ĵ�������ˡ�\n"NOR,me,obj);
                me->start_busy(random(2)+1);
		obj->set_temp("yield",0);
                if( !obj->is_killing(me) ) obj->kill_ob(me);
		if( !me->is_killing(obj) ) me->kill_ob(obj);
                return 1;
        }

        msg=flatter[random(sizeof(flatter))];
        message_vision(HIM+msg+"\n"+NOR,me, obj);
        int1=me->query("int");int2=obj->query("int");
        if(random(int1*100)>random(int2*100)){
                message_vision(HIG"$n�����Ժ�������ЩƮƮȻ�ģ��ƺ��Թ�����Щ�Ʋ�������ЧӦ��\n"NOR,me,obj);

                me->set_temp("flattering",1);
                obj->add_temp("apply/damage", skill/3);
                obj->add_temp("apply/parry", skill/3);
                obj->add_temp("apply/dodge", skill/3);

                me->add("jing",-100);
                me->add("jingli",-100);
                me->add("flattering",1);

                me->start_busy(random(2)+1);
                if(me->query("potential") < me->query("max_potential")){
                        me->add("potential",random(2));
                }       
                me->add("combat_exp",random(6)+1);
                obj->set_temp("flattered",1);
                call_out("remove_effect", 5, me, obj, skill); 
        } else {
                message_vision(HIB"$n����$Nһ�ۣ�һ����ߡ�\n"NOR,me,obj);                      
                obj->set_temp("angry",1);
                call_out("remove_effect2", 10, me, obj); 
        }
        return 1;
}


int remove_effect(object me, object obj, int skill){            
        me->delete_temp("flattering");
        obj->delete_temp("flattered",1);
        obj->add_temp("apply/damage", -skill/3);
        obj->add_temp("apply/parry", -skill/3);
        obj->add_temp("apply/dodge", -skill/3);
        message_vision(HIY"$N��������˿�����������ɤ�ӡ�\n"NOR,me,obj);
}

int remove_effect2(object me, object obj){
        obj->delete_temp("angry");
        message_vision(HIY"$n��ɫ�Լ����͡�\n"NOR,me,obj);
}

