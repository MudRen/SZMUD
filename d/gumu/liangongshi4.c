//ROOM:  /d/gumu/liangongshi4.c
//   lgongf2.c
//By Blacko,2001
//update by April 01/08/19
 
#include <room.h>
#include <ansi.h>
#include <combat.h>

inherit FORCE;
inherit F_CLEAN_UP;
inherit ROOM;

#include "/kungfu/skill/force_list.h"

string check() { return "force"; }

int valid_enable(string usage) { return usage == "force"; }

void create()
{
       set("short", "Ů������");
       set("long", @LONG
�˴���רΪ��ĹŮ�������õ��������ڣ��ⷿ�����Ŀտ���������
�ţ��Ա������������(liangong)ʱ�߻���ħ�����ε��ݶ�����һС����
������ɢ����ʱ�����������䶫���һ������ƽʱ�����عر��š�
LONG
        );
	   
	   set("no_steal", "1");
	   set("no_sleep_room", "1");

	   set("exits", ([
		   "east" : __DIR__"liangongshi2",
		   ]));
 
	   set("item_desc",([
		   "door"          :       (: look_door :),
		   ]));
	   create_door("east", "����", "west", DOOR_CLOSED);

	   set("cost", 0);
	   setup();
}

string look_door()
{
	return "һ���������š�\n";
}

void init()
{
        add_action("do_liangong","liangong");
}

// practice.c

int do_liangong(string arg)
{
        object me=this_player();                        //��ǰ���
        object where = environment(me);         //��������
        string skillname;
        //int skill, skill_basic;
        int xj_lvl = me->query_skill("yunu-xinjing", 1);        //��Ů�ľ��ȼ�
        int force_lvl = me->query_skill("force", 1);            //�����ڹ��ȼ�
        int v,i,j,k;            // ��ʱ����
        int cost;               // ��ϰʱ�ĺķ�
        mapping skl;    // ����skill
        string *sname;  // skill����
		object *inv;    // ���ϴ��Ķ���

        seteuid(getuid());

        // ��Ů�б�
        if (me->query("gender") == "����")
                return notify_fail("�������ܵ�Ů���ҷ������·���������ˣ��å����\n");

        // �����ڹ�С����Ů�ľ�������
        if( force_lvl < xj_lvl)
                return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

        // æʱ����
        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        // սʱ����
        if( me->is_fighting() )
                return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

        // lvlС��30������
        if (xj_lvl<30)
                return notify_fail("����������һ��������������Ȼ��Ů�ľ���Ϊ�����������޷���ת��\n");

        // �������
        if ( me->query_temp("weapon") )
        return notify_fail("��ϰ��Ů�ľ�������֣��������ķ��ɡ�\n");

        // ��������
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)
                if( inv[i]->query("equipped") 
                        && inv[i]->query("armor_type")=="cloth")
                        i = sizeof(inv)+1;
        if (i==sizeof(inv)+2)
        return notify_fail("��ϰ��Ů�ľ������½󳨿����ܼ�ʱɢ��������\n");

        // �ڹ�Ҫ�����������Ԫ��
        skl=this_player()->query_skills();
        sname=sort_array( keys(skl), (: strcmp :) );
    for(v=0; v<sizeof(skl); v++) {
                if (SKILL_D(sname[v])->check() == "force")
                        k++;  
    }
    if ( k >=2 ) {
                // ������߻���ħ�˺�
        me->set("neili", 0);
        me->set("jingli", 50);
        me->set("qi", 50);
                i=(int)(me->query("max_jing")*65/100);
                me->set("eff_jing",i);
                return notify_fail("�����ڲ�ͬ���������ײ���������������Կ��ơ� \n"
                        +"����һҧ��������һ����Ѫ���Ų������߻���ħ��\n");
        }

        // ���ܿ���ϰ���� ---- 30n-1ʱ�������
        if ( (xj_lvl<270) && ((xj_lvl+1)/30*30 == xj_lvl + 1) )
                return notify_fail("�������ϰ����Ů�ľ�����Ȼ��������һ��... \n"
                        +"���ƺ��������޷�ͻ��ƿ����������ʱ������ˡ� \n");

        // ������������
        cost = to_int(sqrt(xj_lvl/to_float(150))*60);
        if ( (int)me->query("qi") < cost+10 )
                return notify_fail("�������������ϰ��Ů�ľ���\n");
        if ( (int)me->query("jingli") < cost+10 )
                return notify_fail("��ľ���������ϰ��Ů�ľ���\n");
        if ( (int)me->query("neili") < cost+10 )
                return notify_fail("�������������ϰ��Ů�ľ���\n");

        // ����
        me->add("neili", -cost);
        me->receive_damage("jingli", cost, "����͸֧��������");
        me->receive_damage("qi", cost, "����͸֧��������");

        // ����Ч��
        me->improve_skill("yunu-xinjing", force_lvl/4 +1, force_lvl > xj_lvl? 0: 1);
        write( HIY "���" + to_chinese("yunu-xinjing") + "�����ˣ�\n" NOR);
        return 1;

}

